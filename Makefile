all: METODOS
	./gera -a 10 > entrada.txt
	./trab3 radixbin 10 < entrada.txt

METODOS:
	gcc -c gera.c
	gcc -c trab3.c
	gcc gera.o -o gera
	gcc trab3.o -o trab3
