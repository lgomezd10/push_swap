#!/bin/bash
echo "pruebas" > fichero_pruebas
for number in {1..100}
do
arg=$(seq -1000 1000 | sort -R | tail -n 500 | tr '\n' ' ')
echo "$number" | tee -a fichero_pruebas
./push_swap $arg | wc -l | tee -a fichero_pruebas
./push_swap $arg | ./checker_linux.dms $arg | tee -a fichero_pruebas
echo $arg >> fichero_pruebas 
done
exit 0