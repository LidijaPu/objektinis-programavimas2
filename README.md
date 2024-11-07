# objektinis-programavimas



### Programos įdiegimo ir paleidimo instrukcija
**1.** Atsisiųskite V1.0 releas'o zip failą.
<br> **2.** Sukurkite direktorija su pavadinimu *"StudentuRusiavimas"* ir išskleiskite į ją atsiųstą zip failą.
<br> **3.** Jei dar neturite įdiekite CMake: [cmake.org](https://cmake.org/download/).
<br> **4.** Direktorijoje *"build"* (rasite tarp atsiustų failų), atidarykite terminalą ir komandinėje eilutėje įrašykite ***"cmake"*** arba jei idiegtas MinGW rasykite ***"cmake -G "MinGW Makefiles" .."***.
<br> **5.** Po to terminalo komandinėje eilutėje įrašykite ***"make"*** arba ***"mingw32-make"** ir *"build"* direktorijoje atsiras *"StudentuRusiavimas.exe"* failas. Programą galite paleisti paspaudus ant jo arba terminalo komandinėje eilutėje įrašius ***"./Sort.exe"**.
<br> **Pastaba.** Pirmą kartą paleidžaint programą ir norėdami atlinkti analizę būtina sugeneruoti naujus failus.


## Programos versijos ir analizė
### _V0.1_
Programa nuskaito įvestus studentų duomenis, ganeruoja juos atsitiktinai arba nuskaito juos iš failo. Galutinį įvertinimą skaičiuoja pagal pasirinktą metodą (vid. arba med.) Duomenys atspausdinami išrikiuoti pagal pavardę ir vardą.

### _V0.2_
Programa nuskaito įvestus studentų duomenis, ganeruoja juos atsitiktinai arba nuskaito juos iš failo. Galutinį įvertinimą skaičiuoja pagal pasirinktą metodą (vid. arba med.) Duomenys atspausdinami išrikiuoti pagal pavardę ir vardą. Taip pat *Studentus* išrušiuja į atskirus failus - *kietiakus* arba *vargsiukus*.

### _V0.3_
Programa nuskaito įvestus studentų duomenis, ganeruoja juos atsitiktinai arba nuskaito juos iš failo. Galutinį įvertinimą skaičiuoja pagal pasirinktą metodą (vid. arba med.) Duomenys atspausdinami išrikiuoti pagal pavardę ir vardą. Taip *Studentus* išrušiuja į atskirus failus - *kietiakus* arba *vargsiukus*. Programoje galima pasirinkti kurio tipo konteinerį naudoti - *list* arba *vector* ir fiksuojamas spartos laikas.

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

### _V1.0_
Programa nuskaito įvestus studentų duomenis, ganeruoja juos atsitiktinai arba nuskaito juos iš failo. Galutinį įvertinimą skaičiuoja pagal pasirinktą metodą (vid. arba med.) Duomenys atspausdinami išrikiuoti pagal pavardę ir vardą. Taip *Studentus* išrušiuja į atskirus failus - *kietiakus* arba *vargsiukus*. Programoje galima pasirinkti kurio tipo konteinerį naudoti - *list* arba *vector* ir fiksuojamas spartos laikas. Pridėtos 3 startegijos *Studentų* duomenims apdoroti: 
* *(1)* Bendro studentai konteinerio (vector ir list tipų) skaidymas į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietiakų";
* *(2)* Bendro studentų konteinerio (vector ir list) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "vargšiukai";
* *(3)* Bendro studentų konteinerio skaidymas (rūšiavimas) panaudojant 2 strategiją įtraukiant į ją "efektyvius" darbo su konteineriais metodus (std::stable_partition).


**Spartos analizė (bendras laikas)**
| Strategija - Konteineris               | **1000**    | **10000**   | **100000**  | **1000000**  | **10000000** |
|----------------------------|-------------|-------------|-------------|--------------|--------------|
| **1 - Vector**      | 0.019459s  | 0.078949s  | 0.769003s  | 7.896289s    | 78.485606s   |
| **2 - Vector**      | 0.020724s   | 0.078206s   | 0.714712s  | 7.526429s    | 76.232662s   |
| **3- Vector**       |0.019869s   | 0.076956s  | 0.751893s  | 7.796333s    | 78.954670s  |
|----------------------------|-------------|-------------|-------------|--------------|--------------|
| **1 - List**      | 0.012516s   | 0.079025s  | 0.766863s   | 8.385664s     | 86.425663s  |
| **2 - List**      | 0.012878s  | 0.078865s   | 0.818386s   | 8.394899s    | 81.391470s   |
| **3- List**       | 0.019579s   |  0.076841s  | 0.775050s   | 7.901729s    | 80.529103s   |




**Atminties naudojimas**
|       |      **1**      |      |      **2**      |      |      **3**      |      |
|-------|------------------|------|------------------|------|------------------|------|
|       | **vector**       | **list** | **vector**       | **list** | **vector**       | **list** |
| **studentai_1000** |   110864 baitai               |  120000 baitai        |        0 baitai           |   0 baitai       |     0 baitai        |     0 baitai           |
| **vargsiukai_1000** |     49296 baitai             |  47040 baitai         |      49296 baitai          |   47040 baitai       |    40768 baitai       |   47040 baitai         |
| **kietiakai_10000** |         73944 baitai         |  72960 baitai         |      110864 baitai         |  72960 baitai        |       63232 baitai       |  72960 baitai    |
|-------|------|------|------|------|------|------|
| **studentai_10000** |   1262352 baitai             |  1200000 baitai       |      0 baitai            |   0 baitai       |     0 baitai       |     0 baitai          |
| **vargsiukai_10000** |     561080 baitai           |  472200 baitai        |     561080 baitai         |  472200 baitai        |       409240 baitai   |   472200 baitai        |
| **kietiakai_100000** |         841568 baitai       |  727800 baitai        |        1262352 baitai      |   727800 baitai        |    630760 baitai      |  727800 baitai      |
|-------|------|------|------|------|------|------|
| **studentai_100000** |   14378520 baitai           |  12000000 baitai      |       0 baitai           |   0 baitai       |     0 baitai        |    0 baitai         |
| **vargsiukai_100000** |     4260360 baitai         |  4772640 baitai       |      4260360 baitai      |   4772640 baitai       |     4136288 baitai        |   4772640 baitai       |
| **kietiakai_1000000** |       6390488 baitai       |  7227360 baitai       |       14378520 baitai    |   7227360 baitai       |      6263712 baitai      |    7227360 baitai        |
|-------|------|------|------|------|------|------|
| **studentai_1000000** |   109186376 baitai         |  120000000 baitai      |          0 baitai         |   0 baitai       |       0 baitai      |   0 baitai          |
| **vargsiukai_1000000** |  48527336 baitai          |  48039600 baitai       |      48527336 baitai      |   48039600 baitai       |      41634320 baitai      |  48039600 baitai      |
| **kietiakai_10000000** |  72790952 baitai          |  71960400 baitai       |      48527336 baitai       |  71960400 baitai        |      62365680 baitai     |  71960400 baitai       |
|-------|------|------|------|------|------|------|
| **studentai_10000000** |   1243700328 baitai       |  1199999880 baitai     |    0 baitai                |   0 baitai       |    0 baitai        |     0 baitai            |
| **vargsiukai_10000000** |  552755736 baitai        |  479866680 baitai      |     552755736 baitai       |   479866680 baitai       |     415884456 baitai   |   479866680 baitai        |
| **kietiakai_100000000** |   829133552 baitai       |  720133200 baitai      |     1243700328 baitai        |  720133200 baitai        |      624115440 baitai       |  720133200 baitai     |



### Kompiuterio parametrai:  
CPU - Intel(R) Core(TM) i5-9300H CPU @ 2.40GHz  
RAM - 12GB  
HDD - 476GB  




