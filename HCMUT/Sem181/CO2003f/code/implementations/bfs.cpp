#include <bits/stdc++.h>

using namespace std;

const int MAXV = (int) 1e3;
vector<int> adj[MAXV];
bool visited[MAXV];

void bfs(int source) {
    fill(visited, visited + nv, false);
    queue<int> q;
    q.push(source);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        visited[u] = true;
        for (int &v : adj[u]) {
            if (!visited[v]) {
                q.push(v);
            }
        }
    }
}

int main() {
    int nv, ne;
    cin >> nv >> ne;
    for (int i = 0; i < ne; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(0);
    return 0;
}
