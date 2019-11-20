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
	Animal cat;
	for (std::multiset<Animal>::iterator i = animals.begin(); i != animals.end(); i++)
	{
		std::cout << *i;
	}
	std::cout << Areal(animals,dog)<<"\n";
	//std::multiset<Animal>::iterator i=animals.begin();
	//std::multiset<Animal > animals3;
	//animals3.insert(lion);
	//animals3.insert(tiger);
	//animals3.insert(elephant);
	//animals3.insert(fox);
	//animals3.insert(dog);
	//animals3.insert(wolf);
	//animals3.insert(dog1);
	//for (std::multiset<Animal>::iterator i = animals3.begin();  i!=animals3.end(); i++)
	//{
	//	std::cout << *i << "\n";
	//}
	SortPlace(animals);
}
