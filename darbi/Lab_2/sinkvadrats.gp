#!/usr/bin/gnuplot --persist

set terminal pngcairo enhanced font "arial,10" fontscale 1.0 size 800, 600
set output "sinkvadrats.png"

set title "Sin(x)^2 and Variations" font ",14"
set key outside right top box
set grid

set xrange [-10:10]
set yrange [-1.5:1.5]

set xzeroaxis lt 1 lc rgb 'black' lw 2
set yzeroaxis lt 1 lc rgb 'black' lw 2
set tics scale 1
set grid ytics mytics
set grid xtics mxtics
set mytics 2
set mxtics 2

# Differentiating each plot with unique color and line style
plot sin(x)*sin(x) title "sin(x)^2" lw 3 lc rgb "red", \
     sin(x)*sin(x)-0.5 title "sin(x)^2 - 0.5" lw 3 lc rgb "blue", \
     sin(x)*sin(x)-1 title "sin(x)^2 - 1" lw 3 lc rgb "green"