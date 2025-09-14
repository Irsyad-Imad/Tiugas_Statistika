#include <iostream>
#include <iomanip> // Diperlukan untuk std::fixed dan std::setprecision
using namespace std;

int main (){
    // Data harus dalam keadaan terurut untuk perhitungan median dan kuartil
    int data_tunggal[15] = {2, 3, 3, 5, 5, 5, 7, 7, 8, 9, 9, 11, 11, 12, 13};

    int length = sizeof(data_tunggal) / sizeof(data_tunggal[0]);

    // --- 1. Mean (Rata-rata) ---
    int sum = 0;
    for(int i = 0; i < length; i++){
        sum += data_tunggal[i];
    }
    float rata_rata = (float)sum / (float)length;
    cout << "Mean (Rata-rata)   : " << fixed << setprecision(2) << rata_rata << endl;

    // --- 2. Median (Nilai Tengah) ---
    // Data sudah diurutkan, kita bisa cari nilai tengah.
    float median;
    // Jika jumlah data ganjil, median adalah nilai di tengah
    if (length % 2 != 0) {
        median = data_tunggal[length / 2];
    } else {
        // Jika jumlah data genap, median adalah rata-rata dari dua nilai di tengah
        median = (float)(data_tunggal[(length / 2) - 1] + data_tunggal[length / 2]) / 2.0;
    }
    cout << "Median             : " << median << endl;

    // --- 3. Modus (Nilai yang Paling Sering Muncul) ---
    int modus = data_tunggal[0];
    int max_count = 0;
    int current_count = 1;

    for (int i = 1; i < length; i++) {
        if (data_tunggal[i] == data_tunggal[i - 1]) {
            current_count++;
        } else {
            if (current_count > max_count) {
                max_count = current_count;
                modus = data_tunggal[i - 1];
            }
            current_count = 1; // Reset hitungan untuk angka baru
        }
    }
    // Pengecekan terakhir untuk kasus modus ada di akhir data
    if (current_count > max_count) {
        modus = data_tunggal[length - 1];
    }
    cout << "Modus              : " << modus << endl;

    // --- 4. Kuartil ---
    // Rumus posisi untuk data tunggal: Kuartil i = data ke i*(n+1)/4
    // Index array dimulai dari 0, jadi posisi dikurangi 1.
    float q1 = data_tunggal[(length + 1) / 4 - 1];
    float q2 = median; // Kuartil 2 selalu sama dengan median
    float q3 = data_tunggal[3 * (length + 1) / 4 - 1];
    cout << "Kuartil 1 (Q1)     : " << q1 << endl;
    cout << "Kuartil 2 (Q2)     : " << q2 << endl;
    cout << "Kuartil 3 (Q3)     : " << q3 << endl;
    return 0;
}