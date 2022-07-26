#ifndef LASTWEAPON_NUMBER_HPP
#define LASTWEAPON_NUMBER_HPP 1
#include "lastweapon/io"
namespace lastweapon {

// <<= '2. Number Theory .,//{
namespace NT{
//#define gcd __gcd
inline LL gcd(LL a, LL b){return b?gcd(b,a%b):a;}
inline LL lcm(LL a, LL b){return a*b/gcd(a,b);}

inline void INC(int &a, int b){a += b; if (a >= MOD) a -= MOD;}
inline int sum(int a, int b){a += b; if (a >= MOD) a -= MOD; return a;}

inline void DEC(int &a, int b){a -= b; if (a < 0) a += MOD;}
inline int dff(int a, int b){a -= b; if (a < 0) a  += MOD; return a;}
inline void MUL(int &a, int b){a = (LL)a * b % MOD;}
//inline int pdt(int a, int b){return (LL)a * b % MOD;}
inline int pdt(int x,int y) {
    int ret; __asm__ __volatile__ ("\tmull %%ebx\n\tdivl %%ecx\n":"=d"(ret):"a"(x),"b"(y),"c"(MOD));
    return ret;
}


inline int gcd(int m, int n, int &x, int &y){

    x = 1, y = 0; int xx = 0, yy = 1, q;

    while (1){
        q = m / n, m %= n;
        if (!m){x = xx, y = yy; return n;}
        DEC(x, pdt(q, xx)), DEC(y, pdt(q, yy));
        q = n / m, n %= m;
        if (!n) return m;
        DEC(xx, pdt(q, x)), DEC(yy, pdt(q, y));
    }
}

inline int sum(int a, int b, int c){return sum(a, sum(b, c));}
inline int sum(int a, int b, int c, int d){return sum(sum(a, b), sum(c, d));}
inline int pdt(int a, int b, int c){return pdt(a, pdt(b, c));}
inline int pdt(int a, int b, int c, int d){return pdt(pdt(a, b), pdt(c, d));}

inline int pow(int a, LL b){
    int c(1); while (b){
        if (b&1) MUL(c, a);
        MUL(a, a), b >>= 1;
    }
    return c;
}

template<class T> inline T pow(T a, LL b){
    T c(1); while (b){
        if (b&1) c *= a;
        a *= a, b >>= 1;
    }
    return c;
}

template<class T> inline T pow(T a, int b){
    return pow(a, (LL)b);
}

inline int _I(int b){
    int a = MOD, x1 = 0, x2 = 1, q; while (1){
        q = a / b, a %= b;
        if (!a) return x2;
        DEC(x1, pdt(q, x2));

        q = b / a, b %= a;
        if (!b) return x1;
        DEC(x2, pdt(q, x1));
    }
}

inline void DIV(int &a, int b){MUL(a, _I(b));}
inline int qtt(int a, int b){return pdt(a, _I(b));}

struct Int{
    int val;

    operator int() const{return val;}

    Int(int _val = 0):val(_val){
        val %= MOD; if (val < 0) val += MOD;
    }
    Int(LL _val):val(_val){
        _val %= MOD; if (_val < 0) _val += MOD;
        val = _val;
    }

    Int& operator +=(const int& rhs){INC(val, rhs);rTs;}
    Int operator +(const int& rhs) const{return sum(val, rhs);}
    Int& operator -=(const int& rhs){DEC(val, rhs);rTs;}
    Int operator -(const int& rhs) const{return dff(val, rhs);}
    Int& operator *=(const int& rhs){MUL(val, rhs);rTs;}
    Int operator *(const int& rhs) const{return pdt(val, rhs);}
    Int& operator /=(const int& rhs){DIV(val, rhs);rTs;}
    Int operator /(const int& rhs) const{return qtt(val, rhs);}
    Int operator-()const{return MOD-*this;}
};

} using namespace NT;//}

}  // namespace lastweapon

#endif  // LASTWEAPON_NUMBER_HPP