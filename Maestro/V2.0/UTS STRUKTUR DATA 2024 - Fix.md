*Jadi kalo 2023 kemarin lebih ke **"problem solving"**, dikasih input output terus disuruh mikir sendiri cara nyusunnya, tapi kalo soal 2024 ini pendekatannya lumayan berbeda. Soal 2024 lebih ke **"bangun dari nol, fungsi per fungsi"**. Setiap bagian dipecah jadi sub-poin spesifik.*

*Tingkat kesulitan Stack juga naik; di 2023 cuma ditanya "apa itu Stack Overflow?", sedangkan di 2024 kalian diminta bikin fungsi Push dan Pop serta membandingkan Stack dengan Single Linked List*

*Breakdown soal:*
- ***Soal 1 (80 poin):** double linked list, dipecah jadi 7 sub-poin (a - g)*
- ***Soal 2 (30 poin):** stack, perbedaan konsep, struktur, push & pop*
---
## SOAL 1 - Double Linked List

Soal 1 kita  diminta membangun DLL **secara sistematis dari bawah ke atas**, mulai dari:
- `struct,` 
- `buatNode,` 
- `insertFirst,`
- `insertLast,` 
- `insertAfter,` 
- `print (cetak),` 
- `main`
Ini merupakan cara menulis kode secara modular

Jadi nanti skenario di bagian `main` nya (soal 1g) seperti ini:

```
1. insertFirst(40)                   → list: [40]
   insertFirst(50)                   → list: [50] ↔ [40]
2. insertLast(30)                    → list: [50] ↔ [40] ↔ [30]
3. insertAfter(elemen pertama, 90)   → list: [50] ↔ [90] ↔ [40] ↔ [30]
4. print (cetak)
```
---
### Double Linked List

Di Single Linked List, setiap node hanya tau siapa yang ada **di depannya**:

```
Single Linked List: [5] → [10] → [8] → NULL
				    (node 10 gatau bahwa 5 ada di belakangnya)
```

Di Double Linked List, setiap node tau siapa yang ada **di depan DAN di belakangnya**:

```
Double Linked List: NULL ← [5] ↔ [10] ↔ [8] → NULL
		            (node 10 tau bahwa di kiri ada 5, di kanan ada 8)
```

Struktur node Double Linked List punya **3 bagian**, antara lain:

```
┌──────┬──────┬──────┐
│ prev │ data │ next │
└──────┴──────┴──────┘
```

Jadi Double Linked List lebih fleksibel, bisa traversal dari kedua arah, dan operasi delete jadi lebih mudah karena langsung bisa akses node sebelumnya.

---
### Soal 1a - Struktur Node DLL (5 poin)

#### Alur Berpikir
##### **Step 1 - Tentukan apa aja yang perlu disimpan tiap node**

Node DLL itu perlu menyimpan:
- Data angkanya sendiri → `int data`
- Alamat node di sebelah kirinya → `struct Node* prev`
- Alamat node di sebelah kanannya → `struct Node* next`
##### **Step 2 - Tulis dalam bentuk struct C**

```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Variabel global untuk menandai ujung-ujung list
struct Node* head = NULL;
struct Node* tail = NULL;
```

> **Kenapa `head` dan `tail` perlu keduanya?** Head itu digunakan untuk mengetahui di mana list dimulai, sementara tail digunakan untuk mengetahui di mana list berakhir. Tanpa tail, setiap kali mau `insertLast` kita harus jalan dari head sampai ujung dulu
---
### Soal 1b - Fungsi buatNode (10 poin)

Fungsi ini merupakan **"pabrik node"**, dipanggil setiap kali mau tambah elemen baru ke list, apapun jenis insertnya.
#### Alur Berpikir
##### **Step 1 - Tentukan tugasnya**

`buatNode` itu harus: minta jatah memori baru, isi datanya, dan set semua pointer ke NULL (karena node baru belum punya tetangga).
##### **Step 2 - Kenapa pakai `malloc`?**

Karena kita mau node ini tetap hidup di memori selama program berjalan, bukan hilang waktu fungsi selesai dieksekusi. `malloc` mengalokasikan memori di **heap**, bukan di stack.

