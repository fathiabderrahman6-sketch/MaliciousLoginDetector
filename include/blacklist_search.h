#ifndef BLACKLIST_SEARCH_H
#define BLACKLIST_SEARCH_H

#define MAX_BLACKLIST 50
#define MAX_STR 50

typedef struct {
    char items[MAX_BLACKLIST][MAX_STR];
    int size;
} Blacklist;

// Fonctions
void initBlacklist(Blacklist *b);
void addToBlacklist(Blacklist *b, const char *item);
int linearSearch(Blacklist *b, const char *item);
int binarySearch(Blacklist *b, const char *item);

#endif
