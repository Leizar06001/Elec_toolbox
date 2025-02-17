#include <Arduino.h>

#include <esp32_smartdisplay.h>
#include <ui/ui.h>
#include "uart_fnc.h"
#include "main.h"

TaskHandle_t uart_task;
SemaphoreHandle_t serial_mtx;

void uart_read_task(void *pvParameters) {
    serial_read_sub();
}

void setup()
{
    Serial.begin(115200);
    // Serial.setDebugOutput(true);
    log_i("Board: %s", BOARD_NAME);
    log_i("CPU: %s rev%d, CPU Freq: %d Mhz, %d core(s)", ESP.getChipModel(), ESP.getChipRevision(), getCpuFrequencyMhz(), ESP.getChipCores());
    log_i("Free heap: %d bytes", ESP.getFreeHeap());
    log_i("Free PSRAM: %d bytes", ESP.getPsramSize());
    log_i("SDK version: %s", ESP.getSdkVersion());

    smartdisplay_init();
    smartdisplay_lcd_set_backlight(1.0f);

    __attribute__((unused)) auto disp = lv_disp_get_default();

    ui_init();

    serial_mtx = xSemaphoreCreateMutex();
    
    xTaskCreatePinnedToCore(
        uart_read_task,      // Function to execute
        "Task1",        // Name of task
        10000,          // Stack size (bytes)
        NULL,           // Task input parameter
        5,              // Priority (1 is low, higher number = higher priority)
        &uart_task,         // Task handle
        0               // Core 0 (Use 1 for Core 1)
    );
}

ulong next_millis;
auto lv_last_tick = millis();

void loop()
{
    auto const now = millis();
    if (now > next_millis)
    {
        next_millis = now + 10;
        print_elms_in_list();

    }

    // Update the ticker
    lv_tick_inc(now - lv_last_tick);
    lv_last_tick = now;

    // Update the UI
    lv_timer_handler();
}