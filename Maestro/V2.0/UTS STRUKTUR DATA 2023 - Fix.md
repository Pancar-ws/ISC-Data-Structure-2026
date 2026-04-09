*Di tahun 2023, yang diuji adalah pemahaman konsep dasar dengan pendekatan **"Problem Solving"**. Soalnya tidak meminta menulis coding lengkap dari nol sampai akhir secara sistematis, melainkan memberikan satu studi kasus logika dan diminta untuk menyelesaikannya. Topik utamanya ada dua: **Double Linked List (DLL)** yang diuji lewat logika urutan input-output, dan **Stack** yang diuji lewat pemahaman teoritis dasar.*

---
## Soal 1 - Double Linked List (80 poin)

**Soal:** Masukkan bilangan 5, 10, 8, 7, 3 ke dalam sebuah list, kemudian cetak hasilnya: 10, 7, 5, 8, 3 - Logika Double Linked List (DLL)

Yang pertama kali harus kalian tanyakan ke diri sendiri:

> “Apakah urutan masukan = urutan cetak/output? Kalau tidak, berarti **tidak boleh** cuma pakai insertLast terus-terusan. Karena memungkinkan terdapat kondisi insertAfter dan insertFirst juga digunakan”

Sebelum ke solusi, kita pahami dulu **apa itu Double Linked List (DLL)**.

Single Linked List: Kereta yang cuma bisa jalan ke depan, nah 
**Double Linked List**: Keretanya bisa jalan ke depan **dan ke belakang**. Setiap node punya **3 bagian:**

```
[prev | data | next]
```

- `prev` → pointer ke node sebelumnya
- `data` → nilai yang disimpan
- `next` → pointer ke node berikutnya
---
### Analisis Input & Output yang Diminta

	- Input: 5, 10, 8, 7, 3 (urutan memasukkan) 
	- Output: 10, 7, 5, 8, 3 (hasil cetak)

berarti kondisi akhir list kita harus:

```
HEAD → [10] ↔ [7] ↔ [5] ↔ [8] ↔ [3] → NULL
```

**gimana caranya nyusunnya? apakah semua operasi (insertFirst, insertAfter, insertLast) digunakan???**

---
### Alur Berpikir
#### Step 1 - Menentukan "Kondisi Akhir"

- **jangan langsung mikirin cara insertnya**, tapi pahami soalnya sampai tau apa yang diminta.

```
Input  : 5, 10, 8, 7, 3  (urutan memasukkan)
Output : 10, 7, 5, 8, 3  (hasil cetak)
```

Output cetak = kondisi list dari HEAD ke TAIL

```
HEAD → [10] ↔ [7] ↔ [5] ↔ [8] ↔ [3] → NULL
```

ini adalah maksud dari "Kondisi Akhir"

---
#### Step 2 - Tau Posisi Setiap Angka

- Angka apa aja yang tersedia: `5, 10, 8, 7, 3`
- Di posisi mana masing masing angka harus berada di kondisi akhir

Kasih label posisi:

```
Posisi:   1     2     3     4     5
List  : [10] ↔ [7] ↔ [5] ↔ [8] ↔ [3]
```

| Angka | Posisi di kondisi akhir |
| ----- | ----------------------- |
| 10    | Posisi 1 (HEAD)         |
| 7     | Posisi 2                |
| 5     | Posisi 3 (tengah)       |
| 8     | Posisi 4                |
| 3     | Posisi 5 (TAIL)         |

---
#### Step 3 - Kenali "Karakter" Tiap Operasi

- Tau **kapan kita boleh pakai operasi apa:**

```
insertFirst  →  dipakai kalo angka mau taruh di PALING DEPAN (jadi HEAD baru)
insertLast   →  dipakai kalo angka mau taruh di PALING BELAKANG (jadi TAIL baru)
insertAfter  →  dipakai kalo angka mau taruh DI TENGAH, setelah node tertentu
```

> **Analogi:** Bayangin aja lagi ngantri presensi kehadiran praktikum struktur data. `insertFirst` itu kamu **nyerobot ke paling depan antrian** buat langsung tanda tangan. `insertLast` itu kamu **ngantri normal di belakang**, bukan nyerobot ke paling depan. sementara kalo `insertAfter` itu kamu lagi ke toilet tapi kamu **nitip posisi di belakang teman yang sudah ada di antrian** buat presensi, jadi nanti pas kamu balik lagi bisa langsung ke antrian belakang temenmu yang udah antri. 
---
#### Step 4 - Angka Pertama: 5

