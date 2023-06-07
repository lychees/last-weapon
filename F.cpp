#include <lastweapon/io>
using namespace lastweapon;

const int N = int(15e2)+9;

int n;
LL a[N], f[N][3];
VVI e;

void dfs(int u, int p) {
    f[u][0] = f[u][1] = 0; f[u][2] = INFF;
    for(int& v : e[u]) if (v != p) {
        dfs(v, u);
        f[u][0] += min(f[v][0], f[v][1], f[v][2]);
        f[u][2] = min(f[u][1] + f[v][0], f[u][2] + f[v][0], (f[u][2] + f[v][2]));
        f[u][1] += f[v][2];
        checkMin(f[u][1], INFF);
    }
    f[u][0] += a[u];
    if(f[u][2] == 0) f[u][2] = INFF;
    //cout << f[u][0] << ' ' << f[u][1] << ' ' << f[u][2] << ' ' << u << ' ' << endl;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    RD(n);
    e.resize(n);
    REP(i, n) {
        LL j, m, v;
        RD(j);
        RD(a[i]);
        RD(m);
        DO(m) {
            RD(v), v--;
            e[i].PB(v);
            e[v].PB(i);
        }
    }
    dfs(0, -1);
    cout << min(f[0][0], f[0][2]) << endl;
}
