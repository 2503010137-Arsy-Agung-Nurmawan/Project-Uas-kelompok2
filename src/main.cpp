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

// ==========================================
// KONTRIBUSI: RANDHAN HIDAYAT (ALGORITMA SORTING)
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

// ==========================================
// KONTRIBUSI: RAKA BRAWIJAYA (ALGORITMA SEARCHING)
// ==========================================
// Mencari data siswa berdasarkan kriteria NIS menggunakan Linear Search
int cariSiswaByNIS(const vector<Siswa>& daftarSiswa, string nisCari) {
    for (size_t i = 0; i < daftarSiswa.size(); i++) {
        if (daftarSiswa[i].nis == nisCari) {
            return i; // Mengembalikan indeks elemen jika ditemukan
        }
    }
    return -1; // Mengembalikan -1 jika data tidak ada
}

// ==========================================
// ==========================================
int main() {
    // Menggunakan gaya C++98 agar aman di semua versi Dev-C++ lama
    vector<Siswa> daftarSiswa;
    
    // Inisialisasi Data Awal (Dummy Data Anggota Kelompok 2)
    Siswa s1 = {"1004", "Raka Brawijaya", "10-A", "Struktur Data", 78};
    Siswa s2 = {"1001", "Fabian Taufiqurrahman", "10-B", "Struktur Data", 85};
    Siswa s3 = {"1003", "Randhan Hidayat", "10-A", "Struktur Data", 92};
    Siswa s4 = {"1002", "Arsy Agung Nurmawan", "10-B", "Struktur Data", 89};
    
    daftarSiswa.push_back(s1);
    daftarSiswa.push_back(s2);
    daftarSiswa.push_back(s3);
    daftarSiswa.push_back(s4);

    int pilihan;
    string nisCari;

    do {
        cout << "\n==================================================\n";
        cout << "         SISTEM AKADEMIK SEDERHANA (KELOMPOK 2)    \n";
        cout << "==================================================\n";
        cout << "1. Tambah Data Akademik Siswa\n";
        cout << "2. Tampilkan Semua Data Siswa\n";
        cout << "3. Urutkan Data Akademik Berdasarkan NIS\n";
        cout << "4. Cari Data Akademik Siswa Berdasarkan NIS\n";
        cout << "5. Keluar Aplikasi\n";
        cout << "--------------------------------------------------\n";
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                Siswa siswaBaru;
                cout << "\n--- INPUT DATA SISWA BARU ---\n";
                cout << "Masukkan NIS   : "; cin >> siswaBaru.nis;
                cin.ignore(); // Membersihkan buffer input
                cout << "Masukkan Nama  : "; getline(cin, siswaBaru.nama);
                cout << "Masukkan Kelas : "; cin >> siswaBaru.kelas;
                cin.ignore();
                cout << "Mata Pelajaran : "; getline(cin, siswaBaru.mataPelajaran);
                cout << "Masukkan Nilai : "; cin >> siswaBaru.nilai;
                
                daftarSiswa.push_back(siswaBaru);
                cout << "\n[Sukses] Data akademik siswa berhasil ditambahkan ke sistem!\n";
                break;
            }
            case 2:
                tampilkanSemuaSiswa(daftarSiswa);
                break;
            case 3:
                urutkanSiswaByNIS(daftarSiswa);
                tampilkanSemuaSiswa(daftarSiswa);
                break;
            case 4:
                cout << "\nMasukkan NIS Siswa yang ingin dicari: ";
                cin >> nisCari;
                {
                    int indeks = cariSiswaByNIS(daftarSiswa, nisCari);
                    if (indeks != -1) {
                        cout << "\n[Data Akademik Ditemukan!]\n";
                        cout << "---------------------------------\n";
                        cout << "NIS            : " << daftarSiswa[indeks].nis << "\n";
                        cout << "Nama           : " << daftarSiswa[indeks].nama << "\n";
                        cout << "Kelas          : " << daftarSiswa[indeks].kelas << "\n";
                        cout << "Mata Pelajaran : " << daftarSiswa[indeks].mataPelajaran << "\n";
                        cout << "Nilai Akhir    : " << daftarSiswa[indeks].nilai << "\n";
                        cout << "---------------------------------\n";
                    } else {
                        cout << "\n[Informasi] Data dengan NIS '" << nisCari << "' tidak ditemukan.\n";
                    }
                }
                break;
            case 5:
                cout << "\nTerima kasih! Keluar dari aplikasi akademik...\n";
                break;
            default:
                cout << "\n[Error] Pilihan menu tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 5);

    return 0;
}
