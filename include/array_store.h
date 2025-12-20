#ifndef ARRAY_STORE_H
#define ARRAY_STORE_H

#include "login.h"

// Structure du tableau dynamique
typedef struct {
    Login *data;
    int size;
    int capacity;
} LoginArray;

// Fonctions
void initArray(LoginArray *arr, int capacity);
void insertArray(LoginArray *arr, Login login);
void printArray(LoginArray *arr);
void freeArray(LoginArray *arr);

#endif
