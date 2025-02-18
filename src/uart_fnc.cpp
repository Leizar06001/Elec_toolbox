#include "uart_fnc.h"
#include <Arduino.h>
#include <ui/ui.h>
#include "main.h"

t_uart_elm *uart_elm_head = NULL;

#define S1_RX 17
#define S2_RX 18
#define S1_TX 12
#define S2_TX 13

#define HEX_CNT 16

bool print_hexa = true;
bool print_ascii = true;

bool read_dev1 = true;
bool read_dev2 = true;

bool pullups = false;

int serial_state = 0;

void set_device(int device, bool state) {
    if (device == 1){
        read_dev1 = state;
    } else if (device == 2) {
        read_dev2 = state;
    }
}

void set_output_hexa(bool state) {
    print_hexa = state;
}

void set_output_ascii(bool state) {
    print_ascii = state;
}

void set_pullups(bool state) {
    pullups = state;
}

bool get_output_hexa() {
    return print_hexa;
}

bool get_output_ascii() {
    return print_ascii;
}

bool get_pullups() {
    return pullups;
}

void serial_prt(const char *str) {
    Serial.println(str);
}

void serial_flush() {
    while (Serial1.available()) Serial1.read();
    while (Serial2.available()) Serial2.read();
}

void serial_start(int baudrate) {
    Serial1.begin(baudrate, SERIAL_8N1, S1_RX, S1_TX);
    Serial2.begin(baudrate, SERIAL_8N1, S2_RX, S2_TX);
    if (pullups == false){
        pinMode(S1_RX, INPUT);
        pinMode(S2_RX, INPUT);
    } else {
        pinMode(S1_RX, INPUT_PULLUP);
        pinMode(S2_RX, INPUT_PULLUP);
    }
    serial_state = 1;
    lv_obj_clear_state(uic_Spinner, LV_STATE_DISABLED);
}

void serial_stop(){
    lv_obj_add_state(uic_Spinner, LV_STATE_DISABLED);
    Serial1.end();
    Serial2.end();
    serial_state = 0;
}

String get_timestamp() {
    unsigned long ms = millis();
    unsigned long seconds = ms / 1000;  // Convertir en secondes
    unsigned int milliseconds = ms % 1000;  // Récupérer les millisecondes restantes
    char tss[15];
    if (seconds > 1000){
        sprintf(tss, "[%lu.%01u] ", seconds, milliseconds / 100);
    } else if (seconds > 100){
        sprintf(tss, "[%lu.%02u] ", seconds, milliseconds / 10);
    } else {
        sprintf(tss, "[%lu.%03u] ", seconds, milliseconds);
    }
    
    return String(tss);;
}

void print_serial2(const char* timestamp, const char* input, int length, int channel){
    uint32_t color;
    uint32_t bg_color;

    static bool darker_1 = false;
    static bool darker_2 = false;

    // Alternate the background color to make it easier to read
    if (channel == 1) {
        color = _ui_theme_color_ColDev1[0];
        if (darker_1){
            bg_color = _ui_theme_color_ColDev1BG2[0];
        } else {
            bg_color = _ui_theme_color_ColDev1BG[0];
        }
        darker_1 = !darker_1;
    } else {
        color = _ui_theme_color_ColDev2[0];
        if (darker_2){
            bg_color = _ui_theme_color_ColDev2BG2[0];
        } else {
            bg_color = _ui_theme_color_ColDev2BG[0];
        }
        darker_2 = !darker_2;
    }

    // If print_hexa, we must cut the message in HEX_CNT characters
    // Print the hex values followed by the ASCII values, then do it until the end of the message
    if (print_hexa) {
        for (int i = 0; i < length; i += HEX_CNT) {
            String log_message = "";
            String log_hex = "";

            // Print the HEX values
            for (int j = 0; j < HEX_CNT; j++) {
                if (i + j < length) {
                    char hex[4];
                    sprintf(hex, "%02X ", input[i + j]);
                    log_hex += hex;
                }
            }
            if (print_ascii) {
                log_message = "| ";
                // Print the ASCII values
                for (int j = 0; j < HEX_CNT; j++) {
                    if (i + j < length) {
                        char ascii[2];
                        ascii[0] = input[i + j];
                        ascii[1] = '\0';
                        log_message += ascii;
                    }
                }
            }

            add_colored_log(timestamp,  color, 
                            log_hex.c_str(),    _ui_theme_color_hexa[0],
                            log_message.c_str(),_ui_theme_color_TextColor[0],
                            bg_color);
        }
    } else {
        if (print_ascii) {
            add_colored_log(timestamp, color, NULL, 0,
                                input,      _ui_theme_color_TextColor[0], bg_color);
        }
    }
}

void print_elms_in_list(){
    xSemaphoreTake(serial_mtx, portMAX_DELAY);
    t_uart_elm *current = uart_elm_head;
    while (current != NULL) {
        print_serial2(current->timestamp, current->input, current->len, current->channel);
        t_uart_elm *temp = current;
        current = current->next;
        free(temp->input);
        free(temp->timestamp);
        free(temp);
    }
    uart_elm_head = NULL;
    xSemaphoreGive(serial_mtx);
}

void add_elm_to_list(String timestamp, char *input, int len, int channel) {
    t_uart_elm *new_elm = (t_uart_elm *)malloc(sizeof(t_uart_elm));
    new_elm->len = len;
    new_elm->channel = channel;
    new_elm->next = NULL;
    
    new_elm->timestamp = (char*)malloc(timestamp.length() + 1);
    if (new_elm->timestamp == NULL) {
        free(new_elm);
        return;
    }
    strcpy(new_elm->timestamp, timestamp.c_str());

    new_elm->input = (char*)malloc(len);
    if (new_elm->input == NULL) {
        free(new_elm->timestamp);
        free(new_elm);
        return;
    }
    memcpy(new_elm->input, input, len);

    xSemaphoreTake(serial_mtx, portMAX_DELAY);
    if (uart_elm_head == NULL) {
        uart_elm_head = new_elm;
    } else {
        t_uart_elm *current = uart_elm_head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_elm;
    }
    xSemaphoreGive(serial_mtx);
}



void serial_read_sub() {
    int prev_state = 0;

    while (1){
        if (serial_state == 0) {
            vTaskDelay(100 / portTICK_PERIOD_MS);
            continue;
        }

        // If we just started reading, flush the serial buffer
        if (prev_state != serial_state) {
            serial_flush();
            prev_state = serial_state;
        }

        // DEVICE 1
        int len = 0;
        String input = "";
        if (read_dev1){
            while (Serial1.available())
            {
                char c = Serial1.read();
                input += c;
                len++;
            }
            if (len > 0){
                add_elm_to_list(get_timestamp(), (char*)input.c_str(), len, 1);
            }
        }

        // DEVICE 2
        len = 0;
        input = "";
        if (read_dev2){
            while (Serial2.available())
            {
                char c = Serial2.read();
                input += c;
                len++;
            }
            if (len > 0){
                add_elm_to_list(get_timestamp(), (char*)input.c_str(), len, 2);
            }
        }
        vTaskDelay(10);
    }
}