#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "simulation.h"


bool do_test(int prisoners, int ind){
    //scramble an array of numbers from 1 to 100
    int ints[prisoners];
    for (int i=0; i < prisoners; i++){
        ints[i] = i+1;
    }

    int rand_arrangement[prisoners];
    srand(ind);
    int current_rand;

    for (int i=0; i < prisoners; i++){
        current_rand = rand() % (prisoners-i);
        rand_arrangement[i] = ints[current_rand];
        pop(ints, current_rand, prisoners);
    }

    //begin test using scrambled array
    for (int i=0; i < prisoners; i++){
        int box_ind = i;
        int box_val = -1;
        int timeout = 50;
        while (box_val != i+1 && timeout > 0){
            box_val = rand_arrangement[box_ind];
            box_ind = box_val-1;
            timeout--;
        }

        if (box_val != i+1){
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv){
    //run the test 1000000 times
    long prisoners;
    long times_to_run;
    if (argc == 1){
        prisoners = 100;
        times_to_run = 1000000;
    }
    else if (argc == 3){
        prisoners = atoi(argv[1]);
        times_to_run = atoi(argv[2]);
    }
    else{
        printf("you have to supply either no arguments or 2 arguments: number of prisoners, number of times to run the test");
        return 1;
    }
    bool succ;
    int total = 0;
    int succ_i = 0;
    int current_time = time(NULL);
    for (int j=0; j < times_to_run; j++){
        succ = do_test(prisoners, current_time+j);
        total++;
        if (succ){
            succ_i++;
        }
    }

    float percentage = (float)succ_i / (float)total * 100;
    printf("%.6f%% success rate\n", percentage);

    return 0;
}