#include <bits/stdc++.h>

using namespace std;

const int MAXV = (int) 1e3;
vector<int> adj[MAXV];
int mark[MAXV];

void dfs(int u) {
    mark[u] = 1;
    for (int &v : adj[u]) {
        if (mark[u] == 0) {
            dfs(v);
        }
    }
    mark[u] = 2;
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
    fill(visited, visited + ne, 0);
    dfs(0);
    return 0;
}
