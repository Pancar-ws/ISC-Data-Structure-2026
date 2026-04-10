/*
 * UTS STRUKTUR DATA 2025 — PAKET B
 * Soal 2: Single Linked List
 *
 * Skenario main:
 *   insertLast(20)   -> [20]
 *   insertLast(30)   -> [20] -> [30]
 *   insertLast(10)   -> [20] -> [30] -> [10]
 *   insertFirst(40)  -> [40] -> [20] -> [30] -> [10]
 *
 * Output yang diharapkan:
 *   [40] -> [20] -> [30] -> [10] -> NULL
 *
 * Perhatikan: format cetak SLL berbeda dari DLL.
 * SLL tidak punya pointer prev, sehingga tidak ada tanda "<-".
 */

#include <stdio.h>
#include <stdlib.h>

/* SLL — hanya punya next, TIDAK ada prev */
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* tail = NULL;

struct Node* buatNode(int data) {
    struct Node* baru = (struct Node*)malloc(sizeof(struct Node));
    baru->data = data;
    baru->next = NULL;
    return baru;
}

void insertLast(int data) {
    struct Node* baru = buatNode(data);

    if (head == NULL) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

void insertFirst(int data) {
    struct Node* baru = buatNode(data);

    if (head == NULL) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

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

int main() {
    /* Skenario 1: tiga kali insertLast */
    insertLast(20);
    printf("insertLast(20) : ");
    cetakList();

    insertLast(30);
    printf("insertLast(30) : ");
    cetakList();

    insertLast(10);
    printf("insertLast(10) : ");
    cetakList();

    /* Skenario 2: insertFirst */
    insertFirst(40);
    printf("insertFirst(40): ");
    cetakList();

    return 0;
}
