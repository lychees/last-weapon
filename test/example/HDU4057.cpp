#include <lastweapon/acm>
#include <lastweapon/bitwise>
using namespace lastweapon;
const char SIGMA[] = {'A', 'T', 'C', 'G'};
int ord[128];

const int N = int(1e3) + 9, M = 10, Z = 4, L = 109;
char s[N]; int dp[2][N][1<<M], val[1<<M];
int n, m;

int ctoi(char c){return ord[c];}
#define acm acm<N,Z,ctoi>
#define v trans[u][c]

struct my_acm : public acm{

    int insert(char str[]){
        int u = 0; REP_S(cur, str) {
            int c = ctoi(*cur);
            if (!v) v = new_node();
            u = v;
        }
        return u;
    }

    void init() {
        RST(val); acm::init(); REP(i ,m) {
            int u = insert(RS(s));
            cnt[u] |= _1(i);
            RD(val[_1(i)]);
        }
        build(); FOR(i, 1, op) {
            int u = Q[i];
            cnt[u] |= cnt[fail[u]];
        }
        FOR(s, 1, _1(m)) val[s] = val[s^low_bit(s)] + val[low_bit(s)];
    }

    void run(){
        int p = 0, q; RST(dp[p]), dp[p][0][0] = 1; REP(i, n){
            q = p, p ^= 1, RST(dp[p]); REP(u, tot) REP(s, _1(m)) if (dp[q][u][s]) {
                REP(c, Z) dp[p][v][s|cnt[v]] = true;
            }
        }

        int res = -1; REP(s, _1(m)){
            if (val[s] <= res) continue;
            REP(u, tot) if (dp[p][u][s]){
                res = val[s];
                break;
            }
        }
        if (res < 0) puts("No Rabbit after 2012!");
        else OT(res);
    }
} A;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    REP(i, Z) ord[SIGMA[i]] = i;
    while (~scanf("%d %d", &m, &n)) {
        A.init(), A.run();
    }
}

