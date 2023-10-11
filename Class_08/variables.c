#include <stdio.h>

int main(void)
 {
 int i; //dikstrētā mainīgā deklarēšana - noteikta izmēra (atbilstoši datu
        //tipam) atmiņas apgabala - int => 4 bytes - precīzi tūlīt uzzināsim
        //atmiņas apgabala sasaistīšana ar norādīto identifikatoru
        //NB! vērtība nav zināma
 printf("i mainīgā izmērs baitos): %ld\n",sizeof(i));
 printf("i mainīgā atrašanās vietas atmiņa (adrese jeb norāde): %p\n",&i);
 printf("i mainīgā vērtība uzreiz pēc deklarēšanas (simbols*): %c\n",i);
 printf("i mainīgā vērtība uzreiz pēc deklarēšanas (dec): %d\n",i);
 printf("i mainīgā vērtība uzreiz pēc deklarēšanas (oct): %#o\n",i);
 printf("i mainīgā vērtība uzreiz pēc deklarēšanas (hex): %#x\n",i);
 printf("i mainīgā vērtība uzreiz pēc deklarēšanas (real*): %f\n",i);
 printf("i mainīgā vērtība uzreiz pēc deklarēšanas (real*): %e\n",i);
 printf("\n");

 // mainīgā "loma' ir mainīties un saglabāt kādu mums noderīgu vērtību
 i= 25; // visbiežāk mainīgā vērtības maiņai mēs pielietosim piešķiršanas operāciju
        // lielums (vertība), kas tiek sarēķināta (sagatavota) pa labi
        // toel ierakstīta atmiņas apgabalā, uz kura norāda idenifikators pa kreisi


 printf("i mainīgā izmērs baitos): %ld\n",sizeof(i));
 printf("i mainīgā atrašanās vietas atmiņa (adrese jeb norāde): %p\n",&i);
 printf("i mainīgā vērtība uzreiz pēc piešķiršanas (simbols*): %c\n",i);
 printf("i mainīgā vērtība uzreiz pēc piešķiršanas (dec): %d\n",i);
 printf("i mainīgā vērtība uzreiz pēc piešķiršanas (oct): %#o\n",i);
 printf("i mainīgā vērtība uzreiz pēc piešķiršanas (hex): %#x\n",i);
 printf("i mainīgā vērtība uzreiz pēc piešķiršanas (real*): %f\n",i);
 printf("i mainīgā vērtība uzreiz pēc piešķiršanas (real*): %e\n",i);
 printf("\n");
 
 char c1 = 'A', c2=0x100, c3 = 056, c4= 78;
 float f1 = 0.0456, f2 = 1.896e2; // mainīgo definēšana
 double d1, d2; 
 printf("c1 mainīgā izmērs baitos): %ld\n",sizeof(c1));
 printf("c1 mainīgā atrašanās vietas atmiņa (adrese jeb norāde): %p\n",&c1);

 printf("c2 mainīgā izmērs baitos): %ld\n",sizeof(c2));
 printf("c2 mainīgā atrašanās vietas atmiņa (adrese jeb norāde): %p\n",&c2);
 
 printf("f1 mainīgā izmērs baitos): %ld\n",sizeof(f1));
 printf("f1 mainīgā atrašanās vietas atmiņa (adrese jeb norāde): %p\n",&f1);
 printf("f1 mainīgā vērtība uzreiz pēc piešķiršanas (simbols*): %c\n",f1);
 printf("f1 mainīgā vērtība uzreiz pēc piešķiršanas (dec): %d\n",f1);
 printf("f1 mainīgā vērtība uzreiz pēc piešķiršanas (oct): %#o\n",f1);
 printf("f1 mainīgā vērtība uzreiz pēc piešķiršanas (hex): %#x\n",f1);
 printf("f1 mainīgā vērtība uzreiz pēc piešķiršanas (real*): %f\n",f1);
 printf("f1 mainīgā vērtība uzreiz pēc piešķiršanas (real*): %e\n",f1);

 printf("f2 mainīgā izmērs baitos): %ld\n",sizeof(f2));
 printf("f2 mainīgā atrašanās vietas atmiņa (adrese jeb norāde): %p\n",&f2);
 
 printf("d1 mainīgā izmērs baitos): %ld\n",sizeof(d1));
 printf("d1 mainīgā atrašanās vietas atmiņa (adrese jeb norāde): %p\n",&d2);

 printf("d2 mainīgā izmērs baitos): %ld\n",sizeof(d2));
 printf("d2 mainīgā atrašanās vietas atmiņa (adrese jeb norāde): %p\n",&d2);

 printf("\n");

 float f3 = f1; //NB! mainīgā vērtības kopēšana
 printf("f1 mainīgā izmērs baitos): %ld\n",sizeof(f1));
 printf("f1 mainīgā atrašanās vietas atmiņa (adrese jeb norāde): %p\n",&f1);
 printf("f1 mainīgā vērtība uzreiz pēc piešķiršanas (real*): %f\n",f1);
 printf("f3 mainīgā izmērs baitos): %ld\n",sizeof(f3));
 printf("f3 mainīgā atrašanās vietas atmiņa (adrese jeb norāde): %p\n",&f3);
 printf("f3 mainīgā vērtība uzreiz pēc piešķiršanas (real*): %f\n",f3);

 int *i_adrese_1 = &i;
 printf("i_adrese_1 mainīgā izmērs baitos): %ld\n",sizeof(i_adrese_1));
 printf("vērtība, kura atrodama pēc i_adrese_1 (dec): %d\n",*i_adrese_1);
 printf("vērtība, kura atrodama pēc i_adrese_1 (real*): %f\n",*i_adrese_1);

 float *i_adrese_2 = i_adrese_1; //uzmanāmies - notiek datu tipa izmaiņa
 printf("i_adrese_2 mainīgā izmērs baitos): %ld\n",sizeof(i_adrese_2));
 printf("vērtība, kura atrodama pēc i_adrese_2 (dec): %d\n",*i_adrese_2);
 printf("vērtība, kura atrodama pēc i_adrese_2 (real*): %f\n",*i_adrese_2);

 return 0;

 }
