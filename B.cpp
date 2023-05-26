#include<bits/stdc++.h>
#include<lastweapon/io>
using namespace std;
using namespace lastweapon;
#define ll long long
namespace IO{//by cyffff

}
const int mod=998244353,N=524288+10;
namespace Poly{
	int n,m,a[N],b[N],c[N],s[N],ss[N],d[N],e[N];
	int f[N],g[N],h[N],F[N],tmp1[N],tmp2[N],tmp3[N];
	int rev[N],inv[N],fac[N],ifac[N],G[19][N],lim;
	inline void init(int n,int mode=1){
		if(mode){
			int l=0;
			for(lim=1;lim<n;lim<<=1)l++;
			for(int i=1;i<lim;i++)
				rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
		}else{
			for(lim=1;lim<n;lim<<=1);
		}
	}
	inline int qpow(int x,int y){
		int res=1;
		while(y){
			if(y&1) res=1ll*res*x%mod;
			x=1ll*x*x%mod;
			y>>=1;
		}
		return res;
	}
	inline void Prefix(int n){
		inv[1]=1;
		for(int i=2;i<=n;i++)
			inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
		fac[0]=1;
		for(int i=1;i<=n;i++)
			fac[i]=1ll*fac[i-1]*i%mod;
		ifac[n]=qpow(fac[n],mod-2);
		for(int i=n;i>=1;i--)
			ifac[i-1]=1ll*ifac[i]*i%mod;
		for(int i=1,p=1;i<=18;i++,p<<=1){
			G[i][0]=1;
			G[i][1]=qpow(3,mod-1>>i);
			for(int j=2;j<p;j++)
				G[i][j]=1ll*G[i][j-1]*G[i][1]%mod;
		}
	}
	inline void NTT(int *a,int t){
		for(int i=0;i<lim;i++)
			if(i<rev[i])
				swap(a[i],a[rev[i]]);
		for(int i=1,t=1;i<lim;i<<=1,t++){
			for(int j=0;j<lim;j+=i<<1){
				int t1,t2;
				for(int k=0;k<i;k++){
					t1=a[j+k];
					t2=1ll*G[t][k]*a[i+j+k]%mod;
					a[j+k]=(t1+t2)%mod;
					a[i+j+k]=(t1-t2+mod)%mod;
				}
			}
		}
		if(t==1) return ;
		int Inv=qpow(lim,mod-2);
		reverse(a+1,a+lim);
		for(int i=0;i<lim;i++)
			a[i]=1ll*a[i]*Inv%mod;
	}
	inline void Inv(int *a,int *b,int n){
		if(n==1){
			b[0]=qpow(a[0],mod-2);
			return ;
		}
		Inv(a,b,n+1>>1);
		init(n<<1);
		for(int i=0;i<n;i++)
			c[i]=a[i];
		for(int i=n;i<lim;i++)
			c[i]=0;
		NTT(c,1),NTT(b,1);
		for(int i=0;i<lim;i++)
			b[i]=1ll*(2-1ll*c[i]*b[i]%mod+mod)%mod*b[i]%mod;
		NTT(b,-1);
		for(int i=n;i<lim;i++)
			b[i]=0;
	}
	inline void Mul(int *a,int *b,int n){
		init(n<<1);
		memset(c,0,lim<<2);
		memcpy(c,b,n<<2);
		NTT(a,1),NTT(c,1);
		for(int i=0;i<lim;i++)
			a[i]=1ll*a[i]*c[i]%mod;
		NTT(a,-1);
	}
	inline void Der(int *a,int *b,int n){
		for(int i=1;i<n;i++)
			b[i-1]=1ll*i*a[i]%mod;
		b[n-1]=0;
	}
	inline void Int(int *a,int *b,int n){
		for(int i=1;i<n;i++)
			b[i]=1ll*a[i-1]*inv[i]%mod;
		b[0]=0;
	}
	inline void polyln(int *a,int *b,int n){
		static int p[N];
		memset(p,0,n<<3);
		memset(d,0,n<<3);
		Der(a,p,n);
		Inv(a,d,n);
		Mul(p,d,n);
		Int(p,b,n);
	}
	inline void Log(int n,int *f,int *g){
		init(n);
		polyln(f,g,lim);
		for(int i=n;i<lim;i++)
			g[i]=0;
	}
	inline void polyexp(int n,int *a,int *b){
		if(n==1){
			b[0]=1;
			return ;
		}
		polyexp(n+1>>1,a,b);
		Log(n,b,s);
		for(int i=0;i<n;i++)
			s[i]=a[i]>=s[i]?a[i]-s[i]:a[i]+mod-s[i];
		for(int i=n;i<lim;i++)
			b[i]=s[i]=0;
		s[0]++;
		NTT(s,1),NTT(b,1);
		for(int i=0;i<lim;i++)
			b[i]=1ll*b[i]*s[i]%mod;
		NTT(b,-1);
		for(int i=n;i<lim;i++)
			b[i]=0;
	}
	inline void Exp(int n,int *a,int *b){
		polyexp(n,a,b);
	}
}
using namespace Poly;
int ask[5],L;
inline int solve(int m){
	memset(g,0,sizeof(g));
	memset(tmp1,0,sizeof(tmp1));
	m--;
	if(!m) return 1;
	for(int i=0;i<L;i++)
		g[i]=1ll*(mod-m)*tmp3[i]%mod;





	Exp(L,g,tmp1);

	REP(i, L) cout << tmp2[i] << " "; cout << endl;

	init(L<<1);
	NTT(tmp1,1);
	for(int i=0;i<lim;i++)
		tmp1[i]=1ll*tmp1[i]*tmp2[i]%mod;
	NTT(tmp1,-1);
	return 1ll*tmp1[m-1]*fac[m-1]%mod;
}
int main(){

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif


	for(int i=0;i<5;i++)
		ask[i]=RD(),n=max(n,ask[i]+1);
	init(n,0);
	L=lim;
	Prefix(L);
	for(int i=0;i<L;i++)
		f[i]=1ll*qpow(2,1ll*i*(i-1)/2%(mod-1))*ifac[i]%mod;


	Log(L,f,F);

	REP(i, L) cout << F[i] << " "; cout << endl;

	Der(F,F,L);

	REP(i, L) cout << F[i] << " "; cout << endl;

	Log(L,F,tmp3);

	REP(i, L) cout << tmp3[i] << " "; cout << endl;

	Der(tmp3,tmp2,L);

	REP(i, L) cout << tmp2[i] << " "; cout << endl;

	NTT(tmp2,1);

	for(int i=0;i<5;i++)
		printf("%d", solve(ask[i])),
		puts("");
	return 0;
}
