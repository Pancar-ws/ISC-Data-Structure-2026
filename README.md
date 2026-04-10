# ISC Data Structure 2026
Learning materials for Data Structure UTS (2023-2025)

---

## Overview

Repository ini berisi **panduan pembelajaran komprehensif** untuk mata kuliah Struktur Data (ISC Semester 2):
- Analisis soal UTS 2023, 2024, 2025
- Penjelasan step-by-step dengan visualisasi ASCII
- Alur berpikir sistematis untuk setiap topik
- Fokus pada **pemahaman**, bukan hafalan

---

## Struktur Direktori

```
ISC-Data-Structure-2026/
├── README.md
├── Soal UTS 2023 - 2025/          (exam papers)
│   ├── 2023 UTS Strukdat.pdf
│   ├── 2024 UTS Strukdat.pdf
│   └── STRUKTUR DATA 2025 PAKET ABC.pdf
└── Penjelasan Soal/                  (LEARNING GUIDES - START HERE!)
    ├── UTS STRUKTUR DATA 2023 - Fix.md
    ├── UTS STRUKTUR DATA 2024 - Fix.md
    └── UTS STRUKTUR DATA 2025 - Fix.md
```

---

## Panduan Cepat

| Tipe Pengguna | Mulai Dari | Tujuan |
|---|---|---|
| **Pemula** | 2025 - Fix.md | Dasar SLL vs DLL |
| **Intermediate** | 2024 - Fix.md | Implementasi modular |
| **Advanced** | 2023 - Fix.md | Problem solving |
| **Latihan** | Folder Soal UTS | Practice dengan soal asli |

---

## Topik Utama

### Double Linked List (DLL)
- 2 pointer: `prev` dan `next`
- Operasi: insertFirst, insertLast, insertAfter
- Fleksibel, bisa traversal 2 arah

### Single Linked List (SLL)
- 1 pointer: `next` saja
- Operasi: insertFirst, insertLast, insertAfter
- Lebih sederhana, hemat memori

### Stack (2023-2024 only)
- Prinsip LIFO (Last In First Out)
- Operasi: push, pop, peek
- **Catatan**: Tidak ada di UTS 2025

---

## Evolusi UTS: 2023 → 2025

| Aspek | 2023 | 2024 | 2025 |
|---|---|---|---|
| **Pendekatan** | Problem Solving | Step-by-step Modular | Multi-Packet |
| **Focus** | DLL + Stack | DLL + Stack | **SLL vs DLL** |
| **Soal Variasi** | 1 versi | 1 versi | **3 versi** (A,B,C) |
| **Tingkat** | Medium | Medium-High | High |

**⚠️ 2025 Update**: Stack dihilangkan sepenuhnya. Fokus penuh pada SLL vs DLL dengan sistem 3 paket.

---

## Konten File Penjelasan Soal

### **2023 - Problem Solving Approach**

**Soal 1** - DLL Analysis (80 poin)
- Input: 5, 10, 8, 7, 3 → Output: 10, 7, 5, 8, 3
- Tentukan sendiri operasi insert mana yang digunakan
- Belajar: Analisis alur berpikir sistematis

**Soal 2** - Stack Teori (20 poin)
- Stack Overflow, definisi struktur

---

### **2024 - Modular Coding Approach**

**Soal 1** - DLL Implementation (80 poin)
- 7 sub-poin terstruktur:
  - 1a: struct Node (prev, data, next)
  - 1b: buatNode()
  - 1c: insertFirst()
  - 1d: insertLast()
  - 1e: insertAfter() - **4 pointer, urutan CRITICAL**
  - 1f: cetakList()
  - 1g: main()

**Skenario**: insertFirst(40) → insertFirst(50) → insertLast(30) → insertAfter(head, 90)

**Soal 2** - Stack Implementation (30 poin)
- 2a: Perbedaan SLL vs Stack
- 2b: Struktur Stack (array + top)
- 2c: push() dan pop() dengan error handling

---

### **2025 - Multi-Packet System**

**Soal 1** - SLL vs DLL Comparison (semua paket)

| Aspek | SLL | DLL |
|---|---|---|
| Pointer per node | 1 (`next`) | 2 (`prev` + `next`) |
| Traversal | Satu arah | Dua arah |
| Memori | Hemat | Boros |
| Kompleksitas | Sederhana | Kompleks |
| Kegunaan | Antrian | Browser history, undo/redo |

**Soal 2** - 3 Paket Implementasi:

| Paket | Tipe | Fitur Khusus |
|---|---|---|
| **A** | DLL | insertFirst + insertLast (3 step each) |
| **B** | SLL | insertFirst + insertLast (2 step each) |
| **C** | SLL | insertFirst + insertLast + **insertAfter** |

