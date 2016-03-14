/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: yoganandc
 *
 * Created on December 3, 2015, 6:36 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"

/*
 * 
 */
int main(int argc, char** argv) {
    struct Set *test1 = set_create(5, 0.75);
    char val1[6];
    strcpy(val1, "hello");
    set_add(test1, val1);
    set_remove(test1, val1);
    set_print(test1);
    return 0;
}
