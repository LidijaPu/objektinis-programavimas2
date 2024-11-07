#include "mylib.h"
#include "stud.h"
#include "failai.h"
#include "listai.h"


void atmintisList(const std::list<Studentas>& lst, const string& name) {
    size_t node_size = sizeof(Studentas) + 2 * sizeof(void*);
    size_t memory_in_bytes = lst.size() * node_size;
    std::cout << "Naudojama atmintis " << name << ": " << memory_in_bytes << " baitai" << std::endl;
}

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



void rusiavimasList(list<Studentas>& studentaiList) {
    studentaiList.sort(palyginimas);
}

void nuskaitytiStudentusList(const string& failoPavadinimas, list<Studentas>& studentaiList, int pasirinkimas) {
    ifstream failas(failoPavadinimas);
    if (!failas.is_open()) {
        cerr << "Klaida atidarant faila!" << endl;
        return;
    }

    string vardas, pavarde;
    vector<int> namuDarbai(5);
    int egzaminas;
    string praleistiEilute;
    getline(failas, praleistiEilute);

    while (failas >> pavarde >> vardas >> namuDarbai[0] >> namuDarbai[1] >> namuDarbai[2] >> namuDarbai[3] >> namuDarbai[4] >> egzaminas) {
        Studentas s;
        s.vardas = vardas;
        s.pavarde = pavarde;
        s.namu_darbai = namuDarbai;
        s.egzaminas = egzaminas;
        s.galutinis = (pasirinkimas == 1) ? galutinisVidurkis(s.namu_darbai, s.egzaminas) : galutineMediana(s.namu_darbai, s.egzaminas);
        studentaiList.push_back(s);
    }
    failas.close();
}

void rusiuotiStudentusList(list<Studentas>& studentaiList, int pasirinkimas, int rusiuotiPagal, int strategija,
    list<Studentas>& vargsiukai, list<Studentas>& kietiakiai) {

    if (strategija == 1) {
        for (const auto& studentas : studentaiList) {
            if (studentas.galutinis < 5.0) {
                vargsiukai.push_back(studentas);
            }
            else {
                kietiakiai.push_back(studentas);
            }
        }
    }
    else if (strategija == 2) {
        // Strategija 2: Perkelti studentus á `vargsiukai` ir pağalinti iğ `studentaiList`, paliekant tik `kietiakiai`
        for (auto it = studentaiList.begin(); it != studentaiList.end(); ) {
            if (it->galutinis < 5.0) {
                vargsiukai.push_back(move(*it));
                it = studentaiList.erase(it);
            }
            else {
                ++it;
            }
        }
        kietiakiai.splice(kietiakiai.end(), studentaiList);  // Likæ studentai yra `kietiakiai`
    }
    else if (strategija == 3) {
        // Strategija 3: Naudoti `stable_partition` ir skirstyti
        auto it = stable_partition(studentaiList.begin(), studentaiList.end(),
            [](const Studentas& s) { return s.galutinis < 5.0; });
        vargsiukai.splice(vargsiukai.end(), studentaiList, studentaiList.begin(), it);
        kietiakiai.splice(kietiakiai.end(), studentaiList);  // Likusi dalis yra `kietiakiai`
    }

    // Rûğiavimas po skirstymo pagal pasirinktà kriterijø
    if (rusiuotiPagal == 1) {
        rusiavimas_vardasList(vargsiukai);
        rusiavimas_vardasList(kietiakiai);
    }
    else if (rusiuotiPagal == 2) {
        rusiavimas_pavardeList(vargsiukai);
        rusiavimas_pavardeList(kietiakiai);
    }
    else if (rusiuotiPagal == 3) {
        rusiavimas_pazimysList(vargsiukai);
        rusiavimas_pazimysList(kietiakiai);
    }
    else {
        cout << "Neteisingas pasirinkimas." << endl;
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
            << setw(20) << studentas.pavarde
            << setw(20) << studentas.vardas
            << setw(10) << fixed << setprecision(2) << studentas.galutinis
            << endl;
    }

    failas.close();
}


void rusiavimas_vardasList(std::list<Studentas>& studentaiList) {
    studentaiList.sort(palyginimas_vardas);
}


void rusiavimas_pavardeList(std::list<Studentas>& studentaiList) {
    studentaiList.sort(palyginimas_pavarde);
}


void rusiavimas_pazimysList(std::list<Studentas>& studentaiList) {
    studentaiList.sort(palyginimas_pazimys);
}




void matuotiVeikimoGreitiList(const string& name, int kiekis, int pasirinkimas, int rusiuotiPagal, int strategija) {
    cout << "Matuojamas veikimo greitis su failu: " << name << "\n";

    auto total_start = high_resolution_clock::now();

    auto start = high_resolution_clock::now();
    list<Studentas> studentaiList;
    nuskaitytiStudentusList(name, studentaiList, pasirinkimas);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count() / 1e6;
    cout << "Duomenu nuskaitymas uztruko: " << fixed << setprecision(6) << duration << "s\n";

    list<Studentas> vargsiukaiList, kietiakiaiList;
    start = high_resolution_clock::now();
    rusiuotiStudentusList(studentaiList, pasirinkimas, rusiuotiPagal, strategija, vargsiukaiList, kietiakiaiList);
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

    atmintisList(studentaiList, "studentaiList");
    atmintisList(vargsiukaiList, "vargsiukaiList");
    atmintisList(kietiakiaiList, "kietiakiaiList");
    cout << "\n" << endl;
}