```c
struct Node* buatNode(int data) {
    struct Node* baru = (struct Node*)malloc(sizeof(struct Node));
    baru->data = data;
    baru->prev = NULL;  // belum punya tetangga kiri
    baru->next = NULL;  // belum punya tetangga kanan
    return baru;
}
```

> **Analogi:** `buatNode` itu ibarat **mencetak gerbong kereta baru dari pabrik**. Gerbongnya udah jadi dan siap pakai, tapi belum disambungkan ke rangkaian manapun. Nah fungsi insert-lah yang nanti tugasnya menyambungkan gerbong gerbong itu.
---
### Soal 1c - insertFirst (10 poin)

Node baru akan menjadi HEAD yang baru. Semua node yang sudah ada akan bergeser satu posisi ke kanan.
#### Alur Berpikir
##### **Step 1 - Identifikasi dua kondisi yang mungkin terjadi**

```
Kondisi A: List masih kosong
  → node baru langsung jadi head sekaligus tail

Kondisi B: List sudah ada isinya
  → node baru disisipkan di depan head yang sekarang
```
##### **Step 2 - Untuk kondisi B, pikirkan urutan penyambungan pointer**

Nah disini kita harus sambungkan dulu **sebelum memutus koneksi lama**:

```
Sebelum insertFirst(50), list: [40]
                                HEAD/TAIL

Step 1 — baru->next = head:
  [50] → [40]
  (baru sudah tau siapa di kanannya)

Step 2 — head->prev = baru:
  [50] ↔ [40]
  (head lama sudah tau siapa di kirinya)

Step 3 — head = baru:
  HEAD sekarang menunjuk ke [50]
  [50] ↔ [40]
   ↑
  HEAD baru
```

```c
void insertFirst(int data) {
    struct Node* baru = buatNode(data);

    if (head == NULL) {
        head = tail = baru;
    } else {
        baru->next = head;     // step 1
        head->prev = baru;     // step 2
        head = baru;           // step 3
    }
}
```

> Jadi selalu sambungkan node baru ke list yang sudah ada **sebelum** mengupdate head/tail. Kalo `head = baru` dipanggil duluan, nanti bakal kehilangan referensi ke list lama
---
### Soal 1d - insertLast (10 poin)

Disini node `baru` akan menjadi TAIL yang baru. Logikanya **simetris** dengan insertFirst, bedanya ini bekerja di ujung kanan list.
#### Alur Berpikir
##### **Step 1 - Sama seperti insertFirst, ada dua kondisi**

```
Kondisi A: List kosong   →  node baru jadi head sekaligus tail
Kondisi B: List ada isi  →  sambungkan di belakang tail sekarang
```
##### **Step 2 - Urutan penyambungan untuk kondisi B**

```
Sebelum insertLast(30), list: [50] ↔ [40]
                                          ↑
                                         TAIL

Step 1 — baru->prev = tail:
  [50] ↔ [40] ← [30]
  (baru tau siapa di kirinya)

Step 2 — tail->next = baru:
  [50] ↔ [40] ↔ [30]
  (tail lama tau siapa di kanannya)

Step 3 — tail = baru:
  TAIL sekarang menunjuk ke [30]
  [50] ↔ [40] ↔ [30]
                  ↑
                TAIL baru
```

```c
void insertLast(int data) {
    struct Node* baru = buatNode(data);

    if (tail == NULL) {
        head = tail = baru;
    } else {
        baru->prev = tail;     // step 1
        tail->next = baru;     // step 2
        tail = baru;           // step 3
    }
}
```
---
### Soal 1e - insertAfter (10 poin)

Disini node `baru` disisipkan **tepat setelah node target** yang sudah diketahui.
#### Alur Berpikir
##### **Step 1 - Visualisasi kondisi sebelum dan sesudah**

```
Sebelum — sisipkan 90 setelah node [50]:
HEAD → [50] ↔ [40] ↔ [30] ← TAIL

Sesudah:
HEAD → [50] ↔ [90] ↔ [40] ↔ [30] ← TAIL
```
##### **Step 2 - Identifikasi semua pointer yang berubah**

Ada **4 pointer** yang harus diurus:

```
1. baru->prev       :  harus tunjuk ke target (50)
2. baru->next       :  harus tunjuk ke node setelah target (40)
3. target->next     :  harus tunjuk ke baru (90)
4. (node 40)->prev  :  harus tunjuk ke baru (90)
```
##### **Step 3 - Tentukan urutan yang aman**

