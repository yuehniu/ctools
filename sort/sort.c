/*
  Desc:
    This is a 'Sort' algorithm implementations, including
    'QuickSort', 'MergeSort', 'InsertionSort', 'HeapSort', etc.

  Author:
    Julien
*/
#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

static int partition(Dtype *UsortData, int LowBound, int HiBound)
{
  Dtype pivot = UsortData[HiBound];
  int i = LowBound;

  for (int j = LowBound; j < HiBound; ++j){
    if (UsortData[j] < pivot){
      Dtype tmp = UsortData[i];
      UsortData[i] = UsortData[j];
      UsortData[j] = tmp; 

      i++;
    }
  }
  UsortData[HiBound] = UsortData[i];
  UsortData[i] = pivot;

  return i;
} 

/*
  Quick Sort.
  
  Args:
    UsortData, original unsorted data.
    LowBound, low bound for current sort cycle.
    HiBound, high bound for current sort cycle.
*/
void QuickSort(Dtype *UsortData, int LowBound, int HiBound)
{
  if (HiBound > LowBound) {
    //printf("Quick sort from %d to %d.\n", LowBound, HiBound);
   
    // Get pivot position
    int pos = partition(UsortData, LowBound, HiBound);

    // Divide
    QuickSort(UsortData, LowBound, pos - 1);
    QuickSort(UsortData, pos + 1, HiBound);
  }

  return;
}

/*
  Insertion Sort.

  Args:
   UsortData, original unsorted data. 
   Len, total data length.
*/
void InsertionSort(Dtype *UsortData, int Len)
{
  for (int j = 1; j < Len; ++j) {
    Dtype key = UsortData[j];
    
    int i = j - 1;
    while (i >= 0 && UsortData[i] > key) {
      UsortData[i + 1] = UsortData[i];
      i = i - 1;
    }
    
    UsortData[i + 1] = key;
  } 

  return;
}

void MergeSort(Dtype *UsortData, int LowBound, int HiBound)
{
  // Divide
  int offset = (HiBound - LowBound) / 2;
  if (HiBound - LowBound > 1){
    MergeSort(UsortData, LowBound, LowBound + offset);
    MergeSort(UsortData + offset, LowBound + offset, HiBound);
  }

  // Merge
  int mid = LowBound + offset; 
  //int low_array[N] = {};
  //int upper_array[N] = {}; 
  int n1 = offset;
  Dtype *low_array = (Dtype *) malloc(n1 * sizeof(Dtype));
  for (int i = 0; i < n1; ++i){
    low_array[i] = UsortData[i];
  }

  int n2 = HiBound - LowBound - offset;
  Dtype *upper_array = (Dtype *) malloc(n2 * sizeof(Dtype));
  for (int i = 0; i < n2; ++i){
    upper_array[i] = UsortData[offset + i];
  }

  int low_value = 0;
  int upper_value = 0;
  while(n1 > 0 || n2 > 0) {
    if (n1 > 0) low_value = low_array[n1 - 1]; 
    if (n2 > 0) upper_value = upper_array[n2 - 1];
    if (low_value < upper_value){
      UsortData[n1 + n2 - 1] = upper_value;
      --n2;
    } else if (low_value > upper_value){
      UsortData[n1 + n2 - 1] = low_value;
      --n1;
    } else {
      if (n1 > 0) {
        UsortData[n1 + n2 - 1] = low_value;
        --n1;
      } else if (n2 > 0) {
        UsortData[n1 + n2 - 1] = upper_value;
        --n2;
      }
    }
    low_value = 0;
    upper_value = 0;
  } 
  //printf("Sort data from %dth from %d\n", LowBound, HiBound);

  free(low_array);
  free(upper_array);
  return;
}