Input pertama: angka **5**. Ini adalah node pertama yang kita punya, jadi list masih kosong saat 5 dimasukkan. Tidak ada pilihan lain:

```
insertFirst(5) atau insertLast(5) → hasilnya sama aja: [5]
```

Kita pilih `insertFirst(5)` karena nanti angka-angka berikutnya akan "mendorong" 5 ke posisi yang benar.

```
State sekarang : [5]
Target akhir   : [10] ↔ [7] ↔ [5] ↔ [8] ↔ [3]
```

---
#### Step 5 - Angka Kedua: 10, Tanya "Di Mana Posisi Final?"

- Angka berikutnya: **10**.  
Di target akhir, angka 10 itu ada di **posisi 1 (HEAD)**. 
Sekarang list kita isinya `[5]` dan 5 ada di posisi 3 di target akhir.

**"Apakah 10 harus ada di depan 5?"** → **Ya**, karena di target akhir, 10 ada di posisi 1 dan 5 ada di posisi 3.

Operasi apa yang naruh angka di depan? → **`insertFirst`**

```
insertFirst(10) → [10] ↔ [5]

State sekarang : [10] ↔ [5]
Target akhir   : [10] ↔ [7] ↔ [5] ↔ [8] ↔ [3]
```

---
#### Step 6 - Angka Ketiga: 8, "Di Mana Posisi Finalnya?"

- Angka berikutnya adalah **8**. 
Di target akhir, angka 8 ada di **posisi 4**. tepat sebelum 3 dan setelah 5.
Sekarang list kita: `[10] ↔ [5]`

**"Apakah 8 harus ada di belakang semua node yang sudah ada?"**

Di target akhir: 10 → 7 → 5 → ***8*** → 3. 
Node 7 dan 3 belum dimasukkan. Tapi perhatikan, 8 pasti ada **di belakang 5**, dan 5 sekarang adalah TAIL.

Nah dari situ kita bisa `insertLast(8)`, karena nanti node 7 akan disisipkan di antara 10 dan 5, dan node 3 akan ditambah di belakang 8.

```
insertLast(8) → [10] ↔ [5] ↔ [8]

State sekarang : [10] ↔ [5] ↔ [8]
Target akhir   : [10] ↔ [7] ↔ [5] ↔ [8] ↔ [3]
```

---
#### Step 7 - Angka Keempat: 7

- Angka berikutnya adalah **7**. 
Di target akhir, angka 7 berada di **posisi 2**,  di antara 10 dan 5.
Sekarang list kita: `[10] ↔ [5] ↔ [8]`

**"Apakah 7 bisa diinsert di depan atau di belakang?"**
Misalnya gini:

``` 
`insertFirst(7)` → list jadi `[7] ↔ [10] ↔ [5] ↔ [8]` ❌ gabisa, angka 7 harus di belakang 10 

`insertLast(7)` → list jadi `[10] ↔ [5] ↔ [8] ↔ [7]` ❌ gabisa, angka 7 harus di posisi 2
```  

maka, **harus pakai `insertAfter`**. Sekarang tinggal nentuin: **insertAfter angka berapa?**
Target akhir: 10 ↔ ***7*** ↔ 5, angkat 7 beraada **setelah 10**, maka `insertAfter(node_10, 7)`

Dan node 10 sekarang ada di mana? → Tepat di **HEAD**, jadi kita bisa langsung pake `head` sebagai pointer ke node 10.

```
insertAfter(head, 7) → [10] ↔ [7] ↔ [5] ↔ [8]

State sekarang : [10] ↔ [7] ↔ [5] ↔ [8]
Target akhir   : [10] ↔ [7] ↔ [5] ↔ [8] ↔ [3]
```

---
#### Langkah 8 - Angka Kelima: 3

- Angka terakhir adalah **3**. 
Di target akhir, 3 ada di **posisi 5 (TAIL)** atau paling belakang.
Sekarang list kita: `[10] ↔ [7] ↔ [5] ↔ [8]`

**"Apakah 3 harus ada di paling belakang?"** → **Ya**, karena memang tidak ada angka lain lagi yang harus dimasukkan setelahnya, maka operasi yang digunakan adalah → **`insertLast`**

```
insertLast(3) → [10] ↔ [7] ↔ [5] ↔ [8] ↔ [3]

State sekarang : [10] ↔ [7] ↔ [5] ↔ [8] ↔ [3]
Target akhir   : [10] ↔ [7] ↔ [5] ↔ [8] ↔ [3]  SUDAH MATCH
```

