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
    catch (const ifstream::failure& e) {
        cerr << "Nepavyko nuskaityti failo: " << e.what() << endl;
    }
}
