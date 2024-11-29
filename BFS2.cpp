#include<bits/stdc++.h>
using namespace std;
#define N 100005
vector<int> graph[N];
int level[N];
int visited[N];
void bfs(int node)
{
    queue<int> q;
    q.push(node);
    visited[node]=1;
    cout<<node<<" ";
    while(!q.empty())
    {
        int current=q.front();
        q.pop();
        cout<<current<<" ";
        for(int child:graph[current])
        {
            if(!visited[child])
            {
                q.push(child);
                visited[child]=1;
                level[child]=level[current]+1;
            }
        }
    }
    cout<<endl;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    cout<<1<<endl;
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bfs(1);
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<"Level of node "<<i<<" is "<<level[i]<<endl;
    }
    return 0;
}
