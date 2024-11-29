#include<bits/stdc++.h>
#define N 100005
#define ll long long
#define pb push_back
#define INF 1e9+10
using namespace std;

vector<pair<int, int>> graph[N]; // Adjacency list representation of the graph

void dijkstra(int start) {
    vector<int>dist(N, INF); // Initializing distance of all nodes to infinity
    vector<int>vis(N, 0); // Initializing visited array to 0
    set<pair<int, int>>s; // Set to store the nodes and their distances
    //weight,node in set
    s.insert({0, start}); // Inserting the starting node with distance 0
   dist[start]=0;   // Distance of starting node is 0
  while(s.size()>0)
  {
    auto node=*(s.begin());//taking the node with minimum distance
    int v=node.second;//node
    int distan=node.first;//distance
    s.erase(s.begin());//removing the node from the set
    if(vis[v]==1)
    {
      continue;
    }   
    vis[v]=1;
    for(auto child:graph[v])
    {
      int u_ch=child.first;
      int w=child.second;
      if(distan+w<dist[u_ch])
      {
        
        dist[u_ch]=distan+w;
        s.insert({dist[u_ch],u_ch});
      }
    }
  }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m; // Number of nodes and edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w; // Input the edges
        graph[u].push_back({v, w});
       
    }
    dijkstra(1); // Starting Dijkstra's algorithm from node 1
}