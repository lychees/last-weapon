#include <lastweapon/bitwise>
using namespace lastweapon;
const int N = int(2e5) + 9;
int a[N];
int n,m,k,z;

bool ok(int i) {

    int c = 0; VI b;

    REP(i, n) {
        if ((a[i] & z) == z) ++c;
        else b.PB(z - a[i]);
    }

    if (c >= k) return 1;
    else {
        if (b.size() + c >= k) {
            SRT(b);
            LL cc = 0; REP(i, k-c) cc += b[i];
            return cc <= m;
        } else {
            return 0;
        }
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    RD(n,m,k); REP(i, n) RD(a[i]);

    z = 0; DWN(i, 31, 0) {
        z |= _1(i);   if (!ok(i)) z ^= _1(i);
        else if (z == _1(i)) REP(j, n) a[j] &= _U(i+1);
    }

    cout << z << endl;
}
