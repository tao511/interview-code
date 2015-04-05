#ifndef INTERVIEW_ANIMAL_SHELETER
#define INTERVIEW_ANIMAL_SHELETER

#include <list>

enum animalType { Cat, Dog, Unknown };

class Animal {
	int _id;
	animalType _type;
public:
	Animal() : _id(0), _type(Unknown) {}
	Animal(int id, animalType type) : _id(id), _type(type) {}
	int id() const { return _id; }
	animalType type() const { return _type; }
};

class AnimalShelter {
	std::list<Animal> animalList; //< All animals are stored here
	std::list<Animal>::iterator oldestDog; //< iterator points to oldest dog
	std::list<Animal>::iterator oldestCat; //< iterator points to oldest cat
	std::list<Animal>::iterator end;

	/**
	 * Find next animal that fits type requirement.
	 */
	void findNext(std::list<Animal>::iterator &animalIter, animalType type) {
		animalIter++; //< Move forward
		for(auto it = animalIter; it != animalList.end(); it++) {
			if (it->type() == type) {
				animalIter = it;
				return;
			}
		}
		animalIter = animalList.end();
	}

public:

	AnimalShelter(){
		oldestDog = animalList.end();
		oldestCat = animalList.end();
		end = animalList.end();
	}

	/**
	 * Put a new animal into shelter.
	 * 
	 * Update oldest Dog or oldest Cat according to the type of new animal
	 */
	void enqueue(Animal animal) {
		// put it into shelter
		animalList.push_back(animal);
		if (end == animalList.end()) {
			end = animalList.begin();
		} else {
			end++;
		}
		// update iterator
		switch(animal.type()) {
			case Cat:
				if (oldestCat == animalList.end())
					oldestCat = end;
				break;
			case Dog:
				if (oldestDog == animalList.end())
					oldestDog = end;
				break;
		}
	}

	/**
	 * Get the oldest animal in the shelter.
	 *
	 */
	Animal dequeueAny() {
		if (animalList.size() == 0) return Animal();
		Animal animal = animalList.front();
		animalList.pop_front();
		if (animalList.size() == 0){
			end = animalList.end(); // just removed the last item
		}

		findNext(animal.type() == Cat ? oldestCat : oldestDog, animal.type());

		return animal;
	}

	/** 
	 * Get the oldest dog.
	 */
	Animal dequeueDog() {
		if (animalList.size() == 0 || oldestDog == animalList.end()) return Animal();
		if (oldestDog == end) end = animalList.end();
		Animal animal = *oldestDog;
		animalList.erase(oldestDog);
		findNext(oldestDog, Dog);
		return animal;
	}

	/**
	 * Get the oldest cat.
	 */
	Animal dequeueCat() {
		if (animalList.size() == 0 || oldestCat == animalList.end()) return Animal();
		if (oldestCat == end) end = animalList.end();
		Animal animal = *oldestCat;
		animalList.erase(oldestCat);
		findNext(oldestCat, Cat);
		return animal;
	}

};

#endif
