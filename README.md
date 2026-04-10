# ISC Data Structure 2026
## Learning Materials for Data Structure UTS (2023-2025)

---

## Overview

Repository ini adalah **koleksi materi pembelajaran komprehensif** untuk mata kuliah **Struktur Data** (ISC Semester 2), yang mencakup:

- **Analisis mendalam** soal-soal UTS dari tahun 2023, 2024, dan 2025
- **Panduan pembelajaran** step-by-step dengan visualisasi ASCII
- **Solusi terstruktur** untuk semua topik utama
- **Penjelasan konseptual** tentang alasan di balik setiap implementasi

Materi ini dirancang untuk membantu mahasiswa **memahami**, bukan hanya sekedar **menghafal** implementasi data structure.

---

## Struktur Materi

```
ISC-Data-Structure-2026/
│
├── README.md                          (file ini)
│
├── Soal UTS 2023 - 2025/             (arsip soal ujian)
│   ├── 2023 UTS Strukdat.pdf         (exam paper 2023)
│   ├── 2024 UTS Strukdat.pdf         (exam paper 2024)
│   └── STRUKTUR DATA 2025 PAKET ABC.pdf  (exam paper 2025 - 3 variasi)
│
└── Penjelasan Soal/                     (LEARNING GUIDES - START HERE!)
    ├── UTS STRUKTUR DATA 2023 - Fix.md
    ├── UTS STRUKTUR DATA 2024 - Fix.md
    └── UTS STRUKTUR DATA 2025 - Fix.md
```

---

## Panduan Penggunaan

### Untuk Belajar Mandiri

1. **Mulai dari file yang paling baru**: `Penjelasan Soal/UTS STRUKTUR DATA 2025 - Fix.md`
   - Materi paling lengkap dan terkini
   - Sistem multi-paket membantu memahami variasi soal
   - Penjelasan fundamental yang solid

2. **Bandingkan dengan tahun sebelumnya** untuk melihat evolusi topik:
   - 2023: Problem solving approach
   - 2024: Step-by-step modular coding
   - 2025: Comprehensive system dengan variasi paket

3. **Praktik dengan soal asli** dari folder `Soal UTS 2023 - 2025/`

---

## 📝 Topik Utama

### 1️⃣ **Double Linked List (DLL)**
- Struktur data dengan dua pointer (`prev` dan `next`)
- Operasi: `insertFirst`, `insertLast`, `insertAfter`
- **Tipe Soal**: Mulai dari analysis (2023) → implementation (2024) → optimization (2025)

### 2️⃣ **Single Linked List (SLL)** 
- Struktur data dengan satu pointer (`next`)
- Lebih sederhana dari DLL tapi kurang fleksibel
- **Baru di 2025**: Perbandingan sistematis dengan DLL melalui sistem paket

### 3️⃣ **Stack**
- Prinsip LIFO (Last In, First Out)
- Operasi: `push`, `pop`, `peek`
- **Tipe Soal**: Teori (2023) → Implementation (2024) → Comparison (2025+)

---

## 🔍 Evolusi UTS 2023 → 2025

| Aspek | 2023 | 2024 | 2025 |
|-------|------|------|------|
| **Pendekatan** | Problem Solving | Step-by-step Modular | Multi-Packet System |
| **Soal 1** | DLL (Analysis) | DLL (7 sub-poin) | DLL + SLL + Comparison |
| **Soal 2** | Stack (Theory only) | Stack (Implementation) | Linked List vs Stack |
| **Topik Utama** | DLL + Stack | DLL + Stack | **SLL vs DLL (100% focus)** |
| **Materi Stack** | ✅ Included | ✅ Included | ❌ Dihilangkan |
| **Tingkat Kesulitan** | Menengah | Medium-High | High (lebih detail) |
| **Soal Variasi** | 1 versi | 1 versi | **3 versi** (A, B, C) |

### 📌 Poin Penting 2025

