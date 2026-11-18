#include <iostream>
#include <vector>
#include <limits>

using namespace std;

bool adaPasangan(const vector<pair<int, int>> relasi, int x, int y)
{
    for (size_t i = 0; i < relasi.size(); i++)
    {
        if (relasi[i].first == x && relasi[i].second == y)
        {
            return true;
        }
    }

    return false;
}

bool adaElemen(const vector<int> himpunan, int x)
{
    for (size_t i = 0; i < himpunan.size(); i++)
    {
        if (himpunan[i] == x)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    // Variabel data elemen himpunan dan pasangan relasi
    int n;
    int m;

    // Input data nilai himpunan
    cout << "jumlah nilai n: ";
    cin >> n;
    // while (cin.fail() || n < 0) {
    //     cout << "Input Tidak Valid" << endl;
    //     cin.clear();
    //     cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //     cin >> n;
    // }

    vector<int> himpunan;

    // Perulangan Himpunan
    for (size_t i = 0; i < n; i++)
    {
        int x;

        cout << "Elemen ke-" << i + 1 << ": ";
        cin >> x;
        if (adaElemen(himpunan, x))
        {
            cout << "Elemen sudah ada, dilewati" << endl;
        }
        else
        {
            himpunan.push_back(x);
        }

    }


    // Input Pasangan relasi
    cout << "Jumlah Pasangan: ";
    cin >> m;
    //     while (cin.fail() || m < 0) {
    //     cout << "Input Tidak Valid" << endl;
    //     cin.clear();
    //     cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //     cin >> m;
    // }

    vector<pair<int, int>> relasi;

    // Perulangan Relasi
    for (size_t i = 0; i < m; i++)
    {
        int x, y;

        cout << "Pasangan ke-" << i + 1 << ": ";
        cin >> x >> y;
        if (!adaElemen(himpunan,x) || !adaElemen(himpunan,y))
        {
            cout << "Input Elemen Tidak Ditemukan!" << endl;
        }
        else if (adaPasangan(relasi, x, y))
        {
            cout << "Pasangan sudah ada, dilewati" << endl;
        }
        else
        {
            relasi.push_back({x, y});
        }

    }

    // Output Hasil Cetak Himpunan
    cout << "Hasil dari Himpunan tersebut adalah: {";

    for (size_t i = 0; i < himpunan.size(); i++)
    {
        if (i > 0)
        {
            cout << ", ";
        }

        cout << himpunan[i];
    }

    cout << "}" << endl;

    // Output Hasil Cetak Relasi
    cout << "Relasi R: {";

    for (size_t i = 0; i < relasi.size(); i++)
    {
        if (i > 0)
        {
            cout << ", ";
        }

        cout << "(" << relasi[i].first << "," << relasi[i].second << ")";
    }

    cout << "}" << endl;

    // Logika Relasi
    bool refleksif = true;

    for (size_t i = 0; i < himpunan.size(); i++)
    {
        int x = himpunan[i];

        if (!adaPasangan(relasi, x, x))
        {
            refleksif = false;
        }
    }
    cout << "Apakah Relasi R Bersifat Refleksif: ";
    if (refleksif)
    {
        cout << "Ya" << endl;
    }
    else
    {
        cout << "Tidak" << endl;
    }

    bool simetris = true;

    for (size_t i = 0; i < relasi.size(); i++)
    {
        int x = relasi[i].first;
        int y = relasi[i].second;

        if (!adaPasangan(relasi, y, x))
        {
            simetris = false;
        }
    }
    cout << "Apakah Relasi R Bersifat Simetris: ";
    if (simetris)
    {
        cout << "Ya" << endl;
    }
    else
    {
        cout << "Tidak" << endl;
    }

    bool transitif = true;

    for (size_t i = 0; i < relasi.size(); i++)
    {
        int a = relasi[i].first;
        int b = relasi[i].second;

        for (size_t j = 0; j < relasi.size(); j++)
        {
            int c = relasi[j].first;
            int d = relasi[j].second;

            if (b == c)
            {
                if (!adaPasangan(relasi, a, d))
                {
                    transitif = false;
                }
            }
        }
    }
    cout << "Apakah Relasi R Bersifat Transitif: ";
    if (transitif)
    {
        cout << "Ya" << endl;
    }
    else
    {
        cout << "Tidak" << endl;
    }

    return 0;
}