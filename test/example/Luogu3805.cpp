#include <lastweapon/string>

const int N = int(1.1e7) + 9;
char s[N];

int main() {
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
#endif
    auto r = lastweapon::manacher(RS(s));
    printf("%d\n", *max_element(ALL(r)) - 1);
}
