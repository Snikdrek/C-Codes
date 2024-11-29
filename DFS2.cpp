#include<bits/stdc++.h>
using namespace std;
#define N 100005
vector<int> graph[N];
bool visited[N];
void dfs(int node) {
    visited[node] = true;
    cout << node << " ";
    cout<<endl;
    for (int child : graph[node]) {
        cout<<"parent "<<node<<" child "<<child<<endl;  
        if (!visited[child]) {
            
            dfs(child);
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n,e;
    cin >> n>>e; // number of nodes
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1);
    return 0;
}