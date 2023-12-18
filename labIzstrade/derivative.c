#undef __STRICT_ANSI__

#include<stdio.h>
#include<math.h>

void main() {
    float a = 0., b = 2 * M_PI, x, delta_x = 1.e-2;
    //floaty;
    printf("\tx\t\tsin(x)\t\tsin\'(x)\n");
    x = a;
    
    while(x<b){
        //y=sin(x);
        printf("%10.2f\t%10.2f\t%10.2f\n",x,sin(x),cos(x));
        //printf(”%10.2f\t%10.2f\n”,x,y);
        x+=delta_x;//x=x+delta_x;
    }
}