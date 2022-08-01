
/*
    This code has been written by MinakoKojima, feel free to ask me question. Blog: http://www.shuizilong.com/house
    Template Date: 2022.7.22
    Note: ...
*/
#pragma comment(linker, "/STACK:36777216")
#define LOCAL
#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <climits>
#include <cassert>
#include <complex>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>


using namespace std;

#define REP(i, n) for (int i=0;i<n;++i)
#define FOR(i, a, b) for (int i=a;i<b;++i)
#define DWN(i, b, a) for (int i=b-1;i>=a;--i)
#define REP_1(i, n) for (int i=1;i<=n;++i)
#define FOR_1(i, a, b) for (int i=a;i<=b;++i)
#define DWN_1(i, b, a) for (int i=b;i>=a;--i)

#define ECH(it, A) for (__typeof((A).begin()) it=(A).begin(); it != (A).end(); ++it)
#define rECH(it, A) for (__typeof((A).rbegin()) it=(A).rbegin(); it != (A).rend(); ++it)
#define REP_S(i, str) for (char*i=str;*i;++i)
#define REP_L(i, hd, suc) for (int i=hd;i;i=suc[i])
#define REP_G(i, u) REP_L(i,hd[u],suc)
#define REP_SS(x, s) for (int x=s;x;x=(x-1)&s)
#define DO(n) for ( int ____n = n; ____n-->0; )

#define ALL(A) A.begin(), A.end()
#define LLA(A) A.rbegin(), A.rend()
#define CPY(A, B) memcpy(A, B, sizeof(A))
#define INS(A, P, B) A.insert(A.begin() + P, B)
#define ERS(A, P) A.erase(A.begin() + P)
#define LBD(A, x) (lower_bound(ALL(A), x) - A.begin())
#define UBD(A, x) (upper_bound(ALL(A), x) - A.begin())
#define CTN(T, x) (T.find(x) != T.end())
#define SZ(A) int((A).size())
#define PB push_back
#define MP(A, B) make_pair(A, B)
#define PTT pair<T, T>
#define Ts *this
#define rTs return Ts
#define fi first
#define se second
#define re real()
#define im imag()

#define Rush for(int ____T=RD(); ____T--;)
#define Display(A, n, m) {                      \
  REP(i, n){		                            \
        REP(j, m-1) cout << A[i][j] << " ";     \
        cout << A[i][m-1] << endl;		        \
	}						                    \
}
#define Display_1(A, n, m) {                    \
	REP_1(i, n){		                        \
        REP_1(j, m-1) cout << A[i][j] << " ";   \
        cout << A[i][m] << endl;		        \
	}						                    \
}

typedef long long LL;
typedef double DB;
typedef unsigned uint;
typedef unsigned long long uLL;

typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<string> VS;
typedef vector<LL> VL;
typedef vector<DB> VF;
typedef set<int> SI;
typedef set<string> SS;
typedef map<int, int> MII;
typedef map<string, int> MSI;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef vector<VII> VVII;

template<class T> inline T& RD(T &);
template<class T> inline void OT(const T &);
inline LL RD(){LL x; return RD(x);}
inline DB& RF(DB &);
inline DB RF(){DB x; return RF(x);}
inline char* RS(char *s);
inline char& RC(char &c);
inline char RC();
inline char& RC(char &c){scanf(" %c", &c); return c;}
inline char RC(){char c; return RC(c);}

