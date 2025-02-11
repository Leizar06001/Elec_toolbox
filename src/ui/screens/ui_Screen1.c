// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.0
// LVGL version: 9.1.0
// Project name: ELEC_TOOLBOX_SL

#include "../ui.h"

void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_remove_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

// *********** BAUDRATE ***********

    ui_baudrate = lv_dropdown_create(ui_Screen1);
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

    ui_Label4 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label4, 263);
    lv_obj_set_y(ui_Label4, 215);
    lv_obj_set_align(ui_Label4, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label4, "Connect");

    ui_SwitchStartStop = lv_switch_create(ui_Screen1);
    lv_obj_set_width(ui_SwitchStartStop, 50);
    lv_obj_set_height(ui_SwitchStartStop, 25);
    lv_obj_set_x(ui_SwitchStartStop, 325);
    lv_obj_set_y(ui_SwitchStartStop, 215);
    lv_obj_set_align(ui_SwitchStartStop, LV_ALIGN_CENTER);
    // lv_obj_add_state(ui_SwitchStartStop, LV_STATE_CHECKED);       /// States

    ui_object_set_themeable_style_property(ui_SwitchStartStop, LV_PART_INDICATOR | LV_STATE_CHECKED, LV_STYLE_BG_COLOR,
                                           _ui_theme_color_Orange);
    ui_object_set_themeable_style_property(ui_SwitchStartStop, LV_PART_INDICATOR | LV_STATE_CHECKED, LV_STYLE_BG_OPA,
                                           _ui_theme_alpha_Orange);

// *********** DEVICE 1 ***********

    ui_edevice1 = lv_checkbox_create(ui_Screen1);
    lv_checkbox_set_text(ui_edevice1, "Device 1");
    lv_obj_set_width(ui_edevice1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_edevice1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_edevice1, -200);
    lv_obj_set_y(ui_edevice1, 215);
    lv_obj_set_align(ui_edevice1, LV_ALIGN_CENTER);
    lv_obj_add_state(ui_edevice1, LV_STATE_CHECKED);
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

    ui_edevice2 = lv_checkbox_create(ui_Screen1);
    lv_checkbox_set_text(ui_edevice2, "Device 2");
    lv_obj_set_width(ui_edevice2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_edevice2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_edevice2, -100);
    lv_obj_set_y(ui_edevice2, 215);
    lv_obj_set_align(ui_edevice2, LV_ALIGN_CENTER);
    lv_obj_add_state(ui_edevice2, LV_STATE_CHECKED);
    lv_obj_add_flag(ui_edevice2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags

    ui_object_set_themeable_style_property(ui_edevice2, LV_PART_INDICATOR | LV_STATE_DEFAULT, LV_STYLE_BORDER_COLOR,
                                           _ui_theme_color_ColDev2);
    ui_object_set_themeable_style_property(ui_edevice2, LV_PART_INDICATOR | LV_STATE_DEFAULT, LV_STYLE_BORDER_OPA,
                                           _ui_theme_alpha_ColDev2);
    ui_object_set_themeable_style_property(ui_edevice2, LV_PART_INDICATOR | LV_STATE_CHECKED, LV_STYLE_BG_COLOR,
                                           _ui_theme_color_ColDev2);
    ui_object_set_themeable_style_property(ui_edevice2, LV_PART_INDICATOR | LV_STATE_CHECKED, LV_STYLE_BG_OPA,
                                           _ui_theme_alpha_ColDev2);

// *********** SWITCH ASCII / HEX ***********

    ui_Label3 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label3, 0);
    lv_obj_set_y(ui_Label3, 215);
    lv_obj_set_align(ui_Label3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label3, "Ascii");

    ui_SwitchAscii = lv_switch_create(ui_Screen1);
    lv_obj_set_width(ui_SwitchAscii, 50);
    lv_obj_set_height(ui_SwitchAscii, 25);
    lv_obj_set_x(ui_SwitchAscii, 50);
    lv_obj_set_y(ui_SwitchAscii, 215);
    lv_obj_set_align(ui_SwitchAscii, LV_ALIGN_CENTER);
    lv_obj_add_state(ui_SwitchAscii, LV_STATE_CHECKED);       /// States

    ui_object_set_themeable_style_property(ui_SwitchAscii, LV_PART_INDICATOR | LV_STATE_CHECKED, LV_STYLE_BG_COLOR,
                                            _ui_theme_color_Orange);
    ui_object_set_themeable_style_property(ui_SwitchAscii, LV_PART_INDICATOR | LV_STATE_CHECKED, LV_STYLE_BG_OPA,
                                            _ui_theme_alpha_Orange);


    ui_Label1 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label1, 101);
    lv_obj_set_y(ui_Label1, 215);
    lv_obj_set_align(ui_Label1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label1, "HEX");

    ui_SwitchHEX = lv_switch_create(ui_Screen1);
    lv_obj_set_width(ui_SwitchHEX, 50);
    lv_obj_set_height(ui_SwitchHEX, 25);
    lv_obj_set_x(ui_SwitchHEX, 149);
    lv_obj_set_y(ui_SwitchHEX, 215);
    lv_obj_set_align(ui_SwitchHEX, LV_ALIGN_CENTER);
    lv_obj_add_state(ui_SwitchHEX, LV_STATE_CHECKED);       /// States

    ui_object_set_themeable_style_property(ui_SwitchHEX, LV_PART_INDICATOR | LV_STATE_CHECKED, LV_STYLE_BG_COLOR,
                                            _ui_theme_color_Orange);
    ui_object_set_themeable_style_property(ui_SwitchHEX, LV_PART_INDICATOR | LV_STATE_CHECKED, LV_STYLE_BG_OPA,
                                            _ui_theme_alpha_Orange);


// *********** SPINER ***********

    ui_Spinner = lv_spinner_create(ui_Screen1);
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

// *********** CONTAINER ***********

    ui_Container1 = lv_obj_create(ui_Screen1);
    lv_obj_remove_style_all(ui_Container1);
    lv_obj_set_width(ui_Container1, 800);
    lv_obj_set_height(ui_Container1, 430);
    lv_obj_set_scroll_dir(ui_Container1, LV_DIR_VER);
    lv_obj_set_style_bg_color(ui_Container1, lv_color_hex(0x262626), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Container1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_scrollbar_mode(ui_Container1, LV_SCROLLBAR_MODE_AUTO);
    lv_obj_set_style_pad_all(ui_Container1, 0, 0);
    lv_obj_set_flex_flow(ui_Container1, LV_FLEX_FLOW_ROW_WRAP);


// *********** EVENTS ***********

    lv_obj_add_event_cb(ui_baudrate, ui_event_baudrate, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SwitchStartStop, ui_event_SwitchStartStop, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_edevice1, ui_event_edevice1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_edevice2, ui_event_edevice2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SwitchHEX, ui_event_SwitchHEX, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SwitchAscii, ui_event_SwitchAscii, LV_EVENT_ALL, NULL);
    uic_baudrate = ui_baudrate;
    uic_SwitchStartStop = ui_SwitchStartStop;
    uic_edevice1 = ui_edevice1;
    uic_edevice2 = ui_edevice2;
    uic_Spinner = ui_Spinner;
    uic_SwitchHEX = ui_SwitchHEX;
    uic_SwitchAscii = ui_SwitchAscii;
}
