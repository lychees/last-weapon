#include <lastweapon/io>
#include <lastweapon/fenwicktree>

using namespace lastweapon;

const int N = int(1e6) + 9;
int A[N], B[N], R[N]; VI P;

struct rec {
    int l, r, v;
    void in() {
        RD(l, r, v);
        A[l] = v;
        FOR_1(i, l+1, r) checkMax(B[i], v);
        P.PB(v);
    }
    bool operator <(const rec& r) const {
        return l > r.l;
    }
} I[N];

const int TN = 4*N;

#define lx (x<<1)
#define rx (lx|1)
#define ml ((l+r)>>1)
#define mr (ml+1)
#define lc lx,l,ml
#define rc rx,mr,r
#define rt 1,0,SZ(P)-1

struct SegTree{;

    struct Tnode {
        int key, pos;
        Tnode (int _key = 0, int _pos = 0):key(_key), pos(_pos){}
        bool operator <(const Tnode& r) const {
            return key < r.key || key == r.key && pos < r.pos;
        }
    } T[TN]; int D[N];

    void upd(int x) {
        T[x] = min(T[lx], T[rx]);
    }

    void add(int x, int d) {
        T[x].key += d;
        D[x] += d;
    }

    void rls(int x) {
        if (D[x]) {
            add(lx, D[x]);
            add(rx, D[x]);
            D[x] = 0;
        }
    }

    void Build(int x, int l, int r) {
        T[x].key = 0, T[x].pos = l; D[x] = 0;
        if (l < r) Build(lc), Build(rc);
    }

    Tnode Query(int x, int l, int r, const int a, const int b) {
        if (b < l || r < a) return {INF, -1};
        if (a <= l && r <= b) {
            return T[x];
        } else {
            rls(x);
            return min(Query(lc, a, b), Query(rc, a, b));
        }
    }

    void Add(int x, int l, int r, const int a, const int b, const int d) {
        if (b < l || r < a) return;
        if (a <= l && r <= b) {
            add(x, d);
        } else {
            rls(x);
            Add(lc, a, b, d); Add(rc, a, b, d);
            upd(x);
        }
    }
} T;

int n, m;

int Find(int x){
    return R[x] == x ? x : R[x] = Find(R[x]);
}


LL solve() {
    RD(n, m); fill(A+1, A+n+1, -1); fill(B+1, B+n+1, -1); P.clear();

    REP(i, m) I[i].in(); UNQ(P);

    vector<vector<rec>> buc(SZ(P));
    REP(i, m) buc[LBD(P, I[i].v)].PB(I[i]);

    m = SZ(P);

    REP_1(i, n+1) R[i] = i;

    DWN(i, m, 0) {
        SRT(buc[i]); set<int> P;
        for (auto t: buc[i]) {
            while (true) {
                int p = Find(t.l); if (p > t.r) break;
                B[p] = i; P.insert(p); R[p] = Find(p+1);
            }
        }
        P.insert(INF); set<int> Q; Q.insert(INF);
        for (auto t: buc[i]) {
            int q = *Q.lower_bound(t.l); if (q <= t.r) continue;
            int p = *P.lower_bound(t.l); if (p > t.r) return -1;
            A[p] = i; P.erase(p); Q.insert(p);
        }
    }

    //return -2;

    //REP_1(i, n) if (~A[i]) A[i] = LBD(P, A[i]);
    //else B[i] = ~B[i] ? LBD(P, B[i]) : 0;

    T.Build(rt); REP_1(i, n) if (~A[i]) T.Add(rt, A[i]+1, m-1, 1);

    REP_1(i, n) {
        if (~A[i]) T.Add(rt, A[i]+1, m-1, -1);
        else A[i] = T.Query(rt, B[i], m-1).pos;
        T.Add(rt, 0, A[i]-1, 1);
    }

    fenwick_tree<int> T(m);
    LL z = (LL)n*(n-1)/2; REP_1(i, n) {
        z -= T.sum(A[i]+1);
        T.add(A[i], 1);
    }
    return z;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("/Users/minakokojima/Documents/GitHub/ACM-Training/Workspace/out.txt", "w", stdout);
#endif

    Rush {
        cout << solve() << endl;
    }
}
