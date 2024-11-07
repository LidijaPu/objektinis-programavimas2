# objektinis-programavimas



### Programos įdiegimo ir paleidimo instrukcija
**1.** Atsisiųskite V1.0 releas'o zip failą.
<br> **2.** Sukurkite direktorija su pavadinimu *"StudentuRusiavimas"* ir išskleiskite į ją atsiųstą zip failą.
<br> **3.** Jei dar neturite įdiekite CMake: [cmake.org](https://cmake.org/download/).
<br> **4.** Direktorijoje *"build"* (rasite tarp atsiustų failų), atidarykite terminalą ir komandinėje eilutėje įrašykite ***"cmake"*** arba jei idiegtas MinGW rasykite ***"cmake -G "MinGW Makefiles" .."***
<br> **5.** Po to terminalo komandinėje eilutėje įrašykite ***"make"*** arba ***"mingw32-make"** ir *"build"* direktorijoje atsiras *"StudentuRusiavimas.exe"* failas. Programą galite paleisti paspaudus ant jo arba terminalo komandinėje eilutėje įrašius ***"./Sort.exe"**
<br> **Pastaba.** Pirmą kartą paleidžaint programą ir norėdami atlinkti analizę būtina sugeneruoti naujus failus


## Programos versijos ir analizė
### _V0.1_

### _V0.2_

### _V0.3_

### _V1.0_




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




