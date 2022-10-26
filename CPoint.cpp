#include "CPoint.h"

CPoint::CPoint(Point* a, int len) {

    this -> len = len;

    arr = new Point[len];
    for (int i = 0; i < len; i++)
        arr[i] = a[i];
}

CPoint::CPoint(const CPoint& a) {

    this -> len = a.len;

    arr = new Point[len];
    for (int i = 0; i < len; i++)
        this -> arr[i] = a.arr[i];
}

CPoint::CPoint(CPoint&& obj) noexcept {

    arr = obj.arr;
    len = obj.len;
    obj.len = 0;
}

CPoint::~CPoint() {

    if (len > 0)
        delete[] arr;
}

CPoint& CPoint::operator=(const CPoint& b) {

    this -> len = b.len;

    arr = new Point[len];
    for (int i = 0; i < len; i++)
        this -> arr[i] = b.arr[i];
    return *this;
}

CPoint& CPoint::operator=(CPoint&& obj) noexcept {

    if (&obj == this)
        return *this;
    delete[] arr;
    len = obj.len;
    arr = obj.arr;
    obj.len = 0;
    return *this;
}

CPoint CPoint::operator+(const CDist& b) const {

    int l = (b.len > this -> len ? this -> len : b.len);
    CPoint crr = CPoint(this -> arr, l);
    for (int i= 0; i < l; i++)
        crr.arr[i] = this -> arr[i] + b.brr[i];
    return crr;
}

CDist CPoint::operator-(const CPoint &a) const {

    int l = (a.len > this -> len ? this -> len : a.len);
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

CPoint& CPoint::operator--(){

    if (len > 1)
        --len;
    else
        cout << "\nError: incorrect data. Decrement operation is unavailable" << endl;
    return *this;
}

CPoint CPoint::operator++(int) {

    CPoint tmp(*this);
    ++(*this);
    return tmp;
}

CPoint CPoint::operator--(int) {

    CPoint tmp(*this);
    --(*this);
    return tmp;
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

CPoint&& operator+(CPoint&& a, CDist& b) {

    for (int i= 0; i < b.len; i++)
        a.arr[i] =  a.arr[i] + b.brr[i];
    return (CPoint&&)a;
}
