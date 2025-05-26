#ifndef MANUSIA_H
#define MANUSIA_H

class manusia {
public:
    string name;
    jantung varJantung;

    manusia(string pName) : name (pName)
    {
        cout << name << " Manusia Dihidupkan\n";
    }
    ~manusia() {
        cout << name << "Manusia Dimatikan\n";
    }

};
#endif