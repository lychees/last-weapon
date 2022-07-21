#include <lastweapon/sam>
using namespace lastweapon;

const int N = int(2e5) + 9, Z = 26;
char str[N];

#define sam sam<N,Z>
#define c (*cur - 'a')
#define v trans[u][c]
#define p par[u]
#define lenn C

struct my_sam : public sam {
    void init(){
        RS(str); REP_S(cur, str) Ext(c);
    }
    void run() {
        static int C[N], Q[N]; //RST(C);
        REP(i, tot) ++C[len[i]];
        REP_1(i, len[tail]) C[i] += C[i-1];
        REP(i, tot) Q[--C[len[i]]] = i;


        while (~scanf("%s", str)){
            fill(lenn, lenn+tot, 0); int u = 0, l = 0; REP_S(cur, str){
                while (u && !v) l = len[u = p];
                if (u = v) checkMax(lenn[u], ++l);
            }
            DWN(i, tot, 1){
                int u = Q[i]; checkMax(lenn[p], lenn[u]);
                checkMin(len[u], lenn[u]);
            }
        }
        cout << *max_element(len+1, len+1+tot) << endl;
    }
} S;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    S.init(); S.run();
}
