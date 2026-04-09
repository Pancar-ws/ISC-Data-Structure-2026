*Tahun 2025 ini agak unik, dosen memakai strategi **Multi-Paket (A, B, C)**. Topiknya 100% full tentang Linked List. Dosen ingin menguji kepahaman kalian akan beda behavior alias perilaku antara Single Linked List (SLL) dan Double Linked List (DLL) secara langsung melalui kodingan. Tiap anak dapet paket yang fungsinya beda-beda sedikit.*
 
 *Perbedaan paling mencolok: **Materi Stack hilang total di UTS 2025**. Dosen lebih menuntut pendalaman pemahaman di pointer memori. Di 2024, kalian fokus bikin satu DLL yang utuh. Di 2025, karena ada sistem paket, dosen menuntut mahasiswa untuk sadar bahwa codingan SLL (Paket B/C) itu lebih simpel karena pointer-nya cuma satu ( `next` aja), tidak seperti DLL (Paket A) yang harus ngurus pointer `prev` juga.*

Perbedaan antar paket:

|                         | Paket A                                  | Paket B                                | Paket C                                     |
| ----------------------- | ---------------------------------------- | -------------------------------------- | ------------------------------------------- |
| **Soal 1**              | Perbedaan SLL vs DLL                     | Perbedaan SLL vs DLL                   | Perbedaan SLL vs DLL                        |
| **Soal 2 - Jenis List** | Double Linked List                       | Single Linked List                     | Single Linked List                          |
| **Operasi khusus**      | insertFirst + insertLast                 | insertFirst + insertLast               | insertLast + insertAfter                    |
| **Skenario main**       | insertLast(20, 30, 10) + insertFirst(40) | insertLast(20,30,10) → insertFirst(40) | insertLast(20,30,10) → insertAfter(head,40) |
## SOAL 1 - Perbedaan SLL vs DLL (Semua Paket)

### Struktur Node SLL vs DLL

```
Single Linked List — node punya 1 pointer:
┌────────┬────────┐
│  data  │  next  │
└────────┴────────┘
  hanya tau siapa yang ADA DI DEPAN

Double Linked List — node punya 2 pointer:
┌────────┬────────┬────────┐
│  prev  │  data  │  next  │
└────────┴────────┴────────┘
  tau siapa yang ADA DI DEPAN dan DI BELAKANG
```
---
### Analisis Perbandingan

#### Alur Berpikir 
##### **Step 1 - Mulai dari struktur node**

Perbedaan utamanya hanya satu: **jumlah pointer**.

```
SLL punya 1 pointer (next)
  ↓
Hanya bisa traversal satu arah
  ↓
Untuk delete node, butuh simpan node sebelumnya dulu
  ↓
Insert/delete lebih rumit di tengah list
  ↓
Tapi lebih hemat memori


DLL punya 2 pointer (prev + next)
  ↓
Bisa traversal dua arah
  ↓
Delete node lebih mudah karena langsung akses prev
  ↓
Insert/delete lebih fleksibel
  ↓
Tapi butuh memori lebih banyak
```
##### **Step 2 - Visualisasi perbedaan**

```
Single Linked List:
HEAD                              TAIL
 ↓                                 ↓
[5] → [10] → [8] → [7] → NULL
 
Traversal: hanya bisa ke KANAN →
Dari node [8], tidak bisa balik ke [10] tanpa mulai dari HEAD lagi!

Double Linked List:
HEAD                                   TAIL
 ↓                                      ↓
NULL ← [5] ↔ [10] ↔ [8] ↔ [7] → NULL

Traversal: bisa ke KANAN → dan ke KIRI ←
Dari node [8], bisa langsung mundur ke [10] lewat pointer prev!
```
##### **Step 3**

| Aspek                 | Single Linked List               | Double Linked List                       |
| --------------------- | -------------------------------- | ---------------------------------------- |
| **Pointer per node**  | 1 (`next` saja)                  | 2 (`prev` dan `next`)                    |
| **Arah traversal**    | Satu arah (HEAD → TAIL)          | Dua arah (bolak-balik)                   |
| **Memori per node**   | Lebih hemat                      | Lebih boros (ekstra 1 pointer)           |
| **Delete node**       | Butuh pointer ke node sebelumnya | Langsung pakai `prev`                    |
| **Kompleksitas kode** | Lebih sederhana                  | Lebih kompleks                           |
| **Fleksibilitas**     | Terbatas                         | Tinggi                                   |
| **Kegunaan**          | List sederhana, antrian          | Browser history, music player, undo/redo |
## SOAL 2 - PAKET A: Double Linked List

