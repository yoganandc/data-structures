/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "hash.h"

const float DEFAULT_LOADFACTOR = 0.75;
const int DEFAULT_CAPACITY = 16;

int hash(const char *word, int size) {
    unsigned int hash = 0;
    int i;

    for (i = 0 ; word[i] != '\0' ; i++) {
        hash = (31 * hash) + word[i];
    }
    
    return hash % size;
}


