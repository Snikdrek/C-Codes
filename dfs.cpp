// #include<bits/stdc++.h>
// #define pb push_back
// #define nl "\n"
// #define pob pop_back
// using namespace std;
// vector<int>graph[200005];
// bool visited[200005];
// void dfs(int vertex)
// {
    
//     visited[vertex]=true;
    
//     for(int child : graph[vertex])
//     {
//         if(visited[child])
//         {
//             continue;
//         }
//         dfs(child);
//     }
// }
// int main()
// {
//     int v,e;
//     cin>>v>>e;
//     for(int i=0;i<e;i++)
//     {
//         int a,b;
//         cin>>a>>b;
//         graph[a].pb(b);
//         graph[b].pb(a);
//     }
//     int ct=0;
//     for(int i=1;i<=v;i++)
//     {
//         if(visited[i])continue;
//         dfs(i);
//         ct++;
//     }
//     cout<<ct<<nl;
// // }
// #include <bits/stdc++.h>
// #define pb push_back
// #define nl "\n"
// #define pob pop_back
// using namespace std;
// vector<int>graph[200005];
// bool visited[200005];
// bool dfs(int vertex,int parent)
// {
//     visited[vertex]=true;
//    bool iscycle=false;
//    for(int child :graph[vertex])
//    {
//        if(visited[child] and child==parent)
//        {
//            continue;
//        }
//        if(visited[child] and child!=parent)
//        {
//            return true;
//        }
//        if(!visited[child])
//        {
//            iscycle|= dfs(child,vertex);
//        }
//    }
//    return iscycle;
// }
// int main()
// {
//     int v,e;
//     cin>>v>>e;
//     for(int i=0;i<e;i++)
//     {
//         int a,b;
//         cin>>a>>b;
//         graph[a].pb(b);
//         graph[b].pb(a);
//     }
//     int ct=0;
//     bool cycle=false;
//     for(int i=1;i<=v;i++)
//     {
//         if(visited[i])continue;
//         if(dfs(i,-1))
//         {
//             cout<<"YES"<<nl;
//             return 0;
//         }
//     }
//     cout<<"NO"<<nl;
// }
//matrix dfs
#include<bits/stdc++.h>
using namespace std;
// void dfs(int i,int j,int initialcol,int newcol,vector<vector<int>>& image)
// {
//     if(i<0 or j<0 or i>=image.size() or j>=image[0].size() or image[i][j]!=initialcol)
//     {
//         return;
//     }
//     image[i][j]=newcol;//changing the color of the pixel
//     dfs(i+1,j,initialcol,newcol,image);
//     dfs(i-1,j,initialcol,newcol,image);
//     dfs(i,j+1,initialcol,newcol,image);
//     dfs(i,j-1,initialcol,newcol,image);

// }
// vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
// int initialcol=image[sr][sc];
// if(initialcol==color)
// {
//     dfs(sr,sc,initialcol,color,image);
// }
// return image;
// }
// void dfs(int i,int j,vector<vector<char>>& grid)
// {
//     if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]!='1')
//     {
//         return;
//     }
//     grid[i][j]='0';
//     dfs(i+1,j,grid);
//     dfs(i-1,j,grid);
//     dfs(i,j+1,grid);
//     dfs(i,j-1,grid);
// }
// int numIslands(vector<vector<char>>& grid) {
//     int count=0;
//     for(int i=0;i<grid.size();i++)
//     {
//         for(int j=0;j<grid[0].size();j++)
//         {
//             if(grid[i][j]=='1')
//             {
//                 dfs(i,j,grid);
//                 count++;
//             }
//         }
        
//     }
//     return count;
// }
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
        # define N 100005
        bool visited[N];
        vector<int> graph[N];
        void dfs(int vertex)
        {
            visited[vertex]=true;
            cout<<vertex<<" ";
            for(int child : graph[vertex])
            {
                cout<<"PAR"<<" "<<vertex<<"child"<<" "<<child<<nl;
                if(visited[child])
                {
                    continue;
                }
                dfs(child);
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
                graph[a].pb(b);
                graph[b].pb(a);
            }
            for(int i=1;i<=v;i++)
            {
                if(visited[i])continue;
                dfs(i);
            }
        }