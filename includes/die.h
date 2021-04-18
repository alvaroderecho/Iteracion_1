/**
 * @brief Define el dado del juego
 *
 * @author Sergio Domínguez
 * @file die.c
 * @version 1.0
 * @date 07-03-2021
 * @copyright GNU Public License
 */

#ifndef DIE_H
#define DIE_H

#include "types.h"

typedef struct _Die Die;

/**
 * @brief Crea el dado del juego
 *
 * @author Sergio Domínguez
 * @file die.c
 * @version 1.0
 * @date 07-03-2021
 * @param id Id del dado
 * @param min Valor mínimo del dado
 * @param max Valor máximo del dado
 * @return *Die
 */
 Die * die_create (Id id, int min, int max);

 /**
 * @brief Destruye el dado del juego
 *
 * @author Sergio Domínguez
 * @file die.c
 * @version 1.0
 * @date 07-03-2021
 * @param d Dado a destruir
 * @return STATUS
 */
 STATUS die_destroy (Die *d);

 /**
 * @brief Devuelve la id de un Dado
 *
 * @author Sergio Domínguez
 * @file die.c
 * @version 1.0
 * @date 07-03-2021
 * @param d Dado a usar
 * @return Id
 */
 Id die_getId (Die *d);

 /**
 * @brief Devuelve la última tirada del dado
 *
 * @author Sergio Domínguez
 * @file die.c
 * @version 1.0
 * @date 07-03-2021
 * @param d Dado a usar
 * @return int
 */
 int die_getLastThrow (Die *d);

  /**
 * @brief "Tira el dado"
 *
 * @author Sergio Domínguez
 * @file die.c
 * @version 1.0
 * @date 07-03-2021
 * @param d Dado a usar
 * @return STATUS
 */
 STATUS die_roll (Die *d);

  /**
 * @brief Imprime los datos de un Dado
 *
 * @author Sergio Domínguez
 * @file die.c
 * @version 1.0
 * @date 07-03-2021
 * @param d Dado a usar
 * @return STATUS
 */
 STATUS die_print (Die *d);
#endif
