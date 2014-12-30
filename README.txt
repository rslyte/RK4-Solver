Ryan Slyter
CS330: Numerical Computer
RK4 Solver

This is a small C program which contains an RK4 solver along with equations for the orbit of Mercury and the flight of a hit baseball (plus an Airy diff equation).

To Run: compile under GCC and pipe the output to a file: "gcc -std=c99 comp16.c -o comp16 | output.plot" You can then plot the outputs using many programs, I used gnuplot. Two output .plot files are included for the baseball and mercury. The program is set up initially to just output for the baseball problem.

Tested in Fedora 19
