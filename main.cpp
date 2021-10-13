#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iomanip>
#include "sorting/MergeSort.h"
#include "sorting/HeapSort.h"
#include "sorting/QuickSort.h"
#include "utils.h"

int main(int argc, char** argv){
    clock_t start, end;
    int index = 10;
    char* method = new char[20];
    int i;

    if((i = ArgPos((char*)"-index", argc, argv)) > 0) index = atoi(argv[i + 1]);
    if((i = ArgPos((char*)"-method", argc, argv)) > 0) strcpy(method, argv[i + 1]);

    long size = pow(2, index);
    int* array = new int[size];
    generateArray(array, size);

    start = clock();

    if((strcmp(method, "bubbleSort") == 0) || (strcmp(method, "BubbleSort") == 0) || (strcmp(method, "bubblesort") == 0)){
        strcpy(method, "Bubble Sort");
        mergeSort(array, 0, size - 1);
    }
    else if((strcmp(method, "mergeSort") == 0) || (strcmp(method, "MergeSort") == 0) || (strcmp(method, "mergesort") == 0)){
        strcpy(method, "Merge Sort");
        mergeSort(array, 0, size - 1);
    }
    else if((strcmp(method, "heapSort") == 0) || (strcmp(method, "HeapSort") == 0) || (strcmp(method, "heapsort") == 0)){
        strcpy(method, "Heap Sort");
        heapSort(array, size);
    }
    else if((strcmp(method, "DutchQuickSort") == 0) || (strcmp(method, "DutchQuicksort") == 0)){
        strcpy(method, "Dutch Quick Sort");
        DutchQuickSort(array, 0, size - 1);
    }
    else if((strcmp(method, "LomutoQuickSort") == 0) || (strcmp(method, "LomutoQuicksort") == 0)){
        strcpy(method, "Lomuto Quick Sort");
        LomutoQuickSort(array, 0, size - 1);
    }
    else if((strcmp(method, "HoareQuickSort") == 0) || (strcmp(method, "HoareQuicksort") == 0)){
        strcpy(method, "Hoare Quick Sort");
        HoareQuickSort(array, 0, size - 1);
    }
    else{
        cout << "Sorting method not found." << endl;
        exit(1);
    }

    end = clock();

//    printArray(array, size);
    cout << "Number of numbers in array: " << size << endl;
    cout << "Sorting method: " << method << endl;
    double duration = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Execution time: " << fixed << duration << setprecision(4) << " sec" << endl;

    return 0;
}
