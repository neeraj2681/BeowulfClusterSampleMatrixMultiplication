gcc ag.c
./a.out

gcc -o npm npmatrix.c
mpicc -o pm pmatrix.c
./npm
mpirun -np 2 -f machinefile ./pm

