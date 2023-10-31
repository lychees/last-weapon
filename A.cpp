#include <lastweapon/io>
#include <lastweapon/number>
using namespace lastweapon;

LL n;
LL f[90][2];
void gao(LL n) {
	LL p=1; REP(i, 63) {
		f[i][1]=n/(p*2)*p;
		LL t=n%(p*2) - (p-1);
		if(t>0) f[i][1]+=min(t,p);
		p <<= 1;
	}
}
int main() {
	Rush{
		gao(RD(n));
		Int z=0; REP(i,63){
			z += Int(1LL<<i) * sqr(Int(f[i][1]));
		}
		cout<< z <<endl;
	}
	return 0;
}
