CFLAGS= -O2 

test: bst.test sort.test
	./*.test

clean: clean.test 

clean.test:	bst.clean sort.clean

bst.test:	./test/bst_test.cpp ./lib/bst.h
	g++ ./test/bst_test.cpp ${CFLAGS} -o $@

bst.clean:
	rm bst.test

sort.test: ./test/sort_test.cpp ./lib/sort.h
	g++ ./test/sort_test.cpp ${CFLAGS} -o $@

sort.clean:
	rm sort.test
