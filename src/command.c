/**
 * @brief It implements the command interpreter
 *
 * @file command.c
 * @author Profesores PPROG
 * @version 2.0
 * @date 13-01-2020
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "command.h"
#include "types.h"

#define CMD_LENGHT 30

char *cmd_to_str[N_CMD][N_CMDT] =
{
{"", "No command"},
{"", "Unknown"},
{"e", "Exit"},
{"t", "Take"},
{"d", "Drop"},
{"rl", "Roll"},
{"m", "move"},
{"i", "inspect"},
{"o", "open"}};

//Puntero tipo char de dimensiones 12x2, 12 filas, 2 columnas.
//Comandos que puede utlizar el jugador

//*************************************************

//T_Command es una enumeración definida en command.h

T_Command command_get_user_input(char *arg)
{
	T_Command cmd = NO_CMD;	  // == -1
	char input[CMD_LENGHT] = "";  //variable input tipo char, tamaño 30
	char aux[CMD_LENGHT] = "";
	int i = UNKNOWN - NO_CMD + 1; // == 0 - (-1) +1 = 2
	char *aux2 = NULL;

	// cmd == -1, input = "", i == 2

	/*si input <=0, cmd == -1 que devolvería el primer apartado de la enumeración
	que es NO_CMD, osea no comando.
	*/

	/* En resumen esta función compara el comando escrito por el jugador,
	si es "n" de "next", "e" de "exit", o escribe algo sin sentido,
	o algo desconocido o "b" de "back".
	*/

	strcpy(arg," ");
	fgets(aux,CMD_LENGHT,stdin); 
	aux2 = strtok(aux," \t\r\n");
	strcpy(input,aux2);//ERROR EN ESTA PARTE, AL METER SOLO ENTER EN LA CONSOLA

	aux2 = strtok (NULL,"\n");

	if (aux2 != NULL){
		strcpy(arg,aux2);
	}
	{
		cmd = UNKNOWN; // == 0
		while (cmd == UNKNOWN && i < N_CMD)
		{ //N_CMD == 7

			if (!strcasecmp(input, cmd_to_str[i][CMDS]) || !strcasecmp(input, cmd_to_str[i][CMDL]))
				/* La condición indica que si el input es igual a un elemento
			del array tipo char "cmd_to_str", deberá guardar la posición
			en la variable cmd. Si el input fuese igual a "n", que está en
			la posición 3 del array, quedaría: cmd = 3+ NO_CMD (NO_CMD == -1)
			, de esta forma quedaría cmd = 2, y devolvería la instrucción "next".
			*/
				cmd = i + NO_CMD;
			else //aquí hacer la excepción de take
				i++;
		}
	}

	/* Si cmd = -1, ha habido directamente un error de comando,
	si cmd = 0, es un comando desconocido,
	si cmd = 1, indica que debe salir "exit",
	si cmd = 2, indica que debe ir a la siguiente casilla "next"
	si cmd = 3, indica que debe ir a la casilla anterior "back"
	*/

	return cmd;
}
