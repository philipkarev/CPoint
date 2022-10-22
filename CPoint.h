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
    CPoint(CPoint&&) noexcept;
    ~CPoint();

    CPoint& operator=(const CPoint&);
    CPoint& operator=(CPoint&& obj) noexcept;

    CPoint operator+(const CDist &b) const;
    CDist operator-(const CPoint &a) const;

    CPoint& operator++();
    CPoint& operator--();

    CPoint operator++(int);
    CPoint operator--(int);

    friend ostream &operator<<(ostream &, const CPoint &);
    friend CPoint&& operator+(CPoint&&, CDist&);

    friend class Point;
    friend class CDist;
};

CPoint&& operator+(CPoint&&, CDist&);

#endif //CPOINT_CPOINT_H
