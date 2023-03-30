#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraylist.h"

//normal array
typedef struct ArrayList {
    void **data;
    int capacity;
    int size;
} ArrayList;

ArrayList *createList(void) {
  ArrayList* arrayL = (ArrayList*) malloc(sizeof (ArrayList));
  arrayL->capacity = 2;
  arrayL->data = malloc(sizeof (void*));
  arrayL->size = 0;
    return arrayL;
}

void append(ArrayList * l, void * data){
    if (l->size == l->capacity) {
      int capacityDouble = l->capacity*2;
      l->data = realloc(l->data, capacityDouble * sizeof(int));
      l->capacity = capacityDouble;
    }
      l->data[l->size] = data;
    l->size++;
}

void push(ArrayList * l, void * data, int i){
  if(i > l->size ) return;

  if (l->size == l->capacity) {
      int capacityDouble = l->capacity*2;
      l->data = realloc(l->data, capacityDouble * sizeof(int));
      l->capacity = capacityDouble;
  }
    
    for(int k = l->size; k > i; k--)
      l->data[k] = l->data[k-1];
    
     l->data[i] = data;
    l->size++;
  

}

void* pop(ArrayList * l, int i){
  if(i<0){
    i = l->size + i;
  }
  
  if(i >= l->size)
    return NULL;

  void *deletedData = l->data[i];
     for (int j = i+1; j < l->size; j++) {
        l->data[j-1] = l->data[j];
    }
    l->size--;
    return deletedData;
  
}

void* get(ArrayList * l, int i){
  if(i<0){
    i = l->size + i;
  }
  if(i >= l->size)
    return NULL;

  return l->data[i];
  

}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
    l->data = realloc(l->data, sizeof(void*) * 2);
  l->capacity = 2;
  l->size = 0;
}
