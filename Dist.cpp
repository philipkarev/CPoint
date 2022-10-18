#include "Point.h"
#include "Dist.h"

Dist::Dist() {
    this -> x = 0;
    this -> y = 0;
}

Dist::Dist(int x, int y) {
    this -> x = x;
    this -> y = y;
}

/*Dist::Dist(const Dist& p) {
    Dist(p.x, p.y);
}*/

Point Dist::operator + (const Point& p) const {
    Point result(x + p.x, y + p.y);
    return result;
}

ostream& operator << (ostream& os, const Dist& d) {
    os << "(D_X:" << d.x << ", D_Y:" << d.y << ")";
    return os;
}
