#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// ==========================================
// ==========================================
// Struktur Data Utama untuk menampung objek Siswa & Nilai Akademik
struct Siswa {
    string nis;
    string nama;
    string kelas;
    string mataPelajaran;
    int nilai;
};

// ==========================================
// KONTRIBUSI: FABIAN TAUFIQURRAHMAN (TAMPIL DATA)
// ==========================================
// Fungsi pendukung untuk menampilkan header tabel yang rapi
void tampilkanHeaderTabel() {
    cout << "\n" << setfill('=') << setw(65) << "=" << endl;
    cout << setfill(' ');
    cout << left << setw(10) << "NIS" 
         << setw(20) << "Nama Siswa" 
         << setw(10) << "Kelas" 
         << setw(18) << "Mata Pelajaran" 
         << setw(7) << "Nilai" << endl;
    cout << setfill('-') << setw(65) << "-" << endl;
    cout << setfill(' ');
}

// Fungsi untuk menampilkan seluruh data siswa akademik
void tampilkanSemuaSiswa(const vector<Siswa>& daftarSiswa) {
    if (daftarSiswa.empty()) {
        cout << "\n[Peringatan] Belum ada data akademik yang tersimpan.\n";
        return;
    }
    
    tampilkanHeaderTabel();
    for (size_t i = 0; i < daftarSiswa.size(); i++) {
        cout << left << setw(10) << daftarSiswa[i].nis 
             << setw(20) << daftarSiswa[i].nama 
             << setw(10) << daftarSiswa[i].kelas 
             << setw(18) << daftarSiswa[i].mataPelajaran 
             << setw(7) << daftarSiswa[i].nilai << endl;
    }
    cout << setfill('=') << setw(65) << "=" << endl;
}
