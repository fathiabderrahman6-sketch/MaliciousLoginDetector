#include <string.h>
#include "blacklist_search.h"

// Initialisation
void initBlacklist(Blacklist *b) {
    b->size = 0;
}

// Ajouter un élément
void addToBlacklist(Blacklist *b, const char *item) {
    strcpy(b->items[b->size++], item);
}

// Recherche linéaire O(n)
int linearSearch(Blacklist *b, const char *item) {
    for (int i = 0; i < b->size; i++) {
        if (strcmp(b->items[i], item) == 0)
            return 1;
    }
    return 0;
}

// Recherche binaire O(log n)
// ⚠️ suppose que la blacklist est triée
int binarySearch(Blacklist *b, const char *item) {
    int left = 0, right = b->size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(item, b->items[mid]);

        if (cmp == 0) return 1;
        if (cmp < 0) right = mid - 1;
        else left = mid + 1;
    }
    return 0;
}
