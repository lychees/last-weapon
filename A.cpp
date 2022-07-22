#include <lastweapon/acm>
using namespace lastweapon;
const int N = int(1e5) + 9, Z = 26;
char T[N], P[N]; VVI dp;
int n, m;

int ctoi(char c){return c -'a';}
#define acm acm<N,Z,ctoi>
struct my_acm : public acm{
    int run() {
        n = strlen(RS(T)), m = strlen(RS(P)); dp.resize(n+1); insert(P); build();
        dp[0].resize(tot, -INF); dp[0][0] = 0;
#define v trans[u][c]
        REP(i, n) {
            dp[i+1].resize(tot, -INF);
            REP(u, tot) {
                if (T[i] == '?') {
                    REP(c, Z) {
                        checkMax(dp[i+1][v], dp[i][u] + cnt[v]);
                    }
                } else {
                    int c = T[i] - 'a';
                    checkMax(dp[i+1][v], dp[i][u] + cnt[v]);
                }
            }
        }
        return *max_element(ALL(dp[n]));
    }
} A;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cout << A.run() << endl;
}
