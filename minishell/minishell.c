#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "minishell.h"
#include "ejecutar.h"

int main(int argc, char *argv[]){
	//first print the prompt, then read the user_input and finally exec all the orders, until user_input == exit
	char user_input_buffer[BUFSIZ];

	printf("\nWelcome to my own uShell!\n");
	while(1)
	{
		imprimir_prompt();
		leer_linea_ordenes(user_input_buffer);
		ejecutar_varias_ordenes(user_input_buffer);
	}
	printf("Bye!\n\n");
}