#include <stdio.h>
#include "stack.h" // Stack pakai Array
#include "queue.h"  // Queue pakai Linked List

int main() {
    int val;

    // ===============
    // PERCOBAAN STACK 
    // ===============
    Stack S;
    initStack(&S);
    
    printf("\n=== TUMPUKAN BUKU ===\n");
    
    // 1. Menambahkan Data Awal (Push)
    printf("Menumpuk buku\n");
    push(&S, 10);
    push(&S, 20);
    push(&S, 30);
    printStack(S); // Harapan: 30 (Top), 20, 10

    // 2. Mengambil Data (Pop) - Manipulasi 1
    printf("\nMengambil satu buku paling atas\n");
    pop(&S, &val);
    printf("   >> Buku yang diambil: ID %d\n", val);
    printStack(S); // Harapan: 20 (Top), 10. (30 hilang)

    // 3. Menambahkan Data Baru (Push) - Manipulasi 2
    printf("\nMenumpuk buku baru\n");
    push(&S, 40);
    push(&S, 50);
    printStack(S); // Harapan: 50 (Top), 40, 20, 10

    // 4. Mengambil Data Lagi (Pop)
    printf("\nMengambil buku lagi\n");
    pop(&S, &val);
    printf("   >> Buku yang diambil: ID %d\n", val); // Harusnya 50
    printStack(S); // Harapan: 40, 20, 10


    // ===============
    // PERCOBAAN QUEUE
    // ===============
    Queue Q;
    initQueue(&Q);

    printf("\n\n=== ANTRIAN NASABAH ===\n");

    // 1. Menambahkan Data Awal (Enqueue)
    printf("Nasabah no 100 dan 200 datang antri\n");
    enqueue(&Q, 100);
    enqueue(&Q, 200);
    printQueue(Q); // Harapan: 100 (Head) -> 200 (Tail)

    // 2. Mengambil Data (Dequeue) - Manipulasi 1
    printf("\nMemanggil satu nasabah untuk dilayani\n");
    dequeue(&Q, &val);
    printf("   >> Nasabah yang dipanggil: No %d\n", val); // Harusnya 100
    printQueue(Q); // Harapan: 200 (Head/Tail)

    // 3. Menambahkan Data Baru (Enqueue) - Manipulasi 2
    printf("\nNasabah baru no 300, 400, dan 500 datang\n");
    enqueue(&Q, 300);
    enqueue(&Q, 400);
    enqueue(&Q, 500);
    printQueue(Q); // Harapan: 200 -> 300 -> 400 -> 500

    // 4. Mengambil Data Lagi (Dequeue)
    printf("\nMemanggil nasabah berikutnya\n");
    dequeue(&Q, &val);
    printf("   >> Nasabah yang dipanggil: No %d\n", val); 
    // Perhatikan! Yang keluar adalah 200 (orang lama), BUKAN 500 (orang baru)
    
    printQueue(Q); // Harapan: 300 -> 400 -> 500

    return 0;
}