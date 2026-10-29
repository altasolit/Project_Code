#include <iostream>
#include <vector>

using namespace std;

int main() {
    //Variabel data elemen himpunan dan pasangan relasi
    int n;
    int m;

    //Input data nilai himpunan
    cout << "jumlah nilai n: ";
    cin >> n;
    
    vector<int> himpunan;

    //Perulangan Himpunan
    for (int i = 0; i < n; i++) {
        int x;
        cout << "Elemen ke-" << i + 1 << ": ";
        cin >> x ;
        himpunan.push_back(x);
    }

    //Input Pasangan relasi
    cout << "Jumlah Pasangan: ";
    cin >> m;

    vector<pair<int,int>> relasi;

    //Perulangan Relasi
    for (int i = 0; i < m; i++) {
        int x,y;
        cout << "Pasangan ke-" << i + 1 << ": ";
        cin >> x >> y;
        relasi.push_back({x,y});
    }

    //Input Cetak Relasi dan Himpunan
    for (int i = 0; i <= himpunan.size(); i++) {
        cout << himpunan.size();
    }

    //Logika Relasi


    //Output Hasil
    cout << "Hasil dari Himpunan tersebut adalah: " << endl;
    cout << "Apakah Himpuan R Bersifat Refleksif: " << endl;
    cout << "Apakah Himpuan R Bersifat Simetris: " << endl;
    cout << "Apakah Himpuan R Bersifat Transitif: " << endl;

    return 0;

}