Kuncinya gini: **sambungkan node baru ke kedua tetangganya DULU**, setelah itu baru putuskan koneksi lama:

```
Step 1 — baru->next = target->next:
  [50]  [90]→[40] ↔ [30]
  (baru sudah tau kanannya adalah 40)

Step 2 — baru->prev = target:
  [50]←[90]→[40] ↔ [30]
  (baru sudah tau kirinya adalah 50)

Step 3 — target->next->prev = baru:
  [50]←[90]↔[40] ↔ [30]
  (node 40 sekarang tau kirinya adalah 90)

Step 4 — target->next = baru:
  [50]↔[90]↔[40] ↔ [30]  (disini udah oke)
  (node 50 sekarang tau kanannya adalah 90)
```

```c
void insertAfter(struct Node* target, int data) {
    if (target == NULL) {
        printf("Target tidak valid!\n");
        return;
    }

    struct Node* baru = buatNode(data);

    baru->next = target->next;      // step 1
    baru->prev = target;            // step 2

    if (target->next != NULL) {
        target->next->prev = baru;  // step 3
    } else {
        tail = baru;  // kalo target adalah tail, update tail
    }

    target->next = baru;            // step 4
}
```

> **Kenapa step 4 harus paling terakhir?** Karena di step 1 kita masi butuh `target->next` untuk tau siapa node di sebelah kanan target. Kalo step 4 dilakukan duluan, `target->next` sudah berubah jadi `baru`, dan kita kehilangan referensi ke node 40
---
### Soal 1f - Prosedur Print/Cetak (10 poin)

#### Cara Berpikir
##### **Step1 - Tentukan format output yang representatif**

Output yang baik untuk DLL itu harus menunjukkan **dua arah pointer**:

```
NULL <- [50] <-> [90] <-> [40] <-> [30] -> NULL
```
##### **Step 2 - Gunakan pointer `curr` untuk traversal**

```c
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
```
---
### Soal 1g - Fungsi Main (25 poin)

#### Analisis Input Output

Sekarang kita rangkai semua fungsi sesuai skenario soal. Pertama, mari kita **petakan kondisi list di setiap step** berikut:

```
Step 1a: insertFirst(40)           → [40]
Step 1b: insertFirst(50)           → [50] ↔ [40]
Step 2 : insertLast(30)            → [50] ↔ [40] ↔ [30]
Step 3 : insertAfter(head, 90)     → sisip 90 setelah head (node 50)
                                   → [50] ↔ [90] ↔ [40] ↔ [30]
Step 4 : Cetak → 50, 90, 40, 30
```
#### Alur Berpikir

**Step 1 **

Soalnya: _"Masukan 90 sebagai elemen diantara elemen pertama dan kedua"_

- Elemen pertama sekarang adalah **50** (HEAD)
- Elemen kedua adalah **40**. 
Jadi 90 harus disisipkan setelah node 50, yang kebetulan adalah `head`.
##### **Step 2 - Verifikasi kondisi list sebelum insertAfter**

```
Sebelum insertAfter:
HEAD → [50] ↔ [40] ↔ [30] ← TAIL
        ↑
       head (ini yang kita pass ke insertAfter)
```
##### **Step 3 - Susun Main-nya**

```c
int main() {

    // Skenario 1: insertFirst dua kali
    insertFirst(40);
    printf("insertFirst(40)      : ");
    cetakList();
    // List: [40]

    insertFirst(50);
    printf("insertFirst(50)      : ");
    cetakList();
    // List: [50] <-> [40]

    // Skenario 2: insertLast
    insertLast(30);
    printf("insertLast(30)       : ");
    cetakList();
    // List: [50] <-> [40] <-> [30]

    // Skenario 3: insertAfter head (node 50), sisipkan 90
    insertAfter(head, 90);
    printf("insertAfter(head, 90): ");
    cetakList();
    // List: [50] <-> [90] <-> [40] <-> [30]

    return 0;
}
```

**Output yang dihasilkan:**

