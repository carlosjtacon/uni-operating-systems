#include "minishell.h"

void imprimir_prompt()
{
   printf("minishell> "); /* se imprime en pantalla una cadena sencilla que servirá de prompt: entrada de órdenes en la consola */
   fflush(stdout);        /* vacía el buffer intermedio de salida y se envía el texto a la pantalla */
}

void eliminar_salto_linea(char *cad)
{
   int i, longitud;

   longitud=strlen(cad);  /* cad es una cadena de caracteres con la orden leída.*/
   for(i=longitud-1; i>=0;i--) /* se busca el carácter de final de línea introducido por fgets y se sustituye por '\0' para indicar el final de orden */
     if (cad[i]=='\n')         
     {
       cad[i]=0;
       break;
     }
}
       
void leer_linea_ordenes(char *buf)
{
    
   memset(buf, 0, sizeof(buf));
   fgets(buf, BUFSIZ-1, stdin); /* fgets almacena la orden leída introduciendo también el carácter de fin de línea introducido */
   buf[BUFSIZ-1]=0; /* se almacena el carácter de fin de cadena al final de buf porque va a ser tratada por eliminar_salto_linea como cadena */
   eliminar_salto_linea(buf);  
}

