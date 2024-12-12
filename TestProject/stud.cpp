#include "stud.h"
#include "mylib.h"


double Studentas::galutinisVidurkis(const vector<int>& namu_darbai, int egzaminas) {
    if (namu_darbai.empty()) return 0.0;

    double sum = accumulate(namu_darbai.begin(), namu_darbai.end(), 0);
    double vidurkis = sum / namu_darbai.size();
    return 0.4 * vidurkis + 0.6 * egzaminas;
}

double Studentas::galutineMediana(vector<int> namu_darbai, int egzaminas) {
    if (namu_darbai.empty()) return 0.0;

    sort(namu_darbai.begin(), namu_darbai.end());
    double mediana = namu_darbai.size() % 2 == 0 ?
        (namu_darbai[namu_darbai.size() / 2 - 1] + namu_darbai[namu_darbai.size() / 2]) / 2.0
        : namu_darbai[namu_darbai.size() / 2];
    return 0.4 * mediana + 0.6 * egzaminas;
}


void isvestis(const vector<Studentas>& studentai, int pasirinkimas) {
    cout << left << setw(15) << "Pavarde"
        << left << setw(15) << "Vardas"
        << left << setw(20) << "Galutinis (Vid.)"
        << left << setw(20) << "Galutinis (Med.)"
        << left << setw(20) << "Adresas" << endl;

    cout << "---------------------------------------------------------------------------------" << endl;

    for (const auto& s : studentai) {
        if (s.getNamuDarbai().empty() || s.getEgzaminas() == 0) {
            cerr << "Klaida: Studentas " << s.getVardas() << " " << s.getPavarde() << " turi netinkamus duomenis." << endl;
            continue;
        }

        double galutinisVid = Studentas::galutinisVidurkis(s.getNamuDarbai(), s.getEgzaminas());
        double galutinisMed = Studentas::galutineMediana(s.getNamuDarbai(), s.getEgzaminas());

        cout << left << setw(15) << s.getPavarde()
            << left << setw(15) << s.getVardas();

        if (pasirinkimas == 1) {
            cout << fixed << setprecision(2) << setw(20) << galutinisVid
                << setw(20) << "-";
        }
        else if (pasirinkimas == 2) {
            cout << setw(20) << "-"
                << fixed << setprecision(2) << setw(20) << galutinisMed;
        }

        cout << setw(20) << &s;
        cout << endl;
    }
}


void generuotiAtsitiktiniusRezultatus(Studentas& s) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 10);

    vector<int> namu_darbai;
    for (int i = 0; i < 5; i++) {
        namu_darbai.push_back(dist(gen));
    }

    s.setNamuDarbai(namu_darbai);
    s.setEgzaminas(dist(gen));
}


void nuskaitytiIsFailo(const string& failoPavadinimas, vector<Studentas>& studentai) {
    try {
        ifstream failas(failoPavadinimas);
        if (!failas.is_open()) {
            throw runtime_error("Nepavyko atidaryti failo!");
        }

        string vardas, pavarde;
        while (failas >> vardas >> pavarde) {
            vector<int> namuDarbai;
            int balas;

            while (failas >> balas) {
                if (balas == -1) break;
                namuDarbai.push_back(balas);
            }

            if (namuDarbai.empty()) {
                throw runtime_error("Klaida faile: nerasta namu darbu arba egzamino balu.");
            }

            int egzaminas = namuDarbai.back();
            namuDarbai.pop_back();
            Studentas s(vardas, pavarde, namuDarbai, egzaminas);

            studentai.push_back(s);
        }

        failas.close();
    }
    catch (const exception& e) {
        cerr << "Klaida: " << e.what() << endl;
    }
}


bool palyginimas(const Studentas& a, const Studentas& b) {
    return (a.getPavarde() == b.getPavarde()) ? a.getVardas() < b.getVardas() : a.getPavarde() < b.getPavarde();
}


void rusiavimas(vector<Studentas>& studentai) {
    sort(studentai.begin(), studentai.end(), palyginimas);
}