template<class T0, class T1> inline T0& RD(T0 &x0, T1 &x1){RD(x0), RD(x1); return x0;}
template<class T0, class T1, class T2> inline T0& RD(T0 &x0, T1 &x1, T2 &x2){RD(x0), RD(x1), RD(x2); return x0;}
template<class T0, class T1, class T2, class T3> inline T0& RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3){RD(x0), RD(x1), RD(x2), RD(x3); return x0;}
template<class T0, class T1, class T2, class T3, class T4> inline T0& RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4){RD(x0), RD(x1), RD(x2), RD(x3), RD(x4); return x0;}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline T0& RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5){RD(x0), RD(x1), RD(x2), RD(x3), RD(x4), RD(x5); return x0;}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline T0& RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5, T6 &x6){RD(x0), RD(x1), RD(x2), RD(x3), RD(x4), RD(x5), RD(x6); return x0;}
template<class T0, class T1> inline void OT(const T0 &x0, const T1 &x1){OT(x0), OT(x1);}
template<class T0, class T1, class T2> inline void OT(const T0 &x0, const T1 &x1, const T2 &x2){OT(x0), OT(x1), OT(x2);}
template<class T0, class T1, class T2, class T3> inline void OT(const T0 &x0, const T1 &x1, const T2 &x2, const T3 &x3){OT(x0), OT(x1), OT(x2), OT(x3);}
template<class T0, class T1, class T2, class T3, class T4> inline void OT(const T0 &x0, const T1 &x1, const T2 &x2, const T3 &x3, const T4 &x4){OT(x0), OT(x1), OT(x2), OT(x3), OT(x4);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void OT(const T0 &x0, const T1 &x1, const T2 &x2, const T3 &x3, const T4 &x4, const T5 &x5){OT(x0), OT(x1), OT(x2), OT(x3), OT(x4), OT(x5);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void OT(const T0 &x0, const T1 &x1, const T2 &x2, const T3 &x3, const T4 &x4, const T5 &x5, const T6 &x6){OT(x0), OT(x1), OT(x2), OT(x3), OT(x4), OT(x5), OT(x6);}
inline char& RC(char &a, char &b){RC(a), RC(b); return a;}
inline char& RC(char &a, char &b, char &c){RC(a), RC(b), RC(c); return a;}
inline char& RC(char &a, char &b, char &c, char &d){RC(a), RC(b), RC(c), RC(d); return a;}
inline char& RC(char &a, char &b, char &c, char &d, char &e){RC(a), RC(b), RC(c), RC(d), RC(e); return a;}
inline char& RC(char &a, char &b, char &c, char &d, char &e, char &f){RC(a), RC(b), RC(c), RC(d), RC(e), RC(f); return a;}
inline char& RC(char &a, char &b, char &c, char &d, char &e, char &f, char &g){RC(a), RC(b), RC(c), RC(d), RC(e), RC(f), RC(g); return a;}
inline DB& RF(DB &a, DB &b){RF(a), RF(b); return a;}
inline DB& RF(DB &a, DB &b, DB &c){RF(a), RF(b), RF(c); return a;}
inline DB& RF(DB &a, DB &b, DB &c, DB &d){RF(a), RF(b), RF(c), RF(d); return a;}
inline DB& RF(DB &a, DB &b, DB &c, DB &d, DB &e){RF(a), RF(b), RF(c), RF(d), RF(e); return a;}
inline DB& RF(DB &a, DB &b, DB &c, DB &d, DB &e, DB &f){RF(a), RF(b), RF(c), RF(d), RF(e), RF(f); return a;}
inline DB& RF(DB &a, DB &b, DB &c, DB &d, DB &e, DB &f, DB &g){RF(a), RF(b), RF(c), RF(d), RF(e), RF(f), RF(g); return a;}
inline void RS(char *s1, char *s2){RS(s1), RS(s2);}
inline void RS(char *s1, char *s2, char *s3){RS(s1), RS(s2), RS(s3);}

template<class T> inline void RST(T &A){memset(A, 0, sizeof(A));}
template<class T> inline void FLC(T &A, int x){memset(A, x, sizeof(A));}
template<class T> inline void CLR(T &A){A.clear();}

template<class T0, class T1> inline void RST(T0 &A0, T1 &A1){RST(A0), RST(A1);}
template<class T0, class T1, class T2> inline void RST(T0 &A0, T1 &A1, T2 &A2){RST(A0), RST(A1), RST(A2);}
template<class T0, class T1, class T2, class T3> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3){RST(A0), RST(A1), RST(A2), RST(A3);}
template<class T0, class T1, class T2, class T3, class T4> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4){RST(A0), RST(A1), RST(A2), RST(A3), RST(A4);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5){RST(A0), RST(A1), RST(A2), RST(A3), RST(A4), RST(A5);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6){RST(A0), RST(A1), RST(A2), RST(A3), RST(A4), RST(A5), RST(A6);}
template<class T0, class T1> inline void FLC(T0 &A0, T1 &A1, int x){FLC(A0, x), FLC(A1, x);}
template<class T0, class T1, class T2> inline void FLC(T0 &A0, T1 &A1, T2 &A2, int x){FLC(A0, x), FLC(A1, x), FLC(A2, x);}
template<class T0, class T1, class T2, class T3> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, int x){FLC(A0, x), FLC(A1, x), FLC(A2, x), FLC(A3, x);}
template<class T0, class T1, class T2, class T3, class T4> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, int x){FLC(A0, x), FLC(A1, x), FLC(A2, x), FLC(A3, x), FLC(A4, x);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, int x){FLC(A0, x), FLC(A1, x), FLC(A2, x), FLC(A3, x), FLC(A4, x), FLC(A5, x);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6, int x){FLC(A0, x), FLC(A1, x), FLC(A2, x), FLC(A3, x), FLC(A4, x), FLC(A5, x), FLC(A6, x);}
template<class T> inline void CLR(priority_queue<T> &Q){while (!Q.empty()) Q.pop();}
template<class T> inline void CLR(stack<T> &S){while (!S.empty()) S.pop();}
template<class T> inline void CLR(queue<T> &Q){while (!Q.empty()) Q.pop();}

