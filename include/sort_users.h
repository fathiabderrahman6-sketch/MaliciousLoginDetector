#ifndef SORT_USERS_H
#define SORT_USERS_H

#define MAX_USERS 50
#define MAX_NAME 50

typedef struct {
    char username[MAX_NAME];
    int fail_count;
} UserFail;

// Fonctions de tri
void bubbleSort(UserFail arr[], int n);
void insertionSort(UserFail arr[], int n);
void quickSort(UserFail arr[], int low, int high);
void mergeSort(UserFail arr[], int left, int right);

#endif