```
insertFirst(40)         : NULL <- [40] -> NULL
insertFirst(50)         : NULL <- [50] <-> [40] -> NULL
insertLast(30)          : NULL <- [50] <-> [40] <-> [30] -> NULL
insertAfter(head, 90)   : NULL <- [50] <-> [90] <-> [40] <-> [30] -> NULL
```
## SOAL 2 - Stack
### Soal 2a - Perbedaan Stack dan Single Linked List (5 poin)

#### Alur Berpikir
##### **Step 1 - Tentukan aspek pembanding**

```
Aspek 1: Akses data     —  di mana kita boleh insert/delete?
Aspek 2: Prinsip kerja  —  ada aturan urutan atau tidak?
Aspek 3: Fleksibilitas  —  seberapa bebas operasinya?
Aspek 4: Penggunaan     —  kapan masing-masing dipakai?
```
##### **Step 2 - Visualisasi perbedaannya**

```
Single Linked List — akses BEBAS:
HEAD → [A] → [B] → [C] → [D] → NULL
        ↑           ↑           ↑
     bisa          bisa        bisa
    insert        insert      insert
    /delete       /delete     /delete
    di sini       di sini     di sini

Stack — akses TERBATAS hanya di TOP:
          ┌─────┐
   TOP →  │  D  │  ← hanya boleh push/pop di sini
          ├─────┤
          │  C  │  ← tidak bisa akses langsung
          ├─────┤
          │  B  │  ← tidak bisa akses langsung
          ├─────┤
          │  A  │  ← tidak bisa akses langsung
          └─────┘
```
##### **Langkah 3 **

| Aspek             | Single Linked List                           | Stack                                            |
| ----------------- | -------------------------------------------- | ------------------------------------------------ |
| **Akses data**    | Bebas — insert/delete di mana saja           | Terbatas — hanya di TOP                          |
| **Prinsip kerja** | Tidak ada aturan urutan khusus               | LIFO — Last In First Out                         |
| **Operasi utama** | insertFirst, insertLast, insertAfter, delete | push, pop, peek                                  |
| **Fleksibilitas** | Tinggi                                       | Rendah tapi terstruktur                          |
| **Kapasitas**     | Dinamis, selama memori tersedia              | Bisa dibatasi (array) atau dinamis (linked list) |
| **Kegunaan**      | Koleksi data umum, playlist, history         | Rekursi, undo/redo, parsing ekspresi matematika  |

> **Analogi pembeda:** SLL itu diibaratkan **rak buku terbuka**, mau ambil atau taruh buku di posisi manapun bebas. Sementara Stack itu diibaratkan **kaleng Pringles**, yang masuk terakhir, keluar pertama. 
---
### Soal 2b - Struktur Data Stack (5 poin)

#### Cara Berpikir
##### **Step 1 - Tentukan komponen yang Stack butuhkan**

```
1. Wadah untuk menyimpan data     → array data[]
2. Penanda posisi elemen teratas  → variabel top
```
##### **Step 2 - Tentukan nilai awal top**

```
top = -1  →  stack kosong (belum ada elemen)

Kenapa -1, bukan 0?
  Index array mulai dari 0.
  Kalau top = 0, kita tidak bisa bedakan antara:
    - stack kosong
    - stack berisi 1 elemen di index 0
  Maka -1 dipakai sebagai penanda "benar-benar kosong"
```
##### **Step 3 - Susun Strukturnya**

```c
#define MAX_SIZE 100

struct Stack {
    int data[MAX_SIZE];  // array penyimpan elemen
    int top;             // index elemen teratas, -1 jika kosong
};

// Inisialisasi — wajib dipanggil sebelum stack dipakai!
void initStack(struct Stack* s) {
    s->top = -1;
}
```
---
### Soal 2c - Fungsi Push dan Pop (20 poin)

Push dan pop merupakan **jantung dari Stack**. Keduanya harus dilengkapi dengan pengecekan kondisi, karena push ke stack penuh adalah Stack Overflow, dan pop dari stack kosong adalah Stack Underflow.

```
Push → memasukkan data ke atas stack
  - Syarat: stack tidak penuh (top < MAX_SIZE - 1)
  - Aksi: naikkan top, lalu isi data[top]

Pop → mengambil dan menghapus data teratas
  - Syarat: stack tidak kosong (top >= 0)
  - Aksi: ambil data[top], lalu turunkan top
```
#### Alur Berpikir - Push
##### **Step 1 - Visualisasi apa yang terjadi saat push**

