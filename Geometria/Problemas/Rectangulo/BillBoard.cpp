// http://www.usaco.org/index.php?page=viewproblem2&cpid=759
#include <bits/stdc++.h>
//Pura gente del coach moy
using namespace std;
#define fio(name) freopen(name ".in","r",stdin);freopen(name ".out","w",stdout)

//X1,Y1 = bottom left, X2 Y2= top right
struct Rect {
	int x1, y1, x2, y2;
	int area() { return (y2 - y1) * (x2 - x1); }
	void input(){ cin>>x1>>y1>>x2>>y2; }
};

int intersectArea(Rect a, Rect b) {
	int xOverlap = max(0, min(a.x2, b.x2) - max(a.x1, b.x1));
	int yOverlap = max(0, min(a.y2, b.y2) - max(a.y1, b.y1));
	return xOverlap * yOverlap;
}

int main(){ 
	fio("billboard");
	Rect a,b,c;
	a.input();
	b.input();
	c.input();
	cout<<a.area()+b.area()-intersectArea(a,c)-intersectArea(b,c)<<'\n';


  return 0;
}