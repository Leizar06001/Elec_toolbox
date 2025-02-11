#include "uart_fnc.h"
#include <Arduino.h>
#include <ui/ui.h>

#define S1_RX 17
#define S1_TX 18

#define HEX_CNT 16

bool print_hexa = true;
bool print_ascii = true;

bool read_dev1 = true;
bool read_dev2 = true;

void add_colored_log(const char* timestamp, uint32_t timestamp_color_hex,
                     const char* hexa,      uint32_t hexa_color_hex,
                     const char* message,   uint32_t message_color_hex)
{
    // Timestamp
    lv_obj_t * label_ts  = lv_label_create(ui_Container1);
    lv_label_set_text(label_ts , timestamp);
    lv_obj_set_style_text_color(label_ts , lv_color_hex(timestamp_color_hex), 0);

    // -- Taille automatique pour le timestamp
    lv_label_set_long_mode(label_ts, LV_LABEL_LONG_WRAP);
    // lv_obj_set_width(label_ts, LV_SIZE_CONTENT);
    lv_obj_set_width(label_ts, LV_PCT(10));

    if (hexa == NULL){
        // Message
        lv_obj_t * label_msg = lv_label_create(ui_Container1);
        lv_label_set_text(label_msg, message);
        lv_obj_set_style_text_color(label_msg, lv_color_hex(message_color_hex), 0);
        lv_label_set_long_mode(label_msg, LV_LABEL_LONG_WRAP);

        // lv_obj_set_width(label_msg, LV_SIZE_CONTENT);
        // lv_obj_set_width(label_msg, LV_PCT(100));
        lv_obj_set_flex_grow(label_msg, 1); // Pour que le message prenne toute la largeur
    } else {
        // Hexa
        lv_obj_t * label_hex = lv_label_create(ui_Container1);
        lv_label_set_text(label_hex, hexa);
        lv_obj_set_style_text_color(label_hex, lv_color_hex(hexa_color_hex), 0);
        lv_label_set_long_mode(label_hex, LV_LABEL_LONG_WRAP);
        lv_obj_set_width(label_hex, LV_PCT(50));

        // Message
        lv_obj_t * label_msg = lv_label_create(ui_Container1);
        lv_label_set_text(label_msg, message);
        lv_obj_set_style_text_color(label_msg, lv_color_hex(message_color_hex), 0);
        lv_label_set_long_mode(label_msg, LV_LABEL_LONG_WRAP);

        // lv_obj_set_width(label_msg, LV_SIZE_CONTENT);
        // lv_obj_set_width(label_msg, LV_PCT(100));
        lv_obj_set_flex_grow(label_msg, 1); // Pour que le message prenne toute la largeur
    }


    lv_obj_t * line_break = lv_obj_create(ui_Container1);
    lv_obj_set_size(line_break, LV_PCT(100), 0);  // 0 height = invisible
    // On supprime tous les styles pour éviter un trait ou une marge
    lv_obj_set_style_border_width(line_break, 0, 0);
    lv_obj_set_style_pad_all(line_break, 0, 0);
    lv_obj_set_style_bg_opa(line_break, LV_OPA_TRANSP, 0);
    // (Pour être certain qu’il n’ait pas de hauteur minimale)
    lv_obj_set_style_min_height(line_break, 0, 0);

    // Scroll to bottom
    lv_obj_scroll_to_y(ui_Container1, lv_obj_get_scroll_y(ui_Container1) + 9999, LV_ANIM_OFF);
}

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

int serial_state = 0;

void serial_start(int baudrate) {
    Serial1.begin(baudrate, SERIAL_8N1, S1_RX, S1_TX);
    serial_state = 1;
    lv_obj_clear_state(uic_Spinner, LV_STATE_DISABLED);
}

void serial_stop(){
    lv_obj_add_state(uic_Spinner, LV_STATE_DISABLED);
    Serial1.end();
    serial_state = 0;
}

String get_timestamp() {
    unsigned long ms = millis();
    unsigned long seconds = ms / 1000;  // Convertir en secondes
    unsigned int milliseconds = ms % 1000;  // Récupérer les millisecondes restantes
    char tss[15];
    sprintf(tss, "[%lu.%03u] ", seconds, milliseconds);
    return String(tss);;
}

void print_serial(const char* input){
    String timestamp = get_timestamp();

    // If print_hexa, we must cut the message in HEX_CNT characters
    // Print the hex values followed by the ASCII values, then do it until the end of the message
    if (print_hexa) {
        for (int i = 0; i < strlen(input); i += HEX_CNT) {
            String log_message = "| ";
            String log_hex = "";

            // Print the HEX values
            for (int j = 0; j < HEX_CNT; j++) {
                if (i + j < strlen(input)) {
                    char hex[4];
                    sprintf(hex, "%02X ", input[i + j]);
                    log_hex += hex;
                }
            }
            // Print the ASCII values
            for (int j = 0; j < HEX_CNT; j++) {
                if (i + j < strlen(input)) {
                    char ascii[2];
                    ascii[0] = input[i + j];
                    ascii[1] = '\0';
                    log_message += ascii;
                }
            }
            add_colored_log(timestamp.c_str(),  _ui_theme_color_ColDev1[0], 
                            log_hex.c_str(),    _ui_theme_color_ColDev2[0],
                            log_message.c_str(),_ui_theme_color_TextColor[0]);
        }
    } else {
        add_colored_log(timestamp.c_str(), _ui_theme_color_ColDev1[0], 
                            NULL, 0,
                            input,      _ui_theme_color_TextColor[0]);
    }
}

void serial_read() {
    if (serial_state == 0) return;

    String input = "";
    while (Serial1.available())
    {
        char c = Serial1.read();
        input += c;
    }
    if (input.length() > 0){
        print_serial(input.c_str());
    }
}