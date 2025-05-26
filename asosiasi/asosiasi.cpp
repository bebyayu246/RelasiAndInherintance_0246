#include <iostream>
#include <vector>
using namespace std;

class dokter;
class pasien 
{
    public:
        string nama;
        vector<dokter*> daftar_dokter;

        pasien(string pNama) :nama(pNama) 
        {
            cout << "Pasien \"" << nama << "\" ada\n";
        }

        ~pasien()
        {
            cout << "Pasien \"" << nama << "\" Tidak Ada\n";
        }

        void TambahkanDokter(dokter*);
        void cetakdokter();
};

class dokter 
{
    public:
        string nama;
        vector<pasien*> daftar_pasien;

        dokter(string pNama) :nama(pNama)
        {
            cout << "Dokter \"" << nama << "\" ada\n";
        }

        ~dokter()
        {
            cout << "Dokter \"" << nama << "\" Tidak ada\n";
        }

        void TambahkanPasien(pasien*);
        void CetakPasien();
};

void pasien::TambahkanDokter(dokter* pDokter)
{
    daftar_dokter.push_back(pDokter);
}

void pasien::cetakdokter()
{
    cout << "Daftar Dokter yang menangani Pasien \"" << this->nama << "\":\n";
    for (auto& a : daftar_dokter)
    {
        cout << a->nama << "\n";
    }
    cout << endl;
};

void dokter::TambahkanPasien(pasien* pPasien)
{
    daftar_pasien.push_back(pPasien);
    pPasien->TambahkanDokter(this);
}

void dokter::CetakPasien()
{
    cout << "Daftar Pasien dari dokter \"" << this->nama << "\":\n";
    for (auto& a : daftar_pasien)
    {
        cout << a->nama << "\n";
    }
    cout << endl;
}

int main()
{
    dokter* varDokter1 = new dokter("dr. Sopyan");
    dokter* varDokter2 = new dokter("dr. Galang");
    pasien* varPasien1 = new pasien("Aji");
    pasien* varPasien2 = new pasien("Zein");

    varDokter1->TambahkanPasien(varPasien1);
    varDokter2->TambahkanPasien(varPasien2);
    varDokter2->TambahkanPasien(varPasien1);

    varDokter1->CetakPasien();
    varDokter2->CetakPasien();
    varPasien1->cetakdokter();
    varPasien2->cetakdokter();

    delete varPasien1;
    delete varPasien2;
    delete varDokter1;
    delete varDokter2;

    return 0;
}