Paket A menggunakan **Double Linked List** dengan skenario: tiga kali insertLast, satu kali insertFirst, lalu cetak. Tidak ada insertAfter di paket ini — fokusnya pada insertFirst dan insertLast yang benar-benar dipahami dari sisi **manajemen pointer prev dan next secara bersamaan**.
### Analisis Input Output

```
Skenario soal:
1. insertLast(20)  → [20]
   insertLast(30)  → [20] ↔ [30]
   insertLast(10)  → [20] ↔ [30] ↔ [10]
2. insertFirst(40) → [40] ↔ [20] ↔ [30] ↔ [10]
3. Cetak kelayar

Output yang diharapkan:
NULL <- [40] <-> [20] <-> [30] <-> [10] -> NULL
```
---
### Soal 2a Paket A - Struktur Node DLL (5 poin)

#### Alur Berpikir
##### **Step 1 - Identifikasi semua informasi yang perlu disimpan setiap node**

Setiap node DLL perlu menyimpan tiga hal:
- Nilai datanya sendiri
- Alamat node di sebelah kirinya
- Alamat node di sebelah kanannya
##### **Step 2 - Terjemahkan ke dalam struct C**

```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;  // pointer ke node sebelumnya
    struct Node* next;  // pointer ke node berikutnya
};

struct Node* head = NULL;
struct Node* tail = NULL;
```
---
### Soal 2b Paket A — Fungsi buatNode (10 poin)

#### Alur Berpikir
##### **Step 1 - Tentukan input dan output**

```
Input  : nilai integer yang mau disimpan
Proses : alokasi memori baru di heap, isi data, set pointer ke NULL
Output : pointer ke node baru yang siap disambungkan
```
##### **Step 2 — Kenapa semua pointer diset NULL dulu?**

```
Node baru itu kaya orang baru yang belum kenal siapapun.
Dia belum punya tetangga kiri (prev = NULL)
dan belum punya tetangga kanan (next = NULL).
Fungsi insert-lah yang nanti "mengenalkan" dia ke tetangganya.
```

```c
struct Node* buatNode(int data) {
    struct Node* baru = (struct Node*)malloc(sizeof(struct Node));
    baru->data = data;
    baru->prev = NULL;
    baru->next = NULL;
    return baru;
}
```
---
### Soal 2c Paket A - insertLast (10 poin)

#### Alur Berpikir
##### **Step 1 - Petakan dua kondisi yang mungkin**

```
Kondisi A: List kosong
  head = NULL, tail = NULL
  → node baru jadi satu-satunya elemen, sekaligus head dan tail

Kondisi B: List sudah ada isinya
  → node baru disambungkan di belakang tail saat ini
```
##### **Step 2 - Untuk kondisi B, tentukan dulu urutan penyambungan pointer**
**Sambungkan node baru ke list yang ada SEBELUM mengupdate tail**:

```
Sebelum insertLast(30), list: [20]
                               HEAD/TAIL

Step 1 — baru->prev = tail:
  [20] ← [30]
  (baru sudah tau kirinya adalah [20])

Step 2 — tail->next = baru:
  [20] ↔ [30]
  (tail lama sudah tau kanannya adalah [30])

Step 3 — tail = baru:
  [20] ↔ [30]
              ↑
           TAIL baru
```

```c
void insertLast(int data) {
    struct Node* baru = buatNode(data);

    if (head == NULL) {
        head = tail = baru;
    } else {
        baru->prev = tail;    // step 1
        tail->next = baru;    // step 2
        tail = baru;          // step 3
    }
}
```
---
### Soal 2d Paket A - insertFirst (10 poin)

#### Alur Berpikir
##### **Step 1 - insertFirst adalah kebalikan simetris dari insertLast**

```
insertLast  → bekerja di ujung KANAN, update tail
insertFirst → bekerja di ujung KIRI,  update head
```
##### **Step 2 - Urutan penyambungan pointer**

```
Sebelum insertFirst(40):
HEAD → [20] ↔ [30] ↔ [10] ← TAIL

Step 1 — baru->next = head:
  [40] → [20] ↔ [30] ↔ [10]
  (baru tau kanannya adalah [20])

Step 2 — head->prev = baru:
  [40] ↔ [20] ↔ [30] ↔ [10]
  (head lama tau kirinya adalah [40])

Step 3 — head = baru:
  HEAD sekarang menunjuk ke [40]
   ↓
  [40] ↔ [20] ↔ [30] ↔ [10]
```

