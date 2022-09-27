#include <lastweapon/io>
using namespace lastweapon;


// <<= 'Random Event .. . //{
namespace RNG{
//srand((unsigned)time(NULL));
#ifdef _TESTLIB_H_
inline ULL random(LL l, LL r){return rnd.next(l, r);}
int dice(){return random(0, 5);}
bool coin(){return random(0, 1);}
#else
inline unsigned int rand16(){return ((rand()) << 15) ^ rand();}
inline unsigned int rand32(){return (rand16() << 16) | rand16();}
int dice(){return rand() % 6;}
bool coin(){return bool(rand() % 2);}
#endif
} using namespace RNG;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "w", stdout);
#endif
    int T = 3; cout << T << endl;
    DO(T) {
        int n = 10000;
        cout << n << " " << 10 << " "<< 1000000ll << endl;
        cout << 0 << " "<< 0 << endl;
        DO(n-2) cout << uint(rand() ) << " " << uint(rand()) << endl;
        cout << 1000000 << " "<< 1000000 << endl;
    }
}
