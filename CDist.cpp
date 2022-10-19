#include "CDist.h"
// #include "CPoint.h"
#include "Dist.h"
// #include "Point.h"

CDist::CDist(Dist* a, int len) {

    this -> len = len;

    brr = new Dist[len]; 
    for (int i = 0; i < len; i++) {
        brr[i] = a[i];
    }
    //cout << "called constr for CDist" << endl;
}

CDist::CDist(const CDist& b) {

    this -> len = b.len;

    brr = new Dist[len];
    for (int i = 0; i < len; i++) {
        this -> brr[i] = b.brr[i];
    }
    //cout << "called copy constr for CDist" << endl;
}

CDist::CDist(CDist&& obj) noexcept {

    brr = obj.brr;
    len = obj.len;
    obj.len = 0;
}

CDist::~CDist() {

    if (len > 0)
        delete[] brr;
    //cout << "called destr for CDist" << endl;
}

CDist& CDist::operator=(const CDist& b) {

    this -> len = b.len;

    brr = new Dist[len];
    for (int i = 0; i < len; i++)
        this -> brr[i] = b.brr[i];
    return *this;
}

CDist& CDist::operator=(CDist&& obj) noexcept {

    if (&obj == this)
        return *this;
    delete[] brr;
    len = obj.len;
    brr = obj.brr;
    obj.len = 0;
    return *this;
}

CPoint CDist::operator+(const CPoint& a) const {

    CPoint crr = CPoint(a);
    for (int i = 0; i < a.len; i++)
        crr.arr[i] = this -> brr[i] + a.arr[i];
    return crr;
}

CDist& CDist::operator++() {

    Dist* crr = new Dist[len+1];
    for (int i = 0; i < len; ++i) {
        crr[i] = brr[i];
        cout << "crr[" << i << "]" << "brr[" << i << "]"  << endl;
    }
    crr[len] = crr[len-1];
    delete brr;
    ++len;
    this -> brr = crr;
    return *this;
}

CDist& CDist::operator--() {

    --len;
    return *this;
}

CDist CDist::operator++(int) {

    CDist tmp(*this);
    ++(*this);
    return tmp;
}
CDist CDist::operator--(int) {

    CDist tmp(*this);
    --(*this);
    return tmp;
}

ostream& operator << (ostream &stream, const CDist& s) {
    stream << "[";
    for (int i = 0; i < s.len; i++) {
        if ( i != 0 ) {
            stream << ", ";
        }
        stream << s.brr[i];
    }
    stream << "]" << endl;
    return stream;
}
