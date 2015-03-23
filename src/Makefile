CFLAGS=  

test: bst.test sort.test 1.1.test 1.2.test 1.3.test 1.4.test 1.5.test 1.6.test 1.7.test

clean: clean.test 

clean.test:	bst.clean sort.clean 1.1.clean 1.2.clean 1.3.clean 1.4.clean 1.5.clean 1.6.clean 1.7.clean

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

1.4.test: ./CtCI5/1_4_substitue_space.cpp ./test/1_4_test.cpp
	g++ ./test/1_4_test.cpp ${CFLAGS} -o $@
	./$@

1.4.clean:
	rm 1.4.test

1.5.test: ./CtCI5/1_5_string_count_compression.cpp ./test/1_5_test.cpp
	g++ ./test/1_5_test.cpp ${CFLAGS} -o $@
	./$@

1.5.clean:
	rm 1.5.test

1.6.test: ./CtCI5/1_6_matrix_rotation.cpp ./test/1_6_test.cpp
	g++ ./test/1_6_test.cpp ${CFLAGS} -o $@
	./$@

1.6.clean:
	rm 1.6.test

1.7.test: ./CtCI5/1_7_set_zero.cpp ./test/1_7_test.cpp
	g++ ./test/1_7_test.cpp ${CFLAGS} -o $@
	./$@
	
1.7.clean:
	rm 1.7.test
