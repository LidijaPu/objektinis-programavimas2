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
