#include <iostream>
#include "Animal.h"
#include <set>

int main() {
	Animal lion, tiger, elephant, fox, dog, wolf;
	lion = { "lion","savana",15 };
	tiger = { "tiger","savana",29 };
	elephant = { "elephant","savana",3 };
	fox = { "fox","savana",56 };
	dog = { "dog","savana",453 };
	wolf = { "wolf","savana",23 };
	std::multiset<Animal> animals;
	animals.insert(lion);
	animals.insert(tiger);
	animals.insert(elephant);
	animals.insert(fox);
	animals.insert(dog);
	animals.insert(wolf);
	Animal cat;
	for (std::multiset<Animal>::iterator i = animals.begin(); i != animals.end(); i++)
	{
		std::cout << *i;
	}
	std::cin >> cat;
	std::cout << cat;
}