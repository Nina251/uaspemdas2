#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    string jurusan;
    string ipk;
    
};

class DataMahasiswa {
private:
    vector<Mahasiswa> daftarMahasiswa;

public:
    void tambahMahasiswa() {
        Mahasiswa mhs;
        cout << "Masukkan Nama: ";
        cin.ignore(); // Mengabaikan newline sebelumnya
        getline(cin, mhs.nama);
        cout << "Masukkan NIM: ";
        cin >> mhs.nim;
        cout << "Masukkan Jurusan: ";
        cin.ignore(); // Mengabaikan newline sebelumnya
        getline(cin, mhs.jurusan);
        cout << "Masukkan IPK: ";
        cin.ignore(); // Mengabaikan newline sebelumnya
        getline(cin, mhs.ipk);
        
        daftarMahasiswa.push_back(mhs);
        cout << "Data mahasiswa berhasil ditambahkan!\n";
    }

    void tampilkanMahasiswa() {
        if (daftarMahasiswa.empty()) {
            cout << "Tidak ada data mahasiswa.\n";
            return;
        }
        
        cout << "\nDaftar Mahasiswa:\n";
        for (size_t i = 0; i < daftarMahasiswa.size(); ++i) {
            const Mahasiswa& mhs = daftarMahasiswa[i];
            cout << "Nama: " << mhs.nama 
                 << ", NIM: " << mhs.nim
				 << "Jurusan: " << mhs.jurusan 
                 << ", IPK: " << mhs.ipk << endl;
        }
    }

    void cariMahasiswa() {
        string nimCari;
        cout << "Masukkan NIM yang dicari: ";
        cin >> nimCari;

        bool ditemukan = false;
        for (size_t i = 0; i < daftarMahasiswa.size(); ++i) {
            const Mahasiswa& mhs = daftarMahasiswa[i];
            if (mhs.nim == nimCari) {
                cout << "Data Ditemukan:\n";
                cout << "Nama: " << mhs.nama 
                     << ", NIM: " << mhs.nim 
                     << "Jurusan: " << mhs.jurusan
                     << ", IPK: " << mhs.ipk << endl;
                ditemukan = true;
                break;
            }
        }
        
        if (!ditemukan) {
            cout << "Data mahasiswa dengan NIM " << nimCari << " tidak ditemukan.\n";
        }
    }
};

int main() {
    DataMahasiswa data;
    int pilihan;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Mahasiswa\n";
        cout << "2. Tampilkan Mahasiswa\n";
        cout << "3. Cari Mahasiswa\n";
        cout << "4. Keluar\n";
        cout << "Pilih opsi (1-4): ";
        
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                data.tambahMahasiswa();
                break;
            case 2:
                data.tampilkanMahasiswa();
                break;
            case 3:
                data.cariMahasiswa();
                break;
            case 4:
                cout << "Terima kasih! Sampai jumpa.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }
    } while (pilihan != 4);

    // Menunggu pengguna menekan tombol sebelum keluar
    cout << "\nTekan sembarang tombol untuk melanjutkan...";
    cin.ignore(); // Mengabaikan newline sebelumnya jika ada
    cin.get(); // Menunggu input dari pengguna

    return 0;
}
