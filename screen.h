/**
 * @brief It defines a screen
 *
 * @file screen.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 07-02-2021
 * @copyright GNU Public License
 */

#ifndef __SCREEN__
#define __SCREEN__

#define SCREEN_MAX_STR 80

typedef struct _Area Area;

/**
 * @brief Inicializa una pantalla
 *
 * @file screen.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 * @return void
 */
void screen_init();

/**
 * @brief Destruye una pantalla
 *
 * @file screen.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 * @return void
 */
void screen_destroy();

/**
 * @brief Pinta una pantalla
 *
 * @file screen.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 * @return void
 */
void screen_paint();

/**
 * @brief Inicializa un área
 *
 * @file screen.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 * @param x Posición x
 * @param y Posición y
 * @param width Ancho
 * @param height Alto
 * @return Area*
 */
Area *screen_area_init(int x, int y, int width, int height);

/**
 * @brief Destruye un área
 *
 * @file screen.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 * @param area Área a destruir
 * @return void
 */
void screen_area_destroy(Area *area);

/**
 * @brief Limpia un área
 *
 * @file screen.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 * @param area Área a limpiar
 * @return void
 */
void screen_area_clear(Area *area);

/**
 * @brief Resetea el cursor de un área
 *
 * @file screen.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 * @param area Área a usar
 * @return void
 */
void screen_area_reset_cursor(Area *area);

/**
 * @brief Modifica un área
 *
 * @file screen.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 * @param area Área a usar
 * @param str  
 * @return void
 */
void screen_area_puts(Area *area, char *str);

#endif
