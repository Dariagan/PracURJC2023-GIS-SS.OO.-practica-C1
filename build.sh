#!/bin/bash

# compilar libreria.c (como objeto, no como ejecutable)
gcc -c libreria.c -o libreria.o

# crear la librería estática
ar crs libreria.a libreria.o

rm -f libreria.o

# compilar test.c y enlazarlo con la librería estática. nombrar al ejecutable "test"
# con L se especifica el path de la librería, que sería .
gcc test.c -o test -L. -l:libreria.a

# no sé si hace falta darle permisos de ejecución, lo hago por las dudas
sudo chmod u+x "test"

