#include <stdio.h> 
#include <signal.h> 
#include <sys/errno.h> 
#include <unistd.h> 
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <stddef.h>
#include "ejecutar.h"
#include "parser.h"
#include "minishell.h"
#include "libmemoria.h"
#include "internas.h"

void ejecutar_varias_ordenes(const char* user_input){
	//count nº of ";" and exec ejecutar_linea_ordenes that number of times, using strsep()
	const char delimeter =';';
	char* running;
	char* token;
	int cont = 1;
	int len,i;
	len = strlen(user_input);

	//";" cont
	for (i = 0; i < len; ++i)
	{
		if (user_input[i]==';')
		{
			cont++;
		}
	}

	//ejecutar_linea_ordenes "cont" times, using strsep to split the string
	running = strdup(user_input);

	for (i = 0; i < cont; ++i)
	{
		token = strsep(&running, &delimeter);
		if (strcmp(token,"exit")==0)
		{
			printf("Bye!\n\n");
			exit(0);
		}
		else if(ord_interna(token)==0)
		{
			ejecutar_linea_ordenes(token);
		}
	}

}

void ejecutar_linea_ordenes(const char* orden){
	//ejecutar_orden with the possibility of bacground "&"
	int backgr;

	ejecutar_orden(orden, &backgr);
}

pid_t ejecutar_orden(const char* orden, int* pbackgr){
	//use execvp to exec the user_input
	char** args;
	pid_t pid;
	int status;
	int input_Indirection;
	int output_Indirection;

	if((args=parser_orden(orden, &input_Indirection, &output_Indirection, pbackgr))== NULL)
	{
		return(-1);
	}

	//fork a child to exec the user_input and wait if it's no "&"
	pid = fork();
	if (pid == -1)
	{
		perror("Error in fork");
		exit(-1);
	}
	else if (pid == 0)
	{
		if ((execvp(args[0],args)) < 0)
		{
			perror("Error in execvp");
			exit(-1);
		}
	}
	else
	{
		if (*pbackgr == 0)
		{
			waitpid(pid, &status, 0);
		}
	}
	free_argumentos(args);

	return 0;
}


