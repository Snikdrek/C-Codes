#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define vl vector<ll>
#define pii pair<int, int>
#define mii map<int, int>
#define pqi priority_queue<int>
#define fire(n) for (ll i = 0; i < n; ++i)
#define c(x) cout << x << endl;
const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1;
// auto itl = lower_bound(a.begin(),a.end(),k);
// auto itu = upper_bound(a.begin(),a.end(),k);
// ll freq=itu-itl;
// cout<<boolalpha<<binary_search(a.begin(),a.end(),k)<<endl;
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);



bool isComposite(int num) { 
   
    if (num <= 3) return false; 
    if (num % 2 == 0 || num % 3 == 0) return true; 
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return true; 
    } 
    return false;
}

// Solve function for each test case

ll bnocc(vector<ll>&v,ll n,ll t)
{
   ll l=0;
    ll r=n-1;
    ll fpos=-1;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(v[mid]<=t)
        {
            if(v[mid]==t)
            {
                fpos=mid;
            }
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    l=0;
    r=n-1;
    ll lpos=-1;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(v[mid]>=t)
        {
            if(v[mid]==t)
            {
                lpos=mid;
            }
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return fpos-lpos+1;
}
ll fib(ll n)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }
    return fib(n-1)+fib(n-2);
}
void bnsolve()
{
    ll n,t;
    cin>>n>>t;
    vector<ll>v(n);
    for(ll i=0;i<n;i++)
    {
        cin>>v[i];
    }
 //bubble sort
    for(ll i=0;i<n-1;i++)
    {
        for(ll j=0;j<n-i-1;j++)
        {
            if(v[j]>v[j+1])
            {
                swap(v[j],v[j+1]);
            }
        }
    }
    for(ll i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<nl;
    for(ll i=0;i<=n;i++)
    {
        cout<<fib(i)<<" ";
    }
    cout<<nl;
    ll l=0;
    ll r=n-1;
 ll ans=bnocc(v,n,t);
    cout<<ans<<nl;    
}
void fsolv()
{
   string s;
    cin>>s;
    ll fc=stoi(string(1, s[0]));
    ll sc=stoi(string(1, s[2]));
    if(fc==sc)
    {
        cout<<s<<nl;
    }
    else if(fc<sc)
    {
        if(s[1]=='<')
        {
            cout<<s<<nl;
        }
        else
        {
            cout<<sc+sc-fc+1<<s[1]<<sc<<nl;
        }
    }
    else if(fc>sc)
    {
        if(s[1]=='>')
        {
            cout<<s<<nl;
        }
        else
        {
            cout<<fc-sc+1<<s[1]<<fc<<nl;
        }
    }
    
}
bool issafe(vector<vector<ll>>&v,ll x,ll y,ll n)
{
   for(ll i=0;i<x;i++)//perpendicular check
   {
    if(v[i][y]==1)
    {
        return false;
    }

   }
   //left diagonal
   ll row=x;
   ll col=y;
   while(row>=0 and col>=0)
   {
    if(v[row][col]==1)
    {
        return false;
    }
    row--;
    col--;
   }
    //right diagonal
    row=x;
    col=y;
    while(row>=0 and col<n)
    {
        if(v[row][col]==1)
        {
            return false;
        }
        row--;
        col++;
    }
    return true;
    
}

bool nqeen(vector<vector<ll>>&v,ll x,ll n)
{
    if(x>=n)
    {
        return true;
    }
    for(ll col=0;col<n;col++)
    {
        if(issafe(v,x,col,n))
        {
            v[x][col]=1;
            if(nqeen(v,x+1,n))
            {
                return true;
            }
            v[x][col]=0;
        }

    }
    return false;

}
void nqsolv()
{
    ll n;
    cin>>n;
    vector<vector<ll>>v(n,vector<ll>(n));

    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            cin>>v[i][j];
        }
    }

}

void solve() {
  string s;
  cin>>s;
  ll fn=stoi(string(1,s[0]));
    ll sn=stoi(string(1,s[2]));
    if(s[1]=='<')
    {
        if(fn<sn)
        {
            cout<<s<<nl;
        }
        else if(fn>sn)
        {
           cout<<fn<<">"<<sn<<nl;
        }
        else
        {
            cout<<fn<<"="<<fn<<nl;
        }
        
    }
    else if(s[1]=='>')
    {
        if(fn>sn)
        {
            cout<<s<<nl;
        }
        else if(fn<sn)
        {
              cout<<fn<<"<"<<sn<<nl;
        }
        else
        {
            cout<<fn<<"="<<fn<<nl;
        }
    }
    else if(s[1]=='=')
    {
        if(fn==sn)
        {
            cout<<s<<nl;
        }
        else if(fn<sn)
        {
           cout<<fn<<"<"<<sn<<nl;
        }
        else if(fn>sn)
        {
            cout<<fn<<">"<<sn<<nl;
        }
    }
   
}
void bfs(vector<ll>v[],ll n,ll s)
{
    queue<ll>q;
    q.push(s);
    ll vis[n+1]={0};
    vis[s]=1;
    while(!q.empty())
    {
        ll p=q.front();
        q.pop();
        cout<<p<<" ";
        for(ll i=0;i<v[p].size();i++)
        {
            if(!vis[v[p][i]])
            {
                q.push(v[p][i]);
                vis[v[p][i]]=1;
            }
        }
    }
}
void solve2r()
{
    
  vector<ll>v[1005];
  ll vis[1005];
  ll n,m;
    cin>>n>>m;
    for(ll i=0;i<m;i++)
    {
        ll x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    bfs(v,n,1);
    
}
// void qsolv()
// {
//    ll x[4]={0,0,-1,1};
//     ll y[4]={-1,1,0,0};
//     for(ll i=0;i<4;i++)
//     {
//         if(isok(child.first+x[i],child.second+y[i]))
//         {
//             q.push({child.first+x[i],child.second+y[i]});
//             vis[child.first+x[i]][child.second+y[i]]=1;
//         }
        
//     }

// }

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio;
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
     }
    return 0;
}