```c
void insertFirst(int data) {
    struct Node* baru = buatNode(data);

    if (head == NULL) {
        head = tail = baru;
    } else {
        baru->next = head;    // step 1
        head->prev = baru;    // step 2
        head = baru;          // step 3
    }
}
```
---
### Soal 2e Paket A - Prosedur Print/Cetak (10 poin)

#### Alur Berpikir
##### **Step 1 - Tentukan format output yang merepresentasikan DLL**

DLL punya pointer dua arah, jadi outputnya harus menunjukkan kedua arah itu:

```
NULL <- [40] <-> [20] <-> [30] <-> [10] -> NULL
```
##### **Step 2 - Gunakan pointer curr untuk jalan dari head ke tail**

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
### Soal 2f Paket A - Fungsi Main (25 poin)

#### Analisis Input Output

Disini kita petakan kondisi list di setiap step skenario soal:

```
Step 1a: insertLast(20)   → [20]
Step 1b: insertLast(30)   → [20] ↔ [30]
Step 1c: insertLast(10)   → [20] ↔ [30] ↔ [10]
Step 2 : insertFirst(40)  → [40] ↔ [20] ↔ [30] ↔ [10]
Step 3 : Cetak
```
#### Alur Berpikir
##### **Step 1 - Baca skenario, identifikasi operasi yang dipake**

Soalnya: 
- insertLast tiga kali, lalu 
- insertFirst sekali
##### **Step 2 - Verifikasi kondisi list sebelum insertFirst**

Sebelum `insertFirst(40)` dipanggil, list sudah berisi `[20] ↔ [30] ↔ [10]`. Node 40 akan disisipkan di depan node 20 yang sekarang adalah head.

```c
int main() {
    // Skenario 1: tiga kali insertLast
    insertLast(20);
    printf("insertLast(20) : "); cetakList();

    insertLast(30);
    printf("insertLast(30) : "); cetakList();

    insertLast(10);
    printf("insertLast(10) : "); cetakList();

    // Skenario 2: insertFirst
    insertFirst(40);
    printf("insertFirst(40): "); cetakList();

    return 0;
}
```

**Output:**

```
insertLast(20) : NULL <- [20] -> NULL
insertLast(30) : NULL <- [20] <-> [30] -> NULL
insertLast(10) : NULL <- [20] <-> [30] <-> [10] -> NULL
insertFirst(40): NULL <- [40] <-> [20] <-> [30] <-> [10] -> NULL
```
---
## SOAL 2 — PAKET B: Single Linked List
### Analisis Input Output

```
Skenario soal: sama dengan Paket A
1. insertLast(20,30,10)
2. insertFirst(40)
3. Cetak

Target kondisi akhir:
HEAD → [40] → [20] → [30] → [10] → NULL
```

Perhatikan formatnya berbeda dari DLL — tidak ada tanda `<->` karena SLL tidak punya pointer balik!

---
### Soal 2a Paket B — Struktur Node SLL (5 poin)
#### Alur Berpikir
##### **Step 1 — Bandingkan dengan DLL, identifikasi apa yang dihilangkan**

```
DLL:  prev | data | next   (3 bagian)
SLL:        data | next    (2 bagian, prev dihapus)
```
##### **Step 2 — Tulis strukturnya**

```c
#include <stdio.h>
#include <stdlib.h>

// SLL — hanya punya next, TIDAK ada prev
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* tail = NULL;
```

> **Dampak langsungnya:** Karena tidak ada `prev`, kita tidak bisa "mundur" dari sebuah node. Kalau sedang di node [30] dan mau tau siapa di belakangnya, kita harus traversal dari head dari awal lagi.
---
### Soal 2b Paket B — Fungsi buatNode SLL (10 poin)
#### Alur Berpikir

Sama seperti DLL, tapi **lebih simpel** karena hanya ada satu pointer yang perlu diinisialisasi:

```c
struct Node* buatNode(int data) {
    struct Node* baru = (struct Node*)malloc(sizeof(struct Node));
    baru->data = data;
    baru->next = NULL;  // hanya next, tidak ada prev
    return baru;
}
```

---
### Soal 2c Paket B — insertLast SLL (10 poin)
#### Alur Berpikir
##### **Step 1 — Bandingkan dengan insertLast DLL**

