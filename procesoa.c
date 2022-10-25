#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main (void)
{
  int fifolectura, fifoescritura;
  int bytesleidos;
  char mensaje[100];
  char buffer[10];
		    
    
  while (1) {  
	  
      //LEO	
	  printf("ESPERANDO RESUPESTA\n");  
  	  fifolectura = open ( "FIFO", 0);   
	  printf("RESPUESTA RECIBIDA--> ");
      bytesleidos= read(fifolectura, buffer, 1);
      while (bytesleidos!=0) {
          printf("%1c", buffer[0]); //muestro el byte leido
          bytesleidos= read(fifolectura, buffer, 1);//leo otro byte
      }
      printf("\n");       
      close (fifolectura);
    
	  printf("ENVIO DE MENSAJE\n");
	  printf("Escribe un mensaje: \t");
	  scanf("%s" , mensaje);
      fifoescritura = open ( "FIFO2", 1);
      write (fifoescritura , mensaje , strlen(mensaje));
      close (fifoescritura);
   
  }
  return (0);
}