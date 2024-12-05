#include "mylib.h"
#include "stud.h"
#include "failai.h"
#include "listai.h"

int main() {
 int pasirinkimas;
 cout << "Pasirinkite: Paleisti programa (1) ar Demonstruoti programa (2): ";
 while (!(cin >> pasirinkimas) || (pasirinkimas != 1 && pasirinkimas != 2)) {
     cout << "Klaida: Prasome ivesti 1 arba 2: ";
     cin.clear();
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
 }

 if (pasirinkimas == 2) {
     cout << "\n..... Studentu valdymo sistemos demonstracija .....\n\n";

     cout << "... Demonstracija: Abstrakti klase Zmogus ...\n";

     Studentas stud("Vardas", "Pavarde", { 8, 9, 10 }, 9);

     cout << "Sukurtas Studentas objektas ir jo duomenys:\n";
     cout << stud;

   //      Zmogus zmogus("Vardas", "Pavarde");

     cout << "\nAbstrakcios klases Zmogus demonstracija baigta.\n\n";

     int testi;
     cout << "Ar norite testi demonstracija su kitomis funkcijomis? Taip (1) ar Ne (2): ";
     while (!(cin >> testi) || (testi != 1 && testi != 2)) {
         cout << "Klaida: Prasome ivesti 1 arba 2: ";
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
     }

     if (testi == 2) {
         cout << "Demonstracija baigta.\n";
         return 0; 
     }

     cout << "... Demonstracija: Rule of Three ...\n";
     Studentas originalus("Vardas", "Pavarde", { 10, 9, 8 }, 9);
     cout << "Originalas:\n" << originalus << endl;

     Studentas kopija = originalus;
     cout << "Kopija (kopijavimo konstruktorius):\n" << kopija << endl;

     Studentas priskirtas;
     priskirtas = originalus;
     cout << "Priskirtas objektas (priskyrimo operatorius):\n" << priskirtas << endl;

     cout << "Rule of Three demonstracija baigta.\n\n";

     cout << "... Demonstracija: Ivesties/isvesties operatoriai ...\n";
     Studentas ivestis;
     cout << "Iveskite studento duomenis rankiniu budu:\n";
     cin >> ivestis;
     cout << "\nIvestas studentas:\n" << ivestis << endl;

     cout << "Ivesties/isvesties operatoriu demonstracija baigta.\n\n";

     cout << "... Demonstracija: Studentu generavimas ...\n";
     Studentas sugeneruotas = Studentas::generuotiStudentuDuomenis();
     cout << "Sugeneruotas studentas:\n" << sugeneruotas << endl;

     cout << "Studentu generavimo demonstracija baigta.\n\n";

     cout << "... Demonstracija: Failu operacijos ...\n";
     vector<Studentas> studentai = {
         Studentas("Vardas", "Pavarde", {10, 9, 8}, 9),
         Studentas("Vardenis", "Pavardenis", {8, 7, 6}, 7),
         Studentas::generuotiStudentuDuomenis()
     };

     string failoVardas = "testas.txt";
     Studentas::rasytiIFaila(studentai, failoVardas);
     cout << "Studentai irasyti i faila '" << failoVardas << "'.\n";

     auto nuskaitytiStudentai = Studentas::nuskaitytiIsFailo(failoVardas);

     cout << "Studentai perskaityti is failo '" << failoVardas << "':\n";
     for (const auto& s : nuskaitytiStudentai) {
         cout << s << endl;
     }

     cout << "\nPerskaityti studentai:\n";
     for (const auto& s : studentai) {
         cout << s << endl;
     }

     cout << "Failu operaciju demonstracija baigta.\n\n";

     cout << "..... Demonstracija baigta .....\n";
     return 0;
 }
    
    vector<Studentas> studentai;
    list<Studentas> studentaiList;
    int n, konteinerioPasirinkimas;
    string name = "studentai.txt";

    cout << "Pasirinkite konteineri: vector (1), list (2): ";
    while (!(cin >> konteinerioPasirinkimas) || (konteinerioPasirinkimas != 1 && konteinerioPasirinkimas != 2)) {
        cout << "Klaida: Prasome ivesti 1 arba 2: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (konteinerioPasirinkimas == 1) {
        cout << "Pasirinkite: rankinis ivestis (1), skaitymas is failo (2), generavimas ir laiko matavimas (3): ";
        while (!(cin >> pasirinkimas) || (pasirinkimas < 1 || pasirinkimas > 3)) {
            cout << "Klaida: Prasome ivesti 1, 2 arba 3: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (pasirinkimas == 1) {
            cout << "Iveskite studentu skaiciu: ";
            while (!(cin >> n) || n <= 0) {
                cout << "Klaida: Prasome ivesti teisinga skaiciu: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            for (int i = 0; i < n; i++) {
                string vardas, pavarde;
                vector<int> namu_darbai;
                int egzaminas;

                cout << "Iveskite studento " << i + 1 << " varda: ";
                cin >> vardas;
                cout << "Iveskite studento " << i + 1 << " pavarde: ";
                cin >> pavarde;

                cout << "Iveskite namu darbu balus (ivesti neigiama skaiciu, norint baigti):" << endl;
                while (true) {
                    int rezultatas;
                    cout << "Namu darbu balas: ";
                    cin >> rezultatas;
                    if (rezultatas < 0) break;
                    if (rezultatas >= 1 && rezultatas <= 10) namu_darbai.push_back(rezultatas);
                    else cout << "Klaida: Prasome ivesti skaiciu tarp 1 ir 10." << endl;
                }

                cout << "Iveskite egzamino bala: ";
                while (!(cin >> egzaminas) || egzaminas < 1 || egzaminas > 10) {
                    cout << "Klaida: Prasome ivesti teisinga egzamino bala (nuo 1 iki 10): ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                Studentas s(vardas, pavarde, namu_darbai, egzaminas);
                studentai.push_back(s);
            }

            int galutinis;
            cout << "Ar norite skaiciuoti galutini bala pagal vidurki (1) ar mediana (2)? ";
            while (!(cin >> galutinis) || (galutinis != 1 && galutinis != 2)) {
                cout << "Klaida: Prasome ivesti 1 arba 2: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            rusiavimas(studentai);
            isvestis(studentai, galutinis);
        }
        else if (pasirinkimas == 2) {
            string failoPavadinimas;
            cout << "Iveskite failo pavadinima: ";
            cin >> failoPavadinimas;
            nuskaitytiIsFailo(failoPavadinimas, studentai);

            int galutinis;
            cout << "Ar norite skaiciuoti galutini bala pagal vidurki (1) ar mediana (2)? ";
            while (!(cin >> galutinis) || (galutinis != 1 && galutinis != 2)) {
                cout << "Klaida: Prasome ivesti 1 arba 2: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            rusiavimas(studentai);
            isvestis(studentai, galutinis);
        }
        else if (pasirinkimas == 3) {
            int failoPasirinkimas;
            cout << "Ar norite generuoti naujus failus (1) ar naudoti jau sugeneruotus failus (2)? ";
            while (!(cin >> failoPasirinkimas) || (failoPasirinkimas != 1 && failoPasirinkimas != 2)) {
                cout << "Klaida: Prasome ivesti 1 arba 2: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            vector<int> kiekiai = { 1000, 10000, 100000, 1000000, 10000000 };

            cout << "Ar norite skaiciuoti galutini bala pagal vidurki (1) ar mediana (2)? ";
            while (!(cin >> pasirinkimas) || (pasirinkimas != 1 && pasirinkimas != 2)) {
                cout << "Klaida: Prasome ivesti 1 arba 2: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            int rusiuotiPagal;
            cout << "Ar norite rusiuoti studentus pagal varda (1), pavarde (2) ar pazymi (3)? ";
            while (!(cin >> rusiuotiPagal) || (rusiuotiPagal < 1 || rusiuotiPagal > 3)) {
                cout << "Klaida: Prasome ivesti 1, 2 arba 3: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            int strategija;
            cout << "Kokia strategija noretumet naudoti (1, 2, 3)? ";
            while (!(cin >> strategija) || (strategija < 1 || strategija > 3)) {
                cout << "Klaida: Prasome ivesti 1, 2 arba 3: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            for (int kiekis : kiekiai) {
                string failoPavadinimas = "studentai_" + to_string(kiekis) + ".txt";

                if (failoPasirinkimas == 1) {
                    auto start = high_resolution_clock::now();
                    generuotiStudentuDuomenis(failoPavadinimas, kiekis);
                    auto end = high_resolution_clock::now();
                    auto duration = duration_cast<microseconds>(end - start).count() / 1e6;
                    cout << "Failo generavimas '" << failoPavadinimas << "' uztruko: " << fixed << setprecision(6) << duration << "s\n";
                }
                matuotiVeikimoGreiti(failoPavadinimas, kiekis, pasirinkimas, rusiuotiPagal, strategija);
            }
        }
    }
    else if (konteinerioPasirinkimas == 2) {
        cout << "Pasirinkite: rankinis ivestis (1), skaitymas is failo (2), generavimas ir laiko matavimas (3): ";
        while (!(cin >> pasirinkimas) || (pasirinkimas < 1 || pasirinkimas > 3)) {
            cout << "Klaida: Prasome ivesti 1, 2 arba 3: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (pasirinkimas == 1) {
            cout << "Iveskite studentu skaiciu: ";
            while (!(cin >> n) || n <= 0) {
                cout << "Klaida: Prasome ivesti teisinga skaiciu: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            for (int i = 0; i < n; i++) {
                string vardas, pavarde;
                vector<int> namu_darbai;
                int egzaminas;

                cout << "Iveskite studento " << i + 1 << " varda: ";
                cin >> vardas;
                cout << "Iveskite studento " << i + 1 << " pavarde: ";
                cin >> pavarde;

                cout << "Iveskite namu darbu balus (ivesti neigiama skaiciu, norint baigti):" << endl;
                while (true) {
                    int rezultatas;
                    cout << "Namu darbu balas: ";
                    cin >> rezultatas;
                    if (rezultatas < 0) break;
                    if (rezultatas >= 1 && rezultatas <= 10) namu_darbai.push_back(rezultatas);
                    else cout << "Klaida: Prasome ivesti skaiciu tarp 1 ir 10." << endl;
                }

                cout << "Iveskite egzamino bala: ";
                while (!(cin >> egzaminas) || egzaminas < 1 || egzaminas > 10) {
                    cout << "Klaida: Prasome ivesti teisinga egzamino bala (nuo 1 iki 10): ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                Studentas sl(vardas, pavarde, namu_darbai, egzaminas);
                studentaiList.push_back(sl);
            }

            int galutinis;
            cout << "Ar norite skaiciuoti galutini bala pagal vidurki (1) ar mediana (2)? ";
            while (!(cin >> galutinis) || (galutinis != 1 && galutinis != 2)) {
                cout << "Klaida: Prasome ivesti 1 arba 2: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            rusiavimasList(studentaiList);
            isvestisList(studentaiList, galutinis);
        }
        else if (pasirinkimas == 2) {
            string failoPavadinimas;
            cout << "Iveskite failo pavadinima: ";
            cin >> failoPavadinimas;
            nuskaitytiIsFailoList(failoPavadinimas, studentaiList, pasirinkimas);

            int galutinis;
            cout << "Ar norite skaiciuoti galutini bala pagal vidurki (1) ar mediana (2)? ";
            while (!(cin >> galutinis) || (galutinis != 1 && galutinis != 2)) {
                cout << "Klaida: Prasome ivesti 1 arba 2: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            rusiavimasList(studentaiList);
            isvestisList(studentaiList, galutinis);
        }
        else if (pasirinkimas == 3) {
            int failoPasirinkimas;
            cout << "Ar norite generuoti naujus failus (1) ar naudoti jau sugeneruotus failus (2)? ";
            while (!(cin >> failoPasirinkimas) || (failoPasirinkimas != 1 && failoPasirinkimas != 2)) {
                cout << "Klaida: Prasome ivesti 1 arba 2: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            list<int> kiekiai = { 1000, 10000, 100000, 1000000, 10000000 };

            cout << "Ar norite skaiciuoti galutini bala pagal vidurki (1) ar mediana (2)? ";
            while (!(cin >> pasirinkimas) || (pasirinkimas != 1 && pasirinkimas != 2)) {
                cout << "Klaida: Prasome ivesti 1 arba 2: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            int rusiuotiPagal;
            cout << "Ar norite rusiuoti studentus pagal varda (1), pavarde (2) ar pazymi (3)? ";
            while (!(cin >> rusiuotiPagal) || (rusiuotiPagal < 1 || rusiuotiPagal > 3)) {
                cout << "Klaida: Prasome ivesti 1, 2 arba 3: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            int strategija;
            cout << "Kokia strategija noretumet naudoti (1, 2, 3)? ";
            while (!(cin >> strategija) || (strategija < 1 || strategija > 3)) {
                cout << "Klaida: Prasome ivesti 1, 2 arba 3: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            for (int kiekis : kiekiai) {
                string failoPavadinimas = "studentai_" + to_string(kiekis) + ".txt";

                if (failoPasirinkimas == 1) {
                    auto start = high_resolution_clock::now();
                    generuotiStudentuDuomenis(failoPavadinimas, kiekis);
                    auto end = high_resolution_clock::now();
                    auto duration = duration_cast<microseconds>(end - start).count() / 1e6;
                    cout << "Failo generavimas '" << failoPavadinimas << "' uztruko: " << fixed << setprecision(6) << duration << "s\n";
                }
                matuotiVeikimoGreitiList(failoPavadinimas, kiekis, pasirinkimas, rusiuotiPagal, strategija);
            }
        }
    }

    return 0;
}
