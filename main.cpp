#include "mylib.h"
#include "stud.h"

int main() {
    try{
        vector<Studentas> studentai;
        int n, pasirinkimas;

        cout << "Ar norite ivesti duomenis ranka (1), skaityti is failo (2), ar generuoti atsitiktinai (3)? ";
        while(!(cin>>pasirinkimas)||(pasirinkimas<1 || pasirinkimas > 3)){
            cout << "Klaida: Prasome ivesti 1, 2 arba 3: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        if (pasirinkimas == 1 || pasirinkimas == 3) {
            cout << "Įveskite studentų skaičių: ";
            while (!(cin >> n) || n <= 0) {
                cout << "Klaida: Prasome ivesti tik skaiciu: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
    
            for (int i = 0; i < n; i++) {
                Studentas s;
                cout << "Įveskite studento " << i + 1 << " vardą: ";
                cin >> s.vardas;
                cout << "Įveskite studento " << i + 1 << " pavardę: ";
                cin >> s.pavarde;
        
                if (pasirinkimas == 1) {
                    cout << "Iveskite namu darbu balus (noredami baigti ivesti, iveskite neigiama skaiciu):" << endl;
                    while (true) {
                        int rezultatas;
                        cout << "Namu darbu balas: ";
                        cin >> rezultatas;
                        if (rezultatas < 0) break;
                        if (rezultatas >= 1 && rezultatas <= 10) s.namu_darbai.push_back(rezultatas);
                        else cout << "Klaida: Prasome ivesti skaiciu tarp 1 ir 10." << endl;
                    }
                    cout << "Iveskite egzamino bala: ";
                    while (!(cin >> s.egzaminas) || s.egzaminas < 1 || s.egzaminas > 10) {
                        cout << "Klaida: Prasome ivesti skaicių nuo 1 iki 10: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                else {
                    generuotiAtsitiktiniusRezultatus(s);
                }
                studentai.push_back(s);
            }
        
        }
        else if (pasirinkimas == 2) {
            string failoPavadinimas;
            cout << "Įveskite failo pavadinimą: ";
            cin >> failoPavadinimas;
            try {
                nuskaitytiIsFailo(failoPavadinimas, studentai);
            }
            catch (const ifstream::failure& e) {
                cerr << "Klaida: nepavyko nuskaityti failo. Priezastis: " << e.what() << endl;
                return 1;
            }
        }
    
        cout << "Ar norite skaiciuoti galutini bala pagal vidurki (1) ar mediana (2)? ";
        while (!(cin >> pasirinkimas) || (pasirinkimas != 1 && pasirinkimas != 2)) {
            cout << "Klaida: Prasome ivesti 1 arba 2: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        rusiavimas(studentai);
        isvestis(studentai, pasirinkimas);

    }
    catch (const invalid_argument& e) {
        cerr << "Klaida: neteisingas ivedimas. Priezastis: " << e.what() << endl;
        return 1;
    }
    catch (const exception& e) {
        cerr << "Ivyko klaida: " << e.what() << endl;
        return 1;
    }
return 0;
}




