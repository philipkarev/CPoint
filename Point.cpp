#include <iostream>
#include "Dist.h"
#include "Point.h"
#define N 2

using namespace std;

Point::Point() {
    this -> x = 0;
    this -> y = 0;
}

Point::Point(int x, int y) {
    this -> x = x;
    this -> y = y;
}

/*Point::Point(const Point& p) {
    Point(p.x, p.y);
}*/

Dist Point::operator - (const Point& b) const{
    Dist d(x - b.x, y - b.y);
    return d;
}

Point Point::operator + (const Dist& d) const{ //оператор сложения CPoint и CDist,возвр.CPoint
    Point p(x + d.x, y + d.y);
    return p;
}

ostream& operator << (ostream& os, const Point& p)
{
    os << "(X:" << p.x << ", Y:" << p.y << ")";
    return os;
}