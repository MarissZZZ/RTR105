#!/usr/bin/gnuplot --persist

# the output file format and name
set terminal png
set output 'sin_squared.png'

# the x-axis range
set xrange [-pi:pi]

# the y-axis range
set yrange [-1:2]

# Set plot title and labels
set title 'Graph of sin(x)^2'
set xlabel 'x'
set ylabel 'y'

f0(x) =         (((-1)**(1+1)*x**(2*1)*2**(2*1-1)) / ((2*1)!))
f1(x) = f0(x) + (((-1)**(2+1)*x**(2*2)*2**(2*2-1)) / ((2*2)!))
f2(x) = f1(x) + (((-1)**(3+1)*x**(2*3)*2**(2*3-1)) / ((2*3)!))
f3(x) = f2(x) + (((-1)**(4+1)*x**(2*4)*2**(2*4-1)) / ((2*4)!))
f4(x) = f3(x) + (((-1)**(5+1)*x**(2*5)*2**(2*5-1)) / ((2*5)!))
f5(x) = f4(x) + (((-1)**(6+1)*x**(2*6)*2**(2*6-1)) / ((2*6)!))

# Plot the function
plot sin(x)**2 lw 4, f0(x) lw 2, f1(x) lw 2, f2(x) lw 2, f3(x) lw 2, f4(x) lw 2, f5(x) lw 2