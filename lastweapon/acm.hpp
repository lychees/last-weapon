#ifndef LASTWEAPON_ACM_HPP
#define LASTWEAPON_ACM_HPP 1

#include "lastweapon/io"

namespace lastweapon {

template <size_t N, size_t Z, int (*ctoi)(char c)> struct acm {
    int trans[N][Z], fail[N], cnt[N]; int Q[N], cz, op, tot;

    acm() {
        init();
    }

    void init() {
        tot = 0; new_node();
    }

    inline int new_node(){
        RST(trans[tot]), fail[tot] = cnt[tot] = 0;
        return tot++;
    }

#define v trans[u][c]
#define f trans[fail[u]][c]

    void build(){
        cz = op = 0; int u = 0; REP(c, Z) if (v) Q[op++] = v;
        while (cz < op){
            u = Q[cz++]; REP(c, Z) {
                if (v) fail[Q[op++] = v] = f;
                else v = f;
            }
        }
    }

    int insert(char str[]){
        int u = 0; REP_S(cur, str) {
            int c = ctoi(*cur);
            if (!v) v = new_node();
            u = v;
        }
        return u;
    }

#define vis Q
    int run(char str[]){
        int z = 0; int t, u = 0; fill(vis, vis + tot, 0);
        REP_S(cur, str){
            int c = ctoi(*cur);
            for (t=u=v;t&&!vis[t];t=fail[t]) {
                z += cnt[t];
                vis[t] = 1;
            }
        }
        return z;
    }
#undef vis

#undef f
#undef v
};
}  // namespace lastweapon

#endif  // LASTWEAPON_ACM_HPP
