#include <lastweapon/sam>
using namespace std;
using namespace lastweapon;

const int N = int(4e5) + 9, Z = 26;

namespace Chairman_Tree {
#define lx c[0][x]
#define rx c[1][x]
#define ly c[0][y]
#define ry c[1][y]
#define lz c[0][z]
#define rz c[1][z]
#define ml ((l+r)>>1)
#define mr (ml+1)
#define lc lx, l, ml
#define rc rx, mr, r
    const int NN = 100*N;
    int c[2][NN]; int tot;
    int a, b;
    int new_node() {
        ++tot;
        return tot;
    }

    void Init(int &x, int l, int r, const int p) {
        x = new_node();
        if (l < r) {
            if (p < mr) Init(lc, p);
            else Init(rc, p);
        }
    }

    int Merge(int x, int y) {
        if (!x || !y) return x | y;
        int z = new_node();
        lz = Merge(lx, ly);
        rz = Merge(rx, ry);
        return z;
    }

    bool Query(int x, int l, int r, const int a, const int b) {
        if (!x || b < l || r < a) return 0;
        if (a <= l && r <= b) return 1;
        return Query(lc, a, b) || Query(rc, a, b);
    }
} using namespace Chairman_Tree;

sam<N, Z> S;
char s[N]; VI adj[N];
int rt[N], dp[N], z;
int n;

void dfs(int u = 0) {
    for (auto v: adj[u]) {
        dfs(v);
        rt[u] = Merge(rt[u], rt[v]);
    }
}

void gao(int u = 0, int w = 0) {
    checkMax(z, dp[u]);
    for (auto v: adj[u]) {
        if (!u || Query(rt[w], 0, n-1, S.pos[v] - S.len[v] + S.len[w], S.pos[v] - 1)) {
            dp[v] = dp[w] + 1;
            gao(v, v);
        } else {
            dp[v] = dp[w];
            gao(v, w);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    RD(n); RS(s);
    REP(i, n) {
        S.Ext(s[i] - 'a'); S.pos[S.tail] = i;
        Init(rt[S.tail], 0, n-1, i);
    }
    FOR(u, 1, tot) adj[S.par[u]].PB(u);

	dfs(); gao();
	cout << z << endl;
}
