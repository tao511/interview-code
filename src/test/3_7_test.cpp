#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_CPP11_NULLPTR
#include "../lib/catch.hpp"
#include "../CtCI5/3_7_animal_shelter.cpp"
#include <climits>

TEST_CASE( "Animal Shelter" )
{
  Animal animals[5] = {
    Animal(1, Dog),
    Animal(2, Dog),
    Animal(3, Cat),
    Animal(4, Dog),
    Animal(5, Cat)
  };

  SECTION( "Get any animal" ) {

    AnimalShelter shelter;

    for(int i = 0; i < 5; i++) {
      shelter.enqueue(animals[i]);
    }

    for(int i = 0; i < 5; i++) {
      REQUIRE( shelter.dequeueAny().id() == animals[i].id() );
    }

  }

  SECTION( "Get only one kind" ) {
		AnimalShelter shelter;

		for(int i = 0; i < 5; i++) {
      shelter.enqueue(animals[i]);
		}

		REQUIRE( shelter.dequeueCat().id() == 3 );
		REQUIRE( shelter.dequeueCat().id() == 5 );
		REQUIRE( shelter.dequeueCat().id() == 0 );
		REQUIRE( shelter.dequeueCat().id() == 0 );

		REQUIRE( shelter.dequeueDog().id() == 1 );
		REQUIRE( shelter.dequeueDog().id() == 2 );
		REQUIRE( shelter.dequeueDog().id() == 4 );
		REQUIRE( shelter.dequeueDog().id() == 0 );
		REQUIRE( shelter.dequeueDog().id() == 0 );

  }

	SECTION( "Mixed" ) {

		AnimalShelter shelter;

		shelter.enqueue(animals[0]);
		shelter.enqueue(animals[2]);

		REQUIRE( shelter.dequeueAny().id() == 1);
		REQUIRE( shelter.dequeueDog().id() == 0);

		shelter.enqueue(animals[1]);

		REQUIRE( shelter.dequeueDog().id() == 2 );

	}

}
