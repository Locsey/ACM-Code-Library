#include<bits/stdc++.h>

using ll = long long; 
using ull = unsigned long long; 
using db = double; 

using std :: cin; 
using std :: cout; 

const int M = 4e5 + 5; 
const int INF = 0x3f3f3f3f; 
const ll LINF = 0x3f3f3f3f3f3f3f3f; 
const int mod = 998244353; 

namespace Marionette_ {
    struct Edge {
        int to; 
        ll w; 
        Edge(int T, ll W) {to = T, w = W;}
    } ; 
    struct Node {
        int u;
        ll w; 
        Node(int U, ll W) {u = U, w = W;}
        inline bool operator < (const Node &rhs) const {
            return w > rhs.w; 
        }
    } ; 
    std :: vector < ll > dijkstra(int n, int s, const std :: vector < std :: vector < Edge > > &G) {
        std :: vector < ll > dist(n + 1, LINF); 
        std :: vector < bool > vist(n + 1, false); 
        std :: priority_queue < Node > pq; 
        dist[s] = 0, pq.push(Node(s, 0)); 
        while(!pq.empty()) {
            auto cur = pq.top(); pq.pop(); 
            int u = cur.u; if(vist[u]) continue ; vist[u] = 1; 
            for(const auto &E : G[u]) {
                int v = E.to; ll w = E.w;
                if(dist[v] > dist[u] + w) dist[v] = dist[u] + w, pq.push(Node(v, dist[v])); 
            }
        }
        return dist; 
    }
    inline void mian() {
        int n, m, s;
        cin >> n >> m >> s; 
        std :: vector < std :: vector < Edge > > G(n + 1);
        for(int i = 0; i < m; ++i) {
            int u, v, w; 
            cin >> u >> v >> w; 
            G[u].push_back(Edge(v, w)); 
        }
        auto dist = dijkstra(n, s, G); 
        for(int i = 1; i <= n; ++i) cout << dist[i] << ' '; 
    }
} ; 

int main() {
    Marionette_ :: mian();
    return 0; 
}