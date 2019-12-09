#pragma once
#include "Flowers_class.h"

class Rose :public Flower {
public:
	Rose() = default;
	void Read(std::istringstream&)override;
	std::ostream& Print()override;
private:
	bool thorn;

};
std::ostream& Rose::Print() {
	Flower::Print();
	cout <<"|thorn :"<< thorn<<"\n";
	return cout;
}
void Rose::Read(std::istringstream& in) {
	Flower::Read(in);
	in >> thorn;
}


class Peonis :public Flower {
public:
	Peonis() = default;
	void Read(std::istringstream&)override;
	std::ostream& Print()override;
private:
	bool natural;
};
void Peonis::Read(std::istringstream& peon) {
	Flower::Read(peon);
	peon >> natural;
}
std::ostream& Peonis::Print() {
	Flower::Print();
	cout << "| natural: "<<natural<<"\n";
	return cout;
}

class Tulip :public Flower {
public:
	Tulip() = default;
	void Read(std::istringstream&)override;
	std::ostream& Print()override;
private:
	bool open;
};
void Tulip::Read(std::istringstream& tul) {
	Flower::Read(tul);
	tul >> open;
}
std::ostream& Tulip::Print() {
	Flower::Print();
	cout << "|open: " << open << "\n";
	return cout;
}