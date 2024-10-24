# objektinis-programavimas
Programa nuskaito įvestus studentų duomenis, ganeruoja juos atsitiktinai arba nuskaito juos iš failo. 
Galutinį įvertinimą skaičiuoja pagal pasirinktą metodą (vid. arba med.) 
Duomenys atspausdinami išrikiuoti pagal pavardę ir vardą. 

Kompiuterio parametrai:  
CPU - Intel(R) Core(TM) i5-9300H CPU @ 2.40GHz  
RAM - 12GB  
HDD - 476GB  





| Greičio analizė                  | **1000**    | **10000**   | **100000**  | **1000000**  | **10000000** |
|----------------------------|-------------|-------------|-------------|--------------|--------------|
| **Nuskaitymas (Vector)**      | 0.00558s    | 0.063199s   | 0.554496s   | 5.25383s     | 41.319246s   |
| **Nuskaitymas (List)**      | 0.008551s   | 0.072018s   | 0.489219s   | 5.148625s    | 48.423361s   |
| **Rūšiavimas (Vector)**       | 0.004653s   | 0.060933s   | 0.534427s   | 4.367090s    | 36.101731s   |
| **Rūšiavimas (List)**       | 0.004679s   | 0.037208s   | 0.419490s   | 4.280785s    | 33.125880s   |
| **Įrašymas - Varg. (Vector)** | 0.003922s   | 0.043867s   | 0.327777s   | 2.421948s    | 25.416993s   |
| **Įrašymas - Varg. (List)** | 0.004851s   | 0.034512s   | 0.389997s   | 2.838789s    | 27.325997s   |
| **Įrašymas - Kiet. (Vector)** | 0.005377s   | 0.064861s   | 0.493673s   | 3.917123s    | 36.520960s   |
| **Įrašymas - Kiet. (List)** | 0.006921s   | 0.038028s   | 0.411899s   | 4.010851s    | 42.467769s   |
| **Bendras (Vector)**          | 0.024676s   | 0.239696s   | 1.916275s   | 15.965627s   | 139.364410s  |
| **Bendras (List)**          | 0.030487s   | 0.186473s   | 1.716101s   | 16.285035s   | 151.348629s  |