```
insertLast DLL punya 3 step:
  Step 1: baru->prev = tail   ← step ini TIDAK ADA di SLL
  Step 2: tail->next = baru
  Step 3: tail = baru

insertLast SLL hanya 2 step:
  Step 1: tail->next = baru   (sambungkan tail ke node baru)
  Step 2: tail = baru         (update tail)
```
##### **Step 2 — Visualisasikan**

```
Sebelum insertLast(30), list: [20]

Step 1 — tail->next = baru:
  [20] → [30]

Step 2 — tail = baru:
  [20] → [30]
               ↑
           TAIL baru
```

```c
void insertLast(int data) {
    struct Node* baru = buatNode(data);

    if (head == NULL) {
        head = tail = baru;
    } else {
        tail->next = baru;    // step 1
        tail = baru;          // step 2
    }
}
```
---
### Soal 2d Paket B — insertFirst SLL (10 poin)
#### Alur Berpikir
##### **Step 1 — Bandingkan dengan insertFirst DLL**

```
insertFirst DLL punya 3 step:
  Step 1: baru->next = head
  Step 2: head->prev = baru   ← step ini TIDAK ADA di SLL
  Step 3: head = baru

insertFirst SLL hanya 2 step:
  Step 1: baru->next = head   (sambungkan node baru ke head lama)
  Step 2: head = baru         (update head)
```
##### **Step 2 — Visualisasikan**

```
Sebelum insertFirst(40):
HEAD → [20] → [30] → [10] → NULL

Step 1 — baru->next = head:
  [40] → [20] → [30] → [10] → NULL

Step 2 — head = baru:
  HEAD
   ↓
  [40] → [20] → [30] → [10] → NULL
```

```c
void insertFirst(int data) {
    struct Node* baru = buatNode(data);

    if (head == NULL) {
        head = tail = baru;
    } else {
        baru->next = head;    // step 1
        head = baru;          // step 2
    }
}
```
---
### Soal 2e Paket B — Prosedur Cetak SLL (10 poin)
#### Alur Berpikir
##### **Step 1 — Format output SLL berbeda dari DLL**

```
DLL: NULL <- [40] <-> [20] <-> [30] <-> [10] -> NULL
              (ada panah dua arah karena ada pointer prev)

SLL: [40] -> [20] -> [30] -> [10] -> NULL
              (hanya panah satu arah karena hanya ada next)
```

```c
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
```
---
### Soal 2f Paket B — Fungsi Main (25 poin)

#### Alur Berpikir

Skenario identik dengan Paket A — bedanya hanya di format output cetaknya:

```c
int main() {
    insertLast(20);
    printf("insertLast(20) : "); cetakList();

    insertLast(30);
    printf("insertLast(30) : "); cetakList();

    insertLast(10);
    printf("insertLast(10) : "); cetakList();

    insertFirst(40);
    printf("insertFirst(40): "); cetakList();

    return 0;
}
```

**Output:**

```
insertLast(20) : [20] -> NULL
insertLast(30) : [20] -> [30] -> NULL
insertLast(10) : [20] -> [30] -> [10] -> NULL
insertFirst(40): [40] -> [20] -> [30] -> [10] -> NULL
```
---
## SOAL 2 — PAKET C: Single Linked List + insertAfter

### Analisis Input Output

```
Skenario soal:
1. insertLast(20), insertLast(30), insertLast(10)
   → [20] → [30] → [10]

2. Masukan 40 sebagai elemen diantara elemen pertama dan kedua
   → insertAfter(head, 40)
   → [20] → [40] → [30] → [10]

3. Cetak kelayar
```

Target kondisi akhir:

```
[20] → [40] → [30] → [10] → NULL
```
---
### Soal 2a, 2b, 2c, 2e Paket C

**Sama persis dengan Paket B** — struktur Node SLL, buatNode, insertLast, dan cetakList tidak berubah. Fokus perbedaan Paket C ada di soal **2d** dan skenario main-nya.

---
### Soal 2d Paket C — insertAfter SLL (10 poin)

`insertAfter` di SLL lebih simpel dari DLL karena kita hanya perlu mengurus **pointer next**, tidak ada pointer prev yang perlu dipikirkan.
#### Alur Berpikir
##### **Step 1 — Visualisasikan kondisi sebelum dan sesudah**

```
Sebelum — sisipkan 40 setelah node [20] (head):
HEAD → [20] → [30] → [10] → NULL

Sesudah:
HEAD → [20] → [40] → [30] → [10] → NULL
```
##### **Step 2 — Identifikasi pointer yang berubah**

