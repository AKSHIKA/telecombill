project: final.o
	cc final.o -o project
final.o: final.c final.h
	cc  -c final.c