template<class T0, class T1> inline void CLR(T0 &A0, T1 &A1){CLR(A0), CLR(A1);}
template<class T0, class T1, class T2> inline void CLR(T0 &A0, T1 &A1, T2 &A2){CLR(A0), CLR(A1), CLR(A2);}
template<class T0, class T1, class T2, class T3> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3){CLR(A0), CLR(A1), CLR(A2), CLR(A3);}
template<class T0, class T1, class T2, class T3, class T4> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4){CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5){CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4), CLR(A5);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6){CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4), CLR(A5), CLR(A6);}
template<class T> inline void CLR(T &A, int n){REP(i, n) CLR(A[i]);}

template<class T> inline bool EPT(T &a){return a.empty();}
template<class T> inline T& SRT(T &A){sort(ALL(A)); return A;}
template<class T, class C> inline T& SRT(T &A, C cmp){sort(ALL(A), cmp); return A;}
template<class T> inline T& RVS(T &A){reverse(ALL(A)); return A;}
template<class T> inline T& UNQQ(T &A){A.resize(unique(ALL(A))-A.begin());return A;}
template<class T> inline T& UNQ(T &A){SRT(A);return UNQQ(A);}
template<class T, class C> inline T& UNQ(T &A, C cmp){SRT(A, cmp);return UNQQ(A);}



/** Constant List .. **/ //{

const int MOD = int(1e9) + 7;
const int INF = 0x3f3f3f3f;
const LL INFF = 0x3f3f3f3f3f3f3f3fLL;
const DB EPS = 1e-9;
const DB OO = 1e20;
const DB PI = acos(-1.0); //M_PI;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};


/** Add On .. **/ //{

template<class T> inline bool checkMin(T &a,const T b){return b < a ? a = b, 1 : 0;}
template<class T> inline bool checkMax(T &a,const T b){return a < b ? a = b, 1 : 0;}
template <class T, class C> inline bool checkUpd(T& a, const T b, C c){return c(b,a) ? a = b, 1 : 0;}
template<class T> inline T min(T a, T b, T c){return min(min(a, b), c);}
template<class T> inline T max(T a, T b, T c){return max(max(a, b), c);}
template<class T> inline T min(T a, T b, T c, T d){return min(min(a, b), min(c, d));}
template<class T> inline T max(T a, T b, T c, T d){return max(max(a, b), max(c, d));}
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline T cub(T a){return a*a*a;}
template<class T> inline T ceil(T x, T y){return (x - 1) / y + 1;}
template<class T> T abs(T x){return x>0?x:-x;}
inline int sgn(DB x){return x < -EPS ? -1 : x > EPS;}
inline int sgn(DB x, DB y){return sgn(x - y);}





/** I/O Accelerator Interface .. **/ //{
#define g (c=getchar())
#define d isdigit(g)
#define p x=x*10+c-'0'
#define n x=x*10+'0'-c
#define pp l/=10,p
#define nn l/=10,n
template<class T> inline T& RD(T &x){
    char c;while(g,c!='-'&&!isdigit(c));
    if (c=='-'){x='0'-g;while(d)n;}
    else{x=c-'0';while(d)p;}
    return x;
}
inline DB& RF(DB &x){
    char c;while(g,c!='-'&&c!='.'&&!isdigit(c));
    if(c=='-')if(g=='.'){x=0;DB l=1;while(d)nn;x*=l;}
        else{x='0'-c;while(d)n;if(c=='.'){DB l=1;while(d)nn;x*=l;}}
    else if(c=='.'){x=0;DB l=1;while(d)pp;x*=l;}
        else{x=c-'0';while(d)p;if(c=='.'){DB l=1;while(d)pp;x*=l;}}
    return x;
}
#undef nn
#undef pp
#undef n
#undef p
#undef d
#undef g
inline char* RS(char *s){
    scanf("%s", s);
    return s;
}

