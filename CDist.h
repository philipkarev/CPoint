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

    ~CDist();

    CPoint operator+(const CPoint& a) const;
    CDist& operator++();
    CDist& operator--();
    friend ostream& operator << (ostream&, const CDist&);

    friend class CPoint;
};

#endif //CPOINT_CDIST_H