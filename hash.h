/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hash.h
 * Author: yoganandc
 *
 * Created on November 30, 2015, 8:09 PM
 */

#ifndef HASH_H
#define HASH_H

extern const float DEFAULT_LOADFACTOR;
extern const int DEFAULT_CAPACITY;

/**
 * This function will hash a C string returning an index based on an array of the size above.
 */
int hash(const char *word, int size);

#endif


