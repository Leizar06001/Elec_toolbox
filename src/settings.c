#include "settings.h"
#include <esp32_smartdisplay.h>

void setDisplayBrightness(float brightness)
{
    smartdisplay_lcd_set_backlight(brightness);
}