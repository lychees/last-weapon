#include <lastweapon/bignum>
#include <lastweapon/acm>
using namespace lastweapon;

const int N = 51, Z = 50, AN = 101;
map<char, int> o; char s[N];
bignum dp[N][AN];

int ctoi(char c) {
    return o[c];
}

#define acm acm<AN,Z,ctoi>
#define v trans[u][c]
#define p fail[u]
struct my_acm : public acm {
    void build(){
        acm::build();
        FOR(u, 1, tot) cnt[u] += cnt[p];
    }
    bignum run(int n, int z) {

        dp[0][0] = 1; REP(i, n) {
            REP(u, tot) REP(c, z) if (!cnt[v]) {
                dp[i+1][v] += dp[i][u];
            }
        }
        return accumulate(dp[n], dp[n]+tot, bignum(0));
    }
};

my_acm A;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    int z, n, m; RD(z, n, m); REP(i, z) o[RC()] = i;
    A.init(); DO(m) A.insert(RS(s)); A.build();
    cout << A.run(n, z) << endl;
}
