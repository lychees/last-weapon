#ifndef LASTWEAPON_DIJKSTRA_HPP
#define LASTWEAPON_DIJKSTRA_HPP 1

#include "lastweapon/io"

namespace lastweapon {

template <class Cost> struct sp_graph {

    vector<vector<pair<int, Cost>>> adj;
    int n;

    sp_graph(int n=0) : n(n) {
        adj.resize(n);
    }

    void add_edge(int x, int y, Cost w) {
        adj[x].push_back({y, w});
    }

    Cost dijkstra(int s, int t) {

        priority_queue<pair<Cost, int>, vector<pair<Cost, int>>, greater<pair<Cost, int>> > Q;
        vector<Cost> d; d.resize(n); REP(i, n) d[i] = std::numeric_limits<Cost>::max();
        Q.push({d[s] = 0, s});

        while(!Q.empty()) {

            auto du = Q.top().fi, u = Q.top().se; Q.pop(); if (du != d[u]) continue;
            if (u == t) return du;

            for (auto e: adj[u]) {
                int v = e.fi, w = e.se;
                if (d[v] > d[u] + w) {
                    d[v] = d[u] + w;
                    Q.push({d[v], v});
                }
            }
        }
        return -1;
    }
};

}  // namespace lastweapon

#endif  // LASTWEAPON_MAXFLOW_HPP
