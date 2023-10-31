#include <lastweapon/io>
#include <lastweapon/fenwicktree>
#pragma comment(linker, "/STACK:36777216")
using namespace lastweapon;
const int N = int(3e3) + 9;
char col[N][N];
bool vis[N][N]; int  tim[N][N];
int n, m, zz, qq, tt, z, xx0, yy0;

map<PII, int> H;

bool inGrid(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int qx[N*N], qy[N*N];

void bfs(int x, int y) {
    int cz = 0, op = 1;
    qx[0] = x, qy[0] = y;
    zz += 1;
    vis[x][y] = 1;

    while (cz < op) {
     x = qx[cz]; y = qy[cz]; ++ cz;
    REP(i, 4) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (!inGrid(xx, yy)) continue;
        if (vis[xx][yy]) continue;
        if (col[xx][yy] == '.') {
            if (tim[xx][yy] != tt) {
                    //cout << "   " << xx << " " << yy << " " << tt << " " << tim[xx][yy] << endl;
                qq += 1;
                tim[xx][yy] = tt;
                xx0 = xx; yy0 = yy;
            //cout << "   " << xx << " " << yy << " " << tt << " " << tim[xx][yy] << endl;
            }
        } else if (col[xx][yy] == 'W') {
            //dfs(xx, yy);
            vis[xx][yy] = 1;
            qx[op] = xx;
            qy[op] = yy;
            ++op;
        }
    }

    }
}

int gao() {
    RD(n, m); H.clear();
    REP(i, n) RS(col[i]), fill(vis[i], vis[i] + m, 0);
    z = 0;

    REP(i, n) REP(j, m) if (!vis[i][j]){
        if (col[i][j] == 'W') {
            zz = 0; qq = 0; ++tt;
            bfs(i, j);
            //cout << zz << " " << qq << endl;
            if (qq == 1) {
                H[{xx0,yy0}] += zz;
                checkMax(z, H[{xx0,yy0}]);
            }
        }
    }
    //cout << z << endl;
    return z;
}

int main() {



#ifndef ONLINE_JUDGE
    freopen("ready_go_part_2_input.txt", "r", stdin);
    //freopen("back_in_black_chapter_1_input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    //init();
    Rush {
        printf("Case #%d: %d\n", ++Case, gao() );
    }

}
