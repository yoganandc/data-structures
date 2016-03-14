/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   set.h
 * Author: yoganandc
 *
 * Created on November 30, 2015, 8:09 PM
 */

#ifndef SET_H
#define SET_H

/**
 * A set which holds all of our data;
 */
struct Set;

/**
 * Allocate memory for the set.
 */
struct Set *set_create(int capacity, float loadFactor);

/**
 * Deallocate memory for the set.
 */
void set_delete(struct Set *set);

/**
 * Add a string to the set.
 */
void set_add(struct Set *set, char *val);

/**
 * Return true if the given string is in the set.
 *
 */
int set_contains(struct Set *set, char *val);

/**
 * Removes the given string from the set. Does nothing if given string is not in Set.
 */
void set_remove(struct Set *set, char *val);

/**
 * Return the size of the set.
 */
int set_size(struct Set *set);

/**
 * Print contents of set to standard output
 */
void set_print(struct Set *set);

#endif


