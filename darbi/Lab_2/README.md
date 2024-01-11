# 2. laboratorijas darbs "Skaitliskās metodes"
## Dihotomijas metode sakņu atrašanai

Dihotomijas metode, kas pazīstama arī kā intervālu dalīšanas metode, ir vienkārša, bet efektīva skaitliskā metode sakņu atrašanai. Tās būtība ir intervāla robežas, kurā atrodas sakne, pakāpeniskā sašaurināšana. Tas tiek realizēts, dalot intervālu uz pusēm un izvēloties to pusintervālu, kurā sakne atrodas (skatīt Attēls 1). Procesu atkārto tik ilgi, līdz tiek sasniegta vēlamā precizitāte. Laboratorijas darba laikā tika izstrādāta C programma, kas implementē dihotomijas metodi.

![Dihotomijas metodes ilustrācija](bildes/Bisection-method.jpg)

*Attēls 1: Dihotomijas metodes ilustrācija.*

Avots: [ResearchGate]([https://www.example.com](https://www.researchgate.net/figure/Bisection-method-This-Bisection-method-states-that-if-fx-is-continuous-which-is-defined_fig2_336638530))


Attēlā redzama funkcijas grafika ilustrācija ar atzīmētām intervāla dalīšanas vietām, kas norāda uz dihotomijas metodes soļiem sakņu atrašanai.

## Funkcijas `sin(x)^2` un tās variācijas

Laboratorijas darba ietvaros tika analizēta funkcija `sin(x)^2` un tās variācijas. Ar gnuplot tika vizuāli attēlotas `sin(x)^2`, `sin(x)^2 - 0.5`, un `sin(x)^2 - 1` funkcijas, kur nobīdes _A_ vertība _A=0; A=0.5; A=1_, kā piemērus, lai grafiski parādītu, kur grafiki krusto _x asi_ - saknes.

![Funkcijas `sin(x)^2` un tās variācijas](bildes/sinkvadrats.png)

## Programmas koda analīze

**Galvenā funkcija `main()`:**

- Šajā funkcijā lietotājs tiek lūgts ievadīt funkcijas izteiksmi un intervālu, kurā meklēt saknes.
- Tiek ģenerēti dati funkcijas grafika uzzīmēšanai.
- Tālāk tiek izsaukta funkcija `find_root_graphically()`, lai vizuāli identificētu iespējamās saknes.
- Beigās tiek parādīts funkcijas grafiks ar atzīmētām iespējamām saknēm.

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
