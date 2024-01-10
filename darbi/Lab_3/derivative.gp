#!/usr/bin/gnuplot --persist
set grid
set title "sin^2(x) funkcijas un tās atvasinājumu grafiki"
set xlabel "x"
set ylabel "Vērtības"
set xtics ("0" 0, "π/2" pi/2, "π" pi, "3π/2" 3*pi/2, "2π" 2*pi)
set ytics auto
set key left top

# Funkcijas sin^2(x) plotēšana
plot [0:2*pi] sin(x)**2 title "sin^2(x)"

# Pirmā atvasinājuma analītiskā formula un tuvinājums no datu faila
replot "derivative.dat" using 1:3 with lines title "sin^2'(x) analītiskais"
replot "derivative.dat" using 1:4 with lines title "sin^2'(x) tuvinājums"

# Otrā atvasinājuma analītiskā formula un tuvinājums no datu faila
replot "derivative.dat" using 1:5 with lines title "sin^2''(x) analītiskais"
replot "derivative.dat" using 1:6 with lines title "sin^2''(x) tuvinājums"

# grafiku saglabā kā PNG formātā
set terminal png size 800,600
set output "derivative.png"
replot
set output
set terminal pop
