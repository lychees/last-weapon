#include<bits/stdc++.h>
namespace in{
    #ifdef slow
    inline int getc(){return getchar();}
    #else
    char buf[1<<21],*p1=buf,*p2=buf;
    inline int getc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
    #endif
    template <typename T>inline void read(T& t){
		t=0;int f=0;char ch=getc();while (!isdigit(ch)){if(ch=='-')f = 1;ch=getc();}
	    while(isdigit(ch)){t=t*10+(ch-48);ch = getc();}if(f)t=-t;
	}
    template <typename T,typename... Args> inline void read(T& t, Args&... args){read(t);read(args...);}
}
namespace out{
	char buffer[1<<21];int p1=-1;const int p2 = (1<<21)-1;
	inline void flush(){fwrite(buffer,1,p1+1,stdout),p1=-1;}
	inline void putc(const char &x) {if(p1==p2)flush();buffer[++p1]=x;}
	template <typename T>void write(T x) {
		static char buf[15];static int len=-1;if(x>=0){do{buf[++len]=x%10+48,x/=10;}while (x);}else{putc('-');do {buf[++len]=-(x%10)+48,x/=10;}while(x);}
		while (len>=0)putc(buf[len]),--len;
	}
}
namespace Math{
	const int N=300000+50;
	int prime[N],tot,miu[N];
	bool isprime[N];
	void init(){
		memset(isprime,0xff,sizeof isprime);
		tot=0;miu[1]=1;
		for(int i=2;i<N;i++){
			if(isprime[i])
				prime[++tot]=i,miu[i]=-1;
			for(int j=1;j<=tot&&i*prime[j]<N;j++){
				isprime[i*prime[j]]=false;
				if(i%prime[j])
					miu[i*prime[j]]=-miu[i];
				else
					miu[i*prime[j]]=0;
			}
		}
	}
}
typedef std::complex<double>complex;
const int N=4e6+10;const double PI=acos(-1);const complex I=complex(0,1);
int rev[N];complex Wn[N];int M,mod;
int ksm(int x,int y) {
	int re=1;
	for(;y;y>>=1,x=1LL*x*x%mod)if(y&1)re=1LL*re*x%mod;
	return re;
}
inline long long num(complex x){double d=x.real();return d<0?(long long)(d-0.5)%mod:(long long)(d+0.5)%mod;}
struct poly{
	std::vector<complex>a0,a1;
	int size(){return a0.size();}
    void resize(int n){a0.resize(n);a1.resize(n);}
	void set(int x,long long y){
		y%=mod;
		a0[x]=y/M;
		a1[x]=y%M;
	}
	long long get(int x){return (M*M*num(a0[x].real())%mod +
				M*(num(a0[x].imag())+num(a1[x].real()))%mod+num(a1[x].imag()))%mod;}
	long long val(int x){return (long long)(M*a0[x].real()+a1[x].real()+mod)%mod;}
};
poly operator+(poly a,poly b){
    int n=std::max(a.size(),b.size());a.resize(n),b.resize(n);
    for(int i=0;i<n;i++)a.set(i,a.val(i)+b.val(i));return a;
}
poly operator-(poly a,poly b){
    int n=std::max(a.size(),b.size());a.resize(n),b.resize(n);
    for(int i=0;i<n;i++)a.set(i,a.val(i)-b.val(i));return a;
}
inline poly one(){poly a;a.resize(1);a.set(0,1);return a;}
inline int ext(int n){int k=0;while((1<<k)<n)k++;return k;}
inline void init(int k){
	int n=1<<k;
	for(int i=0;i<n;i++)
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(k-1));
	for(int i=0;i<n;i++)
		Wn[i]={cos(PI/n*i),sin(PI/n*i)};
}
void FFT(std::vector<complex>&A,int n,int t){
	if(t<0)for(int i=1;i<n;i++)if(i<(n-i))std::swap(A[i],A[n-i]);
	for(int i=0;i<n;i++)
		if(i<rev[i])std::swap(A[i],A[rev[i]]);
	for(int m=1;m<n;m<<=1)
		for(int i=0;i<n;i+=m<<1)
			for(int k=i;k<i+m;k++){
				complex W=Wn[1ll*(k-i)*n/m];
				complex a0=A[k],a1=A[k+m]*W;
				A[k]=a0+a1;A[k+m]=a0-a1;
			}
	if(t<0)for(int i=0;i<n;i++)A[i]/=n;
}
void MTT(poly &A,int n,int t){
	for(int i=0;i<n;i++)A.a0[i]=A.a0[i]+I*A.a1[i];
	FFT(A.a0,n,t);
	for(int i=0;i<n;i++)A.a1[i]=std::conj(A.a0[i?n-i:0]);
	for(int i=0;i<n;i++){
		complex p=A.a0[i],q=A.a1[i];
		A.a0[i]=(p+q)*0.5;A.a1[i]=(q-p)*0.5*I;
	}
}
inline poly operator*(poly a,poly b){
    int n=a.size()+b.size()-1,k=ext(n);
    a.resize(1<<k),b.resize(1<<k),init(k);
    MTT(a,1<<k,1);MTT(b,1<<k,1);
	for(int i=0;i<(1<<k);i++){
		complex p=a.a0[i]*b.a0[i]+I*a.a1[i]*b.a0[i];
		complex q=a.a0[i]*b.a1[i]+I*a.a1[i]*b.a1[i];
		a.a0[i]=p,a.a1[i]=q;
	}
    FFT(a.a0,1<<k,-1);FFT(a.a1,1<<k,-1);a.resize(n);
	long long tmp;for(int i=0;i<n;i++)
		tmp=a.get(i),a.set(i,tmp);
	return a;
}
inline poly deriv(poly a){//求导
    int n=a.size()-1;
    for(int i=0;i<n;i++)a.set(i,a.val(i+1)*(i+1));
    a.resize(n);return a;
}
inline poly inter(poly a){//求原
    int n=a.size()+1;a.resize(n);
    for(int i=n;i>=1;i--)a.set(i,a.val(i-1)*ksm(i,mod-2));
    a.set(0,0);return a;
}
poly inv(poly F,int k){
    int n=1<<k;F.resize(n);
    if(n==1){F.set(0,ksm(F.val(0),mod-2));return F;}
    poly G,H=inv(F,k-1);
    G.resize(n),H.resize(n<<1),F.resize(n<<1);
    for(int i=0;i<n/2;i++)G.set(i,H.val(i)*2);
    H=H*H;H.resize(n);H=H*F;H.resize(n);
    G=G-H;return G;
}
inline poly inv(poly a){
    int n=a.size();
    a=inv(a,ext(n)),a.resize(n);return a;;
}
inline poly ln(poly a){
    int n=a.size();
    a=inter(deriv(a)*inv(a));
    a.resize(n);return a;
}
int n;poly F,G;
int f[N],g[N];
signed main(){

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("/Users/minakokojima/Documents/GitHub/ACM-Training/Workspace/out.txt", "w", stdout);
#endif

	Math::init();
	in::read(n,mod);M=sqrt(mod);F.resize(n+1);F.set(0,1);
	for(int i=1,x;i<=n;i++)in::read(x),F.set(i,x);
	G=ln(F);
	//for(int i=1;i<=n;i++)std::cout<<G.val(i)<<" ";
	//return 0;
	for(int i=1;i<=n;i++)g[i]=1ll*G.val(i)*i%mod;
	for(int i=1;i<=n;i++)for(int j=1;i*j<=n;j++)
		f[i*j]=(f[i*j]+Math::miu[i]*g[j])%mod;
	int ans=0;
	for(int i=1;i<=n;i++)if(f[i])ans++;
	out::write(ans);out::putc('\n');
	for(int i=1;i<=n;i++)if(f[i])out::write(i),out::putc(' ');
	out::flush();
}
