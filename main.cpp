#include <iostream>
#include <stdlib.h>

#include "Point.h"
#include "Dist.h"
#include "CDist.h"
#include "CPoint.h"

int main(){

    srand(time(NULL));

    Point a(rand() % 7, rand() % 7), b(rand() % 7, rand() % 7);
    cout << "a = " << a << "\nb = " << b << endl;
    Dist d1(rand() % 7, rand() % 7), d2(rand() % 7, rand() % 7);
    cout << "d1 = " << d1 << "\nd2 = " << d2 << endl;

    const int dim = 2;
    Dist darr[dim];
    darr[0] = d1;
    darr[1] = d2;

    CDist cd = CDist(darr, dim);
    cout << "cd = " <<  cd << endl;

    Point parr[dim];
    parr[0] = a;
    parr[1] = b;

    CPoint cp = CPoint(parr, dim);

    cout << "cp = " << cp << endl;

    CDist cd2 = CDist(cd);
    cout << "cd2 = " << cd << endl;
    CPoint res = cd2 + cp;
    cout << "res = " << res << endl;
    CPoint res2 = cp + cd2;
    cout << "res2 = " << res2 << endl;

    CDist res3 = res - res2;
    cout << "res3 = " << res3 << endl;
    CDist res4 = res - cp;
    cout << "res4 = " << res4 << endl;

    --res4;
    cout << "--res4; res4-- = " << res4-- << endl;

    // --res4; --res4;
    // cout << "--res4; --res4; = " << res4 << endl;

    ++res2;
    cout << "++res2 = " << res2 << endl;

    --res2; --res2;
    cout << "--res2; --res2; = " << res2 << endl;

    CDist rescopy =  res4;
    cout << "rescopy = " << res4 << endl;

    CDist res6 = CDist(res4);
    res4++;
    cout << "res4++ = " << res4 << endl;

    //res4--;
    //cout << "res4-- = " << res4 << endl;

    cout << "\n\n\nres4 = " << res4 << "and res2 = " << res2 << endl;

    cout << "res4 + res2 = " << res4 + res2 << endl;
    cout << "res2 + res4 = " << res2 + res4 << endl;
    cout << "res4 = " << ++++++res4 << endl;
    //cout << "res2 = " << res2 + ++++res2 << endl;
    cout << "res2 + res4---- = " << res2 + res4---- << endl;

    return 0;
}

