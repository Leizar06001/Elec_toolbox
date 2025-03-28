// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.0
// LVGL version: 9.1.0
// Project name: ELEC_TOOLBOX_SL

#include "ui.h"

const ui_theme_variable_t _ui_theme_color_Back[1] = {0x262626};        // Dark background
const ui_theme_variable_t _ui_theme_alpha_Back[1] = {255};

const ui_theme_variable_t _ui_theme_color_Orange[1] = {0xFF8A00};       // Orange
const ui_theme_variable_t _ui_theme_alpha_Orange[1] = {255};

const ui_theme_variable_t _ui_theme_color_ColDev1[1] = {0x00B3FF};      // Blue
const ui_theme_variable_t _ui_theme_alpha_ColDev1[1] = {255};

const ui_theme_variable_t _ui_theme_color_ColDev1BG[1] = {0x004865};    // Dark blue
const ui_theme_variable_t _ui_theme_alpha_ColDev1BG[1] = {255};

const ui_theme_variable_t _ui_theme_color_ColDev1BG2[1] = {0x003D55};    // Darker blue
const ui_theme_variable_t _ui_theme_alpha_ColDev1BG2[1] = {255};

const ui_theme_variable_t _ui_theme_color_ColDev2[1] = {0xFF00F5};      // Pink
const ui_theme_variable_t _ui_theme_alpha_ColDev2[1] = {255};

const ui_theme_variable_t _ui_theme_color_ColDev2BG[1] = {0x6C0067};    // Dark pink
const ui_theme_variable_t _ui_theme_alpha_ColDev2BG[1] = {255};

const ui_theme_variable_t _ui_theme_color_ColDev2BG2[1] = {0x5F005B};    // Darker pink
const ui_theme_variable_t _ui_theme_alpha_ColDev2BG2[1] = {255};

const ui_theme_variable_t _ui_theme_color_TextColor[1] = {0xFFFFFF};    // White
const ui_theme_variable_t _ui_theme_alpha_TextColor[1] = {255};

const ui_theme_variable_t _ui_theme_color_hexa[1] = {0xFFD77A};         // Yellow
const ui_theme_variable_t _ui_theme_alpha_hexa[1] = {255};

uint8_t ui_theme_idx = UI_THEME_DEFAULT;


void ui_theme_set(uint8_t theme_idx)
{
    ui_theme_idx = theme_idx;
    _ui_theme_set_variable_styles(UI_VARIABLE_STYLES_MODE_FOLLOW);
}

