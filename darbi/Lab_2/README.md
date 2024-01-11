# 2. laboratorijas darbs "Skaitliskās metodes"
## Dihotomijas metode sakņu atrašanai (Funkcijai sin(x)^2 un tās nobīdēm)

Dihotomijas metode, kas pazīstama arī kā intervālu dalīšanas metode, ir vienkārša, bet efektīva skaitliskā metode sakņu atrašanai. Tās būtība ir intervāla robežas, kurā atrodas sakne, pakāpeniskā sašaurināšana. Konkrētāk, ja funkcijas vērtības abos intervāla galapunktos ir pretējās zīmes, tad saskaņā ar starpvērtību teorēmu (ja funkcija ir nepārtraukta) intervālā ir vismaz viena sakne. Turpina šo procesu, iteratīvi sašaurinot intervālu, līdz tiek sasniegta vēlamā precizitāte saknes atrašanai (skatīt *Attēls 1*). Laboratorijas darba laikā tika izstrādāta C programma, kas implementē dihotomijas metodi funkcijai `sin(x)^2` un tās nobīdēm.

![Dihotomijas metodes ilustrācija](bildes/Bisection-method.jpg)

*Attēls 1: Dihotomijas metodes ilustrācija.*

Avots: [ResearchGate]([https://www.example.com](https://www.researchgate.net/figure/Bisection-method-This-Bisection-method-states-that-if-fx-is-continuous-which-is-defined_fig2_336638530))


Attēlā redzama Dihotomijas metode - ja funkcijas vērtības abos intervāla galapunktos ir pretējās zīmes, tad saskaņā ar starpvērtību teorēmu (ja funkcija ir nepārtraukta) intervālā ir vismaz viena sakne. Bisekcijas metode turpina šo procesu, iteratīvi sašaurinot intervālu, līdz tiek sasniegta vēlamā precizitāte saknes atrašanai.

## Funkcijas sin(x)^2 un tās variācijas

Laboratorijas darba ietvaros tika analizēta funkcija `sin(x)^2` un tās variācijas. Ar gnuplot tika vizuāli attēlotas `sin(x)^2`, `sin(x)^2 - 0.5` un `sin(x)^2 - 1` funkcijas, kur nobīdes _A_ vertība ir _A=0; A=0.5; A=1_, kā piemērus, lai grafiski parādītu, kur grafiki krusto _x asi_ - saknes.

![Funkcijas `sin(x)^2` un tās variācijas](bildes/sinkvadrats.png)

*Attēls 2: Funkcijas sin(x)^2 un tās variācijas.*

## Programmas rezultāts ar sin(x)^2-A, kur A=0.5
Kā var redzēt *Attēls 2* funkcijai `sin(x)^2` sakne intervālā [0;1.5] ir `x = π/4`, kas ir aptuveni `0.78539816339`. Izpilot kodu ar precizitāti `0.001` un iterāciju skaitu `785`  tika iegūts, ka sakne `x = 0.784993469715118408203125`, kas ir ļoti tuva vērtība `π/4`. Skatīt rezultātu zemāk:
```shell
sin(x)^2-A sakņu meklētājs (Dihotomijas metode)
---------------------------------------------------
Lūdzu ievadiet mazākās robežas 'a' vērtību: 0
Lūdzu ievadiet lielākās robežas 'b' vērtību: 1.5
Saknes meklēšanas intervāls [0.000;1.500]
---------------------------------------------------
Lūdzu ievadiet nobīdes A vērtību (funkcija tiks bīdīta uz leju vai augšu) A = 0.5
Lūdzu ievadiet precizitātes vērtību (piem. 0.001): 0.001
---------------------------------------------------
Sakne atrodas tuvu pie vērtībām: 
         x = 0.784993469715118408203125000000
         sin(0.7850)^2 - 0.50000 = -0.000404693651944398880004882812
Vajadzīgais iterāciju skaits pie precizitātes 0.001000 ir 785
```
## Programmas koda analīze

**Programmas darbība:**

1. Lietotājs ievada intervāla robežas `a` un `b`, kā arī nobīdes vērtību `A`, kas pārvieto funkciju `sin(x)^2` uz augšu vai leju, un precizitātes vērtību `delta_x`. Šīs vērtības nosaka intervālu, kurā programma meklēs **funkcijas sakni**, un **precizitāti**, ar kādu tā tiks noteikta.

2. Pirms saknes meklēšanas uzsākšanas, programma pārbauda, vai dotajā intervālā ir iespējams atrast sakni. Ja funkcijas vērtības intervāla galapunktos ir vienādas zīmes un A nav nulle, tas var liecināt par to, ka intervālā nav sakņu vai sakņu skaits ir pāra. Tā kā `sin(x)^2` funkcija bez nobīdes nav negatīva, tad jaizpildās nosacījumiem, kuri ir pret Dihotomijas metodes, bet lai programma darbotos, tika veikti uzlabojumi:
A = 0 un A = 1, tad sin(x) * sin(b) > 0, bet ja A nav nulle un A nav 1, tad sin(x) * sin(b) < 0, jo Dihotomijas metodē pieņem, ka funkcijas vērtības šajos galapunktos ir pretējas zīmes (f(a) * f(b) < 0), kas norāda uz to, ka sakne atrodas intervālā, balstoties uz starpvērtību teorēmu. Bet sin(x)^2 funkcija bez nobīdes vai arī nobīdot 1 vienību uz leju neveido pretējas zīmes.

3. Ja sākotnējā pārbaudē netiek konstatēti iepriekš minētie apstākļi, programma sāk iteratīvu procesu, lai atrastu sakni. Tas notiek, palielinot x vērtību par delta_x soli līdz brīdim, kad tiek sasniegta intervāla beigu vērtība.

4. Katrā iterācijas solī tiek pārbaudīts, vai funkcijas vērtība pie kāda x ir pietiekami tuva nullei (mazāka par delta_x). Ja šāds tuvinājums tiek atrasts, programma izvada saknes tuvinātās koordinātas un attiecīgās funkcijas vērtības, kā arī iterāciju skaitu, kas bija nepieciešams, lai sasniegtu šo precizitāti.

5. sin_kvadrata funkcija tiek definēta programmā, lai aprēķinātu un atgrieztu sin(x)^2 - A vērtību, kur A ir nobīde.

6. Ja programma iterācijas procesā neatrod sakni, tā ieteiks lietotājam samazināt precizitāti (delta_x) un mēģināt vēlreiz.

Šīs programmas izstrādē ir svarīgi atcerēties, ka `C valodā` _sin_ funkcijas argumentam ir jābūt **radiānos**, nevis grādos. Tādēļ, ja lietotājs ievadīs grādus, tie būs jāpārveido pirms funkcijas izmantošanas. Turklāt, _sin_ funkcija un matemātiskās operācijas, kas nepieciešamas `sin_kvadrata` funkcijai, prasa matemātikas bibliotēkas `(math.h)` saiti kompilācijas laikā, kas tiek nodrošināta ar `-lm` kompilācijas opciju.

## Programmas palaišanas apraksts

Saglabājiet kodu .c failā, piemēram, kā ir dots `2ld_roots.c`.
Atveriet termināli un ejiet uz direktoriju, kur atrodas fails.

Kompilējiet programmu, izmantojot GCC vai citu C kompilatoru, ar šādu komandu:
```shell
$ gcc 2ld_roots.c -o saknes.out -lm
```
Lai palaistu failu:
```shell
$ ./saknes.out
```
