#include <Arduino.h>

#include <esp32_smartdisplay.h>
#include <ui/ui.h>
#include "uart_fnc.h"

void setup()
{
    Serial.begin(115200);
    // Serial.setDebugOutput(true);
    // log_i("Board: %s", BOARD_NAME);
    // log_i("CPU: %s rev%d, CPU Freq: %d Mhz, %d core(s)", ESP.getChipModel(), ESP.getChipRevision(), getCpuFrequencyMhz(), ESP.getChipCores());
    // log_i("Free heap: %d bytes", ESP.getFreeHeap());
    // log_i("Free PSRAM: %d bytes", ESP.getPsramSize());
    // log_i("SDK version: %s", ESP.getSdkVersion());

    smartdisplay_init();

    __attribute__((unused)) auto disp = lv_disp_get_default();

    ui_init();
}

ulong next_millis;
auto lv_last_tick = millis();

void loop()
{
    auto const now = millis();
    if (now > next_millis)
    {
        next_millis = now + 100;
        serial_read();

    }

    // Update the ticker
    lv_tick_inc(now - lv_last_tick);
    lv_last_tick = now;
    // Update the UI
    lv_timer_handler();
}