LL last_ans; int Case; template<class T> inline void OT(const T &x){
    cout << x << endl;
}
namespace lastweapon {}

namespace lastweapon {

namespace splay {

template <class S, void (*op)(S&, const S, const S), S (*e)()>
struct node {

    static node *NIL; node *c[2], *p;
    int sz; S d;

#define NIL node::NIL
#define l c[0]
#define r c[1]
#define lx x->l
#define rx x->r
#define px x->p
#define ly y->l
#define ry y->r
#define py y->p

    node(S s = e()){d=e();}
    inline void reset(S s){l=r=p=NIL,d=s;sz=1;}

    inline void upd(){
        assert(this != NIL);
        sz = l->sz + 1 + r->sz;
        op(d, l->d, r->d);
    }
    inline int sgn(){return p->r==this;}
    inline void setc(int d,node*x){c[d]=x,px=this;}
    inline void setl(node*x){setc(0,x);}
    inline void setr(node*x){setc(1,x);}

    inline void rot(int d){
        node*y=p,*z=py;z->setc(y->sgn(),this);
        y->setc(d,c[!d]),setc(!d,y),y->upd();
    }
    inline void rot(){rot(sgn());}


    /*inline node* splay(node*t){
        while (p!=t) rot(); upd();
        return this;
    }*/

    inline node*splay(node*t){
        int a,b;while(p!=t){
            if (p->p==t){rot();break;}
            else a=sgn(),b=p->sgn(),(a^b?this:p)->rot(a),rot(b);
        }
        upd();
        return this;
    }
};


template <class S, void (*op)(S&, const S, const S), S (*e)()>
struct splay {

#define node node<S, op, e>

    std::vector<node> d;
    int n; node* rt;

    splay() : splay(0) {}
    explicit splay(int n) : splay(std::vector<S>(n, e())) {}
    explicit splay(const std::vector<S>& a) : n(int(a.size())) {
        rt = new node(); rt->reset(0);
        REP(i, n) {
            node* t = new node();
            t->reset(a[i]);
            t->setl(rt); t->upd();
            rt = t;
        }
        node* t = new node();
        t->reset(0);
        t->setl(rt); t->upd();
        rt = t;
    }

    node *select(int k, node*t=NIL){
        node *x = rt; while (lx->sz != k){
            if (k < lx->sz) x = lx;
            else k -= lx->sz+1, x = rx;
        }
        if (t == NIL) rt = x;

        return x->splay(t);
    }

    node *select(int a, int b){
        return select(a-1, select(b))->r;
    }

    S prod(int a, int b) {
        return select(a, b)->d;
    }

    void set(int p, S s) {
        node* x = select(p, p+1); x->d = s;
        while (x->p != NIL) {
            x = x->p;
            x->upd();
        }
    }
};

#undef NIL

template <class S, void (*op)(S&, const S, const S), S (*e)()>
node *node::NIL = new node;

#undef node
#undef l
#undef r
#undef lx
#undef rx
#undef px
#undef ly
#undef ry
#undef py

}  // namespace splay

}  // namespace lastweapon

using namespace lastweapon;

