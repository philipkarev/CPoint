#ifndef CPOINT_DIST_H
#define CPOINT_DIST_H

#include <iostream>

#include "Point.h"

using namespace std;


class Dist {
    int x, y;
public:
    Dist();
    Dist(int x, int y);
    //Dist(const Dist&);
    Point operator + (const Point &b) const;

    friend class Point;
    friend class CDist;
    friend ostream& operator << (ostream& os, const Dist& p);
};

#endif //CPOINT_DIST_H
