/**
 * @brief Diseña la interfaz para cada comando
 *
 * @file game_reader.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 * @return STATUS
 */

#ifndef __GAME_READER__
#define __GAME_READER__

#include "game.h"

/**
 * @brief Carga los espacios
 *
 * @file game_reader.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 * @param game Juego usado
 * @param filename Nombre del archivo
 * @return STATUS
 */
STATUS game_reader_load_spaces(Game *game, char *filename);

/**
 * @brief Crea un juego a partir de un archivo
 *
 * @file game_reader.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 * @param game Juego usado
 * @param filename Nombre del archivo
 * @return STATUS
 */
STATUS game_reader_create_from_file(Game *game, char *filename);

/**
 * @brief Carga los objetos
 *
 * @file game_reader.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 15/03/2021
 * @param game Juego usado
 * @param filename Nombre del archivo
 * @return STATUS
 */
STATUS game_reader_load_objects(Game *game, char *filename);
#endif
