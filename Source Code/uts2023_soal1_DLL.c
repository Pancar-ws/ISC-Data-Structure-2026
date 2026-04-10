// ------------------------------------------------
//  UTS STRUKTUR DATA 2024
//  Soal 1 — Double Linked List (sub-poin a s/d g)
//  Soal 2 — Stack (sub-poin b dan c)
//  Author: Pancar Wahyu Setiabi (H1D024018)
// ------------------------------------------------

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
    // Step 1: insertFirst(5)
    insertFirst(5);
    printf("Step 1 - insertFirst(5)          : ");
    cetakList();
    // List: [5]

    // Step 2: insertFirst(10) — 10 harus ada di depan 5
    insertFirst(10);
    printf("Step 2 - insertFirst(10)         : ");
    cetakList();
    // List: [10] <-> [5]

    // Step 3: insertLast(8) — 8 harus ada di belakang 5
    insertLast(8);
    printf("Step 3 - insertLast(8)           : ");
    cetakList();
    // List: [10] <-> [5] <-> [8]

    // Step 4: insertAfter(head, 7) — 7 disisipkan setelah node 10 (head)
    insertAfter(head, 7);
    printf("Step 4 - insertAfter(node 10, 7) : ");
    cetakList();
    // List: [10] <-> [7] <-> [5] <-> [8]

    // Step 5: insertLast(3) — 3 paling belakang
    insertLast(3);
    printf("Step 5 - insertLast(3)           : ");
    cetakList();
    // List: [10] <-> [7] <-> [5] <-> [8] <-> [3]

    return 0;
}