#include <lastweapon/io>
#include <lastweapon/number>
using namespace lastweapon;

const int N = int(1e6) + 9;

typedef pair<pair<int, int>, int> rec;

multiset<LL> z;

map<int, multiset<LL> > c, d;

vector<rec> e;
int a[N],b[N],x[N],y[N];

int n, k;

void fix(multiset<LL>& x) {
    while (x.size() > k) x.erase(x.begin());
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("balance_sheet_input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    Rush {
        printf("Case #%d: ", ++Case);
        z.clear(); RD(n, k);

        c.clear(); d.clear(); e.clear();
        REP_1(i, n) {
            RD(a[i],b[i],x[i],y[i]);
            e.PB({{a[i], x[i]}, -i});
            e.PB({{b[i], y[i]}, i});
        }
        SRT(e);

        for (auto& t: e) {
            if (t.se < 0) { // buy
                int id = -t.se;
                c[id].insert(0);
                for (auto i: d[a[id]]) {
                    c[id].insert(i + x[id]);
                    fix(c[id]);
                }
                for (auto i: c[id]) {
                    z.insert(i); fix(z);
                }

            } else { // sell
                int id = t.se;
                for (auto i : c[id]) {
                    d[b[id]].insert(i - y[id]);
                    fix(d[b[id]]);
                }
            }
        }

        Int zz = 0; for (auto& t: z) zz += Int(t);
        cout << zz <<endl;
    }

}
