#ifndef LASTWEAPON_MINCOSTFLOW_HPP
#define LASTWEAPON_MINCOSTFLOW_HPP

#include <algorithm>
#include <cassert>
#include <limits>
#include <queue>
#include <vector>
#include <bitset>

#include "lastweapon/internal_csr"
#include "lastweapon/internal_queue"

namespace lastweapon {

template <class Cap, class Cost, size_t N, size_t M, size_t NN> struct mcf_graph {
    public:
    int D[N], hd[N], suc[M], to[M], cap[M], cst[M];
    int n, m, s, t; LL flow, cost;

    mcf_graph() {
        fill(hd, hd + N, 0);
        m = 2;
    }

    int new_node(){
        hd[n] = 0;
        return n++;
    }

    inline void add_edge(int x, int y, int c, int w = 0){
        suc[m] = hd[x], to[m] = y, cap[m] = c, cst[m] =  w, hd[x] = m++;
        suc[m] = hd[y], to[m] = x, cap[m] = 0, cst[m] = -w, hd[y] = m++;
    }

    inline void add_edgee(int x, int y, int c, int w = 0){
        add_edge(x, y, c, w);
        add_edge(y, x, c, w);
    }

    int Q[NN+1], pre[N], cz, op; bool inQ[N];

#define v to[i]
#define c cap[i]
#define f cap[i^1]
#define w cst[i]

    bool find_path(){
        fill(inQ, inQ+n, 0), fill(D, D+n, INF);
        cz = 0, op = 1; D[Q[cz] = s] = 0; while (cz != op){
            int u = Q[cz++]; inQ[u] = 0; cz &= NN;
            REP_G(i, u) if (c && checkMin(D[v], D[u]+w)){
                pre[v] = i; if (!inQ[v]) Q[op++] = v, inQ[v] = 1, op &= NN;
            }
        }

        return D[t] != INF;
    }

#undef v

    void add_path(){
        int d = INF; int u, v = t; do{
            int i = pre[v]; checkMin(d, c);
            u = to[i^1], v = u;
        } while (u != s);

        flow += d; u, v = t; do{
            int i = pre[v]; f += d, c -= d; cost += d*w;
            u = to[i^1], v = u;
        } while (u != s);
    }

    pair<LL, LL> Run(){
        cost = 0, flow = 0; while (find_path()) add_path();
        return MP(cost, flow);
    }


#undef c
#undef f
#undef w

    void Init(){

        int K, L; RD(n, K, L);
        int a = n+n, b = a+1; s = b+1, t = s+1; int tt = t+1;
        fill(hd, hd+tt+1, 0); m = 2;

        REP(i, n) add_edge(s, i, 1, -RD());
        REP(i, n) add_edge(n+i, t, 1, -RD());

        REP(i, n) {
            add_edge(i, a, INF, 0);
            add_edge(b, n+i, INF, 0);
            add_edge(i, n+i, 1, 0);
        }

        add_edge(a, b, K-L, 0);
        add_edge(t, tt, K, 0); t = tt; n = tt+1;
    }
};

}  // namespace lastweapon

#endif  // LASTWEAPON_MINCOSTFLOW_HPP