Di tahun 2025, **Stack tidak diuji sama sekali**. Sebaliknya, fokus dosen adalah:
- **Pemahaman mendalam** tentang perbedaan SLL vs DLL
- **Implementasi multi-paket** untuk menguji kesadaran mahasiswa tentang trade-off perilaku
- **Pendalaman pointer memory** yang lebih detail

---

## Konten Penjelasan Soal

### **UTS STRUKTUR DATA 2023 - Fix.md**

Materi ini mengajarkan **problem solving approach**:

#### **Soal 1 - Double Linked List (80 poin)**
- Input: 5, 10, 8, 7, 3
- Output yang diharapkan: 10, 7, 5, 8, 3
- **Challenge**: Tentukan sendiri operasi insert mana yang harus digunakan
- **Belajar**: Alur berpikir sistematis untuk analysis soal yang ambigu

Langkah-langkah analisis:
1. Tentukan kondisi akhir dari output
2. Identifikasi posisi setiap elemen
3. Kenali "karakter" setiap operasi (insertFirst vs insertLast vs insertAfter)
4. Susun urutan operasi yang logis

#### **Soal 2 - Stack Teori (20 poin)**
- 2a: Apa itu Stack Overflow? Kapan? Kenapa? Akibatnya?
- 2b: Definisikan struktur Stack (konseptual + implementasi)
- **Output**: Stack overflow check + inisialisasi + operasi dasar

---

### **UTS STRUKTUR DATA 2024 - Fix.md**

Materi ini mengajarkan **modular coding approach** (from zero to hero):

#### **Soal 1 - Double Linked List (80 poin)**
Tujuh sub-poin yang terstruktur:
- **1a**: Definisikan `struct Node` dengan `prev`, `data`, `next`
- **1b**: Fungsi `buatNode()` - "pabrik node"
- **1c**: Fungsi `insertFirst()`
- **1d**: Fungsi `insertLast()`
- **1e**: Fungsi `insertAfter()` - **4 pointer** yang harus dikelola dengan urutan tepat
- **1f**: Fungsi `cetakList()` - output format: `NULL <- [A] <-> [B] <-> [C] -> NULL`
- **1g**: Fungsi `main()` - orchestration seluruh skenario

**Skenario soal**:
```
insertFirst(40)      → [40]
insertFirst(50)      → [50] ↔ [40]
insertLast(30)       → [50] ↔ [40] ↔ [30]
insertAfter(head, 90)→ [50] ↔ [90] ↔ [40] ↔ [30]
```

#### **Soal 2 - Stack (30 poin)**
- **2a**: Perbedaan Stack vs SLL
  - Stack: akses TERBATAS (hanya TOP, prinsip LIFO)
  - SLL: akses BEBAS di mana saja
- **2b**: Struktur Stack dengan array + `top` variable
- **2c**: Implementasi `push()` dan `pop()` dengan error handling

---

### **UTS STRUKTUR DATA 2025 - Fix.md** ⭐ PALING LENGKAP

Materi ini mengajarkan **comprehensive system dengan multi-packet approach**:

#### **Soal 1 - Teori Perbandingan SLL vs DLL (Semua Paket)**

**Tabel Perbandingan**:

| Aspek | SLL | DLL |
|-------|-----|-----|
| **Pointer per node** | 1 (`next`) | 2 (`prev` + `next`) |
| **Arah traversal** | Satu arah | Dua arah |
| **Memori per node** | Lebih hemat | Lebih boros |
| **Delete node** | Perlu pointer ke node sebelumnya | Langsung via `prev` |
| **Kompleksitas kode** | Lebih sederhana | Lebih kompleks |
| **Fleksibilitas** | Terbatas | Tinggi |
| **Kegunaan** | List sederhana, antrian | Browser history, undo/redo |

**Visualisasi**:
```
Single Linked List:
HEAD → [5] → [10] → [8] → [7] → NULL
(hanya bisa ke kanan)

Double Linked List:
NULL ← [5] ↔ [10] ↔ [8] ↔ [7] → NULL
(bisa ke kanan dan ke kiri)
```

