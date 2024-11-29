#include<bits/stdc++.h>
#define pb push_back
#define nl "\n"
#define pob pop_back
using namespace std;
vector<int>graph[200005];
bool visited[200005];
int color[200005];
bool dfs(int vertex)
{
    visited[vertex]=true;
    color[vertex]=1;
    for(int child : graph[vertex])
    {
        if(!visited[child])
        {
            if(color[vertex]==1)
            {
                color[child]=2;
            }
            else
            {
                color[child]=1;
            }
            if(!dfs(child))
            {
                return false;
            }
        }
        else
        {
            if(color[child]==color[vertex])
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    while(true)
    {
    int n,e;
    cin>>n;
    if(n==0)
    {
        break;
    }
    cin>>e;
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    bool isbicolorable=true;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            if(!dfs(i))
            {
                isbicolorable=false;
                break;
            }
        }
    }
    if(isbicolorable)
    {
        cout<<"BICOLORABLE."<<nl;
    }
    else
    {
        cout<<"NOT BICOLORABLE."<<nl;
    }
}
}