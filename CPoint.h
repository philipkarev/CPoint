#ifndef CPOINT_CPOINT_H
#define CPOINT_CPOINT_H

#include "Point.h"
#include "Dist.h"
#include "CDist.h"

using namespace std;

class Dist;
class CDist;

class CPoint {
    Point* arr;
    int len = 0;
public:
    CPoint(Point* a, int len);
    CPoint(const CPoint&);

    ~CPoint();

    CPoint operator+(const CDist &b) const;
    CDist operator-(const CPoint &a) const;

    CPoint& operator++();
    CPoint& operator--();

    friend ostream &operator<<(ostream &, const CPoint &);

    friend class Point;
    friend class CDist;
};

#endif //CPOINT_CPOINT_H
