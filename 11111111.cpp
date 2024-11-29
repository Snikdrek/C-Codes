#include <bits/stdc++.h>
#define pb push_back
#define nl "\n"
#define pob pop_back
#define fire(n) for (ll i = 0; i < n; i++)
#define ou(n) cout << n << nl
#define ll long long
#define nd &&
#define orr ||
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

const int N = 1e3 + 5;
vector<int> g[N];
bool vis[N];

void bfs(int vertex) {
    queue<int> q;
    q.push(vertex);
    vis[vertex] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (auto child : g[node]) {
            if (!vis[child]) {
                q.push(child);
                vis[child] = true;
            }
        }
    }
}

int connectedComponents(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            bfs(i);
            count++;
        }
    }
    return count;
}

void dfs(int vertex) {
    vis[vertex] = true;
    cout << vertex << " " ;
    for (auto child : g[vertex]) {
        if (!vis[child]) {
            dfs(child);
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fastIO

    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    cout << "BFS starting from node 1: ";
    bfs(1);
    cout << nl;

    fill(vis, vis + N, false); // Reset the visited array before DFS

    cout << "DFS starting from node 1: ";
    dfs(1);
    cout << nl;

    fill(vis, vis + N, false); // Reset the visited array before counting connected components

    int cc = connectedComponents(n);
    cout << "Number of connected components: " << cc << nl;

    return 0;
}
