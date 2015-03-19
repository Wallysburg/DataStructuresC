
F= stackimpl
G= stacktest
H1= test1.tdd
H2= test2.tdd

all:
	cc -c $F.c
	cc -o $G $G.c $F.o

test1:
	cat ${H1} | ./$G > ${H1}.out
	diff ${H1}.out ${H1}.ref

test2:
	cat ${H2} | ./$G > ${H2}.out
	diff ${H2}.out ${H2}.ref

clean:
	-rm $F.o
	-rm $G
	-rm ${H1}.out
	-rm ${H2}.out

submit:
	make diff
	make clean
	svn commit -m "submit for grading"

