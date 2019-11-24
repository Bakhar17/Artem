#include "Animal.h"

int main() {
	Animal lion, tiger, elephant, fox, dog, wolf,dog1;
	lion = { "lion","savana",15 };
	tiger = { "tiger","savana",29 };
	elephant = { "elephant","savana",3 };
	fox = { "fox","forest",56 };
	dog = { "dog","savana",4 };
	dog1 = { "dog","house",602 };
	wolf = { "wolf","savana",23 };
	std::multiset<Animal> animals;
	animals.insert(lion);
	animals.insert(tiger);
	animals.insert(elephant);
	animals.insert(fox);
	animals.insert(dog);
	animals.insert(wolf);
	animals.insert(dog1);
	for (std::multiset<Animal>::iterator i = animals.begin(); i != animals.end(); i++)
	{
		std::cout << *i;
	}
	std::cout << Areal(animals,dog)<<"\n";
	SortPlace(animals);
}
