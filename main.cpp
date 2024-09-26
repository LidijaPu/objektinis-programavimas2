#include "mylib.h"
#include "stud.h"

int main() {
    vector<Studentas> studentai;
    int n, nd_kiekis;

    cout << "Ar norite įvesti duomenis ranka (1), skaityti iš failo (2), ar generuoti atsitiktinai (3)? ";
    int pasirinkimas;
    cin >> pasirinkimas;

    if (pasirinkimas == 1) {
        cout << "Įveskite studentų skaičių: ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            Studentas s;
            cout << "Įveskite studento " << i + 1 << " vardą: ";
            cin >> s.vardas;
            cout << "Įveskite studento " << i + 1 << " pavardę: ";
            cin >> s.pavarde;
    
           cout << "Įveskite namų darbų balus (norėdami baigti įvestį, įveskite neigiamą reikšmę):" << endl;

        while (true) {
            int rezultatas;
            cout << "Namų darbų balas: ";
            cin.clear();
            cin >> rezultatas;

            if (!cin || rezultatas < 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break; 
            }
            s.namu_darbai.push_back(rezultatas);
        }

        cout << "Įveskite egzamino balą: ";
        cin >> s.egzaminas;
        studentai.push_back(s);
    }
  } else if (pasirinkimas == 2) {
        string failoPavadinimas;
        cout << "Įveskite failo pavadinimą: ";
        cin >> failoPavadinimas;
        nuskaitytiIsFailo(failoPavadinimas, studentai);

        
    } else if (pasirinkimas == 3) {
        cout << "Įveskite studentų skaičių: ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            Studentas s;
            cout << "Įveskite studento " << i + 1 << " vardą: ";
            cin >> s.vardas;
            cout << "Įveskite studento " << i + 1 << " pavardę: ";
            cin >> s.pavarde;

            generuotiAtsitiktiniusRezultatus(s);

            studentai.push_back(s);
        }
    }
    
    cout << "Ar norite skaičiuoti galutinį balą pagal vidurkį (1) ar medianą (2)?";
    cin >> pasirinkimas;
    
return 0;
}




