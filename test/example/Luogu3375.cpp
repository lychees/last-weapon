#include <lastweapon/string>
using namespace lastweapon;
void output(vector<int> ans, int m) {
    REP(i, ans.size()) {
        if(ans[i] == m-1) {
            cout << i+1-(2*m) << endl;
        }
    }
    REP(i, m) {
        cout << ans[i]+1 << ' ';
    }
    cout << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    vector<char> v;
    string a, b;
    cin >> a >> b;
    REP(i, b.size()) v.push_back(b[i]);
    v.push_back('#');
    REP(i, a.size()) v.push_back(a[i]);
    vector<int> ans = kmp(v);
    output(ans, b.size());
}