/*
const int N = int(1e5) + 9, M = N*2;

struct node{

    static node* NIL; node *c[2], *p;
    int w1, w2, d0; bool r0;

#define NIL node::NIL
#define l c[0]
#define r c[1]
#define lx x->l
#define rx x->r
#define px x->p
#define ly y->l
#define ry y->r
#define py y->p

    void reset(){
        l = r = p = NIL;
        w1 = w2 = d0 = r0 = 0;
    }

    inline node(){
        reset();
    }

    inline void rev(){
        r0 ^= 1, swap(l, r);
    }

    inline void inc(int d){
        if (this == NIL) return;
        w1 += d, w2 += d, d0 += d;
    }

    inline void upd(){
        w2 = max(l->w2, w1, r->w2);
    }

    inline void rls(){
        //if (this == NIL) return;
        if (r0){
            l->rev(), r->rev();
            r0 = 0;
        }
        if (d0){
            l->inc(d0), r->inc(d0);
            d0 = 0;
        }
    }

    // Ðý×ª

    inline int sgn(){return p->l==this?0:p->r==this?1:-1;}
    inline void setc(int d,node*x){c[d]=x,px=this;}

    inline void rot(int d){
        node *y = p, *z = py; if (~y->sgn()) z->setc(y->sgn(), this); else p = z;
        y->setc(!d, c[d]), setc(d, y), y->upd();
    }

    inline void rot(){rot(!sgn());}
    inline void zag(){rot(0);}
    inline void zig(){rot(1);}

    // ÉìÕ¹

    inline void fix(){if(~sgn()) p->fix(); rls();}


    inline node* splay(){
        fix(); while (~sgn()) rot(); upd();
        return this;
    }

    inline node* splay(){
        fix(); while (sgn() != -1){
            node *y = p, *z = py; if (y->sgn() == -1){ rot(); break;}
            if (z->l == y){
                if (y->l == this) y->zig(), zig();
                else zag(), zig();
            }else{
                if (y->r == this) y->zag(), zag();
                else zig(), zag();
            }
        }
        upd();
        return this;
    }

    inline node* acs(){
        node *x = this, *y = NIL; do{
            x->splay();
            rx = y, x->upd();
            y = x, x = px;
        } while (x != NIL);
        return splay();
    }

    node* rt(){node* x; for (x = acs(); x->rls(), lx != NIL; x = lx); return x->splay();}
    node* ert(){acs()->rev(); return this;}


    void Link(node *x){
        if (rt() == x->rt()){
            puts("-1");
        }
        else {
            ert(), p = x;
        }
    }

    void Cut(){
        acs(); l->p = NIL; l = NIL;
    }

    void Cut(node* x){
        if (this == x || rt() != x->rt()){
            puts("-1");
        }
        else {
            ert(), x->Cut();
        }
    }

    void Query(node* x){
        // x->ert(); OT(acs()->w2);
        acs(); node *y = NIL; do{
            x->splay(); if (px == NIL) OT(max(rx->w2, y->w2));
            rx = y, x->upd();
            y = x, x = px;
        } while (x != NIL);
    }

    void Modify(int d){
        acs()->w1 = d;
        // acs()->inc(d);
    }
} *NIL, *T[N];

int hd[N], nxt[M], a[M], b[M], w[M], h[M/2];
// Adjacent list
int n;

#define v b[i]
#define w w[i/2]

inline void dfs(int u = 1, int p = 0){
    for(int i=hd[u];i;i=nxt[i]) if (v != p) {
        T[v]->p = T[u], T[v]->w1 = w; dfs(h[i>>1] = v, u);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    NIL = new node(); REP_1(i, N) T[i] = new node();

    RD(n); FOR(i, 2, n<<1){
        RD(a[i], b[i], w), a[i|1] = b[i], b[i|1] = a[i];
        nxt[i] = hd[a[i]], hd[a[i]] = i; ++i;
        nxt[i] = hd[a[i]], hd[a[i]] = i;
    }

    dfs();

    char cmd[9]; int a, b; while(1){
        RS(cmd); if (cmd[0] == 'Q') {
            RD(a, b); T[a]->Query(T[b]);
        } else if (cmd[0] == 'C'){
            RD(a, b); T[h[a]]->Modify(b);
        } else {
            break;
        }
    }
}
*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=123456789123456789ll;
int n,m,head[100100],cnt;
struct node{int to,next,val;}edge[200100];
void ae(int u,int v,int w){
	edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,head[u]=cnt++;
	edge[cnt].next=head[v],edge[cnt].to=u,edge[cnt].val=w,head[v]=cnt++;
}
int fa[100100],dep[100100],son[100100],sz[100100],dfn[100100],rev[100100],top[100100],tot;
ll dis[100100];
void dfs1(int x){
	sz[x]=1;
	for(int i=head[x];i!=-1;i=edge[i].next){
		if(edge[i].to==fa[x])continue;
		fa[edge[i].to]=x,dis[edge[i].to]=dis[x]+edge[i].val,dep[edge[i].to]=dep[x]+1;
		dfs1(edge[i].to);
		sz[x]+=sz[edge[i].to];
		if(sz[edge[i].to]>sz[son[x]])son[x]=edge[i].to;
	}
}
void dfs2(int x){
	dfn[x]=++tot,rev[tot]=x;if(!top[x])top[x]=x;
	if(son[x])top[son[x]]=top[x],dfs2(son[x]);
	for(int i=head[x];i!=-1;i=edge[i].next)if(edge[i].to!=fa[x]&&edge[i].to!=son[x])dfs2(edge[i].to);
}
int LCA(int x,int y){while(top[x]!=top[y]){if(dep[top[x]]<dep[top[y]])swap(x,y);x=fa[top[x]];}if(dep[x]>dep[y])swap(x,y);return x;}
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
namespace FS{//full section
	ll mn[400100];
	void build(int x,int l,int r){mn[x]=inf;if(l!=r)build(lson,l,mid),build(rson,mid+1,r);}
	void modify(int x,int l,int r,int P,ll val){if(l>P||r<P)return;mn[x]=min(mn[x],val);if(l!=r)modify(lson,l,mid,P,val),modify(rson,mid+1,r,P,val);}
	ll query(int x,int l,int r,int L,int R){if(l>R||r<L)return inf;if(L<=l&&r<=R)return mn[x];return min(query(lson,l,mid,L,R),query(rson,mid+1,r,L,R));}
}
namespace BS{//boundary situation
	struct SegTree{ll b;int k;}seg[400100];
	void build(int x,int l,int r){seg[x].k=0,seg[x].b=inf;if(l!=r)build(lson,l,mid),build(rson,mid+1,r);}
	void modify(int x,int l,int r,int L,int R,int K,ll B){
		if(l>R||r<L)return;
		if(L<=l&&r<=R){
			if(dis[rev[mid]]*K+B<dis[rev[mid]]*seg[x].k+seg[x].b)swap(seg[x].k,K),swap(seg[x].b,B);
			if(dis[rev[l]]*K+B<dis[rev[l]]*seg[x].k+seg[x].b)modify(lson,l,mid,L,R,K,B);
			if(dis[rev[r]]*K+B<dis[rev[r]]*seg[x].k+seg[x].b)modify(rson,mid+1,r,L,R,K,B);
			return;
		}
		modify(lson,l,mid,L,R,K,B),modify(rson,mid+1,r,L,R,K,B);
	}
	ll query(int x,int l,int r,int P){
		if(l>P||r<P)return inf;
		ll ret=dis[rev[P]]*seg[x].k+seg[x].b;
		if(l!=r)ret=min(ret,query(lson,l,mid,P)),ret=min(ret,query(rson,mid+1,r,P));
		return ret;
	}
}
void modify(int L,int R,int K,ll B){L=dfn[L],R=dfn[R],FS::modify(1,1,n,L,dis[rev[L]]*K+B),FS::modify(1,1,n,R,dis[rev[R]]*K+B),BS::modify(1,1,n,L,R,K,B);}
ll query(int L,int R){L=dfn[L],R=dfn[R];return min(FS::query(1,1,n,L,R),min(BS::query(1,1,n,L),BS::query(1,1,n,R)));}
void chain(int x,int y,int K,ll B){while(top[x]!=top[y])modify(top[x],x,K,B),x=fa[top[x]];modify(y,x,K,B);}
void pathmodify(int x,int y,int A,int B){int z=LCA(x,y);chain(x,z,-A,dis[x]*A+B),chain(y,z,A,(dis[x]-dis[z]*2)*A+B);}
ll pathquery(int x,int y){
	ll ret=inf;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		ret=min(ret,query(top[x],x)),x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);ret=min(ret,query(x,y));return ret;
}
int main(){
	scanf("%d%d",&n,&m),memset(head,-1,sizeof(head));
	for(int i=1,x,y,z;i<n;i++)scanf("%d%d%d",&x,&y,&z),ae(x,y,z);
	dfs1(1),dfs2(1);
//	for(int x=1;x<=n;x++)printf("FA:%d SN:%d SZ:%d DP:%d DS:%lld RV:%d DF:%d TP:%d\n",fa[x],son[x],sz[x],dep[x],dis[x],rev[x],dfn[x],top[x]);
	FS::build(1,1,n),BS::build(1,1,n);
	for(int i=1,x,y,a,b,tp;i<=m;i++){
		scanf("%d%d%d",&tp,&x,&y);
		if(tp==1)scanf("%d%d",&a,&b),pathmodify(x,y,a,b);
		else printf("%lld\n",pathquery(x,y));
	}
	return 0;
}