```
Sebelum push(40):
top = -1  →  stack kosong

Setelah push(40):
          ┌─────┐
   top=0→ │ 40  │
          └─────┘

Setelah push(50):
          ┌─────┐
   top=1→ │ 50  │
          ├─────┤
          │ 40  │
          └─────┘
```
##### **Step 2 - Perhatikan urutan operasi di dalam push**

```
s->data[++(s->top)] = data;

Dibaca: naikkan top DULU, baru isi datanya.
Jangan dibalik! Kalau data diisi dulu baru top dinaikkan,
data malah ditaruh di posisi top yang lama.
```

```c
// Fungsi PUSH
void push(struct Stack* s, int data) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack Overflow! Tidak bisa push %d.\n", data);
        return;
    }
    s->data[++(s->top)] = data;
    printf("Push(%d) berhasil. TOP = %d\n", data, s->top);
}
```
#### Alur Berpikir - Pop
##### **Step 1 - Visualisasi apa yang terjadi saat pop**

```
Sebelum pop():
          ┌─────┐
   top=1→ │ 50  │  ← ini yang keluar
          ├─────┤
          │ 40  │
          └─────┘

Setelah pop():
          ┌─────┐
   top=0→ │ 40  │
          └─────┘
  (50 sudah tidak bisa diakses lagi)
```
##### **Step 2 - Perhatikan urutan operasi di dalam pop**

```
return s->data[(s->top)--];

Dibaca: ambil data[top] DULU, baru turunkan top.
Jangan dibalik! Kalau top diturunkan dulu,
kita malah mengambil data dari posisi yang salah.
```

```c
// Fungsi POP
int pop(struct Stack* s) {
    if (s->top == -1) {
        printf("Stack Underflow! Stack sudah kosong.\n");
        return -1;
    }
    int keluar = s->data[(s->top)--];
    printf("Pop() = %d. TOP sekarang = %d\n", keluar, s->top);
    return keluar;
}
```

**Demonstrasi lengkap push dan pop:**

```c
int main() {
    struct Stack s;
    initStack(&s);

    push(&s, 40);   // Stack: [40]           top=0
    push(&s, 50);   // Stack: [40][50]        top=1
    push(&s, 30);   // Stack: [40][50][30]    top=2

    pop(&s);        // keluar 30, Stack: [40][50]    top=1
    pop(&s);        // keluar 50, Stack: [40]        top=0
    pop(&s);        // keluar 40, Stack: kosong      top=-1
    pop(&s);        // Stack Underflow!

    return 0;
}
```

```
Output:
Push(40) berhasil. TOP = 0
Push(50) berhasil. TOP = 1
Push(30) berhasil. TOP = 2
Pop() = 30. TOP sekarang = 1
Pop() = 50. TOP sekarang = 0
Pop() = 40. TOP sekarang = -1
Stack Underflow! Stack sudah kosong.
```
---
### Ringkasan Cara Berpikir Soal 2024

```
┌──────────────────────────────────────────────────────────┐
│                SOAL 1 — Double Linked List               │
│                                                          │
│  1. Struct dulu → ini fondasi semua fungsi               │
│  2. buatNode → "pabrik" yang dipanggil semua insert      │
│  3. insertFirst/Last → selalu ada 2 kondisi:             │
│     list kosong vs list sudah ada isi                    │
│  4. insertAfter → 4 pointer, urutan SANGAT penting:      │
│     sambungkan baru ke tetangga SEBELUM putuskan lama    │
│  5. Main → baca skenario, petakan kondisi                │
│     list di setiap step sebelum nulis kode               │
└──────────────────────────────────────────────────────────┘

┌──────────────────────────────────────────────────────────┐
│                    SOAL 2 — STACK                        │
│                                                          │
│  2a. Perbedaan Stack vs SLL:                             │
│      Kunci = akses data (bebas vs LIFO/TOP only)         │
│  2b. Struktur Stack:                                     │
│      array + top, inisialisasi top = -1                  │
│  2c. Push & Pop:                                         │
│      Push → cek isFull dulu, lalu ++top sebelum isi      │
│      Pop  → cek isEmpty dulu, lalu ambil baru top--      │
│      Urutan operasi top TIDAK boleh dibalik!             │
└──────────────────────────────────────────────────────────┘
```