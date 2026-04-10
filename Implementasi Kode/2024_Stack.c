/*
 * UTS STRUKTUR DATA 2024
 * Soal 2: Stack
 *
 * Demonstrasi:
 *   push(40), push(50), push(30)
 *   pop() x3 + pop() sekali lagi (Stack Underflow)
 *
 * Output yang diharapkan:
 *   Push(40) berhasil. TOP = 0
 *   Push(50) berhasil. TOP = 1
 *   Push(30) berhasil. TOP = 2
 *   Pop() = 30. TOP sekarang = 1
 *   Pop() = 50. TOP sekarang = 0
 *   Pop() = 40. TOP sekarang = -1
 *   Stack Underflow! Stack sudah kosong.
 */

#include <stdio.h>

#define MAX_SIZE 100

struct Stack {
    int data[MAX_SIZE];
    int top;
};

void initStack(struct Stack* s) {
    s->top = -1;
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

int isFull(struct Stack* s) {
    return s->top == MAX_SIZE - 1;
}

void push(struct Stack* s, int data) {
    if (isFull(s)) {
        printf("Stack Overflow! Tidak bisa push %d.\n", data);
        return;
    }
    s->data[++(s->top)] = data;
    printf("Push(%d) berhasil. TOP = %d\n", data, s->top);
}

int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Stack sudah kosong.\n");
        return -1;
    }
    int keluar = s->data[(s->top)--];
    printf("Pop() = %d. TOP sekarang = %d\n", keluar, s->top);
    return keluar;
}

int peek(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack kosong!\n");
        return -1;
    }
    return s->data[s->top];
}

int main() {
    struct Stack s;
    initStack(&s);

    push(&s, 40);
    push(&s, 50);
    push(&s, 30);

    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);   /* Stack Underflow */

    return 0;
}
