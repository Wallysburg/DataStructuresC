

F= bsp
G= bsp-test
T= test1
DEBUG= -d1

all:
	cc -c $F.c
	cc -o $G $G.c $F.o
	
clean:
	-rm $G $F.o $T.run
	