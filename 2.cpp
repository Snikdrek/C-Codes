#include<bits/stdc++.h>
#define pb push_back
#define nl "\n"
#define pob pop_back
#define fire(n) for (ll i = 0; i < n; i++)
#define ou(n) cout << n << nl
#define ll long long
#define nd &&
#define orr ||
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mod 1000000007
int dp[mod];
using namespace std;
vector<ll> v;
void vectorok(){
for(ll i=0;i<1e9;i++)
{
    v[i]=i+1;
}
}

//knapsack 
//fractional knapsack
//greedy
//lambda
int main() {
     #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fastIO
    ll t;
    cin>>t;
    while(t--)
    {
    solve();
}
}

