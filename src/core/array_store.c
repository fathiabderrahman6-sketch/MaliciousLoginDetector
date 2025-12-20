#include <stdio.h>
#include <stdlib.h>
#include "array_store.h"

// Initialisation du tableau
void initArray(LoginArray *arr, int capacity) {
    arr->size = 0;
    arr->capacity = capacity;
    arr->data = (Login *)malloc(capacity * sizeof(Login));
}

// Insertion d'un login
void insertArray(LoginArray *arr, Login login) {
    if (arr->size >= arr->capacity) {
        arr->capacity *= 2;
        arr->data = (Login *)realloc(arr->data, arr->capacity * sizeof(Login));
    }
    arr->data[arr->size++] = login;
}

// Affichage du tableau
void printArray(LoginArray *arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("[%d] %s | %s | %s | %s\n",
               i,
               arr->data[i].timestamp,
               arr->data[i].username,
               arr->data[i].status,
               arr->data[i].ip_address);
    }
}

// Libération mémoire
void freeArray(LoginArray *arr) {
    free(arr->data);
}