---
### Ringkasan

```
┌─────────────────────────────────────────────────┐
│  "Di posisi mana angka ini di kondisi akhir?"   │
└──────────────────┬──────────────────────────────┘
                   │
       ┌───────────┴────────────┐
       ▼                        ▼
  Posisi paling            Posisi paling
    DEPAN?                  BELAKANG?
       │                        │
       ▼                        ▼
  insertFirst             insertLast
                               
  Kalau keduanya TIDAK → insertAfter(node sebelumnya)
```
## Soal 2 - Stack

### Stack
Stack: struktur data yang bekerja dengan prinsip **LIFO - Last In, First Out** → data yang terakhir masuk itu data yang pertama keluar.

Visualisasi Stack:

```
          PUSH →         ← POP
             │               │
             ▼               ▼
          ┌─────┐
   TOP →  │  3  │  ← elemen teratas (paling baru masuk)
          ├─────┤
          │  2  │
          ├─────┤
          │  1  │  ← elemen pertama yang masuk
          └─────┘
```

Stack punya dua operasi utama:

| Operasi   | Artinya                      | Kondisi Error                            |
| --------- | ---------------------------- | ---------------------------------------- |
| `push(x)` | Masukkan data ke atas stack  | Stack sudah penuh → **Stack Overflow**   |
| `pop()`   | Ambil dan hapus data teratas | Stack sudah kosong → **Stack Underflow** |

> **Analogi:** Stack itu ibarat **kaleng Pringles**. Keripik yang paling terakhir dimasukin ke kaleng, itu yang pertama kamu ambil waktu dimakan. Kita ga bisa ngambil dari bawah langsung. 
> 
> Analogi selain itu coba bayangin lift yang maksimal isinya 8 orang. Kalo ada orang ke-9 yang maksa masuk, liftnya bakal bunyi dan _error_, kan? Nah, _Stack Overflow_ adalah kondisi _error_ saat kita memaksa _push_ (masukin data) ke dalam Stack yang memorinya sudah penuh kapasitasnya
---
### Soal 2a - Stack Overflow (10 poin)

Pertanyaannya bukan cuma dalam bentuk definisi, tapi harus bisa jelasin juga:
- `kapan terjadi`
- `kenapa bisa terjadi, dan` 
- `apa akibatnya?`
#### Alur Berpikir
##### **Step 1 - Tau karakteristik Stack**

Stack itu punya kapasitas maksimum. Kalo kita implementasi pake array, kapasitasnya ditentukan dari awal, misalnya:

```c
#define MAX_SIZE 5

struct Stack {
    int data[MAX_SIZE];
    int top;
};
```
Berartistack ini maksimal bisa nampung **5 elemen**. 
##### **Step 2 - Bayangin kondisi stack yang udah penuh**

```
MAX_SIZE = 5

          ┌─────┐
   TOP →  │  E  │  ← index 4 (penuh lur!)
          ├─────┤
          │  D  │  ← index 3
          ├─────┤
          │  C  │  ← index 2
          ├─────┤
          │  B  │  ← index 1
          ├─────┤
          │  A  │  ← index 0
          └─────┘
```
##### **Langkah 3 — Apa yang bakal terjadi kalo kita paksa push lagi?**

```
push(F) ke stack yang sudah penuh →

          ┌─────┐
          │  F  │  ← mau taruh dimana? index cuman sampai 4 (0,1,2,3,4)
          ├─────┤
   TOP →  │  E  │  ← index 4 (batas maksimal)
          ├─────┤
          │  D  │
          ...
```

nah inilah yang disebut **Stack Overflow**, kondisi dimana memaksa memasukkan data ke stack yang sudah tidak punya ruang lagi.
##### **Step 4 — Akibat apa kalo ga dicek?**

Kalo gaada pengecekan `isFull()` sebelum push, program bisa **menulis data ke area memori yang bukan miliknya** , yang dalam bahasa C bisa menyebabkan program crash atau perilaku yang tidak terduga.
#### Ringkasan

```
Stack Overflow merupakan kondisi error yang terjadi ketika operasi
push() dipanggil pada stack yang sudah penuh (top == MAX_SIZE - 1),
sehingga tidak ada lagi ruang untuk menampung data baru.

Jika tidak ditangani, program bisa mengakses memori di luar batas
array yang telah dialokasikan, dapat menyebabkan crash atau undefined behavior.
```

Implementasi pengecekannya:

