/*
  Desc:
    This code aims to test several sort algorithm,
    including 'Quick Sort', 'Insertion Sort', 'Merge Sort', etc.

  Author:
    Julien
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include "sort.h"

//#define NUM 50

int main(int argc, char * argv[])
{
  assert(argc > 1);
  
  int num = atoi(argv[1]);
  Dtype *dataQuick = (Dtype *) malloc(num * sizeof(Dtype));
  Dtype *dataInsert = (Dtype *) malloc(num * sizeof(Dtype));
  Dtype *dataMerge = (Dtype *) malloc(num * sizeof(Dtype));

  for (int i = 0; i < num; ++i) {
    dataQuick[i] = random() % 100;
    dataInsert[i] = dataQuick[i];
    dataMerge[i] = dataQuick[i];
  }

  printf("Unsorted value: \n");
  for (int i = 0; i < num; ++i){
    printf("%d, ", dataQuick[i]);
  }
  printf("\n");

  // Quick Sort
  clock_t start = clock();
  QuickSort(dataQuick, 0, num - 1);
  clock_t end = clock();
  printf("\nSorted value by quick sort(%fs): \n", 
         (double)(end - start) / CLOCKS_PER_SEC);
  for (int i = 0; i < num; ++i){
    printf("%d, ", dataQuick[i]);
  }
  printf("\n");

  // Insertion Sort
  start = clock();
  InsertionSort(dataInsert, num);
  end = clock();
  printf("\nSorted value by insertion sort(%fs): \n", 
         (double)(end - start) / CLOCKS_PER_SEC);
  for (int i = 0; i < num; ++i){
    printf("%d, ", dataInsert[i]);
  }
  printf("\n");

  // Merge Sort
  start = clock();
  MergeSort(dataMerge,0, num);
  end = clock();
  printf("\nSorted value by merge sort(%fs): \n", 
         (double)(end - start) / CLOCKS_PER_SEC);
  for (int i = 0; i < num; ++i){
    printf("%d, ", dataMerge[i]);
  }
  printf("\n");

  free(dataQuick);
  free(dataInsert);
  free(dataMerge);
  return 0;
}
