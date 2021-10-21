# Comparison with Sorting Methods
Compare the time-cost of sorting methods, include:

1. Bubble sort
2. Insertion sort
3. Merge sort
4. Heap sort
5. Quick sort (Dutch National Flag, Lomuto's Partition Scheme, Hoare's Partition Scheme)


## Usage

### Compilation
Use `make` to compile the program.
```
make
```

### Execution
Use `./main.exe` to execute the program. Here are the arguments shown below:
```
Options Description:
    -index <int>
        The index based on 2, which means the length of the number array. Default is 10.
    -method <string>
        The sorting method. Default is `BubbleSort`.
        Here is the method options:
        1)BubbleSort 2)InsertionSort 3)MergeSort 4)HeapSort 5)DutchQuickSort 6)LomutoQuickSort 7)HoareQuickSort
    -save <string>
        The filename which the result saved. The type of file is `.csv`.
        If you do not enter the filename, the result would be print out on the screen.
Usage:
./main.exe -index 15 -method MergeSort -save result.csv
```
