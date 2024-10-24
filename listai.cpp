#include "mylib.h"
#include "stud.h"
#include "failai.h"
#include "listai.h"

void isvestisList(const list<Studentas>& studentaiList, int pasirinkimas) {
    cout << left << setw(15) << "Pavarde"
        << left << setw(15) << "Vardas"
        << left << setw(20) << "Galutinis (Vid.)"
        << left << setw(20) << "Galutinis (Med.)"
        << left << setw(20) << "Adresas" << endl;

    cout << "-------------------------------------------------------------------------------" << endl;

    for (const auto& sl : studentaiList) {
        if (sl.namu_darbai.empty()) {
            cerr << "Klaida: Studentas " << sl.vardas << " " << sl.pavarde << " neturi namu darbu balu." << endl;
            continue;
        }

        double galutinisVid = galutinisVidurkis(sl.namu_darbai, sl.egzaminas);
        double galutinisMed = galutineMediana(sl.namu_darbai, sl.egzaminas);

        cout << left << setw(15) << sl.pavarde
            << left << setw(15) << sl.vardas;

        if (pasirinkimas == 1) {
            cout << fixed << setprecision(2) << setw(20) << galutinisVid
                << setw(20) << "-";
        }
        else if (pasirinkimas == 2) {
            cout << setw(20) << "-"
                << fixed << setprecision(2) << setw(20) << galutinisMed;
        }

        cout << setw(20) << &sl;
        cout << endl;
    }
}

void nuskaitytiIsFailoList(const string& name, list<Studentas>& studentaiList, int pasirinkimas) {
    ifstream fin;

    try {
        fin.open(name);
        if (!fin.is_open()) {
            throw runtime_error("Nepavyko atidaryti failo.");
        }
    }
    catch (const runtime_error& e) {
        cerr << e.what() << endl;
        return;
    }

    try {
        string ignore;
        getline(fin, ignore);
        string line;

        while (getline(fin, line)) {
            istringstream iss(line);
            Studentas sl;
            string vardas, pavarde;

            if (!(iss >> vardas >> pavarde)) {
                cerr << " " << endl;
                continue;
            }

            sl.vardas = vardas;
            sl.pavarde = pavarde;

            int pazymys;
            vector<int> pazymiai;
            while (iss >> pazymys) {
                pazymiai.push_back(pazymys);
            }

            if (!pazymiai.empty()) {
                sl.egzaminas = pazymiai.back();
                pazymiai.pop_back();
                sl.namu_darbai = pazymiai;
            }

            studentaiList.push_back(sl);
        }

        fin.close();
    }


        void rusiavimasList(list<Studentas>& studentaiList) {
    studentaiList.sort(palyginimas);
}

void rusiuotiStudentusList(const string& name, int pasirinkimas, int rusiuotiPagal, const string& filePrefix,
    list<Studentas>& vargsiukaiList, list<Studentas>& kietiakiaiList) {

    ifstream failas(name);

    if (!failas.is_open()) {
        cerr << "Klaida atidarant faila!" << endl;
        return;
    }

    string vardas, pavarde;
    int egzaminas;
    string praleistiEilute;

    getline(failas, praleistiEilute);

    while (failas >> pavarde >> vardas) {
        vector<int> laikinasNamuDarbai(5);
        int balas;

        for (int i = 0; i < 5; ++i) {
            if (failas >> laikinasNamuDarbai[i]) {
                continue;
            }
            else {
                cerr << "Klaida nuskaitant namų darbų balą!" << endl;
                return;
            }
        }

        if (!(failas >> egzaminas)) {
            cerr << "Klaida nuskaitant egzamino balą!" << endl;
            return;
        }

        Studentas sl;
        sl.vardas = vardas;
        sl.pavarde = pavarde;

        sl.namu_darbai = laikinasNamuDarbai;

        sl.egzaminas = egzaminas;

        if (pasirinkimas == 1) {
            sl.galutinis = galutinisVidurkis(sl.namu_darbai, sl.egzaminas);
        }
        else {
            sl.galutinis = galutineMediana(sl.namu_darbai, sl.egzaminas);
        }

        if (sl.galutinis < 5.0) {
            vargsiukaiList.push_back(sl);
        }
        else {
            kietiakiaiList.push_back(sl);
        }
    }

    failas.close();

    if (rusiuotiPagal == 1) {
        rusiavimas_vardasList(vargsiukaiList);
        rusiavimas_vardasList(kietiakiaiList);
    }
    else if (rusiuotiPagal == 2) {
        rusiavimas_pavardeList(vargsiukaiList);
        rusiavimas_pavardeList(kietiakiaiList);
    }
    else if (rusiuotiPagal == 3) {
        rusiavimas_pazimysList(vargsiukaiList);
        rusiavimas_pazimysList(kietiakiaiList);
    }
    else {
        cout << "Neteisingas pasirinkimas." << endl;
    }
}

    
    catch (const ifstream::failure& e) {
        cerr << "Nepavyko nuskaityti failo: " << e.what() << endl;
    }
}
