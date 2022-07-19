#include <lastweapon/sam>
using namespace lastweapon;
const int N = int(2e6) + 9, Z = 26;

sam<N,Z> S; char s[N]; int cnt[N];
VI adj[N]; LL z;

void dfs(int u = 0) {
    for (auto v: adj[u]) {
        dfs(v);
        cnt[u] += cnt[v];
    }
    if (cnt[u] > 1) {
        checkMax(z, (LL)cnt[u] * S.len[u]);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    RS(s); int n = strlen(s); REP(i, n) {
        S.Ext(s[i] - 'a'); cnt[S.tail] = 1;
    }
    FOR(u, 1, S.tot) adj[S.par[u]].PB(u);
    dfs();
    cout << z << endl;
}
