#ifndef SIM_H
#define SIM_H

#include <string.h>
#define len(arr, type) sizeof(arr) / sizeof(type)


void pop(int* arr, int ind, size_t n_ints){
    int ints_to_copy = n_ints-ind-1;
    if (ints_to_copy != 0){
        memcpy(arr+ind, arr+ind+1, ints_to_copy * sizeof(int));
    }
}

#endif