#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <fstream>
#include "sorting/BubbleSort.h"
#include "sorting/InsertionSort.h"
#include "sorting/MergeSort.h"
#include "sorting/HeapSort.h"
#include "sorting/QuickSort.h"
#include "utils.h"

int main(int argc, char** argv){
    // When no arguments input
    if(argc == 1){
        cout << "Options Description:" << endl;
        cout << "\t-index <int>" << endl;
        cout << "\t\tThe index based on 2, which means the length of the number array. Default is 10." << endl;
        cout << "\t-method <string>" << endl;
        cout << "\t\tThe sorting method. Default is `BubleSort`." << endl;
        cout << "\t\tHere is the method options:" << endl;
        cout << "\t\t1)BubbleSort 2)InsertionSort 3)MergeSort 4)HeapSort 5)DutchQuickSort 6)LomutoQuickSort 7)HoareQuickSort" << endl;
        cout << "\t-save <string>" << endl;
        cout << "\t\tThe filename which the result saved. The type of file is `.csv`." << endl;
        cout << "\t\tIf you do not enter the filename, the result would be print out on the screen." << endl;

        cout << "Usage:" << endl;
        cout << "./main.exe -index 15 -method MergeSort -save result.csv" << endl;
        cout << "--------------------" << endl;
    }

    int i;
    clock_t start, end;
    int index = 10;
    char* method = new char[20];
    strcpy(method, "BubbleSort");
    char* filename = new char[20];
    strcpy(filename, "");

    // Argument parse
    if((i = ArgPos((char*)"-index", argc, argv)) > 0) index = atoi(argv[i + 1]);
    if((i = ArgPos((char*)"-method", argc, argv)) > 0) strcpy(method, argv[i + 1]);
    if((i = ArgPos((char*)"-save", argc, argv)) > 0) strcpy(filename, argv[i + 1]);

    long size = pow(2, index);
    int* array = new int[size];
    generateArray(array, size);

    // Start time
    start = clock();

    // Sorting method choosing
    if((strcmp(method, "bubbleSort") == 0) || (strcmp(method, "BubbleSort") == 0) || (strcmp(method, "bubblesort") == 0)){
        strcpy(method, "Bubble Sort");
        bubbleSort(array, size);
    }
    else if((strcmp(method, "insertionSort") == 0) || (strcmp(method, "InsertionSort") == 0) || (strcmp(method, "insertionsort") == 0)){
        strcpy(method, "Insertion Sort");
        insertionSort(array, size);
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

    // End time
    end = clock();
    
    // Compute the execution duration time    
    double duration = double(end - start) / double(CLOCKS_PER_SEC);

    // Write
    if(strcmp(filename, "") == 0){  // Print out when no input-file
        //printArray(array, size);
        cout << "Sorting method: " << method << endl;
        cout << "Index based on 2: " << index << endl;
        cout << "Number of numbers in array: " << size << endl;
        cout << "Execution time: " << fixed << duration << setprecision(4) << " sec" << endl;
    }
    else{   // Write into the file
        ofstream file;

        file.open(filename, ios_base::app);

        // Format: Method, Index, Size, Time
        file << method << ",";
        file << index << ",";
        file << size << ",";
        file << duration << endl;

        file.close();
    }

    return 0;
}
