#include "mylib.h"
#include "stud.h"
#include "failai.h"
#include "listai.h"



void atmintisList(const list<Studentas>& lst, const string& name) {
    size_t node_size = sizeof(Studentas) + 2 * sizeof(void*);
    size_t memory_in_bytes = lst.size() * node_size;
    cout << "Naudojama atmintis " << name << ": " << memory_in_bytes << " baitai" << endl;
}

void isvestisList(const list<Studentas>& studentaiList, int pasirinkimas) {
    cout << left << setw(15) << "Pavarde"
        << left << setw(15) << "Vardas"
        << left << setw(20) << "Galutinis (Vid.)"
        << left << setw(20) << "Galutinis (Med.)"
        << left << setw(20) << "Adresas" << endl;

    cout << "-------------------------------------------------------------------------------" << endl;

    for (const auto& sl : studentaiList) {
        if (sl.getNamuDarbai().empty()) {
            cerr << "Klaida: Studentas " << sl.getVardas() << " " << sl.getPavarde() << " neturi namu darbu balu." << endl;
            continue;
        }

        double galutinisVid = Studentas::galutinisVidurkis(sl.getNamuDarbai(), sl.getEgzaminas());
        double galutinisMed = Studentas::galutineMediana(sl.getNamuDarbai(), sl.getEgzaminas());

        cout << left << setw(15) << sl.getPavarde()
            << left << setw(15) << sl.getVardas();

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
    ifstream fin(name);
    if (!fin.is_open()) {
        cerr << "Nepavyko atidaryti failo." << endl;
        return;
    }

    string ignore;
    getline(fin, ignore);  

    string line;
    while (getline(fin, line)) {
        istringstream iss(line);
        string vardas, pavarde;

        if (!(iss >> vardas >> pavarde)) {
            cerr << "Klaida nuskaitant vardą ar pavardę." << endl;
            continue;
        }

        vector<int> pazymiai;
        int pazymys;
        while (iss >> pazymys) {
            pazymiai.push_back(pazymys);
        }

        if (!pazymiai.empty()) {
            int egzaminas = pazymiai.back();
            pazymiai.pop_back();
            Studentas sl(vardas, pavarde, pazymiai, egzaminas);
            sl.setGalutinis((pasirinkimas == 1) ? Studentas::galutinisVidurkis(pazymiai, egzaminas)
                : Studentas::galutineMediana(pazymiai, egzaminas));
            studentaiList.push_back(sl);
        }
    }
    fin.close();
}

void rusiavimasList(list<Studentas>& studentaiList) {
    studentaiList.sort(palyginimas);
}

void rusiuotiStudentusList(const string& name, int pasirinkimas, int rusiuotiPagal, int strategija,
    const string& filePrefix, list<Studentas>& vargsiukaiList, list<Studentas>& kietiakiaiList) {

    list<Studentas> studentaiList;
    nuskaitytiIsFailoList(name, studentaiList, pasirinkimas);

    if (strategija == 1) {
        for (const auto& studentas : studentaiList) {
            if (studentas.getGalutinis() < 5.0) {
                vargsiukaiList.push_back(studentas);
            }
            else {
                kietiakiaiList.push_back(studentas);
            }
        }
    }
    else if (strategija == 2) {
        for (auto it = studentaiList.begin(); it != studentaiList.end();) {
            if (it->getGalutinis() < 5.0) {
                vargsiukaiList.push_back(move(*it));
                it = studentaiList.erase(it);
            }
            else {
                ++it;
            }
        }
        kietiakiaiList = move(studentaiList);
    }
    else if (strategija == 3) {
        auto it = partition(studentaiList.begin(), studentaiList.end(), [](const Studentas& s) {
            return s.getGalutinis() < 5.0;
            });
        vargsiukaiList.splice(vargsiukaiList.end(), studentaiList, studentaiList.begin(), it);
        kietiakiaiList.splice(kietiakiaiList.end(), studentaiList);
    }

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
}

void surusioti_failaiList(list<Studentas>& studentaiList, const string& name) {
    ofstream failas(name);
    if (!failas.is_open()) {
        cerr << "Klaida: nepavyko sukurti failo " << name << endl;
        return;
    }

    failas << left
        << setw(20) << "Pavarde"
        << setw(20) << "Vardas"
        << setw(10) << "Galutinis"
        << endl;

    for (const auto& studentas : studentaiList) {
        failas << left
            << setw(20) << studentas.getPavarde()
            << setw(20) << studentas.getVardas()
            << setw(10) << fixed << setprecision(2) << studentas.getGalutinis()
            << endl;
    }

    failas.close();
}

void rusiavimas_vardasList(list<Studentas>& studentaiList) {
    studentaiList.sort(palyginimas_vardas);
}

void rusiavimas_pavardeList(list<Studentas>& studentaiList) {
    studentaiList.sort(palyginimas_pavarde);
}

void rusiavimas_pazimysList(list<Studentas>& studentaiList) {
    studentaiList.sort(palyginimas_pazimys);
}

void matuotiVeikimoGreitiList(const string& name, int kiekis, int pasirinkimas, int rusiuotiPagal, int strategija) {
    cout << "Matuojamas veikimo greitis su failu: " << name << "\n";

    auto total_start = high_resolution_clock::now();

    auto start = high_resolution_clock::now();
    list<Studentas> studentaiList;
    nuskaitytiIsFailoList(name, studentaiList, pasirinkimas);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count() / 1e6;
    cout << "Duomenu nuskaitymas uztruko: " << fixed << setprecision(6) << duration << "s\n";

    list<Studentas> vargsiukaiList, kietiakiaiList;

    start = high_resolution_clock::now();
    rusiuotiStudentusList(name, pasirinkimas, rusiuotiPagal, strategija, to_string(kiekis), vargsiukaiList, kietiakiaiList);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start).count() / 1e6;
    cout << "Studentu rusiavimas i dvi grupes uztruko: " << fixed << setprecision(6) << duration << "s\n";

    start = high_resolution_clock::now();
    string vargsiukaiFailas = "vargsiukai_" + to_string(kiekis) + ".txt";
    surusioti_failaiList(vargsiukaiList, vargsiukaiFailas);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start).count() / 1e6;
    cout << "Duomenu irasymas i faila '" << vargsiukaiFailas << "' uztruko: " << fixed << setprecision(6) << duration << "s\n";

    start = high_resolution_clock::now();
    string kietiakiaiFailas = "kietiakiai_" + to_string(kiekis) + ".txt";
    surusioti_failaiList(kietiakiaiList, kietiakiaiFailas);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start).count() / 1e6;
    cout << "Duomenu irasymas i faila '" << kietiakiaiFailas << "' uztruko: " << fixed << setprecision(6) << duration << "s\n";

    auto total_end = high_resolution_clock::now();
    auto total_duration = duration_cast<microseconds>(total_end - total_start).count() / 1e6;
    cout << "Bendras uzduociu atlikimo laikas: " << fixed << setprecision(6) << total_duration << "s\n\n";

    atmintisList(studentaiList, "studentai_list");
    atmintisList(vargsiukaiList, "vargsiukai_list");
    atmintisList(kietiakiaiList, "kietiakiai_list");
    cout << "\n" << endl;
}

