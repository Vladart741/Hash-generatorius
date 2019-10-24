# Hash-generatorius
v.01 - Veikia char konvertavimas į int reikšmę, tačiau neveikia maišos funkcija. Reikia sugalvoti tinkamą funkciją, kad neatsirastų dėsningumo, nes dėl jo po n-simbolių tam tikros hash'o dalis pradeda kartotis.

v.02 - Hash-generatorius daugmaž veikia, tačiau yra trūkumas - neskiria didžiųjų nuo mažųjų raidžių.

v.03 - Veikiantis Hash-generatorius, beliko atlikti numatytus testavimus

# Testavimas:

### 1. Susikurkite testinių įvedimo failų pavyzdžių, tokių kad:
 ### - Bent du failai būtų sudaryti tik iš vieno, tačiau skirtingo, simbolio.

Buvo atlikti testavimai su dviem failais, kuriuose viename buvo v, kitame l raidės. Gauti tokie rezultatai: 
 
| Įvedimas (*input*) | Išvedimas                     |
| ------------------ | ------------------------------------------------------------ |
| v            | 79877d9fab6057544f68ae557aae8e9192718ea665669a56848e8a8ca4ac8270 |
| l            | 47554b6d792e25221d367c23487c5c5f603f5c7433346824525c585a727a503e | 

P.S. simbolių skaičius vienodas, raidė f siauresnė nei kitos
  
###  - Bent du failai būtų sudaryti iš daug visiškai skirtingų simbolių (> 10000 simbolių)

Buvo atlikti testavimai su dviem failais, kuriuose viename buvo >10000 simbolių. Gauti tokie rezultatai:

| Įvedimas (*input*) | Išvedimas                     |
| ------------------ | ------------------------------------------------------------ |
| 51100e6lag7180rk...| dbe9df333fc2b9b6b1ca10b7dc10f0f3f4d3f03ac7c8fcb8e6f0ecee3840e4d2 |
| hew8pne0anndc8os...| 717f7597a3584f4c4760a64d72a686898a69869e5d5e924e7c8682849ca47a68 | 

###  - Bent du failai būtų sudaryti iš daug simbolių ir skirtųsi vienas nuo kito tik vienu simboliu.

Buvo atlikti testavimai su tais pačiais failais iš antros uždoties, tik buvo pakeistas pirmas simbolis. Gauti tokie rezultatai:

| Įvedimas (*input*) | Išvedimas                     |
| ------------------ | ------------------------------------------------------------ |
| 51100e6lag7180rk...| dbe9df333fc2b9b6b1ca10b7dc10f0f3f4d3f03ac7c8fcb8e6f0ecee3840e4d2 |
| ž1100e6lag7180rk...| 37133b2b37ece3e0dbf43ae1383a1a1d1efd1a32f1f226e2101a1618303840fc | 


### - Tuščias failas
  
 | Įvedimas (*input*) | Išvedimas                     |
| ------------------ | ------------------------------------------------------------ |
| (tuščias)          | 23312749553c33fef91258ff2458383b3c1b3850411044322e3834364e562c1a |


### 2. Ištirkite Jūsų sukurtos hash funkcijos efektyvumą: tuo tikslu suhash'uokite kiekvieną eilutę iš [konstitucija.txt](https://github.com/blockchain-group/Blockchain-technologijos/blob/master/pratybos/konstitucija.txt) failo. Reiktų čia matuoti, tik hash'avimo funkcijos veikimo laiką (be input'o nuskaitymo/parengimo). Reiktų pateikti bendrą suminį visų hash'avimų laiką.

Buvo atliktas konstitucijos hash'avimas, eilutė po eilutės ir tai buvo atlikta per 0.03421991 sekundės:
P.S. į laiką neįskaičiuotas nuskaitymas ir įrašimas į failą.

![image](https://user-images.githubusercontent.com/12825358/67531037-b0685e00-f6c9-11e9-9fe1-4611bb9b7f14.png)

Įvestis:

![image](https://user-images.githubusercontent.com/12825358/67528819-130a2b80-f6c3-11e9-9a56-d001d97eacfe.png)

Išvestis:

![image](https://user-images.githubusercontent.com/12825358/67531078-ddb50c00-f6c9-11e9-991e-2ff250ad506d.png)

