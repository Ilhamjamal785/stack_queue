#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H
#include "boolean.h"

#define MAX 10  // Kapasitas maksimum Stack

typedef struct {
    int T[MAX]; // Wadah data menggunakan Array
    int TOP;    // Indeks elemen paling atas
} Stack;

void initStack(Stack *S);
boolean isStackEmpty(Stack S);
boolean isStackFull(Stack S);
void push(Stack *S, int x);
void pop(Stack *S, int *x);
void printStack(Stack S);

#endif