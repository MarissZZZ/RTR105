set terminal png size 800,600 enhanced font 'Verdana,10'
set output 'burtu_histogramma.png'
set style data histograms
set style histogram cluster gap 1
set style fill solid 1.0 border -1
set auto x
set yrange [0:*] # y-ass saksies no 0 un automatiski noteiks maksimumu
set title "Burtu parādīšanās biežums"
set ylabel "Skaits"
set xlabel "Burti"
set grid
plot 'burtu_skaits.dat' using 2:xtic(1) title "Burti"