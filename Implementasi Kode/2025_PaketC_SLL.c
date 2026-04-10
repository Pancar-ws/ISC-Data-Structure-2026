/*
 * UTS STRUKTUR DATA 2025 — PAKET C
 * Soal 2: Single Linked List + insertAfter
 *
 * Skenario main:
 *   insertLast(20)         -> [20]
 *   insertLast(30)         -> [20] -> [30]
 *   insertLast(10)         -> [20] -> [30] -> [10]
 *   insertAfter(head, 40)  -> [20] -> [40] -> [30] -> [10]
 *
 * Output yang diharapkan:
 *   [20] -> [40] -> [30] -> [10] -> NULL
 *
 * insertAfter di SLL lebih simpel dari DLL:
 *   hanya 2 step (DLL butuh 4 step karena ada pointer prev)
 */

#include <stdio.h>
#include <stdlib.h>

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

void insertAfter(struct Node* target, int data) {
    if (target == NULL) {
        printf("Target tidak valid!\n");
        return;
    }

    struct Node* baru = buatNode(data);

    baru->next = target->next;  /* step 1 — HARUS DULUAN */
    target->next = baru;        /* step 2 */

    if (baru->next == NULL) {
        tail = baru;
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
    printf("insertLast(20)        : ");
    cetakList();

    insertLast(30);
    printf("insertLast(30)        : ");
    cetakList();

    insertLast(10);
    printf("insertLast(10)        : ");
    cetakList();

    /* Skenario 2: sisipkan 40 antara elemen pertama (20) dan kedua (30) */
    insertAfter(head, 40);
    printf("insertAfter(head, 40) : ");
    cetakList();

    return 0;
}
