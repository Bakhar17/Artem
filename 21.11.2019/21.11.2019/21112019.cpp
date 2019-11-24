#include "Header.h"


int main()
{
	char note[100], pnote[100];
	int i, p = 0;
	stack s;
	cin >> note;

	for (i = 0; i < strlen(note); i++)
	{
		if (note[i] == '(') s.push(note[i]);
		else if ((note[i] == '+') || (note[i] == '-') || (note[i] == '/') || (note[i] == '*'))
		{
			while ((!s.empty()) && (s.top_prior() > s.prior(note[i])))
			{
				p++;
				pnote[p] = s.pop();
			}
			s.push(note[i]);
		}
		else if (note[i] == ')')
		{
			while ((!s.empty()) && (s.get_top_element() != '('))
			{
				p++;
				pnote[p] = s.pop();
			}
			s.pop();
		}
		else
		{
			p++;
			pnote[p] = note[i];
		}
	}
	while (!s.empty())
	{
		p++;
		pnote[p] = s.pop();
	}
	for (i = 1; i <= p; i++)
		cout << pnote[i];
	cout << endl;
	return 0;
}
