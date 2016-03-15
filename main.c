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
#include <time.h>
#include "set.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    char val[6];
    char val2[300][6];
    int i, j, c;
    struct Set *test1 = set_create(5, 0.75);
    
    srand(time(NULL));
    val[5] = '\0';
    for(i = 0; i < 300; i++) {
        for(j = 0; j < 5; j++) {
            c = (rand() % 26) + 97;
            val[j] = (char) c;
            val2[i][j] = c;
        }
        set_add(test1, val);
        val2[i][5] = '\0';
    }
    set_print(test1);
    printf("\n");
   
    set_remove(test1, val2[0]);
    set_print(test1);
    
    set_remove(test1, val2[1]);
    set_print(test1);
    
    return 0;
}
