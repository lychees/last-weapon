// luogu-judger-enable-o2
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define ll long long
#define N 262147
#define LIM 262144
#define reg register
#define p 1004535809
using namespace std;

struct poly{
    int a[N];
    int t;
};

int rev[N],lg2[N],rt[N],irt[N],inv[N];

inline void read(int &x);
void print(int x);
inline int power(int a,int t);
inline int add(int a,int b);
inline int dec(int a,int b);
void init();
inline void NTT(poly &f,int type,int lim);

inline void mod_read(int &x){
	x = 0;
	char c = getchar();
	while(c<'0'||c>'9') c = getchar();
	while(c>='0'&&c<='9'){
		x = (((ll)x<<3)+(x<<1)+(c^48))%p;
		c = getchar();
	}
}

poly F,G;
int n,k,lim,type;

int main(){
    init();
    inv[1] = 1;
    read(n),mod_read(k),read(type);
    for(reg int i=0;i<n;++i) read(F.a[i]);
    for(reg int i=2;i<n;++i) inv[i] = (ll)(p-p/i)*inv[p%i]%p;
    G.t = n-1,G.a[0] = 1;
    if(type==1){
        for(reg int i=1;i<n;++i)
            G.a[i] = (ll)G.a[i-1]*(dec(k,i)+1)%p*inv[i]%p;
        for(reg int i=1;i<n;++i)
            if(i&1) G.a[i] = G.a[i]?p-G.a[i]:0;
    }else{
        for(reg int i=1;i<n;++i)
            G.a[i] = (ll)G.a[i-1]*inv[i]%p*(i+k-1)%p;
    }
    lim = 1;
    while(lim<=((n-1)<<1)) lim <<= 1;
    NTT(F,1,lim),NTT(G,1,lim);
    for(reg int i=0;i!=lim;++i) F.a[i] = (ll)F.a[i]*G.a[i]%p;
    NTT(F,-1,lim);
    for(reg int i=0;i<n;++i) print(F.a[i]),putchar(' ');
    return 0;
}

inline void NTT(poly &f,int type,int lim){
    reg int w,y,l = lg2[lim]-1;
    for(reg int i=1;i!=lim;++i){
        rev[i] = (rev[i>>1]>>1)|((i&1)<<l);
        if(i>=rev[i]) continue;
        swap(f.a[i],f.a[rev[i]]);
    }
    l = LIM>>1;
    for(reg int mid=1;mid!=lim;mid<<=1){
        for(reg int j=0;j!=lim;j+=(mid<<1)){
            for(reg int k=0;k!=mid;++k){
                w = type==1?rt[l*k]:irt[l*k];
                y = (ll)w*f.a[j|k|mid]%p;
                f.a[j|k|mid] = dec(f.a[j|k],y);
                f.a[j|k] = add(f.a[j|k],y);
            }
        }
        l >>= 1;
    }
    if(type==1) return;
    y = power(lim,p-2);
    for(reg int i=0;i!=lim;++i) f.a[i] = (ll)f.a[i]*y%p;
}

void init(){
    for(reg int i=2;i<=LIM;++i) lg2[i] = lg2[i>>1]+1;
    rt[0] = 1,rt[1] = power(3,(p-1)/LIM);
    irt[0] = 1,irt[1] = power(rt[1],p-2);
    for(reg int i=2;i<=LIM;++i){
        rt[i] = (ll)rt[i-1]*rt[1]%p;
        irt[i] = (ll)irt[i-1]*irt[1]%p;
    }
}

inline int add(int a,int b){
    return a+b>=p?a+b-p:a+b;
}

inline int dec(int a,int b){
    return a<b?a-b+p:a-b;
}

inline int power(int a,int t){
    int res = 1;
    while(t){
        if(t&1) res = (ll)res*a%p;
        a = (ll)a*a%p;
        t >>= 1;
    }
    return res;
}

inline void read(int &x){
    x = 0;
    char c = getchar();
    while(c<'0'||c>'9') c = getchar();
    while(c>='0'&&c<='9'){
        x = (x<<3)+(x<<1)+(c^48);
        c = getchar();
    }
}

void print(int x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
