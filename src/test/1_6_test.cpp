#define CATCH_CONFIG_MAIN
#include "../lib/catch.hpp"
#include "../CtCI5/1_6_matrix_rotation.cpp"

#define LEN 4

TEST_CASE ( "Rotate image by 90 degree" )
{
	SECTION( "Rotate" ) {

		int m[LEN][LEN] = {{1,2,3,4},
											 {5,6,7,8},
											 {9,10,11,12},
											 {13,14,15,16}};

		int res[LEN][LEN] = {{13,9,5,1},
												 {14,10,6,2},
												 {15,11,7,3},
												 {16,12,8,4}};

		rotation(LEN, m);

		for (size_t i = 0; i < LEN; i++) {
			for(size_t j = 0; j < LEN; j++) {
				REQUIRE ( m[i][j] == res[i][j] );
			}
		}
	}
}
