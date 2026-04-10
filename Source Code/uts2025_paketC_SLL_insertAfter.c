// ------------------------------------------------
//  UTS STRUKTUR DATA 2025 — PAKET C
//  Soal 2 — Single Linked List + insertAfter
//  Author: Pancar Wahyu Setiabi (H1D024018)
// ------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

// 2a. Struktur node Single Linked List
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* tail = NULL;

// 2b. Fungsi membuat node baru
struct Node* buatNode(int data) {
    struct Node* baru = (struct Node*)malloc(sizeof(struct Node));
    baru->data = data;
    baru->next = NULL;
    return baru;
}

// 2c. Prosedur insert sebagai elemen terakhir
void insertLast(int data) {
    struct Node* baru = buatNode(data);
    if (head == NULL) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// 2d. Prosedur insert sebagai elemen di antara node yang diketahui
void insertAfter(struct Node* target, int data) {
    if (target == NULL) {
        printf("Target tidak valid!\n");
        return;
    }
    struct Node* baru = buatNode(data);
    baru->next = target->next; // step 1 — HARUS DULUAN
    target->next = baru;       // step 2
    if (baru->next == NULL) {
        tail = baru;
    }
}

// 2e. Prosedur cetak ke layar
void cetakList() {
    if (head == NULL) {
        printf("List kosong!\n");
        return;
    }
    struct Node* curr = head;
    while (curr != NULL) {
        printf("[%d]", curr->data);
        if (curr->next != NULL) printf(" -> ");
        curr = curr->next;
    }
    printf(" -> NULL\n");
}

// 2f. Main — skenario uji
int main() {
    printf("=== UTS 2025 Paket C — Single Linked List + insertAfter ===\n\n");

    // Skenario 1: insertLast 20, 30, 10
    insertLast(20);
    printf("insertLast(20)        : "); cetakList();

    insertLast(30);
    printf("insertLast(30)        : "); cetakList();

    insertLast(10);
    printf("insertLast(10)        : "); cetakList();

    // Skenario 2: sisipkan 40 di antara elemen pertama (20) dan kedua (30)
    // head saat ini = node [20], jadi insertAfter(head, 40)
    insertAfter(head, 40);
    printf("insertAfter(head, 40) : "); cetakList();
    // Output akhir: [20] -> [40] -> [30] -> [10] -> NULL

    return 0;
}