#!/usr/bin/gnuplot -persist
# set terminal pngcairo  transparent enhanced font "arial,10" fontscale 1.0 size 600, 400 
# set output 'multiaxis.1.png'
set dummy jw, y
set grid nopolar
set grid xtics nomxtics noytics nomytics noztics nomztics nortics nomrtics \
 nox2tics nomx2tics y2tics nomy2tics nocbtics nomcbtics
set grid layerdefault   lt 0 linecolor 0 linewidth 0.500,  lt 0 linecolor 0 linewidth 0.500
set key title " " center
set key fixed center top vertical Right noreverse enhanced autotitle nobox
unset parametric
set style data lines
set xtics border out scale 1,0.5 mirror norotate  autojustify
set xtics  norangelimit logscale autofreq 
set ytics border out scale 1,0.5 nomirror norotate  autojustify
set ytics  norangelimit logscale autofreq 
set ztics border out scale 1,0.5 nomirror norotate  autojustify
set y2tics border out scale 1,0.5 nomirror norotate  autojustify
set y2tics  norangelimit autofreq 
set cbtics border out scale 1,0.5 mirror norotate  autojustify
set rtics axis out scale 1,0.5 nomirror norotate  autojustify
set title "Transistor Amplitude and Phase Frequency Response" 
set xlabel "jw (radians)" 
set xrange [ 1.10000 : 90000.0 ] noreverse nowriteback
set x2range [ 1.10000 : 90000.0 ] noreverse nowriteback
set ylabel "magnitude of A(jw)" 
set y2label "Phase of A(jw) (degrees)" 
set yrange [ * : * ] noreverse writeback
set y2range [ * : * ] noreverse writeback
set zrange [ * : * ] noreverse writeback
set cbrange [ * : * ] noreverse writeback
set rrange [ * : * ] noreverse writeback
set logscale y 10
set logscale x 10
set logscale x2 10
set colorbox vertical origin screen 0.9, 0.2 size screen 0.05, 0.6 front  noinvert bdefault
set terminal png size 400,300 enhanced font "Helvetica,20"
set output 'output.png'
A(jw) = ({0,1}*jw/({0,1}*jw+p1)) * (1/(1+{0,1}*jw/p2))
NO_ANIMATION = 1
p1 = 10
p2 = 10000
plot abs(A(jw)) axes x1y1, 180./pi*arg(A(jw)) axes x2y2
