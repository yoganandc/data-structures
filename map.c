/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stddef.h>
#include "hash.h"
#include "map.h"

struct Map_Entry {
    char *key;
    char *val;
};

struct Map {
    struct Map_Entry **data;
    int numElements;
};

struct Map *map_create() {
    return NULL;
}

void map_delete(struct Map *map) {
    
}

void map_put(struct Map *map, char *key,char *val) {
    
}

char *map_get(struct Map *map, char *key) {
    return NULL;
}

void map_remove(struct Map *map, char *key) {
    
}

int map_size(struct Map *map) {
    return 0;
}

void map_print(struct Map *map) {
    
}
