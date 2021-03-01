/**
 * @brief It defines a textual graphic engine
 *
 * @file graphic_engine.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 07-02-2021
 * @copyright GNU Public License
 */

#ifndef __GRAPHIC_ENGINE__
#define __GRAPHIC_ENGINE__

#include "game.h"
#include "command.h"
#include "screen.h"
#include "game_reader.h"



typedef struct _Graphic_engine Graphic_engine;


/**
 * @brief Crea un motor gráfico
 *
 * @file graphic_engine.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 * @return Graphic_engine*
 */
Graphic_engine* graphic_engine_create();

/**
 * @brief Destruye un motor gráfico
 *
 * @file graphic_engine.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 * @param ge Motor a destruir
 * @return void
 */
void graphic_engine_destroy(Graphic_engine *ge);

/**
 * @brief Dibuja un juego en un motor gráfico
 *
 * @file graphic_engine.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 * @param ge Motor a usar
 * @param game Juego a dibujar
 * @return void
 */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game);

/**
 * @brief Leer un comando por pantalla
 *
 * @file graphic_engine.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 * @param ge Motor a usar
 * @param str Comando a leer
 * @return void
 */
void graphic_engine_write_command(Graphic_engine *ge, char *str);

#endif
