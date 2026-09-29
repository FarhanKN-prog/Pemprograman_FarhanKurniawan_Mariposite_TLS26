#include <iostream>

using namespace std;

// Fungsi manual untuk menghitung panjang string tanpa strlen() bawaan
int hitungPanjangString(char str[]) {
    int panjang = 0;
    while (str[panjang] != '\0') {
        panjang++;
    }
    return panjang;
}

// Fungsi manual untuk mengonversi huruf kapital ke nilai posisi alfabet (A=1, ..., Z=26)
int nilaiAlfabet(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 1;
    }
    return 0; // Penanganan spasi atau karakter lain jika ada
}

// Fungsi manual untuk mengonversi nilai angka kembali ke huruf kapital
char karakterAlfabet(int val) {
    while (val > 26) {
        val -= 26;
    }
    while (val < 1) {
        val += 26;
    }
    return (val - 1) + 'A';
}

int main() {
    // Menggunakan array karakter dengan batasan maksimal panjang teks
    char pesan[100];
    cout << "Masukkan pesan asli (huruf kapital): ";
    cin >> pesan;

    int panjang = hitungPanjangString(pesan);
    if (panjang == 0) return 0;

    char hasilSandi[100];
    
    // Karakter pertama tidak mengalami perubahan
    hasilSandi[0] = pesan[0];
    int valSebelumnya = nilaiAlfabet(pesan[0]);

    for (int i = 1; i < panjang; i++) {
        int valSekarang = nilaiAlfabet(pesan[i]);
        
        // Perhitungan sandi: digeser sebanyak nilai dari huruf sebelumnya
        int valBaru = valSekarang + valSebelumnya;
        
        hasilSandi[i] = karakterAlfabet(valBaru);
        
        // Simpan nilai huruf saat ini untuk menjadi penggeser huruf berikutnya
        valSebelumnya = valSekarang;
    }
    hasilSandi[panjang] = '\0'; // Menutup string

    cout << "Pesan setelah disandi: " << hasilSandi << "\n";

    return 0;
}