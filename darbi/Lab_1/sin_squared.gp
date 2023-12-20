#!/usr/bin/gnuplot --persist

# the output file format and name
set terminal png
set output 'sin_squared.png'

# the x-axis range
set xrange [-pi:pi]

# the y-axis range
set yrange [0:1]

# Set plot title and labels
set title 'Graph of sin(x)^2'
set xlabel 'x'
set ylabel 'sin(x)^2'

f0(x) =         ((1**(1+1)*x**(2*1)*2**(2*1-1)) / ((2*1)!))
f1(x) = f0(x) + ((2**(2+1)*x**(2*2)*2**(2*2-1)) / ((2*2)!))
f2(x) = f1(x) + ((3**(3+1)*x**(2*3)*2**(2*3-1)) / ((2*3)!))
f3(x) = f2(x) + ((4**(4+1)*x**(2*4)*2**(2*4-1)) / ((2*4)!))

# Plot the function
plot sin(x)**2 lw 3, f0(x) lw 3, f1(x) lw 3, f2(x) lw 3, f3(x) lw 3