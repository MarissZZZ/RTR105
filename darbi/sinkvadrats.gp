#!/usr/bin/gnuplot --persist

# Set the output file format and name
set terminal png
set output 'sin_squared_plot.png'

# Set the x-axis range
set xrange [-2*pi:2*pi]

# Set the y-axis range
set yrange [0:1]

# Set plot title and labels
set title 'Graph of sin(x)^2'
set xlabel 'x'
set ylabel 'sin(x)^2'

# Plot the function
plot sin(x)**2