Di SLL hanya ada **2 pointer** yang perlu diurus (jauh lebih sedikit dari DLL yang butuh 4!):

```
1. baru->next  : harus tunjuk ke node setelah target (30)
2. target->next: harus tunjuk ke baru (40)
```
##### **Step 3 — Tentukan urutan yang aman**

```
Step 1 — baru->next = target->next:
  HEAD → [20]  [40]→[30] → [10] → NULL
  (baru sudah tau kanannya adalah [30])

Step 2 — target->next = baru:
  HEAD → [20] → [40] → [30] → [10] → NULL  ✅
  (target [20] sekarang tunjuk ke [40])
```

> **KRITIS:** Step 1 harus dilakukan DULU sebelum step 2! Kalau `target->next = baru` dilakukan duluan, referensi ke node [30] hilang selamanya karena `target->next` sudah berubah jadi `baru`. Tidak ada pointer `prev` di SLL yang bisa menyelamatkan kita!

```c
void insertAfter(struct Node* target, int data) {
    if (target == NULL) {
        printf("Target tidak valid!\n");
        return;
    }

    struct Node* baru = buatNode(data);

    baru->next = target->next;   // step 1 — HARUS DULUAN
    target->next = baru;         // step 2

    // Update tail kalau target adalah elemen terakhir
    if (baru->next == NULL) {
        tail = baru;
    }
}
```
---
### Soal 2f Paket C — Fungsi Main (25 poin)

#### Alur Berpikir
##### **Step 1 — Petakan kondisi list di setiap step**

```
Step 1a: insertLast(20) → [20]
Step 1b: insertLast(30) → [20] → [30]
Step 1c: insertLast(10) → [20] → [30] → [10]
Step 2 : insertAfter(head, 40)
         head sekarang = node [20]
         → sisipkan 40 setelah [20]
         → [20] → [40] → [30] → [10]
Step 3 : Cetak
```
##### **Step 2 - Verifikasi: siapa head saat insertAfter dipanggil?**

Setelah tiga kali insertLast, head masih menunjuk ke node [20] karena insertLast tidak pernah mengubah head. Jadi `insertAfter(head, 40)` artinya sisipkan 40 tepat setelah node 20.

```c
int main() {
    // Skenario 1: tiga kali insertLast
    insertLast(20);
    printf("insertLast(20)        : "); cetakList();

    insertLast(30);
    printf("insertLast(30)        : "); cetakList();

    insertLast(10);
    printf("insertLast(10)        : "); cetakList();

    // Skenario 2: sisipkan 40 antara elemen pertama (20) dan kedua (30)
    insertAfter(head, 40);
    printf("insertAfter(head, 40) : "); cetakList();

    return 0;
}
```

**Output:**

```
insertLast(20)        : [20] -> NULL
insertLast(30)        : [20] -> [30] -> NULL
insertLast(10)        : [20] -> [30] -> [10] -> NULL
insertAfter(head, 40) : [20] -> [40] -> [30] -> [10] -> NULL
```
---
#### Ringkasan Alur Berpikir

```
┌─────────────────────────────────────────────────────────┐
│                   SOAL 1 (SEMUA PAKET)                  │
│                                                         │
│  Turunkan semua perbedaan dari 1 fakta dasar:           │
│  "DLL punya prev, SLL tidak."                           │
│  → traversal → delete → memori → kompleksitas           │
└─────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────┐
│               SOAL 2 — PAKET A (DLL)                    │
│                                                         │
│  insertLast → 3 step: prev, next, update tail           │
│  insertFirst → 3 step: next, prev, update head          │
│  Urutan: sambung ke list dulu, update head/tail belakang│
└─────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────┐
│             SOAL 2 — PAKET B (SLL)                      │
│                                                         │
│  Sama seperti Paket A tapi hilangkan semua step         │
│  yang melibatkan pointer prev                           │
│  insertLast → 2 step  (bukan 3)                         │
│  insertFirst → 2 step (bukan 3)                         │
└─────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────┐
│             SOAL 2 — PAKET C (SLL + insertAfter)        │
│                                                         │
│  insertAfter → 2 step SAJA (SLL lebih simpel dari DLL)  │
│  Step 1: baru->next = target->next  ← HARUS DULUAN      │
│  Step 2: target->next = baru                            │
│                                                         │
│  Kenapa step 1 dulu? Karena kalau step 2 duluan,        │
│  referensi ke node berikutnya HILANG SELAMANYA!         │
└─────────────────────────────────────────────────────────┘
```