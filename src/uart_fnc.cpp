#include "uart_fnc.h"
#include <Arduino.h>
#include <ui/ui.h>

#define S1_RX 17
#define S2_RX 18
#define S1_TX 12
#define S2_TX 13

#define HEX_CNT 16

bool print_hexa = true;
bool print_ascii = true;

bool read_dev1 = true;
bool read_dev2 = true;

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

void print_serial(const char* input, int length, int channel){
    String timestamp = get_timestamp();
    uint32_t color;
    uint32_t bg_color;

    if (channel == 1) {
        color = _ui_theme_color_ColDev1[0];
        bg_color = _ui_theme_color_ColDev1BG[0];
    } else {
        color = _ui_theme_color_ColDev2[0];
        bg_color = _ui_theme_color_ColDev2BG[0];
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

            add_colored_log(timestamp.c_str(),  color, 
                            log_hex.c_str(),    _ui_theme_color_hexa[0],
                            log_message.c_str(),_ui_theme_color_TextColor[0],
                            bg_color);
        }
    } else {
        if (print_ascii) {
            add_colored_log(timestamp.c_str(), color, NULL, 0,
                                input,      _ui_theme_color_TextColor[0], bg_color);
        }
    }
}

void serial_read() {
    if (serial_state == 0) return;
    static int prev_state = 0;

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
            print_serial(input.c_str(), len, 1);

            Serial.print("1> ");
            Serial.println(input);
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
            print_serial(input.c_str(), len, 2);

            Serial.print("2> ");
            Serial.println(input);
        }
    }
}