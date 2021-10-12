#include <iostream>
#include "sorting/MergeSort.h"
#include "sorting/HeapSort.h"
#include "utils.h"

int main(){
    int size = 6;
    int* array = new int[size]{4, 1, 2, 8, 0, 9};

    //mergeSort(array, 0, size - 1);
    heapSort(array, size);

    printArray(array, size);
    cout << endl;

    return 0;
}
