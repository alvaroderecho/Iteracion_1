#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link.h"

struct _Link
{
    Id id;                     //Id del enlace
    char name[WORD_SIZE + 1]; //nombre del enlace
    Id sp1;                    //Id espacio inicial
    Id sp2;                    //Id espacio que conecta con el inicial
    BOOL link_st;              //TRUE abierto, FALSE cerrado
};

Link *link_create(Id id)
{

    Link *link;
    if ((link = (Link *)malloc(sizeof(Link))) == NULL)
        return NULL;

    link->id = id;
    link->name[0] = '\0';
    link->sp1 = NO_ID;
    link->sp2 = NO_ID;
    link->link_st = TRUE;

    return link;
}

STATUS link_destroy(Link *link)
{

    if (!link)
        return ERROR;

    free(link);
    link = NULL;
    return OK;
}

STATUS link_set_name(Link *link, char *name)
{
    if (!link || !name)
        return ERROR;

    if (strcpy(link->name, name) == NULL)
        return ERROR;

    return OK;
}

STATUS link_set_sp1(Link *link, Id id)
{
    if (!link)
        return ERROR;
    link->sp1 = id;
    return OK;
}

STATUS link_set_sp2(Link *link, Id id)
{
    if (!link)
        return ERROR;
    link->sp2 = id;
    return OK;
}

STATUS link_change_state(Link *link)
{
    if (!link)
        return ERROR;

    if (link->link_st == TRUE)
        link->link_st = FALSE;
    else
        link->link_st = TRUE;
    return OK;
}

Id link_getId (const Link *link) {
    if (!link) return NO_ID;

    return link->id;
}

char * link_get_name (Link *link) {
    if (!link) return NULL;

    return link->name;
}

Id link_get_sp1 (const Link *link) {
    if (!link) return NO_ID;

    return link->sp1;
}

Id link_get_sp2 (const Link *link) {
    if (!link) return NO_ID;

    return link->sp2;
}

BOOL link_get_state(const Link *link) {
    if (!link) return TRUE;

    return link->link_st;
}

STATUS link_print(const Link *link) {

    if (!link) return ERROR;

    fprintf(stdout,"Id del enlace: %ld\n",link->id);
    //Id del enlace

    fprintf(stdout,"Nombre del enlace: %s\n",link->name);
    //nombre del enlace

    fprintf(stdout,"Id del espacio inicial: %ld\n",link->sp1);
    //Id del espacio inicial

    fprintf(stdout,"Id del espacio final: %ld\n",link->sp2);
    //Id del espacio final

    fprintf(stdout,"Estado del enlace: %d\n",link->link_st);
    //Estado, Abierto = 1, Cerrado = 0

    return OK;
}