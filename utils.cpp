#include "utils.h"

void generateArray(int* array, long size){
    srand(time(NULL));

    for(auto i = 0 ; i < size ; i++){
        array[i] = rand();
    }
}

void printArray(int* array, int size){
    for(auto i = 0 ; i < size ; i++){
        cout << array[i] << " ";
    }
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

