#include <lastweapon/io>
#include <lastweapon/fenwicktree>
using namespace lastweapon;

const int N = int(1e6) + 9;
int A[N]; bool used[N];

VI P; struct rec {
    int l, r, v;
    void in() {
        RD(l, r, v);
        A[l] = v;
        P.PB(v);
    }
    bool operator <(const rec& r) const {
        return l < r.l;
    }
} I[N];



int n, m;

int main() {

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("/Users/minakokojima/Documents/GitHub/ACM-Training/Workspace/out.txt", "w", stdout);
#endif

    Rush {
        RD(n, m); //fill(used+1, used+n+1, 0);


        fill(A+1, A+n+1, 0); P.clear();

        REP(i, m) I[i].in(); UNQ(P);


        //SRT(I);

        /*int ai = 1; REP_1(i, n) if (!A[i]) {
            while (used[ai]) ++ai;
            A[i] = ai;
        }*/

        fenwick_tree<int> T(SZ(P));
        LL z = 0; int mx = 0;
        REP_1(i, n) {
            if (A[i]) {
                int ai = lower_bound(ALL(P), A[i]) - P.begin(); checkMax(mx, ai);
                z += T.sum(SZ(P)) - T.sum(ai+1);
                T.add(ai, 1);
            } else {
                z += T.sum(SZ(P)) - T.sum(mx+1);
            }
        }
        cout << z << endl;
    }
}
