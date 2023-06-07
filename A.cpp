#include <lastweapon/io>
#include <lastweapon/dijkstra>

using namespace lastweapon;

int n, s, t;

int id(int x, int y) {
    if (x == -1 || y == n) return s;
    if (x == n || y == -1) return t;
    return x*n + y;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("/Users/minakokojima/Documents/GitHub/ACM-Training/Workspace/out.txt", "w", stdout);
#endif

    RD(n); s=n*n; t=s+1; sp_graph<int> G(t+1);

    REP(x, n+1) REP(y, n) G.add_edge(id(x-1,y), id(x,y), RD());
    REP(x, n) REP(y, n+1) G.add_edge(id(x,y), id(x,y-1), RD());
    REP(x, n+1) REP(y, n) G.add_edge(id(x,y), id(x-1,y), RD());
    REP(x, n) REP(y, n+1) G.add_edge(id(x,y-1), id(x,y), RD());

    cout << G.dijkstra(s, t) << endl;
}