**Paket A Output**: `NULL <- [40] <-> [20] <-> [30] <-> [10] -> NULL`
**Paket B Output**: `[40] -> [20] -> [30] -> [10] -> NULL`
**Paket C Output**: `[20] -> [40] -> [30] -> [10] -> NULL`

---

## Konsep Kunci

### Alur Berpikir Sistematis
```
Pahami Konteks → Visualisasi → Identifikasi Perubahan → 
Tentukan Urutan → Implementasi
```

### GOLDEN RULE: Urutan Pointer

**SALAH**: Putuskan pointer lama dulu
```c
target->next = baru;  // Referensi ke node setelahnya HILANG!
baru->next = ???      // Tidak ada data!
```

**BENAR**: Sambungkan ke node baru dulu
```c
baru->next = target->next;         // Simpan referensi
baru->prev = target;               // Sambung ke sebelah kiri
target->next->prev = baru;         // Update prev pointer
target->next = baru;               // Terakhir!
```

### Operasi Quick Reference

| Operasi | DLL (langkah) | SLL (langkah) |
|---|---|---|
| insertFirst | 3 (next, prev, update head) | 2 (next, update head) |
| insertLast | 3 (prev, next, update tail) | 2 (next, update tail) |
| insertAfter | 4 (next, prev, prev of next, next) | 2 (next of new, next of target) |

---

## Cara Menggunakan

### Step 1: Pelajari Materi
```bash
# Mulai dari yang terbaru untuk pemahaman terdepan
# Buka: Penjelasan Soal/UTS STRUKTUR DATA 2025 - Fix.md
```

### Step 2: Template Coding
```c
#include <stdio.h>
#include <stdlib.h>

// 1. Struct Node
struct Node {
    int data;
    struct Node* prev;   // hanya untuk DLL
    struct Node* next;
};

// 2-5. Implementasi fungsi sesuai guide
// (buatNode, insertFirst, insertLast, insertAfter, cetakList)

// 6. Main - orchestration skenario soal
int main() {
    // Jalankan skenario sesuai soal
    return 0;
}
```

### Step 3: Latihan dengan Soal Asli
Buka folder `Soal UTS 2023 - 2025/`

---

## Quick Reference Links

| Materi | File | Fokus |
|---|---|---|
| Theory + Problem Solving | Penjelasan Soal/UTS STRUKTUR DATA 2023 - Fix.md | Analisis alur berpikir |
| Modular Implementation | Penjelasan Soal/UTS STRUKTUR DATA 2024 - Fix.md | Coding step-by-step |
| Latest + Multi-Packet | Penjelasan Soal/UTS STRUKTUR DATA 2025 - Fix.md | SLL vs DLL comprehensive |
| Practice Soal | Soal UTS 2023 - 2025/\*.pdf | Real exam problems |

---

## Learning Checklist

- [ ] Pahami perbedaan SLL vs DLL dari tabel perbandingan
- [ ] Visualisasikan pointer movements dalam insertAfter (DLL)
- [ ] Tahu kenapa step 1 insertAfter harus `baru->next = target->next` duluan
- [ ] Bisa identifikasi overhead pointer vs memory efficiency trade-off
- [ ] Implementasi DLL module: struct → buatNode → insert → print
- [ ] Implementasi SLL module dengan insertAfter logic
- [ ] Bandingkan 3-step (DLL) vs 2-step (SLL) di setiap operasi
- [ ] Praktik minimal 1 soal dari setiap tahun

---

## Common Mistakes

| Masalah | Penyebab | Solusi |
|---|---|---|
| Pointer hilang di insertAfter | Ubah `target->next` sebelum save | Step 1: `baru->next = target->next` dulu |
| HEAD/TAIL tidak terupdate | Lupa assignment akhir | Update head/tail SETELAH sambung pointer |
| Output format salah | DLL pakai `->` bukan `<->` | Gunakan `<->` untuk menunjukkan 2 arah |
| Memory leak | malloc tanpa free | Selalu balance malloc dengan free di akhir |

---

## Key Takeaways

1. **Pointer order matters** - urutan sambung pointer CRITICAL
2. **SLL lebih simpel dari DLL** - 1 pointer vs 2 pointer
3. **Multi-packet 2025** - pahami trade-off per paket
4. **Consistent step-by-step** - struktur modular membuat debug mudah
5. **Visualisasi sebelum code** - gambar pointer lebih jelas dari code

---

**For ISC Students | Struktur Data Semester 2 | Learn, Practice, Master**
