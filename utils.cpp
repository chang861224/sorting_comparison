#include "utils.h"

int ArgPos(char* str, int argc, char** argv){
    int a;

    for(a = 1 ; a <  argc ; a++) if (!strcmp(str, argv[a])){
        if(a == argc - 1){
            cout << "Argument missing for " << str << endl;
            exit(1);
        }

        return a;
    }

    return -1;
}

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

