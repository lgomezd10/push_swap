#!/bin/bash
echo "pruebas" > fichero_pruebas
for number in {1..200}
do
arg=$(seq -1000 1000 | sort -R | tail -n 5 | tr '\n' ' ')
echo "$number" | tee -a fichero_pruebas
echo "*" | tee -a fichero_pruebas
./push_swap $arg | wc -l | tee -a fichero_pruebas
./push_swap $arg | ./checker_Mac.dms $arg | tee -a fichero_pruebas
echo $arg >> fichero_pruebas 
done
exit 0

