#include <lastweapon/splay>
using namespace lastweapon;

struct rec{
    int ky, ss, ls, rs, ms;
    rec(int s = 0) {
        ky = ss = ls = rs = ms = s;
    }
};

rec e() {
    rec z = rec(-INF);
    z.ss = 0;
    return z;
}

void op(rec& x, const rec l, const rec r) {
    x.ss = l.ss + x.ky + r.ss;
    x.ls = max(l.ls, l.ss + x.ky + max(0, r.ls));
    x.rs = max(r.rs, max(0, l.rs) + x.ky + r.ss);
    x.ms = max({l.ms, max(l.rs, 0) + x.ky + max(0, r.ls), r.ms});
}

using node = splay::node<rec,op,e>;
using Splay = splay::splay<rec, op, e>;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int n; RD(n); vector<rec> a(n); REP(i, n) a[i] = rec(RD());
    Splay T(a);

    Rush {
        char cmd; RC(cmd); node *x, *y, *z;
        int a, b;

        if (cmd == 'I') {
            RD(a, b);
            y = T.select(a-1, z = T.select(a)); x = new node(); x->reset(rec(b));
            y->setr(x), y->upd(), z->upd();
        } else if (cmd == 'D') {
            RD(a);
            y = T.select(a-1, z = T.select(a+1));
            y->c[1] = node::NIL; y->upd(); z->upd();
        } else if (cmd == 'R') {
            int x, y; RD(x, y);
            T.set(x, rec(y));
        } else {
            RD(a, b); ++b;
            cout << T.prod(a, b).ms << endl;
        }
    }
}