#### **Soal 2 - Implementasi dengan 3 Paket (A, B, C)**

**Paket A: Double Linked List** (paling kompleks)
- `struct Node` dengan `prev` + `data` + `next`
- `insertFirst` + `insertLast` (3 langkah masing-masing)
- Output: `NULL <- [40] <-> [20] <-> [30] <-> [10] -> NULL`

**Paket B: Single Linked List** (lebih simpel)
- `struct Node` dengan `data` + `next` (tidak ada `prev`)
- `insertFirst` + `insertLast` (2 langkah masing-masing)
- Output: `[40] -> [20] -> [30] -> [10] -> NULL`

**Paket C: Single Linked List + insertAfter** (logika khusus)
- Struktur sama dengan Paket B
- Fitur tambahan: `insertAfter()` untuk insert di tengah
- **KRITIS**: Step 1 harus DULUAN: `baru->next = target->next`
- Output: `[20] -> [40] -> [30] -> [10] -> NULL`

---

## 💡 Konsep Pedagogis Utama

### **Alur Berpikir Sistematis**

Untuk setiap masalah, ikuti langkah ini:

```
1. Pahami Konteks
   ↓
2. Visualisasikan Kondisi Awal & Akhir
   ↓
3. Identifikasi Apa yang Berubah (pointer/state)
   ↓
4. Tentukan Urutan Operasi yang Aman
   ↓
5. Implementasikan sesuai urutan
```

### **Urutan Pointer Operasi: SANGAT PENTING**

**Prinsip Emas**: Sambungkan node BARU ke LIST yang ada **SEBELUM** mengubah referensi HEAD/TAIL lama.

**Contoh insertAfter (DLL)**:
```
❌ SALAH - putuskan lama dulu:
target->next = baru;      // STOP! Anda kehilangan referensi ke node setelahnya
baru->next = ???           // Node setelahnya sudah hilang!

✅ BENAR - sambungkan baru dulu:
baru->next = target->next;         // Save referensi ke node setelahnya
baru->prev = target;               // Sambungkan ke node sebelumnya
target->next->prev = baru;         // Update prev pointer node setelahnya
target->next = baru;               // Terakhir, putuskan lama
```

---

## 🛠️ Cara Menggunakan Repository

### **Setup Awal**
```bash
# Clone atau download repository
git clone <repo-url>
cd ISC-Data-Structure-2026

# Struktur terotomi dengan rapi
```

### **Belajar Materi**
1. Buka `Penjelasan Soal` folder
2. **Jika baru**: Mulai dari `UTS STRUKTUR DATA 2025 - Fix.md`
3. **Jika sudah tahu**: Bandingkan 3 file untuk melihat evolusi
4. **Jika ingin latihan**: Buka `Soal UTS 2023 - 2025/` dan kerjakan soal asli

### **Membuat Solusi**
Untuk setiap soal, ikuti template:

```c
#include <stdio.h>
#include <stdlib.h>

// 1. Struct Definition (mirrored dari guide)
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* tail = NULL;

// 2. buatNode - factory function
struct Node* buatNode(int data) {
    // ... (lihat di guide)
}

// 3. insertFirst, insertLast, insertAfter
// ... (implementasi sesuai guide)

// 4. cetakList
void cetakList() {
    // ... (implementasi sesuai guide)
}

// 5. main - orchestration
int main() {
    // Jalankan skenario sesuai soal
    return 0;
}
```

---

## 📊 Mapping Soal ke Materi

### Jika Anda Mendapat Soal Mirip 2023
→ Buka **UTS STRUKTUR DATA 2023 - Fix.md**
- Fokus pada: Analisis alur berpikir problem solving
- Pelajari: Bagaimana menentukan operasi mana yang cocok

### Jika Anda Mendapat Soal Mirip 2024
→ Buka **UTS STRUKTUR DATA 2024 - Fix.md**
- Fokus pada: Implementasi step-by-step modular
- Pelajari: Urutan pointer dan error handling