```c
void push(struct Stack* s, int data) {
    // Cek dulu sebelum push — ini yang mencegah Stack Overflow
    if (s->top == MAX_SIZE - 1) {
        printf("Stack Overflow! Tidak bisa push %d.\n", data);
        return;
    }
    s->data[++(s->top)] = data;
}
```

Visualisasi alurnya:

```
push(F) dipanggil
      │
      ▼
top == MAX_SIZE - 1?
      │
   ┌──┴──┐
  YES    NO
   │      │
   ▼      ▼
TOLAK!  Masukkan data,
Stack   naikkan top
Overflow!
```
---
### Soal 2b — Definisi Struktur Sebuah Stack

Pertanyaannya: _"Definisikan struktur sebuah Stack"_, maksudnya adalah:
- Definisi **konseptual**, apa itu stack, prinsip kerjanya
- Definisi **implementasi**, bagaimana bentuk struct-nya dalam kode
#### Alur Berpikir
##### **Step 1 — Tentukan komponen apa aja yang stack butuhkan**

Stack itu butuh dua hal:
- Tempat untuk menyimpan data → pake **array**
- Penanda posisi elemen paling atas → pake variabel **top**

```
Yang dibutuhkan stack:
┌────────────────────────────┐
│  data[]  → wadah datanya   │
│  top     → penunjuk posisi │
└────────────────────────────┘
```
##### **Step 2 - Tentukan nilai awal top-nya**

`top` dimulai dari index ke **-1**, bukan index ke 0. Kenapa?

```
top = -1  →  stack kosong, belum ada elemen

Push pertama:
  top naik dari index -1 ke 0
  data[0] = elemen pertama

Push kedua:
  top naik dari 0 ke 1
  data[1] = elemen kedua

dan seterusnya...
```

Kalo `top` dimulai dari 0, kita tidak bisa bedakan antara "stack kosong" dengan "stack berisi 1 elemen di index 0". Makanya -1 dipakai sebagai penanda "kosong".
##### **Step 3 - Tulis strukturnya**

```c
#define MAX_SIZE 100

struct Stack {
    int data[MAX_SIZE];  // array penyimpan elemen, ukuran maksimal 100
    int top;             // index elemen teratas, -1 jika stack kosong
};
```
##### **Step 4 - Lengkapi dengan operasi-operasi dasarnya**

```c
// Inisialisasi stack — wajib dipanggil sebelum dipakai!
void initStack(struct Stack* s) {
    s->top = -1;
}

// Cek apakah stack kosong
int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Cek apakah stack penuh
int isFull(struct Stack* s) {
    return s->top == MAX_SIZE - 1;
}

// Push — masukkan data
void push(struct Stack* s, int data) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        return;
    }
    s->data[++(s->top)] = data;
}

// Pop — ambil dan hapus data teratas
int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return s->data[(s->top)--];
}

// Peek — lihat data teratas tanpa hapus
int peek(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack kosong!\n");
        return -1;
    }
    return s->data[s->top];
}
```
##### **Step 5 - Visualisasi kondisi top saat operasi berjalan**

```
init:      top = -1   │ stack kosong

push(10):  top = 0    │ [10]
push(20):  top = 1    │ [10][20]
push(30):  top = 2    │ [10][20][30]   ← TOP

peek():    return 30  │ [10][20][30]   ← tidak berubah

pop():     return 30  │ [10][20]       ← top turun ke 1
pop():     return 20  │ [10]           ← top turun ke 0
pop():     return 10  │ stack kosong   ← top kembali ke -1
```
---
## Ringkasan Soal 2 (2a & 2b)

```
┌─────────────────────────────────────────────────────┐
│              SOAL TEORI = SOAL ANALISIS             │
│                                                     │
│  1. Pahami dulu konteks topiknya (Stack = LIFO)     │
│                                                     │
│  2. Untuk 2a (Stack Overflow):                      │
│     "Apa yang terjadi kalau kondisi batas           │
│      dilanggar?" → push ke stack penuh              │
│                                                     │
│  3. Untuk 2b (Struktur Stack):                      │
│     "Komponen apa yang dibutuhkan?" →               │
│      array + top, lalu lengkapi dengan              │
│      operasi-operasinya                             │
│                                                     │
│  4. Selalu sertakan visualisasi atau kode           │
│     pendukung — jawaban teori tanpa ilustrasi       │
│     biasanya kurang meyakinkan di mata dosen!       │
└─────────────────────────────────────────────────────┘
```
