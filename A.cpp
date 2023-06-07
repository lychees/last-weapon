#include <lastweapon/io>
#include <lastweapon/maxflow>

using namespace lastweapon;

int n;

int id(int x, int y) {
    return x*n + y;
}

const int N = int(5e2) + 9;
int R[N][N], S[N][N];

int main() {

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("/Users/minakokojima/Documents/GitHub/ACM-Training/Workspace/out.txt", "w", stdout);
#endif

    RD(n); ++n; int s=0, t=n*n; mf_graph<int> G(t--);

    REP(x, n) REP(y, n-1) RD(R[x][y]);
    REP(x, n-1) REP(y, n) RD(S[x][y]);
    REP(x, n) REP(y, n-1) G.add_edge(id(x,y), id(x,y+1), R[x][y], RD());
    REP(x, n-1) REP(y, n) G.add_edge(id(x,y), id(x+1,y), S[x][y], RD());

    cout << G.flow(s, t) << endl;
}
