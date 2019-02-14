/**
 * @author Nhat M. Nguyen
 * @update 09-09-18
**/

#include <bits/stdc++.h>

using namespace std;

const int MAXV = (int) 1e3;
const int MAXE = (int) 1e3;

vector<int> adj[MAXV];
int mark[MAXV];
bool is_dag;
stack<int> st;

void dfs(int u) {
    if (mark[u] == 2) return;
    if (mark[u] == 1) { // back edge
        is_dag = false;
        return;
    }
    mark[u] = 1;
    for (int &v : adj[u]) {
        dfs(v);
    }
    mark[u] = 2;
    st.push(u);
}

int main() {
    int nV, nE;
    cin >> nV >> nE;

    for (int i = 0; i < nE; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    fill(mark, mark + nV, 0);
    
    is_dag = true;
    for (int u = 0; u < nV && is_dag; u++) {
        dfs(u);
    }

    if (is_dag) {
        cout << "Topological order: \n";
        for (int i = 0; i < nV; i++) {
            cout << st.top() << '\n';
            st.pop();
        }
    }
    else {
        cout << "Not a DAG\n";
    }

    return 0;
}
