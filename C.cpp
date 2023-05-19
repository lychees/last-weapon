#include <lastweapon/io>
#include <lastweapon/bitwise>
using namespace lastweapon;





const int N = int(1e5)+9, M = 26+1, LV = 20;

char s[N]; int a[N], n;
int C[N], key[N], t1[N], t2[N];

template<typename T> struct rmq {
	vector<T> v; int n;
	static const int b = 30; // block size
	vector<int> mask, t; // mask and sparse table

	int op(int x, int y) {
		return v[x] < v[y] ? x : y;
	}
	// least significant set bit
	int lsb(int x) {
		return x & -x;
	}
	// index of the most significant set bit
	int msb_index(int x) {
		return __builtin_clz(1)-__builtin_clz(x);
	}
	// answer query of v[r-size+1..r] using the masks, given size <= b
	int small(int r, int size = b) {
		// get only 'size' least significant bits of the mask
		// and then get the index of the msb of that
		int dist_from_r = msb_index(mask[r] & ((1<<size)-1));

		return r - dist_from_r;
	}

	rmq(){
	}

	rmq(const vector<T>& v_) : v(v_), n(v.size()), mask(n), t(n) {
		int curr_mask = 0;
		for (int i = 0; i < n; i++) {

			// shift mask by 1, keeping only the 'b' least significant bits
			curr_mask = (curr_mask<<1) & ((1<<b)-1);

			while (curr_mask > 0 and op(i, i - msb_index(lsb(curr_mask))) == i) {
				// current value is smaller than the value represented by the
				// last 1 in curr_mask, so we need to turn off that bit
				curr_mask ^= lsb(curr_mask);
			}
			// append extra 1 to the mask
			curr_mask |= 1;

			mask[i] = curr_mask;
		}

		// build sparse table over the n/b blocks
		// the sparse table is linearized, so what would be at
		// table[j][i] is stored in table[(n/b)*j + i]
		for (int i = 0; i < n/b; i++) t[i] = small(b*i+b-1);
		for (int j = 1; (1<<j) <= n/b; j++) for (int i = 0; i+(1<<j) <= n/b; i++)
			t[n/b*j+i] = op(t[n/b*(j-1)+i], t[n/b*(j-1)+i+(1<<(j-1))]);
	}
	// query(l, r) returns the actual minimum of v[l..r]
	// to get the index, just change the first and last lines of the function
	T query(int l, int r) {
		// query too small
		if (r-l+1 <= b) return v[small(r, r-l+1)];

		// get the minimum of the endpoints
		// (there is no problem if the ranges overlap with the sparse table query)
		int ans = op(small(l+b-1), small(r));

		// 'x' and 'y' are the blocks we need to query over
		int x = l/b+1, y = r/b-1;

		if (x <= y) {
			int j = msb_index(y-x+1);
			ans = op(ans, op(t[n/b*j+x], t[n/b*j+y-(1<<j)+1]));
		}

		return v[ans];
	}
};


struct SA{

    int a[3*N], sa[3*N], rk[N], h[N];
    rmq<int> T;

    inline void rs(int*x,int*y,int*sa,int n,int m){
        REP(i, n)key[i]=i[y][x];
        memset(C, 0,sizeof(C[0])*m);
        REP(i, n) ++C[key[i]];
        FOR(i, 1, m) C[i] += C[i-1];
        DWN(i, n, 0) sa[--C[key[i]]] = y[i];
    }

    void da(int*a,int*sa,int n,int m){
        int *x = t1, *y = t2;
        memset(C,0,sizeof(C[0])*m);
        REP(i, n)++C[x[i]=a[i]];
        FOR(i, 1, m)C[i]+=C[i-1];
        DWN(i, n, 0)sa[--C[x[i]]]=i;
        for(int l=1,p=1;p<n;l<<=1,m=p){
            p=0; FOR(i, n-l, n) y[p++]=i;
            REP(i, n) if (sa[i]>=l) y[p++]=sa[i]-l;
            rs(x,y,sa,n,m),swap(x,y),x[sa[0]]=p=0;FOR(i, 1, n)
                x[sa[i]]=(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+l]==y[sa[i-1]+l])?p:++p;
            ++p;
        }
    }

#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
int c0(int*r,int a,int b)
{return r[a]==r[b]&&r[a+1]==r[b+1]&&r[a+2]==r[b+2];}
int c12(int k,int*r,int a,int b)
{if(k==2) return r[a]<r[b]||r[a]==r[b]&&c12(1,r,a+1,b+1);
 else return r[a]<r[b]||r[a]==r[b]&&key[a+1]<key[b+1];}

void dc3(int*a,int*sa,int n,int m){
    int i, j, *an=a+n, *san=sa+n, ta=0, tb=(n+1)/3, tbc=0, p;
    a[n] = a[n+1] = 0; REP(i, n) if (i%3) t1[tbc++]=i;

    rs(a+2,t1,t2,tbc,m),rs(a+1,t2,t1,tbc,m),rs(a,t1,t2,tbc,m);
    p=0,an[F(t2[0])]=0;FOR(i, 1, tbc)
        an[F(t2[i])]=c0(a,t2[i-1],t2[i])?p:++p;

    if (++p < tbc) dc3(an,san,tbc,p);
    else REP(i, tbc) san[an[i]] = i;

    REP(i, tbc) if(san[i] < tb) t2[ta++] = san[i] * 3;
    if (n%3==1) t2[ta++] = n-1; rs(a,t2,t1,ta,m);
    REP(i, tbc) key[t2[i]=G(san[i])] = i;

    for(i=0,j=0,p=0; i<ta && j<tbc; p++)
        sa[p]=c12(t2[j]%3,a,t1[i],t2[j]) ? t1[i++] : t2[j++];
    for(;i<ta;p++) sa[p]=t1[i++]; for(;j<tbc;p++) sa[p]=t2[j++];
}

void get_h(){
    REP_1(i, n) rk[sa[i]] = i;
    int k=0;for(int i=0;i<n;h[rk[i++]]=k){
        if (k)--k;for(int j=sa[rk[i]-1];a[i+k]==a[j+k];++k);
    }
}


#define cmp(a, b) (h[a]<h[b]?a:b)

inline int lcp(int l, int r){
    int lv = lg2(r - l);
    //return min(h[ST[lv][l]], h[ST[lv][r-_1(lv)]]);
    return T.query(l, r);
    //return 0;
}

inline int lcpp(int l, int r){
    if (l == r) return n-l;
    l = rk[l], r = rk[r]; if (l > r) swap(l, r);
    return lcp(l, r);
}

void get_lcp(){
    VI t; REP_1(i, n) t.PB(h[i]);
    T = rmq<int>(t);
}

void bd(){
    dc3(a,sa,n+1,M),get_h(),get_lcp();
}
} A, B;

PII get(LL k){
    int r = lower_bound(a, a+n, k) - a; k -= a[r-1];
    return MP(A.sa[r], A.h[r]+k);
}

LL f(LL x, LL y){
    if (x>a[n] || y>a[n]) return -1;
    PII a = get(x), b = get(y); int t = min(a.se, b.se);
    return sqr(LL(min(t,A.lcpp(a.fi, b.fi)))) + sqr(LL(min(t,B.lcpp(n-(a.fi+a.se), n-(b.fi+b.se)))));
}


int main(){

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    int m; RD(n, m); strlen(RS(s));  REP(i, n) B.a[n-i-1]=A.a[i]=s[i]-='a'-1;
    A.bd(); B.bd(); REP_1(i, n) a[i]=a[i-1]+n-A.sa[i]-A.h[i];
    DO(m) OT(f(RD(), RD()));
}
