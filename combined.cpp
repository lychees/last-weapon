/*
    Last Weapon is my own algorithms library for competitive programming, it is a fork from ACL with some alternative algorithms and additional features. Use it at your own risk.
    Repo: https://github.com/lychees/last-weapon
    Blog: https://www.shuizilong.com/house
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

int MOD = int(1e9) + 7;
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

template<typename T1, typename T2> istream& operator>>(istream& in, pair<T1, T2>& a) {
    in >> a.fi >> a.se;
    return in;
}
template<typename T, size_t N> istream& operator>>(istream& in, array<T, N>& a) {
    REP(i, N) cin >> a[i];
    return in;
}
template<typename T> istream& operator>>(istream& in, vector<T>& a) {
    REP(i, SZ(a)) in >> a[i];
    return in;
}
template<typename T1, typename T2> ostream& operator<<(ostream& out, pair<T1, T2>& a) {
    out << a.fi << " " << a.se;
    return out;
}
template<typename T, size_t N> ostream& operator<<(ostream& out, array<T, N>& a) {
    REP(i, N-1) out << a[i] << " "; if (N) out << a.back();
    return out;
}
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {
    REP(i, SZ(a)-1) out << a[i] << " "; if (SZ(a)) out << a.back();
    return out;
}





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


template <unsigned M_> struct ModInt {
  static constexpr unsigned M = M_;
  unsigned x;
  constexpr ModInt() : x(0U) {}
  constexpr ModInt(unsigned x_) : x(x_ % M) {}
  constexpr ModInt(unsigned long long x_) : x(x_ % M) {}
  constexpr ModInt(int x_) : x(((x_ %= static_cast<int>(M)) < 0) ? (x_ + static_cast<int>(M)) : x_) {}
  constexpr ModInt(long long x_) : x(((x_ %= static_cast<long long>(M)) < 0) ? (x_ + static_cast<long long>(M)) : x_) {}
  ModInt &operator+=(const ModInt &a) { x = ((x += a.x) >= M) ? (x - M) : x; return *this; }
  ModInt &operator-=(const ModInt &a) { x = ((x -= a.x) >= M) ? (x + M) : x; return *this; }
  ModInt &operator*=(const ModInt &a) { x = (static_cast<unsigned long long>(x) * a.x) % M; return *this; }
  ModInt &operator/=(const ModInt &a) { return (*this *= a.inv()); }
  ModInt pow(long long e) const {
    if (e < 0) return inv().pow(-e);
    ModInt a = *this, b = 1U; for (; e; e >>= 1) { if (e & 1) b *= a; a *= a; } return b;
  }
  ModInt inv() const {
    unsigned a = M, b = x; int y = 0, z = 1;
    for (; b; ) { const unsigned q = a / b; const unsigned c = a - q * b; a = b; b = c; const int w = y - static_cast<int>(q) * z; y = z; z = w; }
    assert(a == 1U); return ModInt(y);
  }
  ModInt operator+() const { return *this; }
  ModInt operator-() const { ModInt a; a.x = x ? (M - x) : 0U; return a; }
  ModInt operator+(const ModInt &a) const { return (ModInt(*this) += a); }
  ModInt operator-(const ModInt &a) const { return (ModInt(*this) -= a); }
  ModInt operator*(const ModInt &a) const { return (ModInt(*this) *= a); }
  ModInt operator/(const ModInt &a) const { return (ModInt(*this) /= a); }
  template <class T> friend ModInt operator+(T a, const ModInt &b) { return (ModInt(a) += b); }
  template <class T> friend ModInt operator-(T a, const ModInt &b) { return (ModInt(a) -= b); }
  template <class T> friend ModInt operator*(T a, const ModInt &b) { return (ModInt(a) *= b); }
  template <class T> friend ModInt operator/(T a, const ModInt &b) { return (ModInt(a) /= b); }
  explicit operator bool() const { return x; }
  bool operator==(const ModInt &a) const { return (x == a.x); }
  bool operator!=(const ModInt &a) const { return (x != a.x); }
  friend std::ostream &operator<<(std::ostream &os, const ModInt &a) { return os << a.x; }
};


constexpr unsigned MO = 998244353U;
constexpr unsigned MO2 = 2U * MO;
constexpr int FFT_MAX = 23;
using Mint = ModInt<MO>;
constexpr Mint FFT_ROOTS[FFT_MAX + 1] = {1U, 998244352U, 911660635U, 372528824U, 929031873U, 452798380U, 922799308U, 781712469U, 476477967U, 166035806U, 258648936U, 584193783U, 63912897U, 350007156U, 666702199U, 968855178U, 629671588U, 24514907U, 996173970U, 363395222U, 565042129U, 733596141U, 267099868U, 15311432U};
constexpr Mint INV_FFT_ROOTS[FFT_MAX + 1] = {1U, 998244352U, 86583718U, 509520358U, 337190230U, 87557064U, 609441965U, 135236158U, 304459705U, 685443576U, 381598368U, 335559352U, 129292727U, 358024708U, 814576206U, 708402881U, 283043518U, 3707709U, 121392023U, 704923114U, 950391366U, 428961804U, 382752275U, 469870224U};
constexpr Mint FFT_RATIOS[FFT_MAX] = {911660635U, 509520358U, 369330050U, 332049552U, 983190778U, 123842337U, 238493703U, 975955924U, 603855026U, 856644456U, 131300601U, 842657263U, 730768835U, 942482514U, 806263778U, 151565301U, 510815449U, 503497456U, 743006876U, 741047443U, 56250497U, 867605899U};
constexpr Mint INV_FFT_RATIOS[FFT_MAX] = {86583718U, 372528824U, 373294451U, 645684063U, 112220581U, 692852209U, 155456985U, 797128860U, 90816748U, 860285882U, 927414960U, 354738543U, 109331171U, 293255632U, 535113200U, 308540755U, 121186627U, 608385704U, 438932459U, 359477183U, 824071951U, 103369235U};

/*
constexpr unsigned MO =  1004535809U;
constexpr unsigned MO2 = 2U * MO;
constexpr int FFT_MAX = 21;
using Mint = ModInt<MO>;
constexpr Mint FFT_ROOTS[FFT_MAX + 1] = {1U, 1004535808U, 483363861U, 395918948U, 691095095U, 67253981U, 89059135U, 337291080U, 317143553U, 8295483U, 327081633U, 714163887U, 295244910U, 2062645U, 524615618U, 333849333U, 50393163U, 925609281U, 615614863U, 862977694U, 848723745U, 702606812U};
constexpr Mint INV_FFT_ROOTS[FFT_MAX + 1] = {1U, 1004535808U, 521171948U, 181280972U, 440257849U, 236219887U, 412852222U, 174881506U, 581383828U, 870703586U, 216733913U, 278605116U, 200320826U, 58507845U, 191870395U, 411091405U, 755911120U, 816727090U, 689146186U, 353531124U, 97543274U, 700146880U};
constexpr Mint FFT_RATIOS[FFT_MAX] = {483363861U, 181280972U, 517765470U, 89836266U, 555820998U, 452781753U, 775939161U, 240583721U, 316199902U, 663813733U, 123325259U, 333317974U, 237423280U, 77061338U, 785227561U, 317445082U, 398519305U, 22415135U, 94458470U, 719009841U};
constexpr Mint INV_FFT_RATIOS[FFT_MAX] = {521171948U, 395918948U, 232236581U, 237230421U, 224910463U, 354315367U, 838316360U, 950996795U, 850581318U, 901398244U, 348478829U, 346227001U, 400741340U, 1003986296U, 423186697U, 870066632U, 5313248U, 594306560U, 924324899U, 674933703U};
*/

