# Naujų tipų kūrimas ir jų naudojimas (3 užduotis)

Pratęskite (tuo pačiu ir patobulinkite) 2-osios užduoties Jūsų turimą programos realizaciją (versiją v1.0) taip, kad vietoje Jūsų sukurtos Studentas (StudentoInfo) ar dar kitaip pavadintos Studentų structūros jos pagrindu sukurkite class'ę, vadovaujantis per teorijos paskaitas nurodomomis "geromis praktikomis".

## Įdiegimas (Unix kompiuteryje) naudojant `Clang` kompiliatorių 

- `git clone https://github.com/Elijus99/OPP_2uzd_DuomenuApdorojimas.git`
- `cd OPP_2uzd_DuomenuApdorojimas` (v0.5.1 ir v1.0.1 reikia nueiti i atitinkama folderi naudojant `cd ...`, pvz. v1.0.1 vector 2 strategija - `cd OPP_2uzd_DuomenuApdorojimas/'v1.0.1 vector'/2strat`)
- `make`
- `make test`

## Naudojimosi instrukcija

- Paleisti programą.
- Pasirinkti ką naudosite galutinio balo skaičiavimui, namų darbų vidurkį ar medianą (Įvesti "v" arba "m").
- Jei norite sugeneruoti studentų sąrašą įveskite "y", jei nenorite - "n". Pasirinkus "y", įveskite kiek įrašų sąraše norite generuoti.
- Jei norite nuskaityti duomenis iš failo "kursiokai.txt" įveskite "y", jei nenorite - "n".
- Įveskite skaičių studentų, kurių duomenis norite įrašyti.
- Jei studentų skaičių pasirinkote didesnį, nei 0, įveskite 1-0 studento vardą, pavardę. Jei norite studento namų darbų pažymius bei egzamino rezultatą įrašyti pats/pati įveskite "i". Jei norite juos sugeneruoti automatiškai įveskite "g". Pasirinkus "i" įveskite studento namų darbų pažymius, kai norėsite sustabdyti šio studento pažymių vedimą įveskite "-1". Tada įveskite egzamino rezultatą. Pakartokite šiuos žingsnius visų studentų duomenims įvesti.

## Spartos analizė [v0.4]

```
Faile generuojamų įrašų kiekis      Programos veikimo laikas

10                                  0.0072s
100                                 0.0089s
1000                                0.0159s
10000                               0.0748s
100000                              0.6115s
```

## Konteinerių spartos analizė [v0.5]

```
Konteineris      Naudojamų įrašų kiekis      Nuskaitymas       Rusiavimas

Vector           10                          0.0005s           0.0000s
Vector           100                         0.0009s           0.0000s
Vector           1000                        0.0043s           0.0000s
Vector           10000                       0.0351s           0.0002s
Vector           100000                      0.3633s           0.0021s

Deque            10                          0.0005s           0.0000s
Deque            100                         0.0008s           0.0000s
Deque            1000                        0.0040s           0.0000s
Deque            10000                       0.0364s           0.0005s
Deque            100000                      0.3497s           0.0052s

List             10                          0.0005s           0.0000s
List             100                         0.0008s           0.0000s
List             1000                        0.0036s           0.0000s
List             10000                       0.0296s           0.0004s
List             100000                      0.3272s           0.0036s
```

## Konteinerių spartos analizė [v1.0]

Versijose v0.4 ir v0.5 studentai į "vargšiukus" ir "kietiakus" buvo skirstomi įrašu struktūroje, o ne keliant studentus į kitą/kitus konteinerius. 

**1 strategija** - Tas pats studentas yra dvejuose konteineriuose: bendrame studentai ir viename iš suskaidytų (vargšiukai arba kietiakai).

```
Konteineris     Naudojamų įrašų kiekis      Nuskaitymas+     Rusiavimas          Rikiavimas      Isvedimas       Viso
                                  StudentList.txt generavimas
Vector          10                          0.0186s          0.0000s             0.0000s         0.0072s         0.0259s
Vector          100                         0.0216s          0.0000s             0.0000s         0.0090s         0.0307s      
Vector          1000                        0.0428s          0.0006s             0.0004s         0.0166s         0.0658s      
Vector          10000                       0.2492s          0.0039s             0.0061s         0.0725s         0.3319s
Vector          100000                      2.3116s          0.0447s             0.0785s         0.5732s         3.0110s

Deque           10                          0.0192s          0.0000s             0.0000s         0.0075s         0.0267s
Deque           100                         0.0224s          0.0001s             0.0000s         0.0084s         0.0308s
Deque           1000                        0.0439s          0.0003s             0.0005s         0.0163s         0.0642s
Deque           10000                       0.2427s          0.0026s             0.0074s         0.1086s         0.3612s
Deque           100000                      2.2807s          0.0280s             0.1026s         0.5981s         3.0093s

List            10                          0.0184s          0.0000s             0.0000s         0.0082s         0.0266s
List            100                         0.0237s          0.0001s             0.0000s         0.0083s         0.0321s
List            1000                        0.0454s          0.0003s             0.0001s         0.0181s         0.0638s
List            10000                       0.2446s          0.0023s             0.0023s         0.1177s         0.3669s
List            100000                      2.3420s          0.0228s             0.0407s         0.5852s         2.9908s
```

**2 strategija** - Jei studentas yra vargšiukas, jis įkeliamas į naująjį "vargšiukų" konteinerį ir ištrinamas iš bendro studentai konteinerio. Po šio žingsnio studentai konteineryje lieka vien tik kietiakai.

```
Konteineris     Naudojamų įrašų kiekis      Nuskaitymas+     Rusiavimas          Rikiavimas      Isvedimas       Viso
                                    StudentList.txt generavimas
Vector          10                          0.0197s          0.0000s             0.0000s         0.0075s         0.0272s
Vector          100                         0.0262s          0.0000s             0.0000s         0.0089s         0.0352s      
Vector          1000                        0.0517s          0.0003s             0.0004s         0.0159s         0.0684s      
Vector          10000                       0.2542s          0.0030s             0.0064s         0.0694s         0.3330s
Vector          100000                      2.3035s          0.0354s             0.0820s         0.5603s         2.9811s

Deque           10                          0.0190s          0.0000s             0.0000s         0.0080s         0.0271s
Deque           100                         0.0211s          0.0000s             0.0000s         0.0086s         0.0298s
Deque           1000                        0.0447s          0.0003s             0.0005s         0.0160s         0.0645s
Deque           10000                       0.2605s          0.0029s             0.0068s         0.0712s         0.3414s
Deque           100000                      2.2826s          0.0305s             0.0941s         0.5864s         2.9937s

List            10                          0.0179s          0.0000s             0.0000s         0.0074s         0.0254s
List            100                         0.0196s          0.0001s             0.0000s         0.0097s         0.0294s
List            1000                        0.0476s          0.0003s             0.0001s         0.0169s         0.0649s
List            10000                       0.2534s          0.0029s             0.0011s         0.0749s         0.3323s
List            100000                      2.3251s          0.0324s             0.0286s         0.6864s         3.0725s
```

## Programos spartos analizė, pritaikius algoritmus, naudojant `std::vector` [v1.0]

```
Naudojamų įrašų kiekis      Be algoritmų       Su algoritmais

10                          0.0235s            0.0272s
100                         0.0330s            0.0352s
1000                        0.0741s            0.0684s
10000                       1.1543s            0.3330s
100000                     89.8005s            2.9811s
```
- Skiltyje "Be algoritmų" nurodyta programos sparta naudojant tik `vector.erase()` funkciją.

- Skiltyje "Su algoritmais" nurodyta programos sparta pritaikius `std::remove_if` algoritmą.

## iterpkKietus() ir raskMinkstus() funkcijų spartos analizė [Papildoma uzduotis]

```
Naudojamų įrašų kiekis    raskMinkstus()                iterpKietus()            std::Vector pakeistas į std::deque

10000                      0.5386s                       1.9865s                 0.0059s
100000                    54.5750s                     194.5236s                 0.0454s
```

## Struct ir class palyginimas [v1.1]

```
Struct
Konteineris     Naudojamų įrašų kiekis      Nuskaitymas+     Rusiavimas          Rikiavimas      Isvedimas       Viso
                                   StudentList.txt generavimas    
Vector          10000                       0.2542s          0.0030s             0.0064s         0.0694s         0.3330s
Vector          100000                      2.3035s          0.0354s             0.0820s         0.5603s         2.9811s

Class
Konteineris     Naudojamų įrašų kiekis      Nuskaitymas+     Rusiavimas          Rikiavimas      Isvedimas       Viso
                                   StudentList.txt generavimas    
Vector          10000                       0.2522s          0.0028s             0.0097s         0.0687s         0.3334s
Vector          100000                      2.4438s          0.0292s             0.1190s         0.5474s         3.1393s
```

## Kompiliatoriaus optimizavimo flag'u palyginimas [v1.1]

```
Flag 01
Konteineris     Naudojamų įrašų kiekis      Nuskaitymas+     Rusiavimas          Rikiavimas      Isvedimas       Viso
                                  StudentList.txt generavimas    
Vector          10000                       0.2915s          0.0030s             0.0114s         0.0712s         0.3771s
Vector          100000                      2.5094s          0.0296s             0.1300s         0.5583s         3.2273s

Flag 02
Konteineris     Naudojamų įrašų kiekis      Nuskaitymas+     Rusiavimas          Rikiavimas      Isvedimas       Viso
                                  StudentList.txt generavimas    
Vector          10000                       0.2522s          0.0028s             0.0097s         0.0687s         0.3334s
Vector          100000                      2.4438s          0.0292s             0.1190s         0.5474s         3.1393s

Flag 03
Konteineris     Naudojamų įrašų kiekis      Nuskaitymas+     Rusiavimas          Rikiavimas      Isvedimas       Viso
                                  StudentList.txt generavimas    
Vector          10000                       0.2679s          0.0032s             0.0095s         0.0710s         0.3516s
Vector          100000                      2.5070s          0.0334s             0.1157s         0.5553s         3.2114s
```

## Versijų istorija (changelog)

### [v1.1](https://github.com/Elijus99/OPP_2uzd_DuomenuApdorojimas/releases/tag/v1.1) - (2019-04-10)

**Koreguota**

- `struct stud` pakeistas į `class stud`.
- Dalis funkcijų integruotos į `class stud`.
- Papildytas **README** failas.

**Pridėta**

- Sukurti failai student.cpp ir student.h, kuriuose aprašoma `class stud` ir su jos nariais susijusos funkcijos.

### [Papildoma uzduotis](https://github.com/Elijus99/OPP_2uzd_DuomenuApdorojimas/releases/tag/v0.4p) - (2019-03-24)

**Pridėta** 

- Sukurta funkcija raskMinkstus().
- Funkcija raskMinkstus() modifikuota, pakeistas pavadinimas į iterpkKietus().
- Atlikta funkcijų raskMinkstus() ir iterpkKietus() spartos analizė.

**Koreguota**

- Papildytas **README** failas

### [v1.0](https://github.com/Elijus99/OPP_2uzd_DuomenuApdorojimas/releases/tag/v1.0) - (2019-03-09)

**Pridėta**

- Optimizuotas studentų rūšiavimas į "vargšiukus" ir "kietiakus".
- Pateikti konteinerių spartos analizės duomenys skirtingoms rūšiavimo strategijoms.
- Programai pritaikyti algoritmai.
- Pateikti vektoriaus spartos analizės duomenys prieš bei po algoritmų pritaikymo.

**Koreguota**

- Papildytas **README** failas

### [v0.5](https://github.com/Elijus99/OPP_2uzd_DuomenuApdorojimas/releases/tag/v0.5) - (2019-03-01)

**Pridėta**

- Atlikta konteinerių spartos analizė.

**Koreguota**

- `std::vector<stud>` pakeistas į `std::deque<stud>` dėl didesnės spartos
- Papildytas **README** failas

### [v0.4](https://github.com/Elijus99/OPP_2uzd_DuomenuApdorojimas/releases/tag/v0.4) - (2019-02-26)

**Pridėta**

- Studentų sąrašų failų generavimas
- Studentų rūšiavimas į "vargšiukus" (galutinis balas < 5.0) ir "kietiakus" (galutinis balas >= 5.0) ir jų išvedimas į atskirus failus
- Programos spartos analizė

**Koreguota**

- Papildytas **README** failas

### [v0.3](https://github.com/Elijus99/OPP_2uzd_DuomenuApdorojimas/releases/tag/v0.3) - (2019-02-22)

**Koreguota**

- Atliktas kodo refactoring'as (sukurti failai functions.cpp, functions.h, libraries.h, į juos perkelta atitinkamos kodo dalys)
- Panaudotas Exception Handling'as
- Papildytas **README** failas

### [v0.2](https://github.com/Elijus99/OPP_2uzd_DuomenuApdorojimas/releases/tag/v0.2) - (2019-02-17)

**Pridėta**

- Duomenų nuskaitymas iš "kursiokai.txt" failo
- Studentų sąrašas rikiuojamas abėcėlės tvarka (Norint, kad programa rikiuotų tvarkingai, vardai turi prasidėti iš didžiosios raidės)

**Koreguota**

- Papildytas **README** failas

### [v0.1](https://github.com/Elijus99/OPP_2uzd_DuomenuApdorojimas/releases/tag/v0.1) - (2019-02-16)

**Pridėta**

- Pirmoji programos versija
