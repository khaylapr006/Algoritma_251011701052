#include <iostream>
#include <iomanip>
using namespace std;

//STRUCT DATA PEGAWAI
struct Pegawai {
    string nama;
    int jamKerja;
    int honor;
    int honorLembur;
    int total;
};

//CLASS HITUNG GAJI
class Gaji {
public:
    void hitung (Pegawai &p) {
        p.honor = 25000;

        if (p.jamKerja > 8) {
            p.honorLembur = (p.jamKerja - 8) * 1500;
        } else {
            p.honorLembur = 0;
        }

        p.total = p.honor + p.honorLembur;
    }
};

int main () {
    int menu;
    char ulang;

    do{
        cout << "\n========== MENU UTAMA ===========\n";
        cout << "1. Input & Tampilkan Gaji Pegawai\n";
        cout << "2. Keluar\n";
        cout << "Pilih Menu :";
        cin >> menu;

        while (menu < 1 || menu > 2) {
            cout <<"Menu tidak valid! Pilih lagi:";
            cin >> menu;
        }

        if (menu == 1){
            int n;
            cout << "\nMasukan jumlah pegawai:";
            cin >> n;

        //ARRAY DINAMIS+POINTER
        Pegawai *pegawai = new Pegawai [n];
        Gaji gaji;
        int totalSemua = 0;

        for (int i = 0; i < n; i++) {
            cout << "\nPegawai ke-" << i+1 << endl;
            cout << "Nama        : ";
            cin >> pegawai[i].nama;
            cout << "Jam Kerja   : ";
            cin >> pegawai[i].jamKerja;
            
            
            gaji.hitung(pegawai[i]);
            totalSemua += pegawai[i].total;
        }
        //OUTPUT TABEL
        cout << "\n======================= PT.MENCARI BERKAH =======================\n";
        cout << "Tanggal : 12 Januari 2026\n";
        cout << "=================================================================\n";
        cout << left << setw(5) << "No"
             << setw(15) << "Nama"
             << setw(10) << "Honor"
             << setw(10) << "Jam"
             << setw(15) << "Lembur"
             << setw(10) << "Total" << endl;
        cout << "=================================================================\n";

        for (int i = 0; i < n; i++) {
            cout << left << setw(5) << i+1
                 << setw(15) << pegawai[i].nama
                 << setw(10) << pegawai[i].honor
                 << setw(10) << pegawai[i].jamKerja
                 << setw(15) << pegawai[i].honorLembur
                 << setw(10) << pegawai[i].total << endl;
        }

        cout << "=================================================================\n";
        cout << "Total Honor Pegawai Sebesar : Rp" << totalSemua << endl;

        delete[] pegawai ; //menghapus memori dinamis

        }

        cout << "\nKembali ke menu? (Iya/Tidak):";
        cin >> ulang;

    } while (ulang == 'y' || ulang == 'Y');

    cout << "\nProgram selesai.\n";
    return 0;
}
