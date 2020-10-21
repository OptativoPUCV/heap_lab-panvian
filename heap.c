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
  if(pq->size==0) return NULL;
  return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){
  if(pq->size==pq->capac) {
    pq->capac=pq->capac*2+1;
    pq->heapArray=realloc(pq->heapArray,pq->capac);    
  }
  heapElem aux2;
  pq->heapArray[pq->size].priority=priority;
  pq->heapArray[pq->size].data=data;
  int aux=pq->size;
  pq->size++;
  while(pq->heapArray[aux].priority>pq->heapArray[(aux-1)/2].priority){
    aux2=pq->heapArray[aux];
    pq->heapArray[aux]=pq->heapArray[(aux-1)/2];
    pq->heapArray[(aux-1)/2]=aux2;
    aux=(aux-1)/2;
  }
}

void heap_pop(Heap* pq){
  int aux=0;
  heapElem aux2;
  //aux2=pq->heapArray[0];
  pq->heapArray[0]=pq->heapArray[pq->size-1];
  //pq->heapArray[pq->size-1]=aux2;
  pq->size--;
  while(pq->heapArray[aux].priority<pq->heapArray[2*aux+1].priority || pq->heapArray[aux].priority<pq->heapArray[2*aux+2].priority) {
    if(2*aux+1==pq->size || 2*aux+2==pq->size) return;
    if(pq->heapArray[2*aux+1].priority < pq->heapArray[2*aux+2].priority) {
      aux2=pq->heapArray[aux];
      pq->heapArray[aux]=pq->heapArray[2*aux+2];
      pq->heapArray[2*aux+2]=aux2;
      aux=2*aux+2;
    }
    else {
      aux2=pq->heapArray[aux];
      pq->heapArray[aux]=pq->heapArray[2*aux+1];
      pq->heapArray[2*aux+1]=aux2;
      aux=2*aux+1;
    }
  }
}

Heap* createHeap(){
  Heap *H=(Heap*)malloc(sizeof(Heap));
  H->size=0;
  H->capac=3;
  heapElem* arreglo=(heapElem*)malloc(3*sizeof(heapElem));
  H->heapArray=arreglo;
  return H;
}
