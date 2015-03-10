#
# barebones makefile
# put your name and date
# in this too
#

F= linkedlist
G= ll-test
T= test1
DEBUG= -d1
#DEBUG=

all:
	cc -c $F.c
	cc -o $G $G.c $F.o
	
test:
	cat $T.tdd | ./$G ${DEBUG} > $T.run
	diff $T.out $T.run
	
clean:
	-rm $G $F.o $T.run

submit:
	make clean
	svn commit -m "submitted for grading"
