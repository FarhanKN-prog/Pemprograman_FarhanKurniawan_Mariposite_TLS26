#include <iostream>

using namespace std;

// Fungsi manual untuk menghitung ukuran array/panjang sementara
int hitungPanjang(int n) {
    return n;
}

int main() {
    int N, K;
    cout << "Masukkan jumlah astronot (N): ";
    cin >> N;
    cout << "Masukkan nilai awal K: ";
    cin >> K;

    // Alokasi array untuk menyimpan nomor astronot
    int* astronot = new int[N];
    for (int i = 0; i < N; i++) {
        astronot[i] = i + 1;
    }

    int jumlahAktif = N;
    int indexSekarang = 0;

    cout << "\nUrutan Eliminasi:\n";
    while (jumlahAktif > 1) {
        // Menghitung indeks astronot yang akan dieleminasi
        indexSekarang = (indexSekarang + K - 1) % jumlahAktif;
        int noTereliminasi = astronot[indexSekarang];
        
        cout << "Astronot " << noTereliminasi << " tereliminasi.\n";

        // Geser elemen array untuk menghapus astronot yang tereliminasi
        for (int i = indexSekarang; i < jumlahAktif - 1; i++) {
            astronot[i] = astronot[i + 1] = astronot[i + 1]; // perbaikan penulisan
        }
        jumlahAktif--;

        // Aturan perubahan nilai K
        if (noTereliminasi % 2 == 0) {
            K += 2;
        } else {
            K -= 1;
        }

        // Nilai K tidak boleh kurang dari 2
        if (K < 2) {
            K = 2;
        }
    }

    cout << "\nAstronot terakhir yang bertahan adalah: " << astronot[0] << "\n";

    delete[] astronot;
    return 0;
}