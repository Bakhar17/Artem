#include "train.h"
#include <vector>
#include <algorithm>
#include <iterator>
using std::cout;
int main()
{
	Train b("Petr", 2,0);
	Train c, k, w, e, g, s, h, y;
	k = { "Malin",5,0 };
	c = { "Kamenka",11,0};
	w = { "Malin",12,1};
	e = { "Malin",3,2 };
	g = { "Malin",9,0 };
	s = { "Kamenka",10,0 };
	h = { "Malin",1,1 };
	y = { "Kamenka",2,2 };
	std::vector<Train> tr1 { b,c,k,w,e,g,s,h,y };
	sort(tr1.begin(), tr1.end(), [&tr1](Train first, Train second) {return (first.GetPlace() > second.GetPlace()); });
	copy(tr1.begin(), tr1.end(),std::ostream_iterator<Train>(cout));
	cout << "\n";
	copy_if(tr1.begin(), tr1.end(), std::ostream_iterator<Train>(cout), [&tr1](Train& a)->bool {return a.If_E(); });
	
}
