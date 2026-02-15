#include <stdio.h>
#include "stack.h"

void initStack(Stack *S) {
    S->TOP = -1; // -1 artinya kosong (karena indeks array mulai dari 0)
}

boolean isStackEmpty(Stack S) {
    return S.TOP == -1;
}

boolean isStackFull(Stack S) {
    return S.TOP == MAX - 1;
}

void push(Stack *S, int x) {
    if (isStackFull(*S)) {
        printf("Error: Stack Penuh! Tidak bisa push %d\n", x);
    } else {
        S->TOP++;          // Naikkan indeks TOP
        S->T[S->TOP] = x;  // Masukkan data ke posisi TOP
    }
}

void pop(Stack *S, int *x) {
    if (isStackEmpty(*S)) {
        printf("Error: Stack Kosong!\n");
    } else {
        *x = S->T[S->TOP]; // Ambil data
        S->TOP--;          // Turunkan indeks TOP (data dianggap hilang)
    }
}

void printStack(Stack S) {
    printf("[Stack]: ");
    if (isStackEmpty(S)) {
        printf("Kosong\n");
    } else {
        // Cetak dari TOP ke bawah (LIFO)
        for (int i = S.TOP; i >= 0; i--) {
            printf("%d ", S.T[i]);
        }
        printf("\n");
    }
}