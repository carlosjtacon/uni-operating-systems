#include <unistd.h>
#include <stdio.h>

pid_t ejecutar_orden(const char *orden, int *pbackgr);
void ejecutar_linea_ordenes(const char *orden);
void ejecutar_varias_ordenes(const char *user_input);