#ifndef _QUICK_SORT_H_
#define _QUICK_SORT_H_

#include "../utils.h"

void DutchPartition(int* arr, int l, int r, int& i, int& j);
void DutchQuickSort(int* arr, int l, int r);

int LomutoPartition(int* arr, int low, int high);
void LomutoQuickSort(int* arr, int low, int high);

int HoarePartition(int* arr, int low, int high);
void HoareQuickSort(int* arr, int low, int high);

#endif
