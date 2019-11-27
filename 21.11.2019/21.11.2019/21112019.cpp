#include "Header.h"


int main()
{
	char note[100];
	cin >> note;
	string pnote = OPZ(note);
	Calc(pnote);
	system("pause");
	return 0;
}
