#include <iostream>
#include <vector>

using namespace std;

bool adaPasangan(vector<pair<int, int>> relasi, int x, int y)
{
    for (int i = 0; i < relasi.size(); i++)
    {
        if (relasi[i].first == x && relasi[i].second == y)
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

    vector<int> himpunan;

    // Perulangan Himpunan
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "Elemen ke-" << i + 1 << ": ";
        cin >> x;
        himpunan.push_back(x);
    }

    // Input Pasangan relasi
    cout << "Jumlah Pasangan: ";
    cin >> m;

    vector<pair<int, int>> relasi;

    // Perulangan Relasi
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cout << "Pasangan ke-" << i + 1 << ": ";
        cin >> x >> y;
        relasi.push_back({x, y});
    }

    // Output Hasil Cetak Himpunan
    cout << "Hasil dari Himpunan tersebut adalah: {";

    for (int i = 0; i < himpunan.size(); i++)
    {
        if (i > 0)
        {
            cout << ", ";
        }

        cout << himpunan[i];
    }

    cout << "}" << endl;

    //Output Hasil Cetak Relasi
    cout << "Relasi R: {";

    for (int i = 0; i < relasi.size(); i++) {
        if (i < 0)
        {
            cout << ", ";
        }

        cout << relasi[i].first, relasi[i].second;
    }

    cout << "}" << endl;

    // Logika Relasi
    bool refleksif = true;

    for (int i = 0; i < himpunan.size(); i++)
    {
        int x = himpunan[i];

        if (!adaPasangan(relasi, x, x))
        {
            refleksif = false;
        }
    }
    cout << "Apakah Himpuan R Bersifat Refleksif: " << endl;
    if (refleksif)
    {
        cout << "Ya" << endl;
    }
    else
    {
        cout << "Tidak" << endl;
    }

    bool simetris = true;

    for (int i = 0; i < relasi.size(); i++)
    {
        int x = relasi[i].first;
        int y = relasi[i].second;

        if (!adaPasangan(relasi, y, x))
        {
            simetris = false;
        }
    }
    cout << "Apakah Himpuan R Bersifat Simetris: " << endl;
    if (simetris)
    {
        cout << "Ya" << endl;
    }
    else
    {
        cout << "Tidak" << endl;
    }

    bool transitif = true;

    for (int i = 0; i < relasi.size(); i++)
    {
        int a = relasi[i].first;
        int b = relasi[i].second;

        for (int j = 0; j < relasi.size(); j++)
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
    cout << "Apakah Himpuan R Bersifat Transitif: " << endl;
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