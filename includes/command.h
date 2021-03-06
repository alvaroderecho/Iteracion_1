/**
 * @brief It implements the command interpreter
 *
 * @file command.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 13-01-2020
 * @copyright GNU Public License
 */

#ifndef COMMAND_H
#define COMMAND_H

#define N_CMDT 2
#define N_CMD 11

typedef enum enum_CmdType
{
  CMDS,
  CMDL
} T_CmdType;

typedef enum enum_Command
{
  NO_CMD = -1,
  UNKNOWN,
  EXIT,
  TAKE,
  DROP,
  ROLL,
  MOVE,
  INSPECT,
  OPEN,
  TURNON,
  TURNOFF
} T_Command;

/**
 * @brief Ejecuta un comando
 *
 * @file command.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @return T_Command
 */
T_Command command_get_user_input(char *arg);

#endif
