#ifndef LASTWEAPON_SAM_HPP
#define LASTWEAPON_SAM_HPP 1

#include "lastweapon/io"

namespace lastweapon {

template <size_t N, size_t Z> struct sam {     
    int trans[N][Z], par[N], len[N], pos[N], tot, tail;
    
#define v trans[u][c]
#define p par[u]
#define pp par[uu]

    sam() {
        init();
    }

    void init() {
        tot = 0; tail = new_node();
    }
 
    inline int new_node(){
        RST(trans[tot]);
        return tot++;
    }
 
    inline int new_node(int u){
        CPY(trans[tot], trans[u]); par[tot] = par[u]; pos[tot] = pos[u];
        return tot++;
    }
 
    inline int h(int u){
        return len[u] - len[p];
    }
 
    int Ext(int c){
        int u = tail, uu = new_node(); len[uu] = len[u] + 1;
        while (u && !v) v = uu, u = p;
        if (!u && !v) v = uu, pp = 0;
        else{
            if (len[v] == len[u] + 1) pp = v;
            else{
                int _v = v, vv = new_node(_v); len[vv] = len[u] + 1; par[_v] = pp = vv;
                while (u && v == _v) v = vv, u = p;
                if (!u && v == _v) v = vv;
            }
        }
        return tail = uu;
    }

#undef c
#undef p
#undef pp
#undef v

};
}  // namespace lastweapon

#endif  // LASTWEAPON_ACM_HPP
