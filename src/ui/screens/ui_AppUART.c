// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.0
// LVGL version: 9.1.0
// Project name: ELEC_TOOLBOX_SL

#include "../ui.h"

int line_count = 0;

void ui_AppUART_screen_init(void)
{
    ui_AppUART = lv_obj_create(NULL);
    lv_obj_remove_flag(ui_AppUART, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

// *********** BAUDRATE ***********

    ui_baudrate = lv_dropdown_create(ui_AppUART);
    lv_dropdown_set_options(ui_baudrate, "115200\n57600\n19200\n9600");
    lv_obj_set_width(ui_baudrate, 99);
    lv_obj_set_height(ui_baudrate, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_baudrate, -342);
    lv_obj_set_y(ui_baudrate, 215);
    lv_obj_set_align(ui_baudrate, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_baudrate, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags


    ui_object_set_themeable_style_property(lv_dropdown_get_list(ui_baudrate),  LV_PART_SELECTED | LV_STATE_DEFAULT,
                                           LV_STYLE_BG_COLOR, _ui_theme_color_Orange);
    ui_object_set_themeable_style_property(lv_dropdown_get_list(ui_baudrate),  LV_PART_SELECTED | LV_STATE_DEFAULT,
                                           LV_STYLE_BG_OPA, _ui_theme_alpha_Orange);
    ui_object_set_themeable_style_property(lv_dropdown_get_list(ui_baudrate),  LV_PART_SELECTED | LV_STATE_CHECKED,
                                           LV_STYLE_BG_COLOR, _ui_theme_color_Orange);
    ui_object_set_themeable_style_property(lv_dropdown_get_list(ui_baudrate),  LV_PART_SELECTED | LV_STATE_CHECKED,
                                           LV_STYLE_BG_OPA, _ui_theme_alpha_Orange);

// *********** CONNECT ***********

    ui_SwitchStartStop = lv_switch_create(ui_AppUART);
    lv_obj_set_width(ui_SwitchStartStop, 70);
    lv_obj_set_height(ui_SwitchStartStop, 35);
    lv_obj_set_x(ui_SwitchStartStop, 315);
    lv_obj_set_y(ui_SwitchStartStop, 215);
    lv_obj_set_align(ui_SwitchStartStop, LV_ALIGN_CENTER);
    lv_obj_add_state(ui_SwitchStartStop, LV_STATE_CHECKED);       /// States

    ui_object_set_themeable_style_property(ui_SwitchStartStop, LV_PART_INDICATOR | LV_STATE_CHECKED, LV_STYLE_BG_COLOR,
                                           _ui_theme_color_Orange);
    ui_object_set_themeable_style_property(ui_SwitchStartStop, LV_PART_INDICATOR | LV_STATE_CHECKED, LV_STYLE_BG_OPA,
                                           _ui_theme_alpha_Orange);

    ui_Label4 = lv_label_create(ui_AppUART);
    lv_obj_set_width(ui_Label4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label4, 254);
    lv_obj_set_y(ui_Label4, 215);
    lv_obj_set_align(ui_Label4, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label4, "RUN");

// *********** DEVICE 1 ***********

    ui_edevice1 = lv_checkbox_create(ui_AppUART);
    lv_checkbox_set_text(ui_edevice1, "Device 1");
    lv_obj_set_width(ui_edevice1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_edevice1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_edevice1, -226);
    lv_obj_set_y(ui_edevice1, 215);
    lv_obj_set_align(ui_edevice1, LV_ALIGN_CENTER);
    lv_obj_add_state(ui_edevice1, LV_STATE_CHECKED);       /// States
    lv_obj_add_flag(ui_edevice1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags

    ui_object_set_themeable_style_property(ui_edevice1, LV_PART_INDICATOR | LV_STATE_DEFAULT, LV_STYLE_BORDER_COLOR,
                                        _ui_theme_color_ColDev1);
    ui_object_set_themeable_style_property(ui_edevice1, LV_PART_INDICATOR | LV_STATE_DEFAULT, LV_STYLE_BORDER_OPA,
                                        _ui_theme_alpha_ColDev1);
    ui_object_set_themeable_style_property(ui_edevice1, LV_PART_INDICATOR | LV_STATE_CHECKED, LV_STYLE_BG_COLOR,
                                        _ui_theme_color_ColDev1);
    ui_object_set_themeable_style_property(ui_edevice1, LV_PART_INDICATOR | LV_STATE_CHECKED, LV_STYLE_BG_OPA,
                                        _ui_theme_alpha_ColDev1);

// *********** DEVICE 2 ***********

    ui_edevice2 = lv_checkbox_create(ui_AppUART);
    lv_checkbox_set_text(ui_edevice2, "Device 2");
    lv_obj_set_width(ui_edevice2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_edevice2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_edevice2, -128);
    lv_obj_set_y(ui_edevice2, 215);
    lv_obj_set_align(ui_edevice2, LV_ALIGN_CENTER);
    lv_obj_add_state(ui_edevice2, LV_STATE_CHECKED);       /// States
    lv_obj_add_flag(ui_edevice2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags

    ui_object_set_themeable_style_property(ui_edevice2, LV_PART_INDICATOR | LV_STATE_DEFAULT, LV_STYLE_BORDER_COLOR,
                                        _ui_theme_color_ColDev2);
    ui_object_set_themeable_style_property(ui_edevice2, LV_PART_INDICATOR | LV_STATE_DEFAULT, LV_STYLE_BORDER_OPA,
                                        _ui_theme_alpha_ColDev2);
    ui_object_set_themeable_style_property(ui_edevice2, LV_PART_INDICATOR | LV_STATE_CHECKED, LV_STYLE_BG_COLOR,
                                        _ui_theme_color_ColDev2);
    ui_object_set_themeable_style_property(ui_edevice2, LV_PART_INDICATOR | LV_STATE_CHECKED, LV_STYLE_BG_OPA,
                                        _ui_theme_alpha_ColDev2);

// *********** SEND ***********                                            
                                                
    ui_BtnUartSend = lv_button_create(ui_AppUART);
    lv_obj_set_width(ui_BtnUartSend, 120);
    lv_obj_set_height(ui_BtnUartSend, 34);
    lv_obj_set_x(ui_BtnUartSend, 157);
    lv_obj_set_y(ui_BtnUartSend, 215);
    lv_obj_set_align(ui_BtnUartSend, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_BtnUartSend, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_remove_flag(ui_BtnUartSend, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_BtnUartSend, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    ui_object_set_themeable_style_property(ui_BtnUartSend, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_COLOR,
                                        _ui_theme_color_Orange);
    ui_object_set_themeable_style_property(ui_BtnUartSend, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_OPA,
                                        _ui_theme_alpha_Orange);

    ui_Label9 = lv_label_create(ui_BtnUartSend);
    lv_obj_set_width(ui_Label9, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label9, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label9, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label9, "SEND");

// *********** MENU ***********   

    ui_BtnUartMenu = lv_button_create(ui_AppUART);
    lv_obj_set_width(ui_BtnUartMenu, 120);
    lv_obj_set_height(ui_BtnUartMenu, 34);
    lv_obj_set_x(ui_BtnUartMenu, 10);
    lv_obj_set_y(ui_BtnUartMenu, 215);
    lv_obj_set_align(ui_BtnUartMenu, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_BtnUartMenu, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_remove_flag(ui_BtnUartMenu, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_BtnUartMenu, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_BtnUartMenu, lv_color_hex(0xFF5900), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BtnUartMenu, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label15 = lv_label_create(ui_BtnUartMenu);
    lv_obj_set_width(ui_Label15, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label15, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label15, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label15, "MENU");

// *********** SPINER ***********

    ui_Spinner = lv_spinner_create(ui_AppUART);
    //lv_spinner_set_anim_params(ui_Spinner, 1000, 90);
    lv_obj_set_width(ui_Spinner, 35);
    lv_obj_set_height(ui_Spinner, 35);
    lv_obj_set_x(ui_Spinner, 375);
    lv_obj_set_y(ui_Spinner, 215);
    lv_obj_set_align(ui_Spinner, LV_ALIGN_CENTER);
    lv_obj_add_state(ui_Spinner, LV_STATE_DISABLED);       /// States
    lv_obj_remove_flag(ui_Spinner, LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_set_style_arc_width(ui_Spinner, 7, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_object_set_themeable_style_property(ui_Spinner, LV_PART_INDICATOR | LV_STATE_DEFAULT, LV_STYLE_ARC_COLOR,
                                           _ui_theme_color_Orange);
    ui_object_set_themeable_style_property(ui_Spinner, LV_PART_INDICATOR | LV_STATE_DEFAULT, LV_STYLE_ARC_OPA,
                                           _ui_theme_alpha_Orange);
    lv_obj_set_style_arc_width(ui_Spinner, 7, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_Spinner, 0, LV_PART_INDICATOR | LV_STATE_DISABLED);

// *********** LOG CONTAINER ***********

    ui_Container1 = lv_obj_create(ui_AppUART);
    lv_obj_remove_style_all(ui_Container1);
    lv_obj_set_width(ui_Container1, 800);
    lv_obj_set_height(ui_Container1, 430);
    lv_obj_set_scroll_dir(ui_Container1, LV_DIR_VER);
    lv_obj_set_style_bg_color(ui_Container1, lv_color_hex(0x262626), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Container1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_scrollbar_mode(ui_Container1, LV_SCROLLBAR_MODE_AUTO);
    lv_obj_set_style_pad_all(ui_Container1, 0, 0);
    lv_obj_set_flex_flow(ui_Container1, LV_FLEX_FLOW_ROW_WRAP);


// *********** UART SEND ***********

    ui_WinUartSend = lv_obj_create(ui_AppUART);
    lv_obj_remove_style_all(ui_WinUartSend);
    lv_obj_set_width(ui_WinUartSend, 800);
    lv_obj_set_height(ui_WinUartSend, 310);
    lv_obj_set_align(ui_WinUartSend, LV_ALIGN_BOTTOM_MID);
    lv_obj_add_flag(ui_WinUartSend, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_remove_flag(ui_WinUartSend, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_WinUartSend, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_WinUartSend, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_UartKB = lv_keyboard_create(ui_WinUartSend);
    lv_obj_set_width(ui_UartKB, 800);
    lv_obj_set_height(ui_UartKB, 211);
    lv_obj_set_align(ui_UartKB, LV_ALIGN_BOTTOM_MID);

    ui_UartSendTxt = lv_textarea_create(ui_WinUartSend);
    lv_obj_set_width(ui_UartSendTxt, 675);
    lv_obj_set_height(ui_UartSendTxt, 87);
    lv_obj_set_x(ui_UartSendTxt, 5);
    lv_obj_set_y(ui_UartSendTxt, 5);
    lv_textarea_set_placeholder_text(ui_UartSendTxt, "Please type some data...");



    ui_UartSendDtType = lv_dropdown_create(ui_WinUartSend);
    lv_dropdown_set_options(ui_UartSendDtType, "Ascii\nHexa");
    lv_obj_set_width(ui_UartSendDtType, 110);
    lv_obj_set_height(ui_UartSendDtType, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_UartSendDtType, -5);
    lv_obj_set_y(ui_UartSendDtType, 5);
    lv_obj_set_align(ui_UartSendDtType, LV_ALIGN_TOP_RIGHT);
    lv_obj_add_flag(ui_UartSendDtType, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags


    ui_object_set_themeable_style_property(lv_dropdown_get_list(ui_UartSendDtType),  LV_PART_SELECTED | LV_STATE_CHECKED,
                                            LV_STYLE_BG_COLOR, _ui_theme_color_Orange);
    ui_object_set_themeable_style_property(lv_dropdown_get_list(ui_UartSendDtType),  LV_PART_SELECTED | LV_STATE_CHECKED,
                                            LV_STYLE_BG_OPA, _ui_theme_alpha_Orange);

    ui_UartSendDtType1 = lv_dropdown_create(ui_WinUartSend);
    lv_dropdown_set_options(ui_UartSendDtType1, "Dev 1\nDev 2");
    lv_obj_set_width(ui_UartSendDtType1, 110);
    lv_obj_set_height(ui_UartSendDtType1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_UartSendDtType1, -5);
    lv_obj_set_y(ui_UartSendDtType1, 50);
    lv_obj_set_align(ui_UartSendDtType1, LV_ALIGN_TOP_RIGHT);
    lv_obj_add_flag(ui_UartSendDtType1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags


    ui_object_set_themeable_style_property(lv_dropdown_get_list(ui_UartSendDtType1),  LV_PART_SELECTED | LV_STATE_CHECKED,
                                            LV_STYLE_BG_COLOR, _ui_theme_color_Orange);
    ui_object_set_themeable_style_property(lv_dropdown_get_list(ui_UartSendDtType1),  LV_PART_SELECTED | LV_STATE_CHECKED,
                                            LV_STYLE_BG_OPA, _ui_theme_alpha_Orange);


// *********** EVENTS ***********

    lv_obj_add_event_cb(ui_baudrate, ui_event_baudrate, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SwitchStartStop, ui_event_SwitchStartStop, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_edevice1, ui_event_edevice1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_edevice2, ui_event_edevice2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_BtnUartSend, ui_event_BtnUartSend, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_BtnUartMenu, ui_event_BtnUartMenu, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_UartSendTxt, ui_event_UartSendTxt, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_AppUART, ui_event_AppUART, LV_EVENT_ALL, NULL);
    uic_baudrate = ui_baudrate;
    uic_SwitchStartStop = ui_SwitchStartStop;
    uic_edevice1 = ui_edevice1;
    uic_edevice2 = ui_edevice2;
    uic_Spinner = ui_Spinner;
    uic_BtnUartMenu = ui_BtnUartMenu;
    uic_WinUartSend = ui_WinUartSend;
    uic_UartKB = ui_UartKB;
    uic_UartSendTxt = ui_UartSendTxt;
    uic_UartSendDtType = ui_UartSendDtType;
    uic_UartSendDtType = ui_UartSendDtType1;
}







void add_colored_log(const char* timestamp, uint32_t timestamp_color_hex,
    const char* hexa, uint32_t hexa_color_hex,
    const char* message, uint32_t message_color_hex, uint32_t background_color_hex)
{
    // Create a container to group the entire log entry
    lv_obj_t * log_entry = lv_obj_create(ui_Container1);
    lv_obj_set_size(log_entry, LV_PCT(100), LV_SIZE_CONTENT);
    lv_obj_set_flex_flow(log_entry, LV_FLEX_FLOW_ROW_WRAP);
    lv_obj_set_flex_align(log_entry, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_set_style_pad_all(log_entry, 0, 0);  // Optional: Adjust spacing
    lv_obj_set_style_pad_column(log_entry, 0, 0);  // Optional: Adjust spacing
    lv_obj_set_style_pad_top(log_entry, 3, 0);  // Optional: Adjust spacing
    lv_obj_set_style_border_width(log_entry, 0, 0);
    lv_obj_set_style_bg_color(log_entry, lv_color_hex(background_color_hex), 0); // Dark background
    lv_obj_set_style_bg_opa(log_entry, LV_OPA_MAX, 0); // Transparent background

    // Timestamp
    lv_obj_t * label_ts  = lv_label_create(log_entry);
    lv_label_set_text(label_ts , timestamp);
    lv_obj_set_style_text_color(label_ts , lv_color_hex(message_color_hex), 0);
    lv_obj_set_width(label_ts, LV_PCT(11));
    lv_obj_set_style_pad_all(label_ts, 0, 0);
    lv_obj_set_style_text_font(label_ts, &ui_font_Font1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_long_mode(label_ts, LV_LABEL_LONG_CLIP);

    // lv_obj_set_style_bg_opa(label_ts, LV_OPA_COVER, 0); 
    // lv_obj_set_style_bg_color(label_ts, lv_color_hex(0x000000), 0); // Dark background

    if (hexa == NULL) {
        // Message only
        lv_obj_t * label_msg = lv_label_create(log_entry);
        lv_label_set_text(label_msg, message);
        lv_obj_set_style_text_color(label_msg, lv_color_hex(message_color_hex), 0);
        lv_obj_set_width(label_msg, LV_SIZE_CONTENT);
        lv_label_set_long_mode(label_msg, LV_LABEL_LONG_WRAP);
    } else {
        // Hexa
        lv_obj_t * label_hex = lv_label_create(log_entry);
        lv_label_set_text(label_hex, hexa);
        lv_obj_set_style_text_color(label_hex, lv_color_hex(hexa_color_hex), 0);
        lv_obj_set_width(label_hex, LV_PCT(60));
        lv_obj_set_style_text_font(label_hex, &ui_font_Font1, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_label_set_long_mode(label_hex, LV_LABEL_LONG_WRAP);

        // lv_obj_set_style_bg_opa(label_hex, LV_OPA_COVER, 0); 
        // lv_obj_set_style_bg_color(label_hex, lv_color_hex(0xFF0000), 0); // Dark background

        // Message
        lv_obj_t * label_msg = lv_label_create(log_entry);
        lv_label_set_text(label_msg, message);
        lv_obj_set_style_text_color(label_msg, lv_color_hex(message_color_hex), 0);
        lv_obj_set_width(label_msg, LV_SIZE_CONTENT);
        lv_label_set_long_mode(label_msg, LV_LABEL_LONG_WRAP);

        // lv_obj_set_style_bg_opa(label_msg, LV_OPA_COVER, 0); 
        // lv_obj_set_style_bg_color(label_msg, lv_color_hex(0x000000), 0); // Dark background
    }

    // Scroll to bottom
    lv_obj_scroll_to_y(ui_Container1, lv_obj_get_scroll_y(ui_Container1) + 9999, LV_ANIM_OFF);

    // Check if we should remove old entries
    line_count++;
    while (line_count > 200) {
        lv_obj_t * oldest_entry = lv_obj_get_child(ui_Container1, 0);  // Get first log entry container
        if (oldest_entry) {
            lv_obj_del(oldest_entry); // Delete entire log entry
        }
        line_count--;
    }
}
