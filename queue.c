#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void initQueue(Queue *Q) {
    Q->HEAD = NULL;
    Q->TAIL = NULL;
}

boolean isQueueEmpty(Queue Q) {
    return Q.HEAD == NULL;
}

void enqueue(Queue *Q, int x) {
    // Alokasi Node Baru
    ElmtQueue *P = (ElmtQueue*) malloc(sizeof(ElmtQueue));
    if (P != NULL) {
        P->info = x;
        P->next = NULL;

        if (isQueueEmpty(*Q)) {
            Q->HEAD = P;
            Q->TAIL = P;
        } else {
            Q->TAIL->next = P; // Sambung dari belakang
            Q->TAIL = P;       // Update TAIL
        }
    }
}

void dequeue(Queue *Q, int *x) {
    if (isQueueEmpty(*Q)) {
        printf("Error: Queue Kosong!\n");
    } else {
        ElmtQueue *hapus = Q->HEAD;
        *x = hapus->info;
        
        Q->HEAD = Q->HEAD->next; // Majukan HEAD
        if (Q->HEAD == NULL) {   // Jika elemen terakhir dihapus
            Q->TAIL = NULL;
        }
        free(hapus); // Deallokasi memori
    }
}

void printQueue(Queue Q) {
    ElmtQueue *bantu = Q.HEAD;
    printf("[Queue]: ");
    while (bantu != NULL) {
        printf("%d -> ", bantu->info);
        bantu = bantu->next;
    }
    printf("NULL\n");
}