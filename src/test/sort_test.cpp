#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_CPP11_NULLPTR
#include "../lib/catch.hpp"
#include "../lib/sort.h"

TEST_CASE( "QuickSort", "[QuickSort]")
{
  std::vector<int> vec = std::vector<int>();
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(0);
  vec.push_back(3);
  vec.push_back(2);
  vec.push_back(2);
  vec.push_back(5);

  SECTION( "Partition" ) {
    REQUIRE( partition(vec, 0, vec.size() - 1) == 5 );
		REQUIRE( vec[0] == 1 );
		REQUIRE( vec[1] == 2 );
		REQUIRE( vec[2] == 0 );
		REQUIRE( vec[3] == 2 );
		REQUIRE( vec[4] == 2 );
		REQUIRE( vec[5] == 3 );
		REQUIRE( vec[6] == 5 );
  }

  SECTION( "Sort" ) {
		quickSort(vec, 0, vec.size() - 1);
		REQUIRE( vec[0] == 0 );
		REQUIRE( vec[1] == 1 );
		REQUIRE( vec[2] == 2 );
		REQUIRE( vec[3] == 2 );
		REQUIRE( vec[4] == 2 );
		REQUIRE( vec[5] == 3 );
		REQUIRE( vec[6] == 5 );
  }
}
