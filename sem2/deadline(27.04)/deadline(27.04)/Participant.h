#ifndef PARTICIPANT_
#define PARTICIPANT_
#include <string>
#include <vector>
class Participant
{
public:
	Participant(std::wstring name_, double rating_, int red_, int green_, int blue_);
	~Participant();
	const std::wstring GetName()const { return name; };
	const double GetRating()const { return rating; };
	const int GetRed()const { return Red; };
	const int GetGreen()const { return Green; };
	const int GetBlue()const { return Blue; };
	void SetRed(int);
	void SetGreen(int);
	void SetBlue(int);
	void SetRating(double);
private:
	std::wstring name;
	double rating;
	int Red;
	int Green;
	int Blue;
};



#endif // !PARTICIPANT_
