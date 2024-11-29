// #include<bits/stdc++.h>
// #define pb push_back
// #define nl "\n"
// #define pob pop_back
// #define fire(n) for (ll i = 0; i < n; i++)
// #define ou(n) cout << n << nl
// #define ll long long
// #define nd &&
// #define orr ||
// #define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// using namespace std;
// const ll n=1e5+10;
// ll graph[n][n];
//  vector<pair<ll,ll>>graph1[n];
//  vector<ll>graph2[n];
//  bool visited[n];
// void dfs(ll vertex)
// {
//     visited[vertex]=true;
//     // cout<<vertex<<nl;
//     for(int child : graph2[vertex])
//     {
//         // cout<<"parent"<<" "<<vertex<<"child"<<child<<nl;
//         if(visited[child])
//         {
//             continue;
//         }
     
//             dfs(child);
        
//     }
// }
// using namespace std;
// int main()
// {

// ll v,e;
// cin>>v>>e;
// for(ll i=0;i<e;i++)
// {
//     ll a,b;
//     cin>>a>>b;
  
//     graph2[a].pb(b);
//     graph2[b].pb(a);
// }

// int ct=0;
// for(int i=1;i<=v;i++)
// {
//     if(visited[i])continue;
//     dfs(i);
//     ct++;
// }
// cout<<ct<<nl;
// //matrix cannot be used for larger graphs however finding connections and weights is much efficient in matrix.


// }
// #include<bits/stdc++.h>
// #define pb push_back
// #define nl "\n"
// #define pob pop_back
// #define fire(n) for (ll i = 0; i < n; i++)
// #define ou(n) cout << n << nl
// #define ll long long
// #define nd &&
// #define orr ||
// #define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// using namespace std;
// const ll n=1e5+10;
// vector<ll>graph2[n];
// vector<vector<ll>>cc;
// vector<ll>current_cc;
// bool visited[n];

// void dfs(ll vertex) {
//     current_cc.pb(vertex);//store the current vertex in the current connected component vector  so that we can store the current connected component in the vector
//     visited[vertex]=true;
//     for(int child : graph2[vertex]) {//traverse the children of the current vertex and if the child is not visited then call the dfs function on the child
//         if(!visited[child]) {
//             dfs(child);
//         }
//     }
// }

// int main() {
//         #ifndef ONLINE_JUDGE
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
//    #endif
//     ll v,e;
//     cin>>v>>e;
//     for(ll i=0;i<e;i++) {
//         ll a,b;
//         cin>>a>>b;
//         graph2[a].pb(b);
//         graph2[b].pb(a);
//     }

//     int ct=0;
//     for(int i=1;i<=v;i++) {
//         if(!visited[i]) {
//             current_cc.clear();//clear the current connected component vector before starting a new connected component search from a new vertex i so that we can store the new connected component in the vector
//             dfs(i);
//             cc.pb(current_cc);//store the current connected component
//             ct++;
//         }
//     }
//     cout<<cc.size()<<nl;
//      for(auto c_cc : cc)
//      {
//         for(auto vertex : c_cc)
//         {
//             cout<<vertex<<" ";
//         }
//         cout<<nl;
//      }
// }
// #include<bits/stdc++.h>
// #define pb push_back
// #define nl "\n"
// #define pob pop_back
// #define fire(n) for (ll i = 0; i < n; i++)
// #define ou(n) cout << n << nl
// #define ll long long
// #define nd &&
// #define orr ||
// #define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// using namespace std;
// const ll n=1e5+10;
// vector<ll>graph2[n];
// vector<vector<ll>>cc;
// vector<ll>current_cc;
// bool visited[n];

// bool dfs(ll vertex,ll parent) {
//     current_cc.pb(vertex);//store the current vertex in the current connected component vector  so that we can store the current connected component in the vector
//     visited[vertex]=true;
//     bool loopexist=false;
//     for(int child : graph2[vertex]) {
//         if(visited[child] and child != parent) {
//             return true;
//         }
//         if(!visited[child]) {
//             loopexist |= dfs(child, vertex);
//         }
//     }
//     return loopexist;
// }

// int main() {
//     #ifndef ONLINE_JUDGE
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
//    #endif
//     ll v,e;
//     cin>>v>>e;
//     for(ll i=0;i<e;i++) {
//         ll a,b;
//         cin>>a>>b;
//         graph2[a].pb(b);
//         graph2[b].pb(a);
//     }

//     int ct=0;
//     bool isloop=false;
//     for(int i=1;i<=v;i++) {
//         if(!visited[i]) {
//             current_cc.clear();
//             //clear the current connected component vector before starting a new connected component search from a new vertex i so that we can store the new connected component in the vector
//             if(dfs(i,0))
//             {
//                 isloop=true;
//                 break;
//             }
//             cc.pb(current_cc);//store the current connected component
//             ct++;
//         }
//     }
//     cout<<isloop<<nl;

// }
