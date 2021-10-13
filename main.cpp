#include <iostream>
#include <cmath>
#include "sorting/MergeSort.h"
#include "sorting/HeapSort.h"
#include "sorting/QuickSort.h"
#include "utils.h"

int main(){
    long size = pow(2, 5);
    int* array = new int[size];
    generateArray(array, size);

    //mergeSort(array, 0, size - 1);
    //heapSort(array, size);
    quickSort(array, 0, size - 1);

    printArray(array, size);
    cout << endl;

    return 0;
}
