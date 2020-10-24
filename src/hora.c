#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>


//Función que se ejecuta al recibir la señal.
void Signal(int sig){
	
	//Se declaran y definen las variables necesarias para poder obtener la fecha y hora del sistema
	time_t tiempo = time(0);
	struct tm *tlocal = localtime(&tiempo);
	char output[128];
	strftime(output, 128, "%c", tlocal);
	
	//Se muestra en pantalla la fecha, hora y un aviso para recibir nuevamente una señal
	printf("Señal SIGUSR1 recibida: %s\n", output);
	printf("Listo para recibir la señal SIGUSR1.\n");
	
}

//Función principal.
int main (int argc, char* argv[]){

	//Se llama a la función Signal() cuando re recibe la señal SIGUSR1.
	signal(SIGUSR1, &Signal);
	
	//Se obtiene el PID del proceso actual
	pid_t pid0;
	
	//Se imprime el PID del proceso actual y un aviso para recibir la señal
	printf("Programa hora ejecutandose. PID=%d.\n", getpid());
	printf("Listo para recibir la señal SIGUSR1.\n");
	
	//Se utiliza un while infinito para que el proceso se cierre solo con el comando de interrupcion ^C
	while(1){
	}

	return 0;
}
