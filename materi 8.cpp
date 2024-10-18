#include <iostream>
#include <string>
using namespace std;

struct Zodiak {
    string nama;
    int startDay, startMonth;
    int endDay, endMonth;
};

void isiDataZodiak(Zodiak zodiak[]) {
    zodiak[0] = {"CAPRICORN", 22, 12, 19, 1};
    zodiak[1] = {"AQUARIUS", 20, 1, 18, 2};
    zodiak[2] = {"PISCES", 19, 2, 20, 3};
    zodiak[3] = {"ARIES", 21, 3, 19, 4};
    zodiak[4] = {"TAURUS", 20, 4, 20, 5};
    zodiak[5] = {"GEMINI", 21, 5, 20, 6};
    zodiak[6] = {"CANCER", 21, 6, 22, 7};
    zodiak[7] = {"LEO", 23, 7, 22, 8};
    zodiak[8] = {"VIRGO", 23, 8, 22, 9};
    zodiak[9] = {"LIBRA", 23, 9, 22, 10};
    zodiak[10] = {"SCORPIO", 23, 10, 21, 11};
    zodiak[11] = {"SAGITTARIUS", 22, 11, 21, 12};
}

string tentukanZodiak(int day, int month, Zodiak zodiak[], int size) {
    for (int i = 0; i < size; i++) {
        if ((month == zodiak[i].startMonth && day >= zodiak[i].startDay) ||
            (month == zodiak[i].endMonth && day <= zodiak[i].endDay)) {
            return zodiak[i].nama;
        }
    }
    return "Tidak Diketahui";
}

void displayData(string zodiak, int day, int month, int year) {
    cout << "\nInformation" << endl;
    cout << "Tanggal Lahir Anda: " << day << "-" << month << "-" << year << endl;
    cout << "Zodiak Anda adalah: " << zodiak << endl;
}

int main() {
    const int JUMLAH_ZODIAK = 12;
    Zodiak daftarZodiak[JUMLAH_ZODIAK];

    isiDataZodiak(daftarZodiak);

    int day, month, year;

    cout << "Masukkan Tanggal Lahir Anda [tgl-bln-tahun] (contoh: 24-12-1970): ";
    char delimiter; // variabel untuk membaca '-' pada format input
    cin >> day >> delimiter >> month >> delimiter >> year;

    string zodiak = tentukanZodiak(day, month, daftarZodiak, JUMLAH_ZODIAK);

    displayData(zodiak, day, month, year);

    return 0;
}
