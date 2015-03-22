CFLAGS=  

test: bst.test sort.test 1.1.test 1.2.test 1.3.test

clean: clean.test 

clean.test:	bst.clean sort.clean 1.1.clean 1.2.clean 1.3.clean

# Data structures and algorithms

bst.test:	./test/bst_test.cpp ./lib/bst.h
	g++ ./test/bst_test.cpp ${CFLAGS} -o $@
	./$@

bst.clean:
	rm bst.test

sort.test: ./test/sort_test.cpp ./lib/sort.h
	g++ ./test/sort_test.cpp ${CFLAGS} -o $@
	./$@

sort.clean:
	rm sort.test

# Cracking the coding interview v5

1.1.test: ./CtCI5/1_1_unique_char.cpp ./test/1_1_test.cpp
	g++ ./test/1_1_test.cpp ${CFLAGS} -o $@
	./$@

1.1.clean:
	rm 1.1.test

1.2.test: ./CtCI5/1_2_reverse_char_string.cpp ./test/1_2_test.cpp
	g++ ./test/1_2_test.cpp ${CFLAGS} -o $@
	./$@

1.2.clean:
	rm 1.2.test

1.3.test: ./CtCI5/1_3_string_permutation.cpp ./test/1_3_test.cpp
	g++ ./test/1_3_test.cpp ${CFLAGS} -o $@
	./$@

1.3.clean:
	rm 1.3.test
