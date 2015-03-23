#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_CPP11_NULLPTR
#include "../lib/catch.hpp"
#include "../CtCI5/1_7_set_zero.cpp"

TEST_CASE( "Set row to zero" )
{
	size_t m = 10;
	size_t n = 5;
	int **matrix = (int **)calloc(m, sizeof(int *));
	for(size_t i = 0; i < m; i++) {
		matrix[i] = (int *)calloc(n, sizeof(int));
		for(size_t j = 0; j < n; j++) {
			matrix[i][j] = 1;
		}
	}
	matrix[1][1] = 0;
	matrix[1][2] = 0;
	matrix[3][4] = 0;
	setZero(matrix, m, n);

	for(size_t i = 0; i < m; i++) {
		for(size_t j = 0; j < n; j++) {
			if(i == 1 || i == 3 || j == 1 || j == 2 || j == 4) {
				REQUIRE( matrix[i][j] == 0);
			} else {
				REQUIRE( matrix[i][j] == 1);
			}
		}
	}

	// free memory
	for(size_t i = 0; i < m; i++) {
		free(matrix[i]);
	}
	free(matrix);

}
