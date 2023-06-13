#include <lastweapon/io>
#include <lastweapon/mincostflow>
using namespace lastweapon;

const int N = 40, M = 100;
int cost[N][M], last[N][M], cnt[N][M];

int main() {

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    int n, m, p; RD(n, m); p = 800; int s = n+m*p, t = s+1, nn = 0;
    mcf_graph<int, int> G(t+1); int pn = 0;

    REP(i, n) G.add_edge(s, i, pn += RD(), 0);
    REP(i, p) REP(j, m) G.add_edge(n+p*j+i, t, 1, 0);

    REP(i, n) REP(j, m) last[i][j] = G.add_edge(i, n+p*j, 1, RD(cost[i][j]));

    int z = 0; //cout << pn << endl;

    REP_1(pi, pn) {
        z += G.flow(s, t, pi).se;
        REP(i, n) REP(j, m) if (G._edges[last[i][j]].flow == 1) {
            ++cnt[i][j];
            last[i][j] = G.add_edge(i, n+p*j+cnt[i][j], 1, (cnt[i][j]+1)*cost[i][j]);
            break;
        }
    }

    printf("%d\n", z);
    // printf("%d\n", G.flow(s, t).se);
}
