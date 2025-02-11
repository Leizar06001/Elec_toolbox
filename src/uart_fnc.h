#ifndef UART_FNC_H
#define UART_FNC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ui/ui.h>

void serial_start(int baudrate);
void serial_stop();
void serial_read();

void set_device(int device, bool state);
void set_output_hexa(bool state);
void set_output_ascii(bool state);

void serial_prt(const char *str);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif