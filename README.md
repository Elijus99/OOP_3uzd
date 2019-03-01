# Duomenų apdorojimas (2 užduotis)

## Užduoties aprašymas
- Parašykite programą, kuri nuskaito šiuos studentų duomenis:
- vardą ir pavardę
- n atliktų namų darbų (nd) rezultatus (10-balėje sistemoje), o taip pat egzamino (egz) rezultatą.
- Tuomet iš šių duomenų, suskaičiuoja galutinį balą (galutinis):  
`galutinis = 0.4 * vidurkis/mediana + 0.6 * egzaminas`
 - Duomenys pateikiami į ekraną tokiu ar panašiu pavidalu (kur galutinis apskaičiuotas balas pateikiamas dviejų skaičių po kablelio tikslumu):
``` 
Pavardė     Vardas       Galutinis (Vid.) / Galutinis (Med.)
-----------------------------------------------------------
Arvydas     Sabonis      x.xx               x.xx
Rimas       Kurtinaitis  y.yy               y.yy
...
```

## Įdiegimas (Unix kompiuteryje) naudojant `Clang` kompiliatorių 

- `git clone https://github.com/Elijus99/OPP_2uzd_DuomenuApdorojimas.git`
- `cd OPP_2uzd_DuomenuApdorojimas`
- `make`
- `make test`

## Spartos analizė [v0.4]

```
Faile generuojamų įrašų kiekis      Programos veikimo laikas       Programos veikimo laikas(su vardų rikiavimu pagal abėcėlę)

10                                  0.0316s                        0.0341s
100                                 0.0553s                        0.0564s
1000                                0.2603s                        0.3338s
10000                               2.0908s                        3.0262s
100000                             19.4860s                       31.4563s
```

## Konteinerių spartos analizė [v0.5]

```
Naudojamų įrašų keikis      Vector            List              Deque

10                          0.0063s           0.0057s           0.0062s
100                         0.0182s           0.0146s           0.0155s
1000                        0.1365s           0.1147s           0.1328s
10000                       1.3200s           1.0791s           1.1157s
100000                     12.4403s           9.4744s           9.6988s
```

## Versijų istorija (changelog)

### [v0.5](https://github.com/Elijus99/OPP_2uzd_DuomenuApdorojimas/releases/tag/v0.5) - (2019-03-01)

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
