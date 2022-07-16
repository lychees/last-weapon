# half-plane

It solves half plane problems.

**@{keyword.complexity}**

## @{keyword.examples}

- [https://icpc.kattis.com/problems/domes](https://icpc.kattis.com/problems/domes)

[cpp]
#include <lastweapon/geometry>
using namespace lastweapon::CG;

int main(){

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    int x, y; RD(x, y);

    vector<Line> H;
    H.PB(Line(Po(0,0), Po(x,0)));
    H.PB(Line(Po(x,0), Po(x,y)));
    H.PB(Line(Po(x,y), Po(0,y)));
    H.PB(Line(Po(0,y), Po(0,0)));

    int n; RD(n);
    VP P; P.resize(n); REP(i, n) P[i].in();
    VI o; o.resize(n); REP(i, n) --RD(o[i]);
    REP(i, n) REP(j, i) H.PB(Line(P[o[i]], P[o[j]]));

    printf("%.9f\n", getArea(getHPI(H))/2);
}

[/cpp]