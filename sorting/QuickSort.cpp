#include "QuickSort.h"

/* This function partitions a[] in three parts
   a) a[l..i] contains all elements smaller than pivot
   b) a[i+1..j-1] contains all occurrences of pivot
   c) a[j..r] contains all elements greater than pivot */
void DutchPartition(int* arr, int l, int r, int& i, int& j){
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
void DutchQuickSort(int* arr, int l, int r){
    if (r <= l){
        return;
    }

    int i, j;

    // Note that i and j are passed as reference
    DutchPartition(arr, l, r, i, j);

    // Recur
    DutchQuickSort(arr, l, j);
    DutchQuickSort(arr, i, r);
}


/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
   array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int LomutoPartition(int* arr, int low, int high){
    int pivot = arr[high];  // pivot
    int i = (low - 1);      // Index of smaller element

    for(int j = low; j <= high- 1; j++){
        // If current element is smaller than or
        // equal to pivot
        if(arr[j] <= pivot){
            i++;    // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
   arr[] --> Array to be sorted,
   low  --> Starting index,
   high  --> Ending index */
void LomutoQuickSort(int* arr, int low, int high){
    if(low < high){
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = LomutoPartition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        LomutoQuickSort(arr, low, pi - 1);
        LomutoQuickSort(arr, pi + 1, high);
    }
}


/* This function takes first element as pivot, and places
   all the elements smaller than the pivot on the left side
   and all the elements greater than the pivot on
   the right side. It returns the index of the last element
   on the smaller side*/
int HoarePartition(int* arr, int low, int high){
    int pivot = arr[low];
    int i = low - 1, j = high + 1;

    while(true){
        // Find leftmost element greater than
        // or equal to pivot
        do{
            i++;
        } while(arr[i] < pivot);

        // Find rightmost element smaller than
        // or equal to pivot
        do{
            j--;
        } while(arr[j] > pivot);

        // If two pointers met.
        if(i >= j){
            return j;
        }

        swap(arr[i], arr[j]);
    }
}

/* The main function that implements QuickSort
   arr[] --> Array to be sorted,
   low  --> Starting index,
   high  --> Ending index */
void HoareQuickSort(int* arr, int low, int high){
    if(low < high){
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = HoarePartition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        HoareQuickSort(arr, low, pi);
        HoareQuickSort(arr, pi + 1, high);
    }
}

