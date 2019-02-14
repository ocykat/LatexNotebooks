#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int v, w;

    Edge(int v_, int w_) {
        v = v_, w = w_;
    }
};

struct Vertex {
    int label;
    int d;

    Vertex(int label_, int d_) {
        label = label_;
        d  = d_;
    }

    bool operator < (const Vertex& other) const {
        return d > other.d;   // minheap
    }
};

const int MAXV = (int) 1e3;
const int MAXE = (int) 1e3;
const int INF  = (int) 1e9;  // Infinite distance: should be > max_w * max_nE
int dist[MAXV];
bool visited[MAXV];
vector<Edge> adj[MAXV];
priority_queue<Vertex, vector<Vertex>> pq;
int nV, nE;

void relax(int u, Edge e) {
    if (dist[e.v] > dist[u] + e.w) {
        dist[e.v] = dist[u] + e.w;
        pq.emplace(e.v, dist[e.v]);
    }
}

void dijkstra(int src) {
    fill(dist, dist + nV, INF);
    fill(visited, visited + nV, false);

    dist[src] = 0;
    pq.emplace(src, 0);

    while (!pq.empty()) {
        int u = pq.top().label;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (Edge& e : adj[u]) {
            if (visited[e.v]) continue;
            relax(u, e);
        }
    }
}

int main() {
    cin >> nV >> nE;

    for (int i = 0; i < nE; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }

    dijkstra(0);

    for (int i = 0; i < nV; i++) {
        printf("Dist[%d] = %d\n", i, dist[i]);
    }

    return(0);
}
