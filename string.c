/*
** EPITECH PROJECT, 2023
** z.c
** File description:
** z
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../string.h"

void string_init(string_t *this, const char *s)
{
    this->str = malloc(strlen(s)+1);
    this->string_init = &string_init;
    this->string_destroy = &string_destroy;
    this->assign_s = &assign_s;
    this->assign_c = &assign_c;
    this->append_c = &append_c;
    this->append_s = &append_s;
    this->at = &at;
    this->clear = &clear;
    this->length = &length;
    this->compare_s = &compare_s;
    this->compare_c = &compare_c;
    this->copy = &copy;
    this->c_str = &c_str;
    this->empty = &empty;
    strcpy(this->str, s);
}

void string_destroy(string_t *this)
{
    free(this->str);
}
