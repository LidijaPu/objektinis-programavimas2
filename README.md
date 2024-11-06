# objektinis-programavimas
Programa nuskaito įvestus studentų duomenis, ganeruoja juos atsitiktinai arba nuskaito juos iš failo. 
Galutinį įvertinimą skaičiuoja pagal pasirinktą metodą (vid. arba med.) 
Duomenys atspausdinami išrikiuoti pagal pavardę ir vardą. 

Kompiuterio parametrai:  
CPU - Intel(R) Core(TM) i5-9300H CPU @ 2.40GHz  
RAM - 12GB  
HDD - 476GB  





| Strategija - Konteineris               | **1000**    | **10000**   | **100000**  | **1000000**  | **10000000** |
|----------------------------|-------------|-------------|-------------|--------------|--------------|
| **1 - Vector**      | 0.019459s  | 0.078949s  | 0.769003s  | 7.896289s    | 78.485606s   |
| **2 - Vector**      | 0.020724s   | 0.078206s   | 0.714712s  | 7.526429s    | 76.232662s   |
| **3- Vector**       | 0.004653s   | 0.060933s   | 0.534427s   | 4.367090s    | 36.101731s   |
|----------------------------|-------------|-------------|-------------|--------------|--------------|
| **1 - List**      | 0.00558s    | 0.063199s   | 0.554496s   | 5.25383s     | 41.319246s   |
| **2 - List**      | 0.008551s   | 0.072018s   | 0.489219s   | 5.148625s    | 48.423361s   |
| **3- List**       | 0.004653s   | 0.060933s   | 0.534427s   | 4.367090s    | 36.101731s   |





|       |      **1**      |      |      **2**      |      |      **3**      |      |
|-------|------------------|------|------------------|------|------------------|------|
|       | **vector**       | **list** | **vector**       | **list** | **vector**       | **list** |
| **studentai_1000** |   110864 baitai               |   0 baitai       |                  |          |                  |          |
| **vargsiukai_1000** |     49296 baitai             |     49296 baitai     |                  |          |                  |          |
| **kietiakai_10000** |         73944 baitai         |      110864 baitai    |                  |          |                  |          |
|-------|------------------|------|------------------|------|------------------|------|
| **studentai_10000** |   1262352 baitai             |   0 baitai       |                  |          |                  |          |
| **vargsiukai_10000** |     561080 baitai           |   561080 baitai       |                  |          |                  |          |
| **kietiakai_100000** |         841568 baitai       |   1262352 baitai     |                  |          |                  |          |
|-------|------------------|------|------------------|------|------------------|------|
| **studentai_100000** |   14378520 baitai           |   0 baitai       |                  |          |                  |          |
| **vargsiukai_100000** |     4260360 baitai         |    4260360 baitai      |                  |          |                  |          |
| **kietiakai_1000000** |       6390488 baitai       |   14378520 baitai       |                  |          |                  |          |
|-------|------------------|------|------------------|------|------------------|------|
| **studentai_1000000** |   109186376 baitai         |     0 baitai     |                  |          |                  |          |
| **vargsiukai_1000000** |  48527336 baitai          |     48527336 baitai     |                  |          |                  |          |
| **kietiakai_10000000** |  72790952 baitai          |     109186376 baitai     |                  |          |                  |          |
|-------|------------------|------|------------------|------|------------------|------|
| **studentai_10000000** |   1243700328 baitai       |  0 baitai       |                  |          |                  |          |
| **vargsiukai_10000000** |  552755736 baitai        |    552755736 baitai      |                  |          |                  |          |
| **kietiakai_100000000** |   829133552 baitai       |     1243700328 baitai     |                  |          |                  |          |



vector 2


