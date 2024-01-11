# 2. laboratorijas darbs "Skaitliskās metodes"
## Grafiskā metode funkcijas sakņu atrašanai

Grafiskā metode ir vienkārša un vizuāla skaitliskā metode, kas ļauj tuvināti noteikt funkcijas saknes. Šī metode ir īpaši noderīga, lai vizuāli identificētu funkcijas krustpunktu ar x asi, kas atbilst funkcijas saknei. Grafiskā metode ļauj vizuāli novērtēt funkcijas sakņu atrašanās vietas intervālā. Laboratorijas darba laikā tika izstrādāta C programma, kas ļauj uzzīmēt funkcijas grafiku un vizuāli identificēt iespējamās saknes.

![Funkcijas grafiks ar iespējamām saknēm](bildes/sinkvadrats.png)

Attēlā ir parādīts funkcijas grafiks, kas uzzīmēts, izmantojot gnuplot. Grafiks ļauj vizuāli identificēt punktus, kur funkcijas grafiks šķērso x asi, kas norāda uz iespējamām saknēm. Šī metode ir noderīga, lai iegūtu sākotnējo tuvinājumu saknei, kas pēc tam var tikt precizēts, izmantojot citas skaitliskās metodes.

## Grafiskās metodes piemērošana

Sākumā tika izmantots gnuplot, lai uzzīmētu funkcijas `f(x)` grafiku:
![Funkcijas f(x) grafiks](bildes/funkcijas_grafiks.png)

## Programmas koda analīze

**Funkcija `find_root_graphically()`:**

- Šī funkcija palīdz identificēt funkcijas saknes grafiski.
- Sākumā tiek ģenerēti dati funkcijas grafika uzzīmēšanai.
- Tad tiek izmantots gnuplot, lai vizuāli parādītu funkcijas grafiku un iespējamās saknes.
- Katrā iterācijā tiek parādīts funkcijas grafiks ar aizvien precīzākiem intervāliem.
- Beigās funkcija sniedz vizuālu informāciju par iespējamām saknēm.

**Galvenā funkcija `main()`:**

- Šajā funkcijā lietotājs tiek lūgts ievadīt funkcijas izteiksmi un intervālu, kurā meklēt saknes.
- Tiek ģenerēti dati funkcijas grafika uzzīmēšanai.
- Tālāk tiek izsaukta funkcija `find_root_graphically()`, lai vizuāli identificētu iespējamās saknes.
- Beigās tiek parādīts funkcijas grafiks ar atzīmētām iespējamām saknēm.

## Programmas darbības apraksts

Saglabājiet kodu .c failā, piemēram, `2ld_roots.c`.
Atveriet termināli vai komandrindu un ejiet uz direktoriju, kur atrodas fails.
Kompilējiet programmu, izmantojot GCC vai citu C kompilatoru. Piemēram:

```shell
$ gcc 2ld_roots.c -o roots_finder.out -lm
