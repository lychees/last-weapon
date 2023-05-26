#include <lastweapon/poly>
using namespace lastweapon;

Poly H, HH;
int n;

LL C2(LL n) {
    return n*(n-1)/2;
}

int b(int n) {
    --n; if (!n) return 1;
    Poly A(n); REP(i, n) A[i] = H[i] * -n;
    Poly B = HH.mod(n) * A.exp();
    return (B[n-1] * fac[n-1]).x;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    vector<int> q; DO(5) q.PB(RD()); n = *max_element(ALL(q)) + 1;
    Poly C(n), G(n); REP(i, n) G[i] = Mint(2).pow(C2(i)), G[i] *= invFac[i]; C = G.log();
    H = C.D().log(); HH = H.D();

    for (auto i: q) printf("%d\n", b(i));
}
