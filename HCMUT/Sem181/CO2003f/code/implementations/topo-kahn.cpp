#include <bits/stdc++.h>

using namespace std;

const int MAXV = (int) 1e6;
vector<int> adj[MAXV];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // Input
    int nv, ne;
    cin >> nv >> ne;

    for (int i = 0; i < ne; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // Calculate in-degree
    vector<int> indeg(nv, 0);
    
    for (int u = 0; u < nv; u++) {
        for (int &v : adj[u]) {
            indeg[v]++;
        }
    }

    // Kahn's algorithm
    vector<int> result;
    queue<int> q;
    
    for (int u = 0; u < nv; u++) {
        if (indeg[u] == 0) {
            q.push(u);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);

        for (int &v : adj[u]) {
            indeg[v]--;
            if (indeg[v] == 0) {
                q.push(v);
            }
        }
    }

    if ((int) result.size() != nv) {
        cout << "MAXVot a directed acrylic graph!\n";
    }
    else {
        cout << "Topological order:\n";
        for (int &u : result) {
            cout << u << " ";
        }
        cout << "\n";
    }

    return 0;
}
