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

CDist::CDist(const CDist& b){
    this -> len = b.len;

    brr = new Dist[len];
    for (int i = 0; i < len; i++) {
        this -> brr[i] = b.brr[i];
    }

    //cout << "called copy constr for CDist" << endl;
}

CDist::~CDist() {
    delete[] brr;
    //cout << "called destr for CDist" << endl;
}

CPoint CDist::operator+(const CPoint& a) const {
    CPoint crr = CPoint(a);
    for (int i = 0; i < a.len; i++)
        crr.arr[i] = this -> brr[i] + a.arr[i];
    return crr;
}

CDist& CDist::operator++() {

    Dist* crr = new Dist[len+1];
    for (int i = 0; i < len; ++i)
        crr[i] = brr[i];
    crr[len] = crr[len-1];
    delete[] brr;
    ++len;
    this -> brr = crr;
    return *this;
}

/*CDist& CDist::operator++() {
    Dist* crr = new Dist[len+1];
    for (int i = 0; i < len; ++i)
        crr[i] = brr[i];
    crr[len] = crr[len-1];
    delete brr;
    ++len;
    this -> brr = new Dist[len];
    for (int i = 0; i < len + 1; ++i)
        brr[i] = crr[i];
    return *this;
}*/

CDist& CDist::operator--() {
    --len;
    return *this;
}

/*CDist& CDist::operator++() {

    cout << "len = " << len << endl;
    len =  len + 1;
    cout << "len = " << len << endl;
    brr[len-1] = brr[len-2];
    return *this;

}*/

/*CDist& CDist::operator++(){
    Dist* crr = new Dist[this -> len + 1];
    for (int i = 0; i < this -> len; ++i)
        crr[i] = this -> brr[i];
    crr[this -> len] = crr [this -> len - 1];
    CDist drr = CDist(crr, this -> len + 1);
    delete[] crr;
    return drr;
}*/

/*CDist CDist::operator++(const CDist& b) const {
    int l = b.len + 1;
    Dist* crr = new Dist[l];
    for (int i = 0; i < l-1; ++i)
        crr[i] = b.brr[i];
    crr[l-1] = crr[l-2];
    CDist drr = CDist(crr, l);
    delete[] crr;
    return drr;
}*/

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
