// ------------------------------------------------
//  UTS STRUKTUR DATA 2025 — PAKET B
//  Soal 2 — Single Linked List
//  Author: Pancar Wahyu Setiabi (H1D024018)
// ------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

// 2a. Struktur node Single Linked List
struct Node {
    int data;
    struct Node* next; // tidak ada prev
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

// 2d. Prosedur insert sebagai elemen pertama
void insertFirst(int data) {
    struct Node* baru = buatNode(data);
    if (head == NULL) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
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
    printf("=== UTS 2025 Paket B — Single Linked List ===\n\n");

    // Skenario 1: insertLast 20, 30, 10
    insertLast(20);
    printf("insertLast(20) : "); cetakList();

    insertLast(30);
    printf("insertLast(30) : "); cetakList();

    insertLast(10);
    printf("insertLast(10) : "); cetakList();

    // Skenario 2: insertFirst 40
    insertFirst(40);
    printf("insertFirst(40): "); cetakList();
    // Output akhir: [40] -> [20] -> [30] -> [10] -> NULL

    return 0;
}