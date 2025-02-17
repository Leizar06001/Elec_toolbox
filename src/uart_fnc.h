#ifndef UART_FNC_H
#define UART_FNC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ui/ui.h>

typedef struct s_uart_elm {
    char *timestamp;
    char *input;
    int len;
    int channel;
    struct s_uart_elm *next;
} t_uart_elm;

void serial_start(int baudrate);
void serial_stop();
void serial_read();
void serial_read_sub();

void set_device(int device, bool state);
void set_output_hexa(bool state);
void set_output_ascii(bool state);

void serial_prt(const char *str);

void print_elms_in_list();


#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif