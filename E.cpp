#include<bits/stdc++.h>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define ForkD(i,k,n) for(int i=n;i>=k;i--)
#define Rep(i,n) for(int i=0;i<n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define RepD(i,n) for(int i=n;i>=0;i--)
#define Forp(x) for(int p=pre[x];p;p=next[p])
#define Forpiter(x) for(int &p=iter[x];p;p=next[p])
#define Lson (o<<1)
#define Rson ((o<<1)+1)
#define MEM(a) memset(a,0,sizeof(a));
#define MEMI(a) memset(a,0x3f,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define MEMx(a,b) memset(a,b,sizeof(a));
#define INF (0x3f3f3f3f)
#define F (1000000007)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define vi vector<int>
#define pi pair<int,int>
#define SI(a) ((a).size())
#define Pr(kcase,ans) printf("Case #%d: %lld\n",kcase,ans);
#define PRi(a,n) For(i,n-1) cout<<a[i]<<' '; cout<<a[n]<<endl;
#define PRi2D(a,n,m) For(i,n) { \
						For(j,m-1) cout<<a[i][j]<<' ';\
						cout<<a[i][m]<<endl; \
						}
#pragma comment(linker, "/STACK:102400000,102400000")
#define ALL(x) (x).begin(),(x).end()
#define gmax(a,b) a=max(a,b);
#define gmin(a,b) a=min(a,b);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return ((a-b)%F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
long double a[10101];
ll p[10010];
ll q[10101];
bool ck(int n,long double t) {
	For(i,n) {
		double c=(a[i]*t);
		ll c2=round(c+1e-7);
		if(!(fabs(c-c2)<1e-7)) return 0;
		q[i]=c2;
	}
	ll s=0;
	For(i,n) s+=q[i]*q[i];
	if(fabs(t-sqrt((double)s))>1e-7) return 0;
	return 1;
}
int main()
{
//	freopen("A.in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read();
	For(i,n) {
		cin>>a[i];
	}
	int m=1e4;
	For(i,m) p[i]=i;
	//random_shuffle(p+1,p+1+m);

	For(i,m) {
		bool fl=ck(n,p[i]/a[1]);
		if(fl) {
			//ll g=0;
			//For(i,n) g=__gcd(::q[i],g);
			//For(i,n) q[i]/=g;
			//For(i,n) if (q[i] > 10000) break;
			For(i,n) cout << q[i] << endl;
			return 0;
		}
	}
	cout <<"-1" << endl;

	return 0;
}

