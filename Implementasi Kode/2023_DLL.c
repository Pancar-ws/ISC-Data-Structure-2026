/*
 * UTS STRUKTUR DATA 2023
 * Soal 1: Double Linked List
 *
 * Input  : 5, 10, 8, 7, 3 (urutan memasukkan)
 * Output : 10, 7, 5, 8, 3 (hasil cetak)
 *
 * Kondisi akhir list:
 * HEAD -> [10] <-> [7] <-> [5] <-> [8] <-> [3] -> NULL
 *
 * Operasi yang digunakan:
 *   insertFirst(5)        -> [5]
 *   insertFirst(10)       -> [10] <-> [5]
 *   insertLast(8)         -> [10] <-> [5] <-> [8]
 *   insertAfter(head, 7)  -> [10] <-> [7] <-> [5] <-> [8]
 *   insertLast(3)         -> [10] <-> [7] <-> [5] <-> [8] <-> [3]
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* tail = NULL;

struct Node* buatNode(int data) {
    struct Node* baru = (struct Node*)malloc(sizeof(struct Node));
    baru->data = data;
    baru->prev = NULL;
    baru->next = NULL;
    return baru;
}

void insertFirst(int data) {
    struct Node* baru = buatNode(data);

    if (head == NULL) {
        head = tail = baru;
    } else {
        baru->next = head;
        head->prev = baru;
        head = baru;
    }
}

void insertLast(int data) {
    struct Node* baru = buatNode(data);

    if (tail == NULL) {
        head = tail = baru;
    } else {
        baru->prev = tail;
        tail->next = baru;
        tail = baru;
    }
}

void insertAfter(struct Node* target, int data) {
    if (target == NULL) {
        printf("Target tidak valid!\n");
        return;
    }

    struct Node* baru = buatNode(data);

    baru->next = target->next;
    baru->prev = target;

    if (target->next != NULL) {
        target->next->prev = baru;
    } else {
        tail = baru;
    }

    target->next = baru;
}

void cetakList() {
    if (head == NULL) {
        printf("List kosong!\n");
        return;
    }

    struct Node* curr = head;
    printf("NULL <- ");
    while (curr != NULL) {
        printf("[%d]", curr->data);
        if (curr->next != NULL) printf(" <-> ");
        curr = curr->next;
    }
    printf(" -> NULL\n");
}

int main() {
    /* Input: 5, 10, 8, 7, 3 — urutan memasukkan */

    insertFirst(5);
    printf("insertFirst(5)       : ");
    cetakList();

    insertFirst(10);
    printf("insertFirst(10)      : ");
    cetakList();

    insertLast(8);
    printf("insertLast(8)        : ");
    cetakList();

    insertAfter(head, 7);
    printf("insertAfter(head, 7) : ");
    cetakList();

    insertLast(3);
    printf("insertLast(3)        : ");
    cetakList();

    return 0;
}
