#include<bits/stdc++.h>
using namespace std;
vector<int>graph[200005];
vector<int>depth(200005);
vector<int>height(200005);
void dfs(int vertex,int parent=0)
{
    cout<<vertex<<" ";
    for(int child : graph[vertex])
    {
        if(child==parent)
        {
            continue;
    
    
        }
        depth[child]=depth[vertex]+1;//depth of child is depth of parent+1 example 1 is parent of 2 so depth of 2 is depth of 1+1
        dfs(child,vertex);
        height[vertex]=max(height[vertex],1+height[child]);//height of vertex is maximum height of its children+1
    }
}
int main()
{
    int v,e;
    cin>>v>>e;
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1);
    cout<<endl; 
    for(int i=1;i<=v;i++)
    {
        cout<<i<<" "<<depth[i]<<" "<<height[i]<<endl;
    }
}