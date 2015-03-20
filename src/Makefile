CFLAGS= -O2 

test: bst.test

clean: clean.test

clean.test:	bst.clean

bst.test:	./bst_test.cpp ./lib/bst.h
	g++ bst_test.cpp ${CFLAGS} -o $@

bst.clean:
	rm bst.test