### Jika Anda Mendapat Soal Mirip 2025
→ Buka **UTS STRUKTUR DATA 2025 - Fix.md**
- Fokus pada: Perbandingan SLL vs DLL
- Pelajari: Perbedaan implementasi 3 paket (A, B, C)
- **Ingat**: 2025 TIDAK ada Stack — fokus penuh ke Linked List

---

## 🎓 Learning Objectives

Setelah mempelajari materi ini, Anda seharusnya dapat:

✅ **Memahami** struktur dan prinsip DLL dan SLL
✅ **Mengimplementasikan** operasi insert (first, last, after) dengan benar
✅ **Menjelaskan** trade-off antara SLL vs DLL
✅ **Menulis** kode berstruktur dengan modular approach
✅ **Menganalisis** urutan pointer dan alasan setiap step
✅ **Mendeteksi** dan menghindari memory leak dan referensi yang hilang
✅ **Memecahkan** problem soal dengan systematic thinking

---

## 🐛 Troubleshooting Common Mistakes

### ❌ Pointer Hilang di insertAfter
```c
// SALAH
target->next = baru;  // Referensi ke node setelahnya HILANG!

// BENAR
baru->next = target->next;  // Save dulu
target->next = baru;        // Ubah setelah
```

### ❌ Tidak Update HEAD/TAIL setelah insertFirst/Last
```c
// SALAH
baru->next = head;

// BENAR — harus ada step update head juga
baru->next = head;
head->prev = baru;
head = baru;  // ← JANGAN LUPA ini!
```

### ❌ Output Format Salah
```c
// SALAH — DLL tapi format SLL
printf("[%d] -> ", curr->data);

// BENAR
printf("[%d] <-> ", curr->data);  // Kedua arah pointer
```

---

## 📞 Referensi Cepat

### Operasi DLL vs SLL

**insertFirst**:
- DLL: 3 langkah (next, prev, update head)
- SLL: 2 langkah (next, update head)

**insertLast**:
- DLL: 3 langkah (prev, next, update tail)
- SLL: 2 langkah (next, update tail)

**insertAfter**:
- DLL: 4 pointer, urutan CRITICAL
- SLL: 2 pointer, step 1: `baru->next = target->next` **HARUS DULUAN**

---

## 🔗 File Links Quick Access

| Topik | File | Purpose |
|-------|------|---------|
| 2023 DLL + Stack Theory | Penjelasan Soal/UTS STRUKTUR DATA 2023 - Fix.md | Problem Solving Approach |
| 2024 DLL + Stack Code | Penjelasan Soal/UTS STRUKTUR DATA 2024 - Fix.md | Modular Implementation |
| 2025 SLL vs DLL | Penjelasan Soal/UTS STRUKTUR DATA 2025 - Fix.md | Comprehensive System |
| Soal 2023 Original | Soal UTS 2023 - 2025/2023 UTS Strukdat.pdf | Original Exam |
| Soal 2024 Original | Soal UTS 2023 - 2025/2024 UTS Strukdat.pdf | Original Exam |
| Soal 2025 Original | Soal UTS 2023 - 2025/STRUKTUR DATA 2025 PAKET ABC.pdf | Original Exam (3 variants) |

---

## 📌 Catatan Akhir

- **Materi ini adalah pembelajaran**, bukan copy-paste solution
- **Pahami alur berpikir** di setiap step, tidak hanya kode
- **Praktik berkali-kali** hingga mahir
- **Jangan hafal**, tapi **mengerti** mengapa setiap langkah perlu
- **Urutan pointer sangat penting** — satu kesalahan bisa membuat program crash

---

## 📄 Version History

| Versi | Tanggal | Konten |
|-------|---------|--------|
| V2.0 | 2025 | Multi-packet system (A, B, C), comprehensive guides |
| V1.0 | 2024 | Basic DLL + Stack materials |

---

**Created for ISC Students | Struktur Data Semester 2 | 2023-2025**
