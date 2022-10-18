#ifndef CPOINT_POINT_H
#define CPOINT_POINT_H

#include <iostream>
using namespace std;

class Dist;

class Point {
    int x, y;
public:
    Point();
    Point(int x, int y);
    //Point(const Point&);

    Point operator+(const Dist &b) const;
    Dist operator-(const Point &b) const;

    friend class Dist;
    friend ostream& operator<<(ostream& os, const Point& p);
};

#endif //CPOINT_POINT_H
