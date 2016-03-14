/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash.h"
#include "set.h"

struct Set_Entry {
    char *val;
};

struct Set {
    struct Set_Entry **data;
    int num_elements;
    float load_factor;
    float capacity;
};

struct Set *set_create(int capacity, float loadFactor) {
    struct Set *ret = (struct Set *) calloc(sizeof(struct Set), 1);
    ret->data = (struct Set_Entry **) calloc(sizeof(struct Set_Entry *), capacity);
    
    if(loadFactor >0 && loadFactor <= 1) {
        ret->load_factor = loadFactor;
    } else {
        ret->load_factor = DEFAULT_LOADFACTOR;
    }
    
    if(capacity > 0) {
        ret->capacity = capacity;
    } else {
        ret->capacity = DEFAULT_CAPACITY;
    }
    
    ret->num_elements = 0;
    
    return ret;
}

void set_delete(struct Set *set) {
    int i;
    
    if(set == NULL) {
        return;
    }
    
    for(i = 0; i < set->capacity; i++) {
        if(set->data[i] != NULL) {
            int j = 0;
            while(set->data[i][j].val != NULL) {
                free(set->data[i][j].val);
            }
            free(set->data[i]);
        }
    }
    free(set->data);
    free(set);
    set = NULL;
}

void set_add(struct Set *set, char *val) {
    double load;
    
    if(set == NULL || val == NULL) {
        return;
    }
    
    load = ((double) set->num_elements) / set->capacity;
    
    /* If load is greater than loadFactor, we need to rehash the table */
    if(load >= set->load_factor) {
        int i;
        struct Set *new_set = (struct Set *) calloc(sizeof(struct Set), 1);
        
        new_set->capacity = set->capacity * 2;
        new_set->num_elements = 0;
        new_set->load_factor = set->load_factor;
        new_set->data = (struct Set_Entry **) calloc(sizeof(struct Set_Entry *), new_set->capacity);
        
        for(i = 0; i < set->capacity; i++) {
            if(set->data[i] != NULL) {
                int j = 0;
                while(set->data[i][j].val != NULL) {
                    set_add(new_set, set->data[i][j].val);
                }
            }
        }
        
        set->capacity = new_set->capacity;
        free(set->data);
        set->data = new_set->data;
        free(new_set);
        set_add(set, val);
        
    /* Load is still less than loadFactor */
    } else {
        int val_hash = hash(val, set->capacity);
        
        /* If the bucket is empty */
        if(set->data[val_hash] == NULL) {
            set->data[val_hash] = (struct Set_Entry *) calloc(sizeof(struct Set_Entry), 2);
            set->data[val_hash][0].val = (char *) calloc(sizeof(char), strlen(val) + 1);
            strcpy(set->data[val_hash][0].val, val);
            set->data[val_hash][1].val = NULL;
            
        /* Bucket is not empty */    
        } else {
            int bucket_size = 1;
            while(set->data[val_hash][bucket_size - 1].val != NULL) {
                bucket_size++;
            }
            set->data[val_hash] = (struct Set_Entry *) realloc(set->data[val_hash], bucket_size + 1);
            set->data[val_hash][bucket_size].val = (char *) calloc(sizeof(char), strlen(val) + 1);
            strcpy(set->data[val_hash][bucket_size].val, val);
            set->data[val_hash][bucket_size + 1].val = NULL;
        }
        set->num_elements++;
    }
}

int set_contains(struct Set *set, char *val) {
    int val_hash;
    
    if(set == NULL || val == NULL) {
        return 0;
    } 
    
    val_hash = hash(val, set->capacity);
    if(set->data[val_hash] != NULL) {
        int i = 0;
        while(set->data[val_hash][i].val != NULL) {
            if(strcmp(set->data[val_hash][i].val, val) == 0) {
                return 1;
            }
        }
    }
    return 0;
}

void set_remove(struct Set *set, char *val) {
    if(set == NULL || val == NULL) {
        return;
    }
    
    if(set_contains(set, val)) {
        int val_hash;
        int bucket_size;
        
        val_hash = hash(val, set->capacity);
        bucket_size = 1;
        while(set->data[val_hash][bucket_size - 1].val != NULL) {
            bucket_size++;
        }
        
        /* BUCKET SIZE IS TWO - REMOVE BUCKET */
        if(bucket_size == 2) {
            free(set->data[val_hash][0].val);
            free(set->data[val_hash]);
            set->data[val_hash] = NULL;
            
        /* BUCKET SIZE GREATER THAN TWO */    
        } else {
            int index = 0;
            int i;
            while(!strcmp(set->data[val_hash][index].val, val)) {
                index++;
            }
            free(set->data[val_hash][index].val);
            for(i = index; i < bucket_size; i++) {
                set->data[val_hash][i] = set->data[val_hash][i + 1];
            }
            set->data[val_hash] = (struct Set_Entry *) realloc(set->data[val_hash], bucket_size - 1);
        }
    }
}

int set_size(struct Set *set) {
    return set->num_elements;
}

void set_print(struct Set *set) {
    int i;
    printf("{ ");
    for(i = 0; i < set->capacity; i++) {
        if(set->data[i] != NULL) {
            int j = 0;
            int k = 0;
            while(set->data[i][j].val != NULL) {
                printf("[%d] = %s ", i, set->data[i][j].val);
                if(k == 5) {
                    printf("\n  ");
                    k = 0;
                }
                j++;
                k++;
            }
        }
    }
    printf("}\n");
}
