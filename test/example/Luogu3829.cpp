#include <lastweapon/geometry>
using namespace lastweapon::CG;

int main(){

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("/Users/minakokojima/Documents/GitHub/ACM-Training/Workspace/out.txt", "w", stdout);
#endif

    int n; DB a,b,r; vector<Po> P;
    RD(n); RF(a,b,r); a /= 2; b /= 2; a -= r; b -= r;
    Po d[4] = {Po(b, a), Po(-b, a), Po(-b, -a), Po(b, -a)};

    DO(n) {
        Po o; o.in(); DB theta; RF(theta);
        for (auto d: d) P.PB(o+d.rot(theta));
    }
    printf("%.2f\n", getPeri(getCH(P)) + 2*r*PI);
}
