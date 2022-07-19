#include <lastweapon/io>
#undef im
#include <lastweapon/convolution>
#include <lastweapon/modint>

using namespace lastweapon;

using mint = static_modint<1004535809>;
using poly = vector<mint>;



#define g (c=getchar())
#define d isdigit(g)
#define p x=x*10+c-'0'
#define n x=x*10+'0'-c
#define pp l/=10,p
#define nn l/=10,n
template<class T> inline T& RD2(T &x){
    char c;while(g,c!='-'&&!isdigit(c));
    x=c-'0';while(d){
        p; x %= 1004535809;
    }
    return x;
}
#undef nn
#undef pp
#undef n
#undef p
#undef d
#undef g

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int n,k,t; RD(n);
     RD2(k); RD(t);

    poly a(n), b(n); REP(i, n) RD(a[i]); b[0] = 1;


	if (t) {
        FOR(i, 1, n) b[i]  = b[i-1] / i * mint(k-i+1);
        for (int i=1;i<n;i+=2) b[i] = -b[i];
	} else {
        FOR(i, 1, n) b[i]  = b[i-1] / i * mint(k+i-1);
	}
    a = convolution(a, b);
    REP(i, n) printf("%d ", a[i].val());
}
