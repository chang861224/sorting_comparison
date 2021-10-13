#include "QuickSort.h"

void partition(int* arr, int l, int r, int& i, int& j){
    i = l - 1, j = r;
    int p = l - 1, q = r;
    int v = arr[r];

    while(true){
        // From left, find the first element greater than
        // or equal to v. This loop will definitely
        // terminate as v is last element
        while(arr[++i] < v)
            ;

        // From right, find the first element smaller than
        // or equal to v
        while(v < arr[--j]){
            if(j == l){
                break;
            }
        }

        // If i and j cross, then we are done
        if(i >= j){
            break;
        }

        // Swap, so that smaller goes on left greater goes
        // on right
        swap(arr[i], arr[j]);

        // Move all same left occurrence of pivot to
        // beginning of array and keep count using p
        if(arr[i] == v){
            p++;
            swap(arr[p], arr[i]);
        }

        // Move all same right occurrence of pivot to end of
        // array and keep count using q
        if(arr[j] == v){
            q--;
            swap(arr[j], arr[q]);
        }
    }

    // Move pivot element to its correct index
    swap(arr[i], arr[r]);

    // Move all left same occurrences from beginning
    // to adjacent to arr[i]
    j = i - 1;
    for(int k = l; k < p; k++, j--){
        swap(arr[k], arr[j]);
    }

    // Move all right same occurrences from end
    // to adjacent to arr[i]
    i = i + 1;
    for(int k = r - 1; k > q; k--, i++){
        swap(arr[i], arr[k]);
    }
}

// 3-way partition based quick sort
void quickSort(int* arr, int l, int r){
    if (r <= l){
        return;
    }

    int i, j;

    // Note that i and j are passed as reference
    partition(arr, l, r, i, j);

    // Recur
    quickSort(arr, l, j);
    quickSort(arr, i, r);
}