void fft(Mint *as, int n) {
  assert(!(n & (n - 1))); assert(1 <= n); assert(n <= 1 << FFT_MAX);
  int m = n;
  if (m >>= 1) {
    for (int i = 0; i < m; ++i) {
      const unsigned x = as[i + m].x;  // < MO
      as[i + m].x = as[i].x + MO - x;  // < 2 MO
      as[i].x += x;  // < 2 MO
    }
  }
  if (m >>= 1) {
    Mint prod = 1U;
    for (int h = 0, i0 = 0; i0 < n; i0 += (m << 1)) {
      for (int i = i0; i < i0 + m; ++i) {
        const unsigned x = (prod * as[i + m]).x;  // < MO
        as[i + m].x = as[i].x + MO - x;  // < 3 MO
        as[i].x += x;  // < 3 MO
      }
      prod *= FFT_RATIOS[__builtin_ctz(++h)];
    }
  }
  for (; m; ) {
    if (m >>= 1) {
      Mint prod = 1U;
      for (int h = 0, i0 = 0; i0 < n; i0 += (m << 1)) {
        for (int i = i0; i < i0 + m; ++i) {
          const unsigned x = (prod * as[i + m]).x;  // < MO
          as[i + m].x = as[i].x + MO - x;  // < 4 MO
          as[i].x += x;  // < 4 MO
        }
        prod *= FFT_RATIOS[__builtin_ctz(++h)];
      }
    }
    if (m >>= 1) {
      Mint prod = 1U;
      for (int h = 0, i0 = 0; i0 < n; i0 += (m << 1)) {
        for (int i = i0; i < i0 + m; ++i) {
          const unsigned x = (prod * as[i + m]).x;  // < MO
          as[i].x = (as[i].x >= MO2) ? (as[i].x - MO2) : as[i].x;  // < 2 MO
          as[i + m].x = as[i].x + MO - x;  // < 3 MO
          as[i].x += x;  // < 3 MO
        }
        prod *= FFT_RATIOS[__builtin_ctz(++h)];
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    as[i].x = (as[i].x >= MO2) ? (as[i].x - MO2) : as[i].x;  // < 2 MO
    as[i].x = (as[i].x >= MO) ? (as[i].x - MO) : as[i].x;  // < MO
  }
}

void invFft(Mint *as, int n) {
  assert(!(n & (n - 1))); assert(1 <= n); assert(n <= 1 << FFT_MAX);
  int m = 1;
  if (m < n >> 1) {
    Mint prod = 1U;
    for (int h = 0, i0 = 0; i0 < n; i0 += (m << 1)) {
      for (int i = i0; i < i0 + m; ++i) {
        const unsigned long long y = as[i].x + MO - as[i + m].x;  // < 2 MO
        as[i].x += as[i + m].x;  // < 2 MO
        as[i + m].x = (prod.x * y) % MO;  // < MO
      }
      prod *= INV_FFT_RATIOS[__builtin_ctz(++h)];
    }
    m <<= 1;
  }
  for (; m < n >> 1; m <<= 1) {
    Mint prod = 1U;
    for (int h = 0, i0 = 0; i0 < n; i0 += (m << 1)) {
      for (int i = i0; i < i0 + (m >> 1); ++i) {
        const unsigned long long y = as[i].x + MO2 - as[i + m].x;  // < 4 MO
        as[i].x += as[i + m].x;  // < 4 MO
        as[i].x = (as[i].x >= MO2) ? (as[i].x - MO2) : as[i].x;  // < 2 MO
        as[i + m].x = (prod.x * y) % MO;  // < MO
      }
      for (int i = i0 + (m >> 1); i < i0 + m; ++i) {
        const unsigned long long y = as[i].x + MO - as[i + m].x;  // < 2 MO
        as[i].x += as[i + m].x;  // < 2 MO
        as[i + m].x = (prod.x * y) % MO;  // < MO
      }
      prod *= INV_FFT_RATIOS[__builtin_ctz(++h)];
    }
  }
  if (m < n) {
    for (int i = 0; i < m; ++i) {
      const unsigned y = as[i].x + MO2 - as[i + m].x;  // < 4 MO
      as[i].x += as[i + m].x;  // < 4 MO
      as[i + m].x = y;  // < 4 MO
    }
  }
  const Mint invN = Mint(n).inv();
  for (int i = 0; i < n; ++i) {
    as[i] *= invN;
  }
}

void fft(vector<Mint> &as) {
  fft(as.data(), as.size());
}
void invFft(vector<Mint> &as) {
  invFft(as.data(), as.size());
}

vector<Mint> convolve(vector<Mint> as, vector<Mint> bs) {
  if (as.empty() || bs.empty()) return {};
  const int len = as.size() + bs.size() - 1;
  int n = 1;
  for (; n < len; n <<= 1) {}
  as.resize(n); fft(as);
  bs.resize(n); fft(bs);
  for (int i = 0; i < n; ++i) as[i] *= bs[i];
  invFft(as);
  as.resize(len);
  return as;
}
vector<Mint> square(vector<Mint> as) {
  if (as.empty()) return {};
  const int len = as.size() + as.size() - 1;
  int n = 1;
  for (; n < len; n <<= 1) {}
  as.resize(n); fft(as);
  for (int i = 0; i < n; ++i) as[i] *= as[i];
  invFft(as);
  as.resize(len);
  return as;
}

constexpr int LIM_INV = 1 << 20;  // @
Mint inv[LIM_INV], fac[LIM_INV], invFac[LIM_INV];
struct ModIntPreparator {
  ModIntPreparator() {
    inv[1] = 1;
    for (int i = 2; i < LIM_INV; ++i) inv[i] = -((Mint::M / i) * inv[Mint::M % i]);
    fac[0] = 1;
    for (int i = 1; i < LIM_INV; ++i) fac[i] = fac[i - 1] * i;
    invFac[0] = 1;
    for (int i = 1; i < LIM_INV; ++i) invFac[i] = invFac[i - 1] * inv[i];
  }
} preparator;

static constexpr int LIM_POLY = 1 << 20;  // @
static_assert(LIM_POLY <= 1 << FFT_MAX, "Poly: LIM_POLY <= 1 << FFT_MAX must hold.");
static Mint polyWork0[LIM_POLY], polyWork1[LIM_POLY], polyWork2[LIM_POLY], polyWork3[LIM_POLY];

struct Poly : public vector<Mint> {
  Poly() {}
  explicit Poly(int n) : vector<Mint>(n) {}
  Poly(const vector<Mint> &vec) : vector<Mint>(vec) {}
  Poly(std::initializer_list<Mint> il) : vector<Mint>(il) {}
  int size() const { return vector<Mint>::size(); }
  Mint at(long long k) const { return (0 <= k && k < size()) ? (*this)[k] : 0U; }
  int ord() const { for (int i = 0; i < size(); ++i) if ((*this)[i]) return i; return -1; }
  int deg() const { for (int i = size(); --i >= 0; ) if ((*this)[i]) return i; return -1; }
  Poly mod(int n) const { return Poly(vector<Mint>(data(), data() + min(n, size()))); }
  friend std::ostream &operator<<(std::ostream &os, const Poly &fs) {
    os << "[";
    for (int i = 0; i < fs.size(); ++i) { if (i > 0) os << ", "; os << fs[i]; }
    return os << "]";
  }

  Poly &operator+=(const Poly &fs) {
    if (size() < fs.size()) resize(fs.size());
    for (int i = 0; i < fs.size(); ++i) (*this)[i] += fs[i];
    return *this;
  }
  Poly &operator-=(const Poly &fs) {
    if (size() < fs.size()) resize(fs.size());
    for (int i = 0; i < fs.size(); ++i) (*this)[i] -= fs[i];
    return *this;
  }
  Poly &operator*=(const Poly &fs) {
    if (empty() || fs.empty()) return *this = {};
    const int nt = size(), nf = fs.size();
    int n = 1;
    for (; n < nt + nf - 1; n <<= 1) {}
    assert(n <= LIM_POLY);
    resize(n);
    fft(data(), n);  // 1 E(n)
    memcpy(polyWork0, fs.data(), nf * sizeof(Mint));
    memset(polyWork0 + nf, 0, (n - nf) * sizeof(Mint));
    fft(polyWork0, n);  // 1 E(n)
    for (int i = 0; i < n; ++i) (*this)[i] *= polyWork0[i];
    invFft(data(), n);  // 1 E(n)
    resize(nt + nf - 1);
    return *this;
  }
  Poly &operator/=(const Poly &fs) {
    const int m = deg(), n = fs.deg();
    assert(n != -1);
    if (m < n) return *this = {};
    Poly tsRev(m - n + 1), fsRev(min(m - n, n) + 1);
    for (int i = 0; i <= m - n; ++i) tsRev[i] = (*this)[m - i];
    for (int i = 0, i0 = min(m - n, n); i <= i0; ++i) fsRev[i] = fs[n - i];
    const Poly qsRev = tsRev.div(fsRev, m - n + 1);  // 13 E(m - n + 1)
    resize(m - n + 1);
    for (int i = 0; i <= m - n; ++i) (*this)[i] = qsRev[m - n - i];
    return *this;
  }
  Poly &operator%=(const Poly &fs) {
    const Poly qs = *this / fs;  // 13 E(deg(t) - deg(f) + 1)
    *this -= fs * qs;  // 3 E(|t|)
    resize(deg() + 1);
    return *this;
  }
  Poly &operator+=(const Mint fs) {
    (*this)[0] += fs;
    return *this;
  }
  Poly &operator-=(const Mint fs) {
    (*this)[0] -= fs;
    return *this;
  }
  Poly &operator*=(const Mint &a) {
    for (int i = 0; i < size(); ++i) (*this)[i] *= a;
    return *this;
  }
  Poly &operator/=(const Mint &a) {
    const Mint b = a.inv();
    for (int i = 0; i < size(); ++i) (*this)[i] *= b;
    return *this;
  }
  Poly operator+() const { return *this; }
  Poly operator-() const {
    Poly fs(size());
    for (int i = 0; i < size(); ++i) fs[i] = -(*this)[i];
    return fs;
  }
  Poly operator+(const Poly &fs) const { return (Poly(*this) += fs); }
  Poly operator-(const Poly &fs) const { return (Poly(*this) -= fs); }
  Poly operator*(const Poly &fs) const { return (Poly(*this) *= fs); }
  Poly operator/(const Poly &fs) const { return (Poly(*this) /= fs); }
  Poly operator%(const Poly &fs) const { return (Poly(*this) %= fs); }
  Poly operator+(const Mint &fs) const { return (Poly(*this) += fs); }
  Poly operator-(const Mint &fs) const { return (Poly(*this) -= fs); }
  Poly operator*(const Mint &a) const { return (Poly(*this) *= a); }
  Poly operator/(const Mint &a) const { return (Poly(*this) /= a); }
  friend Poly operator*(const Mint &a, const Poly &fs) { return fs * a; }

  Poly inv(int n) const {
    assert(!empty()); assert((*this)[0]); assert(1 <= n);
    assert(n == 1 || 1 << (32 - __builtin_clz(n - 1)) <= LIM_POLY);
    Poly fs(n);
    fs[0] = (*this)[0].inv();
    for (int m = 1; m < n; m <<= 1) {
      memcpy(polyWork0, data(), min(m << 1, size()) * sizeof(Mint));
      memset(polyWork0 + min(m << 1, size()), 0, ((m << 1) - min(m << 1, size())) * sizeof(Mint));
      fft(polyWork0, m << 1);  // 2 E(n)
      memcpy(polyWork1, fs.data(), min(m << 1, n) * sizeof(Mint));
      memset(polyWork1 + min(m << 1, n), 0, ((m << 1) - min(m << 1, n)) * sizeof(Mint));
      fft(polyWork1, m << 1);  // 2 E(n)
      for (int i = 0; i < m << 1; ++i) polyWork0[i] *= polyWork1[i];
      invFft(polyWork0, m << 1); // 2 E(n)
      memset(polyWork0, 0, m * sizeof(Mint));
      fft(polyWork0, m << 1); // 2 E(n)
      for (int i = 0; i < m << 1; ++i) polyWork0[i] *= polyWork1[i];
      invFft(polyWork0, m << 1); // 2 E(n)
      for (int i = m, i0 = min(m << 1, n); i < i0; ++i) fs[i] = -polyWork0[i];
    }
    return fs;
  }
  /*
  Poly inv(int n) const {
    assert(!empty()); assert((*this)[0]); assert(1 <= n);
    assert(n == 1 || 3 << (31 - __builtin_clz(n - 1)) <= LIM_POLY);
    assert(n <= 1 << (FFT_MAX - 1));
    Poly fs(n);
    fs[0] = (*this)[0].inv();
    for (int h = 2, m = 1; m < n; ++h, m <<= 1) {
      const Mint a = FFT_ROOTS[h], b = INV_FFT_ROOTS[h];
      memcpy(polyWork0, data(), min(m << 1, size()) * sizeof(Mint));
      memset(polyWork0 + min(m << 1, size()), 0, ((m << 1) - min(m << 1, size())) * sizeof(Mint));
      {
        Mint aa = 1;
        for (int i = 0; i < m; ++i) { polyWork0[(m << 1) + i] = aa * polyWork0[i]; aa *= a; }
        for (int i = 0; i < m; ++i) { polyWork0[(m << 1) + i] += aa * polyWork0[m + i]; aa *= a; }
      }
      fft(polyWork0, m << 1);  // 2 E(n)
      fft(polyWork0 + (m << 1), m);  // 1 E(n)
      memcpy(polyWork1, fs.data(), min(m << 1, n) * sizeof(Mint));
      memset(polyWork1 + min(m << 1, n), 0, ((m << 1) - min(m << 1, n)) * sizeof(Mint));
      {
        Mint aa = 1;
        for (int i = 0; i < m; ++i) { polyWork1[(m << 1) + i] = aa * polyWork1[i]; aa *= a; }
        for (int i = 0; i < m; ++i) { polyWork1[(m << 1) + i] += aa * polyWork1[m + i]; aa *= a; }
      }
      fft(polyWork1, m << 1);  // 2 E(n)
      fft(polyWork1 + (m << 1), m);  // 1 E(n)
      for (int i = 0; i < (m << 1) + m; ++i) polyWork0[i] *= polyWork1[i] * polyWork1[i];
      invFft(polyWork0, m << 1);  // 2 E(n)
      invFft(polyWork0 + (m << 1), m);  // 1 E(n)
      {
        Mint bb = 1;
        for (int i = 0, i0 = min(m, n - m); i < i0; ++i) {
          unsigned x = polyWork0[i].x + (bb * polyWork0[(m << 1) + i]).x + MO2 - (fs[i].x << 1);  // < 4 MO
          fs[m + i] = Mint(static_cast<unsigned long long>(FFT_ROOTS[2].x) * x) - polyWork0[m + i];
          fs[m + i].x = ((fs[m + i].x & 1) ? (fs[m + i].x + MO) : fs[m + i].x) >> 1;
          bb *= b;
        }
      }
    }
    return fs;
  }
  */
  Poly div(const Poly &fs, int n) const {
    assert(!fs.empty()); assert(fs[0]); assert(1 <= n);
    if (n == 1) return {at(0) / fs[0]};
    const int m = 1 << (31 - __builtin_clz(n - 1));
    assert(m << 1 <= LIM_POLY);
    Poly gs = fs.inv(m);  // 5 E(n)
    gs.resize(m << 1);
    fft(gs.data(), m << 1);  // 1 E(n)
    memcpy(polyWork0, data(), min(m, size()) * sizeof(Mint));
    memset(polyWork0 + min(m, size()), 0, ((m << 1) - min(m, size())) * sizeof(Mint));
    fft(polyWork0, m << 1);  // 1 E(n)
    for (int i = 0; i < m << 1; ++i) polyWork0[i] *= gs[i];
    invFft(polyWork0, m << 1);  // 1 E(n)
    Poly hs(n);
    memcpy(hs.data(), polyWork0, m * sizeof(Mint));
    memset(polyWork0 + m, 0, m * sizeof(Mint));
    fft(polyWork0, m << 1);  // 1 E(n)
    memcpy(polyWork1, fs.data(), min(m << 1, fs.size()) * sizeof(Mint));
    memset(polyWork1 + min(m << 1, fs.size()), 0, ((m << 1) - min(m << 1, fs.size())) * sizeof(Mint));
    fft(polyWork1, m << 1);  // 1 E(n)
    for (int i = 0; i < m << 1; ++i) polyWork0[i] *= polyWork1[i];
    invFft(polyWork0, m << 1);  // 1 E(n)
    memset(polyWork0, 0, m * sizeof(Mint));
    for (int i = m, i0 = min(m << 1, size()); i < i0; ++i) polyWork0[i] -= (*this)[i];
    fft(polyWork0, m << 1);  // 1 E(n)
    for (int i = 0; i < m << 1; ++i) polyWork0[i] *= gs[i];
    invFft(polyWork0, m << 1);  // 1 E(n)
    for (int i = m; i < n; ++i) hs[i] = -polyWork0[i];
    return hs;
  }
  Mint divAt(const Poly &fs, long long k) const {
    assert(k >= 0);
    if (size() >= fs.size()) {
      const Poly qs = *this / fs;  // 13 E(deg(t) - deg(f) + 1)
      Poly rs = *this - fs * qs;  // 3 E(|t|)
      rs.resize(rs.deg() + 1);
      return qs.at(k) + rs.divAt(fs, k);
    }
    int h = 0, m = 1;
    for (; m < fs.size(); ++h, m <<= 1) {}
    if (k < m) {
      const Poly gs = fs.inv(k + 1);  // 10 E(|f|)
      Mint sum;
      for (int i = 0, i0 = min<int>(k + 1, size()); i < i0; ++i) sum += (*this)[i] * gs[k - i];
      return sum;
    }
    assert(m << 1 <= LIM_POLY);
    polyWork0[0] = Mint(2U).inv();
    for (int hh = 0; hh < h; ++hh) for (int i = 0; i < 1 << hh; ++i) polyWork0[1 << hh | i] = polyWork0[i] * INV_FFT_ROOTS[hh + 2];
    const Mint a = FFT_ROOTS[h + 1];
    memcpy(polyWork2, data(), size() * sizeof(Mint));
    memset(polyWork2 + size(), 0, ((m << 1) - size()) * sizeof(Mint));
    fft(polyWork2, m << 1);  // 2 E(|f|)
    memcpy(polyWork1, fs.data(), fs.size() * sizeof(Mint));
    memset(polyWork1 + fs.size(), 0, ((m << 1) - fs.size()) * sizeof(Mint));
    fft(polyWork1, m << 1);  // 2 E(|f|)
    for (; ; ) {
      if (k & 1) {
        for (int i = 0; i < m; ++i) polyWork2[i] = polyWork0[i] * (polyWork2[i << 1 | 0] * polyWork1[i << 1 | 1] - polyWork2[i << 1 | 1] * polyWork1[i << 1 | 0]);
      } else {
        for (int i = 0; i < m; ++i) {
          polyWork2[i] = polyWork2[i << 1 | 0] * polyWork1[i << 1 | 1] + polyWork2[i << 1 | 1] * polyWork1[i << 1 | 0];
          polyWork2[i].x = ((polyWork2[i].x & 1) ? (polyWork2[i].x + MO) : polyWork2[i].x) >> 1;
        }
      }
      for (int i = 0; i < m; ++i) polyWork1[i] = polyWork1[i << 1 | 0] * polyWork1[i << 1 | 1];
      if ((k >>= 1) < m) {
        invFft(polyWork2, m);  // 1 E(|f|)
        invFft(polyWork1, m);  // 1 E(|f|)
        const Poly gs = Poly(vector<Mint>(polyWork1, polyWork1 + k + 1)).inv(k + 1);  // 10 E(|f|)
        Mint sum;
        for (int i = 0; i <= k; ++i) sum += polyWork2[i] * gs[k - i];
        return sum;
      }
      memcpy(polyWork2 + m, polyWork2, m * sizeof(Mint));
      invFft(polyWork2 + m, m);  // (floor(log_2 k) - ceil(log_2 |f|)) E(|f|)
      memcpy(polyWork1 + m, polyWork1, m * sizeof(Mint));
      invFft(polyWork1 + m, m);  // (floor(log_2 k) - ceil(log_2 |f|)) E(|f|)
      Mint aa = 1;
      for (int i = m; i < m << 1; ++i) { polyWork2[i] *= aa; polyWork1[i] *= aa; aa *= a; }
      fft(polyWork2 + m, m);  // (floor(log_2 k) - ceil(log_2 |f|)) E(|f|)
      fft(polyWork1 + m, m);  // (floor(log_2 k) - ceil(log_2 |f|)) E(|f|)
    }
  }


  Poly D() const {
    Poly f(max(size() - 1, 1));
    for (int i = 1; i < size(); ++i) f[i - 1] = i * (*this)[i];
    return f;
  }

  Poly I() const {
    Poly f(size() + 1);
    for (int i = 0; i < size(); ++i) f[i + 1] = ::inv[i + 1] * (*this)[i];
    return f;
  }

  Poly log(int n) const {
    assert(!empty()); assert((*this)[0].x == 1U); assert(n <= LIM_INV);
    Poly fs = mod(n);
    for (int i = 0; i < fs.size(); ++i) fs[i] *= i;
    fs = fs.div(*this, n);
    for (int i = 1; i < n; ++i) fs[i] *= ::inv[i];
    return fs;
  }
  Poly exp(int n) const {
    assert(!empty()); assert(!(*this)[0]); assert(1 <= n);
    assert(n == 1 || 1 << (32 - __builtin_clz(n - 1)) <= min(LIM_INV, LIM_POLY));
    if (n == 1) return {1U};
    if (n == 2) return {1U, at(1)};
    Poly fs(n);
    fs[0].x = polyWork1[0].x = polyWork1[1].x = polyWork2[0].x = 1U;
    int m;
    for (m = 1; m << 1 < n; m <<= 1) {
      for (int i = 0, i0 = min(m, size()); i < i0; ++i) polyWork0[i] = i * (*this)[i];
      memset(polyWork0 + min(m, size()), 0, (m - min(m, size())) * sizeof(Mint));
      fft(polyWork0, m);  // (1/2) E(n)
      for (int i = 0; i < m; ++i) polyWork0[i] *= polyWork1[i];
      invFft(polyWork0, m);  // (1/2) E(n)
      for (int i = 0; i < m; ++i) polyWork0[i] -= i * fs[i];
      memset(polyWork0 + m, 0, m * sizeof(Mint));
      fft(polyWork0, m << 1);  // 1 E(n)
      memcpy(polyWork3, polyWork2, m * sizeof(Mint));
      memset(polyWork3 + m, 0, m * sizeof(Mint));
      fft(polyWork3, m << 1);  // 1 E(n)
      for (int i = 0; i < m << 1; ++i) polyWork0[i] *= polyWork3[i];
      invFft(polyWork0, m << 1);  // 1 E(n)
      for (int i = 0; i < m; ++i) polyWork0[i] *= ::inv[m + i];
      for (int i = 0, i0 = min(m, size() - m); i < i0; ++i) polyWork0[i] += (*this)[m + i];
      memset(polyWork0 + m, 0, m * sizeof(Mint));
      fft(polyWork0, m << 1);  // 1 E(n)
      for (int i = 0; i < m << 1; ++i) polyWork0[i] *= polyWork1[i];
      invFft(polyWork0, m << 1);  // 1 E(n)
      memcpy(fs.data() + m, polyWork0, m * sizeof(Mint));
      memcpy(polyWork1, fs.data(), (m << 1) * sizeof(Mint));
      memset(polyWork1 + (m << 1), 0, (m << 1) * sizeof(Mint));
      fft(polyWork1, m << 2);  // 2 E(n)
      for (int i = 0; i < m << 1; ++i) polyWork0[i] = polyWork1[i] * polyWork3[i];
      invFft(polyWork0, m << 1);  // 1 E(n)
      memset(polyWork0, 0, m * sizeof(Mint));
      fft(polyWork0, m << 1);  // 1 E(n)
      for (int i = 0; i < m << 1; ++i) polyWork0[i] *= polyWork3[i];
      invFft(polyWork0, m << 1);  // 1 E(n)
      for (int i = m; i < m << 1; ++i) polyWork2[i] = -polyWork0[i];
    }
    for (int i = 0, i0 = min(m, size()); i < i0; ++i) polyWork0[i] = i * (*this)[i];
    memset(polyWork0 + min(m, size()), 0, (m - min(m, size())) * sizeof(Mint));
    fft(polyWork0, m);  // (1/2) E(n)
    for (int i = 0; i < m; ++i) polyWork0[i] *= polyWork1[i];
    invFft(polyWork0, m);  // (1/2) E(n)
    for (int i = 0; i < m; ++i) polyWork0[i] -= i * fs[i];
    memcpy(polyWork0 + m, polyWork0 + (m >> 1), (m >> 1) * sizeof(Mint));
    memset(polyWork0 + (m >> 1), 0, (m >> 1) * sizeof(Mint));
    memset(polyWork0 + m + (m >> 1), 0, (m >> 1) * sizeof(Mint));
    fft(polyWork0, m);  // (1/2) E(n)
    fft(polyWork0 + m, m);  // (1/2) E(n)
    memcpy(polyWork3 + m, polyWork2 + (m >> 1), (m >> 1) * sizeof(Mint));
    memset(polyWork3 + m + (m >> 1), 0, (m >> 1) * sizeof(Mint));
    fft(polyWork3 + m, m);  // (1/2) E(n)
    for (int i = 0; i < m; ++i) polyWork0[m + i] = polyWork0[i] * polyWork3[m + i] + polyWork0[m + i] * polyWork3[i];
    for (int i = 0; i < m; ++i) polyWork0[i] *= polyWork3[i];
    invFft(polyWork0, m);  // (1/2) E(n)
    invFft(polyWork0 + m, m);  // (1/2) E(n)
    for (int i = 0; i < m >> 1; ++i) polyWork0[(m >> 1) + i] += polyWork0[m + i];
    for (int i = 0; i < m; ++i) polyWork0[i] *= ::inv[m + i];
    for (int i = 0, i0 = min(m, size() - m); i < i0; ++i) polyWork0[i] += (*this)[m + i];
    memset(polyWork0 + m, 0, m * sizeof(Mint));
    fft(polyWork0, m << 1);  // 1 E(n)
    for (int i = 0; i < m << 1; ++i) polyWork0[i] *= polyWork1[i];
    invFft(polyWork0, m << 1);  // 1 E(n)
    memcpy(fs.data() + m, polyWork0, (n - m) * sizeof(Mint));
    return fs;
  }
  Poly pow(Mint a, int n) const {
    assert(!empty()); assert((*this)[0].x == 1U); assert(1 <= n);
    return (a * log(n)).exp(n);  // 13 E(n) + (16 + 1/2) E(n)
  }
  Poly pow(long long a, int n) const {
    assert(a >= 0); assert(1 <= n);
    if (a == 0) { Poly gs(n); gs[0].x = 1U; return gs; }
    const int o = ord();
    if (o == -1 || o > (n - 1) / a) return Poly(n);
    const Mint b = (*this)[o].inv(), c = (*this)[o].pow(a);
    const int ntt = min<int>(n - a * o, size() - o);
    Poly tts(ntt);
    for (int i = 0; i < ntt; ++i) tts[i] = b * (*this)[o + i];
    tts = tts.pow(Mint(a), n - a * o);  // (29 + 1/2) E(n - a ord(t))
    Poly gs(n);
    for (int i = 0; i < n - a * o; ++i) gs[a * o + i] = c * tts[i];
    return gs;
  }
  Poly sqrt(int n) const {
    assert(!empty()); assert((*this)[0].x == 1U); assert(1 <= n);
    assert(n == 1 || 1 << (32 - __builtin_clz(n - 1)) <= LIM_POLY);
    if (n == 1) return {1U};
    if (n == 2) return {1U, at(1) / 2};
    Poly fs(n);
    fs[0].x = polyWork1[0].x = polyWork2[0].x = 1U;
    int m;
    for (m = 1; m << 1 < n; m <<= 1) {
      for (int i = 0; i < m; ++i) polyWork1[i] *= polyWork1[i];
      invFft(polyWork1, m);  // (1/2) E(n)
      for (int i = 0, i0 = min(m, size()); i < i0; ++i) polyWork1[i] -= (*this)[i];
      for (int i = 0, i0 = min(m, size() - m); i < i0; ++i) polyWork1[i] -= (*this)[m + i];
      memset(polyWork1 + m, 0, m * sizeof(Mint));
      fft(polyWork1, m << 1);  // 1 E(n)
      memcpy(polyWork3, polyWork2, m * sizeof(Mint));
      memset(polyWork3 + m, 0, m * sizeof(Mint));
      fft(polyWork3, m << 1);  // 1 E(n)
      for (int i = 0; i < m << 1; ++i) polyWork1[i] *= polyWork3[i];
      invFft(polyWork1, m << 1);  // 1 E(n)
      for (int i = 0; i < m; ++i) { polyWork1[i] = -polyWork1[i]; fs[m + i].x = ((polyWork1[i].x & 1) ? (polyWork1[i].x + MO) : polyWork1[i].x) >> 1; }
      memcpy(polyWork1, fs.data(), (m << 1) * sizeof(Mint));
      fft(polyWork1, m << 1);  // 1 E(n)
      for (int i = 0; i < m << 1; ++i) polyWork0[i] = polyWork1[i] * polyWork3[i];
      invFft(polyWork0, m << 1);  // 1 E(n)
      memset(polyWork0, 0, m * sizeof(Mint));
      fft(polyWork0, m << 1);  // 1 E(n)
      for (int i = 0; i < m << 1; ++i) polyWork0[i] *= polyWork3[i];
      invFft(polyWork0, m << 1);  // 1 E(n)
      for (int i = m; i < m << 1; ++i) polyWork2[i] = -polyWork0[i];
    }
    for (int i = 0; i < m; ++i) polyWork1[i] *= polyWork1[i];
    invFft(polyWork1, m);  // (1/2) E(n)
    for (int i = 0, i0 = min(m, size()); i < i0; ++i) polyWork1[i] -= (*this)[i];
    for (int i = 0, i0 = min(m, size() - m); i < i0; ++i) polyWork1[i] -= (*this)[m + i];
    memcpy(polyWork1 + m, polyWork1 + (m >> 1), (m >> 1) * sizeof(Mint));
    memset(polyWork1 + (m >> 1), 0, (m >> 1) * sizeof(Mint));
    memset(polyWork1 + m + (m >> 1), 0, (m >> 1) * sizeof(Mint));
    fft(polyWork1, m);  // (1/2) E(n)
    fft(polyWork1 + m, m);  // (1/2) E(n)
    memcpy(polyWork3 + m, polyWork2 + (m >> 1), (m >> 1) * sizeof(Mint));
    memset(polyWork3 + m + (m >> 1), 0, (m >> 1) * sizeof(Mint));
    fft(polyWork3 + m, m);  // (1/2) E(n)
    for (int i = 0; i < m; ++i) polyWork1[m + i] = polyWork1[i] * polyWork3[m + i] + polyWork1[m + i] * polyWork3[i];
    for (int i = 0; i < m; ++i) polyWork1[i] *= polyWork3[i];
    invFft(polyWork1, m);  // (1/2) E(n)
    invFft(polyWork1 + m, m);  // (1/2) E(n)
    for (int i = 0; i < m >> 1; ++i) polyWork1[(m >> 1) + i] += polyWork1[m + i];
    for (int i = 0; i < n - m; ++i) { polyWork1[i] = -polyWork1[i]; fs[m + i].x = ((polyWork1[i].x & 1) ? (polyWork1[i].x + MO) : polyWork1[i].x) >> 1; }
    return fs;
  }
  template <class F> Poly sqrt(int n, F modSqrt) const {
    assert(1 <= n);
    const int o = ord();
    if (o == -1) return Poly(n);
    if (o & 1) return {};
    const Mint c = modSqrt((*this)[o]);
    if (c * c != (*this)[o]) return {};
    if (o >> 1 >= n) return Poly(n);
    const Mint b = (*this)[o].inv();
    const int ntt = min(n - (o >> 1), size() - o);
    Poly tts(ntt);
    for (int i = 0; i < ntt; ++i) tts[i] = b * (*this)[o + i];
    tts = tts.sqrt(n - (o >> 1));  // (10 + 1/2) E(n)
    Poly gs(n);
    for (int i = 0; i < n - (o >> 1); ++i) gs[(o >> 1) + i] = c * tts[i];
    return gs;
  }
  Poly shift(const Mint &a) const {
    if (empty()) return {};
    const int n = size();
    int m = 1;
    for (; m < n; m <<= 1) {}
    for (int i = 0; i < n; ++i) polyWork0[i] = fac[i] * (*this)[i];
    memset(polyWork0 + n, 0, ((m << 1) - n) * sizeof(Mint));
    fft(polyWork0, m << 1);  // 2 E(|t|)
    {
      Mint aa = 1;
      for (int i = 0; i < n; ++i) { polyWork1[n - 1 - i] = invFac[i] * aa; aa *= a; }
    }
    memset(polyWork1 + n, 0, ((m << 1) - n) * sizeof(Mint));
    fft(polyWork1, m << 1);  // 2 E(|t|)
    for (int i = 0; i < m << 1; ++i) polyWork0[i] *= polyWork1[i];
    invFft(polyWork0, m << 1);  // 2 E(|t|)
    Poly fs(n);
    for (int i = 0; i < n; ++i) fs[i] = invFac[i] * polyWork0[n - 1 + i];
    return fs;
  }
};

Mint linearRecurrenceAt(const vector<Mint> &as, const vector<Mint> &cs, long long k) {
  assert(!cs.empty()); assert(cs[0]);
  const int d = cs.size() - 1;
  assert(as.size() >= static_cast<size_t>(d));
  return (Poly(vector<Mint>(as.begin(), as.begin() + d)) * cs).mod(d).divAt(cs, k);
}

struct SubproductTree {
  int logN, n, nn;
  vector<Mint> xs;
  vector<Mint> buf;
  vector<Mint *> gss;
  Poly all;
  SubproductTree(const vector<Mint> &xs_) {
    n = xs_.size();
    for (logN = 0, nn = 1; nn < n; ++logN, nn <<= 1) {}
    xs.assign(nn, 0U);
    memcpy(xs.data(), xs_.data(), n * sizeof(Mint));
    buf.assign((logN + 1) * (nn << 1), 0U);
    gss.assign(nn << 1, nullptr);
    for (int h = 0; h <= logN; ++h) for (int u = 1 << h; u < 1 << (h + 1); ++u) {
      gss[u] = buf.data() + (h * (nn << 1) + ((u - (1 << h)) << (logN - h + 1)));
    }
    for (int i = 0; i < nn; ++i) {
      gss[nn + i][0] = -xs[i] + 1;
      gss[nn + i][1] = -xs[i] - 1;
    }
    if (nn == 1) gss[1][1] += 2;
    for (int h = logN; --h >= 0; ) {
      const int m = 1 << (logN - h);
      for (int u = 1 << (h + 1); --u >= 1 << h; ) {
        for (int i = 0; i < m; ++i) gss[u][i] = gss[u << 1][i] * gss[u << 1 | 1][i];
        memcpy(gss[u] + m, gss[u], m * sizeof(Mint));
        invFft(gss[u] + m, m);  // ((1/2) ceil(log_2 n) + O(1)) E(n)
        if (h > 0) {
          gss[u][m] -= 2;
          const Mint a = FFT_ROOTS[logN - h + 1];
          Mint aa = 1;
          for (int i = m; i < m << 1; ++i) { gss[u][i] *= aa; aa *= a; };
          fft(gss[u] + m, m);  // ((1/2) ceil(log_2 n) + O(1)) E(n)
        }
      }
    }
    all.resize(nn + 1);
    all[0] = 1;
    for (int i = 1; i < nn; ++i) all[i] = gss[1][nn + nn - i];
    all[nn] = gss[1][nn] - 1;
  }
  vector<Mint> multiEval(const Poly &fs) const {
    vector<Mint> work0(nn), work1(nn), work2(nn);
    {
      const int m = max(fs.size(), 1);
      auto invAll = all.inv(m);  // 10 E(|f|)
      std::reverse(invAll.begin(), invAll.end());
      int mm;
      for (mm = 1; mm < m - 1 + nn; mm <<= 1) {}
      invAll.resize(mm, 0U);
      fft(invAll);  // E(|f| + 2^(ceil(log_2 n)))
      vector<Mint> ffs(mm, 0U);
      memcpy(ffs.data(), fs.data(), fs.size() * sizeof(Mint));
      fft(ffs);  // E(|f| + 2^(ceil(log_2 n)))
      for (int i = 0; i < mm; ++i) ffs[i] *= invAll[i];
      invFft(ffs);  // E(|f| + 2^(ceil(log_2 n)))
      memcpy(((logN & 1) ? work1 : work0).data(), ffs.data() + m - 1, nn * sizeof(Mint));
    }
    for (int h = 0; h < logN; ++h) {
      const int m = 1 << (logN - h);
      for (int u = 1 << h; u < 1 << (h + 1); ++u) {
        Mint *hs = (((logN - h) & 1) ? work1 : work0).data() + ((u - (1 << h)) << (logN - h));
        Mint *hs0 = (((logN - h) & 1) ? work0 : work1).data() + ((u - (1 << h)) << (logN - h));
        Mint *hs1 = hs0 + (m >> 1);
        fft(hs, m);  // ((1/2) ceil(log_2 n) + O(1)) E(n)
        for (int i = 0; i < m; ++i) work2[i] = gss[u << 1 | 1][i] * hs[i];
        invFft(work2.data(), m);  // ((1/2) ceil(log_2 n) + O(1)) E(n)
        memcpy(hs0, work2.data() + (m >> 1), (m >> 1) * sizeof(Mint));
        for (int i = 0; i < m; ++i) work2[i] = gss[u << 1][i] * hs[i];
        invFft(work2.data(), m);  // ((1/2) ceil(log_2 n) + O(1)) E(n)
        memcpy(hs1, work2.data() + (m >> 1), (m >> 1) * sizeof(Mint));
      }
    }
    work0.resize(n);
    return work0;
  }
  Poly interpolate(const vector<Mint> &ys) const {
    assert(static_cast<int>(ys.size()) == n);
    Poly gs(n);
    for (int i = 0; i < n; ++i) gs[i] = (i + 1) * all[n - (i + 1)];
    const vector<Mint> denoms = multiEval(gs);  // ((3/2) ceil(log_2 n) + O(1)) E(n)
    vector<Mint> work(nn << 1, 0U);
    for (int i = 0; i < n; ++i) {
      assert(denoms[i]);
      work[i << 1] = work[i << 1 | 1] = ys[i] / denoms[i];
    }
    for (int h = logN; --h >= 0; ) {
      const int m = 1 << (logN - h);
      for (int u = 1 << (h + 1); --u >= 1 << h; ) {
        Mint *hs = work.data() + ((u - (1 << h)) << (logN - h + 1));
        for (int i = 0; i < m; ++i) hs[i] = gss[u << 1 | 1][i] * hs[i] + gss[u << 1][i] * hs[m + i];
        if (h > 0) {
          memcpy(hs + m, hs, m * sizeof(Mint));
          invFft(hs + m, m);  // ((1/2) ceil(log_2 n) + O(1)) E(n)
          const Mint a = FFT_ROOTS[logN - h + 1];
          Mint aa = 1;
          for (int i = m; i < m << 1; ++i) { hs[i] *= aa; aa *= a; };
          fft(hs + m, m);  // ((1/2) ceil(log_2 n) + O(1)) E(n)
        }
      }
    }
    invFft(work.data(), nn);  // E(n)
    return Poly(vector<Mint>(work.data() + nn - n, work.data() + nn));
  }
};


using namespace lastweapon;

Poly H, HH;
int n;

LL C2(LL n) {
    return n*(n-1)/2;
}

int b(int n) {
    --n; if (!n) return 1;
    Poly A(n); REP(i, n) A[i] = H[i] * -n;
    Poly B = HH.mod(n) * A.exp(n); --n;
    return (B[n] * fac[n]).x;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    vector<int> q; DO(5) q.PB(RD()); n = *max_element(ALL(q)) + 1;
    Poly C(n), G(n); REP(i, n) G[i] = Mint(2).pow(C2(i)), G[i] *= invFac[i]; C = G.log(n);
    H = C.D().log(n); HH = H.D();

    for (auto i: q) printf("%d\n", b(i));
}

