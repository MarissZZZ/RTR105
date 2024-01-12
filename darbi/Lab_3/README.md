# 3. laboratorijas darbs "Skaitliskās metodes"
## Skaitliskā diferencēšana funkcijai sin(x)^2
Skaitliskā diferencēšana ir metode, ko izmanto, lai aptuveni aprēķinātu funkcijas atvasinājumu noteiktā punktā. Šī metode ir īpaši noderīga, ja atvasinājuma analītiskā forma ir sarežģīta vai nezināma. Skaitliskā diferencēšana aptuveni aprēķina atvasinājumu, izmantojot funkcijas vērtības noteiktos punktos. Laboratorijas darbā tiek apskatīta funkcijas sin(x)^2 skaitliskā diferencēšana, izmantojot C programmēšanas valodu. Kods sastāv no funkcijām, lai aprēķinātu sin(x)^2 un tās pirmās un otrās kārtas atvasinājumus, analītiski un skaitliski diferencējot.

## Programmas koda struktūra
**1. Funkcijas definīcijas:**
- `sin_kvadrats(float x)`: Aprēķina sin^2(x).
- `pirmais_analit(float x)`: Aprēķina sin^2(x) pirmo analītisko atvasinājumu.
- `otrais_analit(float x)`: Aprēķina sin^2(x) otro analītisko atvasinājumu.

**2. Atvasinājumu aproksimācijas:**
- `pirmais_parnest(float x, float delta_x)`: Aprēķina sin^2(x) pirmās kārtas atvasinājumu izmantojot skaitlisko diferencēšanu.
- `otrais_parnest(float x, float delta_x)`: Aprēķina sin^2(x) otrās kārtas atvasinājumu izmantojot skaitlisko diferencēšanu.

**3. Galvenā funkcija `(main)`:**
- Nolasa ievades vērtības.
- Veic aprēķinus intervālā no `a` līdz `b` ar precizitāti `delta_x`.
- Rezultātus izvada gan konsolē, gan ieraksta failā `derivative.dat`.

## Programmas koda analīze

**Programmas darbība:**

1. Lietotājam jāievada sākuma un beigu vērtības `(a un b)`, kā arī diferencēšanas solis `(delta_x)`
2. Pēc šo vērtību ievades, programma aprēķina un izvada:
- `sin(x)^2` vērtības;
- `sin(x)^2` **pirmo** un **otro atvasinājumu** gan analītiski, gan izmantojot skaitlisko diferencēšanu (intervālā no `a` līdz `b`).
- Rezultāti tiek ierakstīti failā `derivative.dat`, kurā tiek saglabāti gan analītiskie, gan skaitliskie atvasinājumi noteiktam `x` vērtību diapazonam.
  
## Atvasinājuma vērtības aprēķināšana

**Pirmās kārtas atvasinājums:**

1. _Analītiskā metode_ `(pirmais_analit funkcija)`: pirmās kārtas atvasinājums tiek aprēķināts izmantojot matemātisko analīzi. Šajā gadījumā, `sin(x)^2` pirmā kārtas atvasinājums ir `2sin(x)cos(x)`.
2. _Skaitliskā metode_ `(pirmais_parnest funkcija)`: pirmās kārtas atvasinājums tiek aprēķināts izmantojot skaitlisko diferencēšanu ar tiešās atšķirības metodi. Šeit izmanto izteiksmi `(sin(x + delta_x)^2 - sin(x)^2) / delta_x`,
kur:

`(sin(x + delta_x)^2` - Tā ir `sin(x)^2` vertība pie `x + delta_x`, kur `delta_x` ir maza pieauguma vērtība, kas tiek pievienota `x`.
`sin(x)^2` - Tā ir `sin(x)` vertība pie `x`.
`(sin(x + delta_x)^2 - sin(x)^2)` - Šī izteiksme aprēķina funkcijas izmaiņu starp šiem diviem punktiem.
`delta_x` - Dalot šo izmaiņu ar `delta_x`, iegūst vidējo izmaiņas ātrumu šajā intervālā.

Kad `delta_x` tuvojas nullei, šī formula tuvojas pirmā kārtas atvasinājumam `sin(x)^2`. Tomēr skaitliskajā diferencēšanā izmanto nelielu, bet fiksētu `delta_x` vērtību.

Šī metode ir noderīga, ja funkcija ir sarežģīta vai nav iespējams atrast analītisko atvasinājumu.

**Otrās kārtas atvasinājums:**

1. _Analītiskā metode_ `(otrais_analit funkcija)`: otrās kārtas atvasinājums tiek aprēķināts, veicot pirmās kārtas atvasinājuma atkārtotu atvasināšanu. `sin^2(x)` otrās kārtas atvasinājums ir `2cos^2(x) - 2sin^2(x)`.
2. _Skaitliskā metode_ `(otrais_parnest funkcija)`: Līdzīgi pirmajam gadījumam, otrās kārtas atvasinājums tiek aprēķināts izmantojot skaitlisko diferencēšanu: `(sin(x + delta_x)^2 - 2sin(x)^2 + sin(x - delta_x)^2) / delta_x^2`,
kur:

`sin(x + delta_x)^2` un `sin(x - delta_x)^2` - Tās ir `sin(x)^2` vērtības pie x + delta_x un x - delta_x.
Šeit `delta_x` ir maza vērtība, kas tiek pievienota un atņemta no `x`.
`2sin(x)^2`: Divreizēja `sin^2(x)` vērtība pašreizējā punktā `x`.
`(sin(x + delta_x)^2 - 2sin(x)^2 + sin(x - delta_x)^2)`: Šī izteiksme aprēķina funkcijas izmaiņu šajā intervālā.
`delta_x^2`: Dalot šo izmaiņu ar kvadrātu δx, iegūst vidējo izmaiņas ātrumu attiecībā pret `x` izmaiņu kvadrātu.

Arī šajā gadījumā mazākas `delta_x` vērtības nodrošina precīzākus rezultātus, bet praksē tiek izmantotas fiksētas vērtības.

## Programmas palaišanas apraksts

Saglabājiet kodu .c failā, piemēram, kā ir dots `3ld_derivative.c`.
Atveriet termināli un ejiet uz direktoriju, kur atrodas fails.

Kompilējiet programmu, izmantojot GCC vai citu C kompilatoru, ar šādu komandu:
```shell
$ gcc 3ld_roots.c -o derivative.out -lm
```
Lai palaistu failu:
```shell
$ ./derivative.out
```

## Programmas rezultāts

