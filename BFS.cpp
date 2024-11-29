#include <bits/stdc++.h>
using namespace std;

#define N 100005

vector<int> graph[N];
int level[N];
bool visited[N];

void bfs(int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;
    level[node] = 0;

    while (!q.empty()) {
        int u = q.front();
        cout << u << " ";
        q.pop();
        for (auto child : graph[u]) {
            if (!visited[child]) {
                q.push(child);
                visited[child] = true;
                level[child] = level[u] + 1;
            }
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m; // number of nodes and edges
    cin >> n >> m;

    for (int i = 0; i < m; i++) { // input the edges
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bfs(1);
    cout << endl;

    for (int i = 1; i <= n; i++) {
        if (visited[i]) {
            cout << "Level of node " << i << " is " << level[i] << endl;
        } else {
            cout << "Node " << i << " is not reachable from the start node." << endl;
        }
    }

    return 0;
}
