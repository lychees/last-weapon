#include<bits/stdc++.h>
using namespace std;
int const inv2=499122177;
namespace polynomials
{
    int const p=998244353,g=3;
    int const N=(1<<19)+1;
    int w[N],iv[N],r[N],last;
    typedef vector<int> vec;
    int mod(int x){return x>=p?x-p:x;}
    int pw(int x,int y)
    {
        int res=1;
        while(y)
        {
            if(y&1)res=1ll*res*x%p;
            x=1ll*x*x%p;
            y>>=1;
        }
        return res;
    }
    void init(int n)
    {
        int lim=1;
        while(lim<n)lim<<=1;
        iv[1]=1;
        for(int i=2;i<=lim;i++)iv[i]=mod(p-1ll*(p/i)*iv[p%i]%p);
        for(int i=1;i<lim;i<<=1)
        {
            int wn=pw(g,(p-1)/(i<<1));
            for(int j=0,ww=1;j<i;j++,ww=1ll*ww*wn%p)w[i+j]=ww;
        }
    }
    void ntt(vec &f,int n,int op)
    {
        f.resize(n);
        for(int i=1;i<n;i++)r[i]=(r[i>>1]>>1)|((i&1)?(n>>1):0);
        for(int i=1;i<n;i++)if(i<r[i])swap(f[i],f[r[i]]);
        for(int i=1;i<n;i<<=1)
        for(int j=0;j<n;j+=i<<1)
            for(int k=0;k<i;k++)
            {
                int x=f[j+k],y=1ll*f[i+j+k]*w[i+k]%p;
                f[j+k]=mod(x+y);f[i+j+k]=mod(x-y+p);
            }
        if(op==-1)
        {
            reverse(&f[1],&f[n]);
            for(int i=0;i<n;i++)f[i]=1ll*f[i]*iv[n]%p;
        }
    }
    void getinv(vec f,vec &g,int n)
    {
        static vec x;
        g.resize(n);
        if(n==1){g[0]=pw(f[0],p-2);return;}
        getinv(f,g,(n+1)>>1);
        int lim=1;
        while(lim<(n<<1))lim<<=1;
        x.resize(lim);
        for(int i=0;i<n;i++)x[i]=f[i];
        for(int i=n;i<lim;i++)x[i]=0;
        g.resize(lim);
        ntt(x,lim,1),ntt(g,lim,1);
        for(int i=0;i<lim;i++)g[i]=1ll*g[i]*(2-1ll*g[i]*x[i]%p+p)%p;
        ntt(g,lim,-1);
        g.resize(n);
    }
    void getln(vec f,vec &g,int n)
    {
        static vec x;
        getinv(f,x,n);
        for(int i=0;i<n-1;i++)f[i]=1ll*f[i+1]*(i+1)%p;
        f[n-1]=0;
        int lim=1;
        while(lim<((n<<1)-1))lim<<=1;
        ntt(f,lim,1),ntt(x,lim,1);
        for(int i=0;i<lim;i++)x[i]=1ll*x[i]*f[i]%p;
        ntt(x,lim,-1);
        g.resize(n);
        g[0]=0;
        for(int i=1;i<n;i++)g[i]=1ll*x[i-1]*iv[i]%p;
    }
}
using namespace polynomials;
int fac[200005],inv[200005];
vec f,G,ans;
int main()
{
    int n;
    scanf("%d",&n);
    n++;
    init(n<<1);
    fac[0]=inv[0]=1;
    for(int i=1;i<n;i++)fac[i]=1ll*fac[i-1]*i%p;
    inv[n-1]=pw(fac[n-1],p-2);
    for(int i=n-2;i>=1;i--)inv[i]=1ll*inv[i+1]*(i+1)%p;
    f.resize(n);
    for(int i=1;i<n;i++) {
        f[i]=1ll*(((i+1)&1)?(p-1):1)*inv[i]%p*pw(inv2,(1ll*i*(i-1)>>1)%(p-1))%p;
        cout << f[i] << endl;
    }
    for(int i=0;i<n;i++)f[i]=mod(p-f[i]);
    f[0]=mod(f[0]+1);
    getinv(f,G,n);
    for(int i=0;i<n;i++)G[i]=1ll*G[i]*pw(2,(1ll*i*(i-1)>>1)%(p-1))%p;
    getln(G,ans,n);
    for(int i=1;i<n;i++)printf("%d\n",1ll*ans[i]*fac[i]%p);
    return 0;
}
