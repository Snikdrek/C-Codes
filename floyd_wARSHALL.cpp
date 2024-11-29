#include<bits/stdc++.h>
#define N 510
#define ll long long
#define pb push_back
#define INF 1e9+10
using namespace std;
int dist[N][N];
int main()
{
     #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(i==j)
            {
                dist[i][j]=0;
            }
            else
            
            dist[i][j]=INF;
        }
    }
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        dist[u][v]=w;
       
    }
    for(int k=1;k<=n;k++)

    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dist[i][k]!=INF && dist[k][j]!=INF){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
            }
        }

    }
     for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dist[i][j]==INF)
                {
                    cout<<"I"<<" ";
                }
                else
                cout<<dist[i][j]<<" ";
            }
            cout<<endl;
        }
    
}