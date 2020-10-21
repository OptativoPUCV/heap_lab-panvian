#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){

}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap *H=(Heap*)malloc(sizeof(Heap));
  H->size=0;
  H->capac=3;
  heapElem* arreglo=(heapElem*)malloc(3*sizeof(heapElem));
  H->heapArray=arreglo;
  return H;
}
