#ifndef CPOINT_CDIST_H
#define CPOINT_CDIST_H

#include <iostream>
#include "CPoint.h"
using namespace std;

class Dist;
class CPoint;

class CDist {
    Dist* brr;
    int len = 0;
public:
    CDist(Dist* a, int len);
    CDist(const CDist&);
    CDist(CDist&&) noexcept;
    ~CDist();

    CDist& operator=(const CDist&);
    CDist& operator=(CDist&& obj) noexcept;

    CPoint operator+(const CPoint& a) const;

    CDist& operator++();
    CDist& operator--();

    CDist operator++(int);
    CDist operator--(int);

    friend ostream& operator << (ostream&, const CDist&);
    friend CPoint&& operator+(CPoint&&, CDist&);

    friend class CPoint;
};

#endif //CPOINT_CDIST_H