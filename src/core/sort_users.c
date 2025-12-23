#include "sort_users.h"

// Utilitaire swap
static void swap(UserFail *a, UserFail *b) {
    UserFail t = *a;
    *a = *b;
    *b = t;
}

// ---------------- BUBBLE SORT O(n²)
void bubbleSort(UserFail arr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j].fail_count < arr[j+1].fail_count)
                swap(&arr[j], &arr[j+1]);
}

// ---------------- INSERTION SORT O(n²)
void insertionSort(UserFail arr[], int n) {
    for (int i = 1; i < n; i++) {
        UserFail key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].fail_count < key.fail_count) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// ---------------- QUICK SORT O(n log n)
static int partition(UserFail arr[], int low, int high) {
    int pivot = arr[high].fail_count;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].fail_count > pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i + 1;
}

void quickSort(UserFail arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// ---------------- MERGE SORT O(n log n)
static void merge(UserFail arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    UserFail L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i=0, j=0, k=l;
    while (i < n1 && j < n2) {
        if (L[i].fail_count >= R[j].fail_count)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(UserFail arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
