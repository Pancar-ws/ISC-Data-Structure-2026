# ISC-Data-Structure-2026

Repositori ini berisi kumpulan materi belajar, penjelasan soal, dan implementasi kode untuk persiapan UTS Struktur Data ISC 2026.

---

## 📁 Struktur Repositori

```
ISC-Data-Structure-2026/
├── Penjelasan Soal/          # Pembahasan soal UTS per tahun (Markdown)
│   ├── UTS STRUKTUR DATA 2023 - Fix.md
│   ├── UTS STRUKTUR DATA 2024 - Fix.md
│   └── UTS STRUKTUR DATA 2025 - Fix.md
├── Soal UTS 2023 - 2025/     # File PDF soal asli UTS
│   ├── 2023 UTS Strukdat.pdf
│   ├── 2024 UTS Strukdat.pdf
│   └── STRUKTUR DATA 2025 PAKET ABC.pdf
└── Implementasi Kode/        # Kode C siap kompilasi & jalankan
    ├── 2023_DLL.c            # Double Linked List — skenario UTS 2023
    ├── 2024_DLL.c            # Double Linked List — skenario UTS 2024
    ├── 2024_Stack.c          # Stack (push, pop) — skenario UTS 2024
    ├── 2025_PaketA_DLL.c     # Double Linked List — Paket A UTS 2025
    ├── 2025_PaketB_SLL.c     # Single Linked List — Paket B UTS 2025
    └── 2025_PaketC_SLL.c     # Single Linked List + insertAfter — Paket C UTS 2025
```

---

## 📖 Penjelasan Soal

| Tahun | Topik Utama | Link |
|-------|-------------|------|
| 2023  | Double Linked List (problem solving) + Stack (teori) | [Buka →](Penjelasan%20Soal/UTS%20STRUKTUR%20DATA%202023%20-%20Fix.md) |
| 2024  | Double Linked List (bangun dari nol) + Stack (push & pop) | [Buka →](Penjelasan%20Soal/UTS%20STRUKTUR%20DATA%202024%20-%20Fix.md) |
| 2025  | SLL vs DLL + Multi-Paket (A/B/C) | [Buka →](Penjelasan%20Soal/UTS%20STRUKTUR%20DATA%202025%20-%20Fix.md) |

---

## 💻 Cara Menjalankan Kode

Pastikan sudah menginstall **GCC** (compiler C). Masuk ke folder `Implementasi Kode` lalu kompilasi dan jalankan:

```bash
cd "Implementasi Kode"

# Contoh: menjalankan kode DLL 2023
gcc 2023_DLL.c -o output && ./output

# Contoh: menjalankan kode Stack 2024
gcc 2024_Stack.c -o output && ./output
```

---

## 🗂️ Ringkasan Topik per Tahun

### 2023 — Problem Solving
- **Double Linked List**: diberi input 5, 10, 8, 7, 3 → output harus 10, 7, 5, 8, 3. Tentukan operasi insert yang tepat.
- **Stack**: definisi Stack Overflow dan struktur Stack.

### 2024 — Bangun dari Nol
- **Double Linked List**: struct, buatNode, insertFirst, insertLast, insertAfter, print, main.
- **Stack**: perbedaan Stack vs SLL, struktur Stack, fungsi push & pop.

### 2025 — Multi-Paket (SLL vs DLL)
- **Paket A** (DLL): insertLast × 3 + insertFirst
- **Paket B** (SLL): insertLast × 3 + insertFirst
- **Paket C** (SLL): insertLast × 3 + insertAfter