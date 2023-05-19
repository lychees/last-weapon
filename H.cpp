#include <lastweapon/io>
using namespace lastweapon;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    LL a, b; RD(a, b); int z = 0;
    while (a >= 1 && b >= 1) {
        LL d = gcd(a, b);
        a -= d; b -= d; ++z;
    }
    cout << z << endl;
}
