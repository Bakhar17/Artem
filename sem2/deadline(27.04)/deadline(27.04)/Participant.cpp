#include "Participant.h"

Participant::Participant(std::wstring name_, double rating_, int red_, int green_, int blue_) :name(name_), rating(rating_), Red(red_), Green(green_), Blue(blue_)
{
}

Participant::~Participant()
{
}

void Participant::SetRed(int red_)
{
	this->Red = red_;
}
void Participant::SetGreen(int green_)
{
	this->Green = green_;
}

void Participant::SetBlue(int blue_)
{
	this->Blue = blue_;
}
void Participant::SetRating(double rating_) {
	this->rating = rating_;
}

