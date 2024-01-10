#!/usr/bin/gnuplot --persist


set terminal png
set output "sinkvadrats.png"

set title "Sin(x)^2" font ",12"
set key left box
set grid

set xrange [-10:10]

set xzeroaxis lt 1 lc rgb 'black' lw 2
set yzeroaxis lt 1 lc rgb 'black' lw 2
set tics scale 1
set grid ytics mytics
set grid xtics mxtics
set mytics 2
set mxtics 2

plot sin(x)*sin(x) lw 3, sin(x)*sin(x)-0.5 lw 3, sin(x)*sin(x)-1 lw 3