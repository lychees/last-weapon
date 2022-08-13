#include <lastweapon/geometry>
#include <lastweapon/fenwicktree>

using namespace lastweapon;
using namespace CG;

const int N = int(5e4) + 9;
DB d[N]; Line L[N];
int n, K;

int f(DB r) {
    Circle C(Po(0, 0), r); r *= r;
    vector<pair<double, int>> P; int m = 0;
    REP(i, n) if (d[i] < r){
        Po p0, p1; C.getIntersect(L[i], p0, p1);
        P.PB({p0.arg(), m}); P.PB({p1.arg(), m});
        ++m;
    }

    int z = 0; VI l(m, -1); fenwick_tree<int> T(m*2); SRT(P);
    REP(i, m*2) {
        int x = P[i].se;
        if (~l[x]) {
            T.add(l[x], -1);
            z += T.sum(l[x], i);
        } else {
            T.add(l[x] = i, 1);
        }
    }
    return z;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    RD(n, K); REP(i, n) {
        int A,B,C; RD(A,B,C);
        if (!A)
            L[i] = Line(Po(0, (DB)-C/B), Po(1, (DB)-C/B));
        else if (!B)
            L[i] = Line(Po((DB)-C/A, 0), Po((DB)-C/A, 1));
        else if (!C)
            L[i] = Line(Po(0, 0), Po(-B, A));
        else
            L[i] = Line(Po((DB)-C/A, 0), Po(0, (DB)-C/B));
        d[i] = dist2(L[i], Po(0, 0));
    }

    DB l = 0, r = 1e7;
    DO(233) {
        DB m = (l + r) / 2;
        if (f(m) < K) l = m;
        else r = m;
    }
    printf("%.9f\n", l);
}
