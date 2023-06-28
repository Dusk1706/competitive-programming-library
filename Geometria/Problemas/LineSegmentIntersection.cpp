// A C++ program to check if two given line segments intersect
#include <iostream>
using namespace std;

struct P
{
	int x;
	int y;
};

// Given three collinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(P p, P q, P r){
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
		q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
	return true;

	return false;
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are collinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(P p, P q, P r){
	// See https://www.geeksforgeeks.org/orientation-3-ordered-points/
	// for details of below formula.
	int val = (q.y - p.y) * (r.x - q.x) -
			(q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0; // collinear

	return (val > 0)? 1: 2; // clock or counterclock wise
}

bool doIntersect(P p1, P p2, P p3, P p4){
	// Find the four orientations needed for general and
	// special cases
	int o1 = orientation(p1, p2, p3);
	int o2 = orientation(p1, p2, p4);
	int o3 = orientation(p3, p4, p1);
	int o4 = orientation(p3, p4, p2);

	// General case
	if (o1 != o2 && o3 != o4)
		return true;

	// Special Cases
	// p1, q1 and p2 are collinear and p2 lies on segment p1q1
	if (o1 == 0 && onSegment(p1, p3, p2)) return true;

	// p1, q1 and q2 are collinear and q2 lies on segment p1q1
	if (o2 == 0 && onSegment(p1, p4, p2)) return true;

	// p2, q2 and p1 are collinear and p1 lies on segment p2q2
	if (o3 == 0 && onSegment(p3, p1, p4)) return true;

	// p2, q2 and q1 are collinear and q1 lies on segment p2q2
	if (o4 == 0 && onSegment(p3, p2, p4)) return true;

	return false; // Doesn't fall in any of the above cases
}

int main(){
	struct P p1 = {1, 1}, q1 = {10, 1};
	struct P p2 = {1, 2}, q2 = {10, 2};

	doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";

	p1 = {10, 0}, q1 = {0, 10};
	p2 = {0, 0}, q2 = {10, 10};
	doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";

	p1 = {-5, -5}, q1 = {0, 0};
	p2 = {1, 1}, q2 = {10, 10};
	doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";

	return 0;
}
