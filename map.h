/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   map.h
 * Author: yoganandc
 *
 * Created on November 30, 2015, 8:09 PM
 */

#ifndef MAP_H
#define MAP_H

/**
 * Defines a key value pair to be stored in the map.
 */
struct Map_Entry;

/**
 * Defines a map with a list of pairs.
 */
struct Map;

/**
 * Return a map allocated with no elements.
 */
struct Map *map_create();

/**
 * Delete an allocated map.
 */
void map_delete(struct Map *map);

/**
 * Put an element with the given key and value in the map
 */
void map_add(struct Map *map, char *key, char *val);

/**
 * Get a value from the map based on a key.  Returns the value with the associated key.
 */
char *map_get(struct Map *map, char *key);

/**
 * Remove the pair of the given key and return the pair to the caller.
 */
void map_remove(struct Map *map, char *key);

/**
 * Returns the size of the map.
 */
int map_size(struct Map *map);

/**
 * Print contents of map to standard output.
 */
void map_print(struct Map *map);

#endif
