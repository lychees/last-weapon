#include <lastweapon/acm>

using namespace lastweapon;

const int N = int(5e5) + 9, Z = 26, L = int(1e6) + 9;

int ctoi(char c) {
    return c - 'a';
}

acm<N, Z, ctoi> A; char s[L];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    Rush {
        A.init(); Rush A.insert(RS(s)); A.build();
        RS(s); cout << A.run(s) << endl;
    }
}
