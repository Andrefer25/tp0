/*
 * main.c
 *
 *  Created on: 28 feb. 2019
 *      Author: utnso
 */

#include "tp0.h"

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/
	int conexion;
	char* ip;
	char* puerto;

	t_log* logger;
	t_config* config;

	logger = iniciar_logger();

	//Loggear "soy un log"

	log_info(logger,"soy un log");

	config = leer_config();

	ip = config_get_string_value(config,"IP");

	puerto = config_get_string_value(config,"PUERTO");

	log_info(logger,ip);

	log_info(logger,puerto);

	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/

	//antes de continuar, tenemos que asegurarnos que el servidor esté corriendo porque lo necesitaremos para lo que sigue.

	//crear conexion

	conexion = crear_conexion(ip,puerto);

	printf("Se conecto en el socket %i\n",conexion);

	//enviar mensaje

	enviar_mensaje("hola",conexion);

	//recibir mensaje

	char* mensaje = recibir_mensaje(conexion);

	//loguear mensaje recibido

	log_info(logger,mensaje);

	free(mensaje);

	terminar_programa(conexion, logger, config);
}

//TODO
t_log* iniciar_logger(void)
{
	return log_create("./tp0.log","tp0",true,LOG_LEVEL_INFO);
}

//TODO
t_config* leer_config(void)
{
	return config_create("./tp0.config");
}

//TODO
void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	log_destroy(logger);
	config_destroy(config);
	liberar_conexion(conexion);
	//Y por ultimo, para cerrar, hay que liberar lo que utilizamos (conexion, log y config) con las funciones de las commons y del TP mencionadas en el enunciado
}
