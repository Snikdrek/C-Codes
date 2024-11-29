#include<bits/stdc++.h>
#define pb push_back
#define nl "\n"
#define pob pop_back
#define fire(n) for (ll i = 0; i < n; i++)
#define ou(n) cout << n << nl
#define ll long long
#define nd &&
#define orr ||

int n,q;
int c[300005];
int e[300005],s[300005];
using namespace std;
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t,j,k,l,m;
    cin>>t;
    while(t--){
        //taking input
        cin>>n>>q;
        for(int i=1;i<=n;i++)cin>>c[i],e[i]=e[i-1]+c[i],s[i]=s[i-1]+(c[i]==1?2:1);
        while(q--){
            int l,r;
            cin>>l>>r;
            if(l==r){
                cout<<"NO\n";continue;
            }
            if(e[r]-e[l-1]<s[r]-s[l-1])cout<<"NO\n";
            else cout<<"YES\n";
        }
    }
    return 0;
}