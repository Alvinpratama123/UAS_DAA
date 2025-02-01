#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

void cetakBuku(string* buku, int jumlah) {
    for (int i = 0; i < jumlah; i++) {
        cout << buku[i] << " ";
    }
    cout << endl;
}

int main() {
    string input;
    cout << "Masukan nama buku: ";
    getline(cin, input);

    // Memisahkan nama-nama buku yang dipisahkan oleh spasi
    stringstream ss(input);
    string namaBuku;
    int jumlah = 0;

    // Menghitung jumlah buku
    while (ss >> namaBuku) {
        jumlah++;
    }

    // Mengalokasikan array dinamis untuk nama-nama buku
    string* buku = new string[jumlah];
    string* ptr; // Variabel pointer untuk menunjuk ke elemen dalam array buku

    // Mengisi array buku
    ss.clear();
    ss.str(input);
    int index = 0;
    while (ss >> namaBuku) {
        ptr = &buku[index]; // Menggunakan pointer untuk mengakses elemen array
        *ptr = namaBuku;
        index++;
    }

    // Menampilkan nama buku menggunakan pointer
    cout << "Nama buku pointer *a : ";
    cetakBuku(buku, jumlah);

    // Memodifikasi nama buku
    for (int i = 0; i < jumlah; i++) {
        ptr = &buku[i]; // Menggunakan pointer untuk mengakses elemen array
        // Modifikasi: menambahkan spasi setelah nama "buku"
        size_t pos = ptr->find("buku");
        if (pos != string::npos) {
            ptr->insert(pos + 4, " ");
        }
    }

    // Menampilkan nama buku setelah modifikasi
    cout << "Buku setelah di modifikasi: ";
    cetakBuku(buku, jumlah);

    // Mengurutkan nama buku
    sort(buku, buku + jumlah);

    // Menampilkan nama buku setelah diurutkan
    cout << "Nama buku pointer *a setelah di urutkan : ";
    cetakBuku(buku, jumlah);

    // Modifikasi kedua: mengganti nama buku
    for (int i = 0; i < jumlah; i++) {
        ptr = &buku[i]; // Menggunakan pointer untuk mengakses elemen array
        *ptr = "buku" + to_string(i + 4); // Mengganti nama buku menjadi buku4, buku5, buku6, dst.
    }

    // Menampilkan nama buku setelah modifikasi kedua
    cout << "Buku setelah di modifikasi: ";
    cetakBuku(buku, jumlah);

    // Menampilkan nama buku menggunakan pointer lagi setelah modifikasi kedua
    cout << "Nama buku pointer *a : ";
    cetakBuku(buku, jumlah);

    // Membersihkan memori yang dialokasikan
    delete[] buku;

    return 0;
}
