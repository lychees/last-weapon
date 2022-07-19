#include <lastweapon/sam>
using namespace lastweapon;
const int N = int(2e6) + 9, Z = 26;

sam<N,Z> S; char s[N]; int cnt[N];
VI adj[N]; LL z;

void dfs(int u = 0) {
    z += S.len[u] - S.len[S.par[u]];
    for (auto v: adj[u]) {
        dfs(v);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    RD(n); RS(s);
    REP(i, n) {
        S.Ext(s[i] - 'a');
    }
    FOR(u, 1, S.tot) adj[S.par[u]].PB(u);
    dfs();
    cout << z << endl;
}