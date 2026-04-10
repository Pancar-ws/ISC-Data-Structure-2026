/*
 * UTS STRUKTUR DATA 2024
 * Soal 1: Double Linked List
 *
 * Skenario main:
 *   insertFirst(40)          -> [40]
 *   insertFirst(50)          -> [50] <-> [40]
 *   insertLast(30)           -> [50] <-> [40] <-> [30]
 *   insertAfter(head, 90)    -> [50] <-> [90] <-> [40] <-> [30]
 *
 * Output yang diharapkan:
 *   NULL <- [50] <-> [90] <-> [40] <-> [30] -> NULL
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
    /* Skenario 1: insertFirst dua kali */
    insertFirst(40);
    printf("insertFirst(40)      : ");
    cetakList();

    insertFirst(50);
    printf("insertFirst(50)      : ");
    cetakList();

    /* Skenario 2: insertLast */
    insertLast(30);
    printf("insertLast(30)       : ");
    cetakList();

    /* Skenario 3: insertAfter head (node 50), sisipkan 90 */
    insertAfter(head, 90);
    printf("insertAfter(head, 90): ");
    cetakList();

    return 0;
}
