#include <lastweapon/io>
// #include <lastweapon/segtree>
using namespace lastweapon;

const int N = int(5e5)+9;

/*
LL gcd(LL a,LL b)
{
    return b?gcd(b,a%b):abs(a);
}*/

inline LL gcd(LL a,LL b)
{
	if(a<0) a=-a;
	if(b<0) b=-b;
	if(!a) return b;
	if(!b) return a;
	LL t=__builtin_ctzll(a|b),tmp;
	a>>=__builtin_ctzll(a);
	do
	{
		b>>=__builtin_ctzll(b);
		if(a>b)
		{
			tmp=a,a=b,b=tmp;
		}
		b-=a;
	} while(b);
	return a<<t;
}

LL op(LL a, LL b) { return gcd(a, b); }
LL e() { return 0; }
int m, n;

const int TN = 4*N, M = 710;


#define lx (x<<1)
#define rx (lx|1)
#define ml ((l+r)>>1)
#define mr (ml+1)
#define lc lx,l,ml
#define rc rx,mr,r
#define rt 1,0,n-1

struct SegTree{

    vector<LL> T;

    void add(int x, LL d) {
        T[x] += d;
    }

    void Build(int x, int l, int r, vector<LL> &a) {
        if (l < r) {
            T[x] = 0;
            Build(lc, a), Build(rc, a);
        } else {
            T[x] = a[l];
        }
    }

    LL Query(int x, int l, int r, const int p) {
        if (l == r) {
            return T[x];
        } else {
            return T[x] + (p < mr ? Query(lc, p) : Query(rc, p));
        }
    }

    void Add(int x, int l, int r, const int a, const int b, const LL d) {
        if (b < l || r < a) return;
        if (a <= l && r <= b) {
            add(x, d);
        } else {
            Add(lc, a, b, d); Add(rc, a, b, d);
        }
    }
} S[M];


struct SegTree2{

    vector<LL> T;

    void upd(int x) {
        T[x] = gcd(T[lx], T[rx]);
    }

    void add(int x, LL d) {
        T[x] += d;
    }

    void Build(int x, int l, int r, vector<LL> &a) {
        if (l < r) {
            Build(lc, a), Build(rc, a);
            upd(x);
        } else {
            T[x] = a[l];
        }
    }

    LL Query(int x, int l, int r, const int a, const int b) {
        if (b < l || r < a) return 0;
        if (a <= l && r <= b) {
            return T[x];
        } else {
            return gcd(Query(lc, a, b), Query(rc, a, b));
        }
    }

    void Add(int x, int l, int r, const int p, const LL d) {
        if (l == r) {
            add(x, d);
        } else {
            if (p < mr) Add(lc, p, d);
            else Add(rc, p, d);
            upd(x);
        }
    }
} T[M];

bool flip;

int main() {

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    RD(m, n); // if (m != 1) return 0;
    int y0, x0; RD(y0, x0); --x0; --y0; int Q; RD(Q);

    if (m > n) {
        swap(m, n);
        flip = 1;
    }

    vector<vector<LL>> a, d; a.resize(m); d.resize(m);

    if (flip) {
        REP(i, n) REP(j, m) a[j].PB(RD());
    } else {
        REP(j, m) REP(i, n) a[j].PB(RD());
    }

    REP(j, m) {
        REP(i, n-1) d[j].PB(a[j][i+1] - a[j][i]);
        d[j].PB(0);
    }

    REP(i, m) S[i].T.resize(4*n), S[i].Build(rt, a[i]);
    REP(i, m) T[i].T.resize(4*n), T[i].Build(rt, d[i]);

    DO(Q) {

        int cmd, u, l, d, r; RD(cmd, u, l, d, r);

        if (!cmd) {
            u = y0 - u; d = y0 + d; l = x0 - l; r = x0 + r;
            if (flip) swap(u, l), swap(d, r);

            LL z = 0; FOR_1(i, u, d) {
                z = gcd(z, gcd(S[i].Query(rt, l), l < r ? T[i].Query(rt, l, r-1) : 0));
            }
            printf("%lld\n", abs(z));
        } else {
            LL delta; RD(delta); //continue;
            --l; --r; --u; --d; if (flip) swap(u, l), swap(d, r);

            FOR_1(i, u, d) {
                S[i].Add(rt, l, r, delta);
                if (l) T[i].Add(rt, l-1, delta);
                T[i].Add(rt, r, -delta);
            }
        }
    }
}
