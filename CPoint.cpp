#include "CPoint.h"

CPoint::CPoint(Point* a, int len) {

    this -> len = len;

    arr = new Point[len];
    for (int i = 0; i < len; i++) {
        arr[i] = a[i];
    }
}

CPoint::CPoint(const CPoint& a) {

    this -> len = a.len;

    arr = new Point[len];
    for (int i = 0; i < len; i++)
        this -> arr[i] = a.arr[i];
}

CPoint::~CPoint(){

    delete[] arr;
}

CPoint CPoint::operator+(const CDist& b) const {

    CPoint crr = CPoint(this -> arr, this -> len);
    for (int i= 0; i < b.len; i++)
        crr.arr[i] = this -> arr[i] + b.brr[i];
    return crr;
}

CDist CPoint::operator-(const CPoint &a) const {

    int l = a.len;
    Dist* brr = new Dist[l];
    for (int i = 0; i < l; i++)
        brr[i] = this -> arr[i] - a.arr[i];
    CDist crr = CDist(brr, l);
    delete[] brr;
    return crr;
}

CPoint& CPoint::operator++() {

    Point* crr = new Point[len+1];
    for (int i = 0; i < len; ++i)
        crr[i] = arr[i];
    crr[len] = crr[len-1];
    delete[] arr;
    ++len;
    this -> arr = crr;
    return *this;
}

/*CPoint& CPoint::operator++(){
    Point* crr = new Point[len+1];
    for (int i = 0; i < len; ++i)
        crr[i] = arr[i];
    crr[len] = crr[len-1];
    delete arr;
    ++len;
    this -> arr = new Point[len];
    for (int i = 0; i < len + 1; ++i)
        arr[i] = crr[i];
    return *this;
}*/

CPoint& CPoint::operator--(){

    --len;
    return *this;
}

ostream & operator << (ostream &stream, const CPoint& s) {
    stream << "[";
    for (int i = 0; i < s.len; i++) {
        if ( i != 0 ) {
            stream << ", ";
        }
        stream << s.arr[i];
    }
    stream << "]" << endl;
    return stream;
}