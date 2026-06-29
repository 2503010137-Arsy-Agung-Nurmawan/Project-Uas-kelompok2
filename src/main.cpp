// ==========================================
// KONTRIBUSI: RANDHAN HIDAYAT (ALGORITMA SORTING-SELESAI)
// ==========================================
// Mengurutkan data berdasarkan NIS secara Ascending menggunakan Bubble Sort
void urutkanSiswaByNIS(vector<Siswa>& daftarSiswa) {
    int n = daftarSiswa.size();
    if (n <= 1) return;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Membandingkan string NIS secara alfabetis / numerik
            if (daftarSiswa[j].nis > daftarSiswa[j + 1].nis) {
                // Proses Tukar Posisi Data (Swap)
                Siswa temp = daftarSiswa[j];
                daftarSiswa[j] = daftarSiswa[j + 1];
                daftarSiswa[j + 1] = temp;
            }
        }
    }
    cout << "\n[Sukses] Data akademik berhasil diurutkan berdasarkan NIS (Ascending)!\n";
}
