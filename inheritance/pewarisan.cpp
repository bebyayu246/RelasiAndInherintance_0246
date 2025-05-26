#include <iostream>
#include <string>
using namespace std;

class orang
{
    public:
        string nama;

        orang(string pNama) : nama(pNama)
        {
            cout << "Orang Dibuat\n" << endl;
        }

        ~orang()
        {
            cout << "Orang Dihapus\n" << endl;
        }

        int jumlah(int a, int b)
        {
            return a + b;
        }
};

class pelajar : public orang
{
    public:
        string sekolah;

        pelajar(string pNama, string pSekolah) : orang(pNama), sekolah(pSekolah)
        {
            cout << "Pelajar Dibuat\n" << endl;
        }

        ~pelajar()
        {
            cout << "Pelajar Dihapus\n" << endl;
        }

        string perkenalan()
        {
            return "Halo, Nama saya " + nama + "dari sekolah " + sekolah + "\n";
        }
};

int main()
{
    pelajar siswa1("Andi laksono", "SMAN 1 Bantul");
    cout << siswa1.perkenalan();
    cout << "Hasil = " << siswa1.jumlah(10, 90) << endl;

    return 0;
}