// ------------------------------------------------
//  UTS STRUKTUR DATA 2024
//  Soal 1 — Double Linked List (sub-poin a s/d g)
//  Soal 2 — Stack (sub-poin b dan c)
//  Author: Pancar Wahyu Setiabi (H1D024018)
// ------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

//  SOAL 1 — DOUBLE LINKED LIST
// 1a. Struktur node Double Linked List
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* tail = NULL;

// 1b. Fungsi membuat node baru
struct Node* buatNode(int data) {
    struct Node* baru = (struct Node*)malloc(sizeof(struct Node));
    baru->data = data;
    baru->prev = NULL;
    baru->next = NULL;
    return baru;
}

// 1c. Prosedur insert sebagai elemen pertama
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

// 1d. Prosedur insert sebagai elemen terakhir
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

// 1e. Prosedur insert sebagai elemen di antara node yang diketahui
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

// 1f. Prosedur cetak ke layar
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

//  SOAL 2 — STACK
#define MAX_SIZE 100

// 2b. Struktur data Stack
struct Stack {
    int data[MAX_SIZE];
    int top;
};

void initStack(struct Stack* s) {
    s->top = -1;
}

int isFull(struct Stack* s) {
    return s->top == MAX_SIZE - 1;
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// 2c. Fungsi push
void push(struct Stack* s, int data) {
    if (isFull(s)) {
        printf("Stack Overflow! Tidak bisa push %d.\n", data);
        return;
    }
    s->data[++(s->top)] = data;
    printf("Push(%d) berhasil. TOP = %d\n", data, s->top);
}

// 2c. Fungsi pop
int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Stack sudah kosong.\n");
        return -1;
    }
    int keluar = s->data[(s->top)--];
    printf("Pop() = %d. TOP sekarang = %d\n", keluar, s->top);
    return keluar;
}

//  MAIN — Skenario Uji Soal 1g
int main() {
    // --- SOAL 1 ---
    printf("=== UTS 2024 — Soal 1: Double Linked List ===\n\n");

    // Skenario 1: insertFirst(40) lalu insertFirst(50)
    insertFirst(40);
    printf("insertFirst(40)      : ");
    cetakList();

    insertFirst(50);
    printf("insertFirst(50)      : ");
    cetakList();

    // Skenario 2: insertLast(30)
    insertLast(30);
    printf("insertLast(30)       : ");
    cetakList();

    // Skenario 3: insertAfter elemen pertama (head = 50), sisipkan 90
    insertAfter(head, 90);
    printf("insertAfter(head,90) : ");
    cetakList();
    // Output akhir: NULL <- [50] <-> [90] <-> [40] <-> [30] -> NULL

    printf("\n=== UTS 2024 — Soal 2: Stack ===\n\n");

    // --- SOAL 2 ---
    struct Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s); // Stack Underflow

    return 0;
}