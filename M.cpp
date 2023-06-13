#include <lastweapon/io>
#include <lastweapon/mincostflow>
using namespace lastweapon;

int main() {

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    int n, m, p; RD(n, m); p = 800; int s = n+m*p, t = s+1, nn = 0;
    mcf_graph<int, int> G(t+1);

    REP(i, n) G.add_edge(s, i, RD(), 0);
    REP(i, p) REP(j, m) G.add_edge(n+p*j+i, t, 1, 0);

    REP(i, n) REP(j, m) {
        int c; RD(c); REP(k, p) G.add_edge(i, n+p*j+k, 1, (k+1)*c);
    }

    printf("%d\n", G.flow(s, t).se);
}
