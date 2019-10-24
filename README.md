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
| v            | 606e648692473e3b364f953c619575787958758d4c4d813d6b7571738b936957 |
| l            | 5e6c628490453c39344d933a5f9373767756738b4a4b7f3b69736f7189916755 | 

P.S. simbolių skaičius vienodas, raidė f siauresnė nei kitos
  
###  - Bent du failai būtų sudaryti iš daug visiškai skirtingų simbolių (> 10000 simbolių)

Buvo atlikti testavimai su dviem failais, kuriuose viename buvo >10000 simbolių. Gauti tokie rezultatai:

| Įvedimas (*input*) | Išvedimas                     |
| ------------------ | ------------------------------------------------------------ |
| 51100e6lag7180rk...| 98a69cbeca7f76736e87cd7499cdadb0b190adc58485b975a3ada9abc3cba18f |
| hew8pne0anndc8os...| 9eaca2c4d0857c79748dd37a9fd3b3b6b796b3cb8a8bbf7ba9b3afb1c9d1a795 | 

###  - Bent du failai būtų sudaryti iš daug simbolių ir skirtųsi vienas nuo kito tik vienu simboliu.

Buvo atlikti testavimai su tais pačiais failais iš antros uždoties, tik buvo pakeistas pirmas simbolis. Gauti tokie rezultatai:

| Įvedimas (*input*) | Išvedimas                     |
| ------------------ | ------------------------------------------------------------ |
| 51100e6lag7180rk...| 98a69cbeca7f76736e87cd7499cdadb0b190adc58485b975a3ada9abc3cba18f |
| ž1100e6lag7180rk...| a6b4aaccd88d84817c95db82a7dbbbbebf9ebbd39293c783b1bbb7b9d1d9af9d | 


### - Tuščias failas
  
 | Įvedimas (*input*) | Išvedimas                     |
| ------------------ | ------------------------------------------------------------ |
| (tuščias)          | 4a584e707c31282520397f264b7f5f6263425f7736376b27555f5b5d757d5341 |

