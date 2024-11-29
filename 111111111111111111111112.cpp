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
 #define cy cout<<"YES"<<endl
    #define cn cout<<"NO"<<endl
    #define mod 1000000007
using namespace std;
ll bigmod(ll b,ll p,ll m)
{
    if(p==0)
    {
        return 1;
    }
    else if(p%2!=0)
    {
        ll x=b%m;
        ll y=(bigmod(b,p-1,m))%m;
        return (x*y)%m;
    }
    else
    {
        ll x=(bigmod(b,p/2,m))%m;
        return (x*x)%m;
    }
}
//for inverse modulo
ll inversemodulo(ll a,ll b)
{
    return(a%mod*bigmod(b,mod-2,mod)%mod)%mod;
}
ll fact(ll n,ll r=1)
{
    if(n==0)
    {
        return r;
    }
    return fact(n-1,(r*n)%mod);
}
ll n;
ll ar[100];
ll sumofarray(ll i=0,ll t=0)
{
    if(i==n)
    {
        return t;
    }
    return sumofarray(i+1,t+ar[i]);
}
ll maxarrayelement(ll i=0,ll m=INT_MIN)
{
    if(i==n)
    {
        return m;
    }
    return maxarrayelement(i+1,max(m,ar[i]));
}
ll fibo(ll a=0,ll b=0,ll i=2)
{
    if(i==n)
    {
        return a+b;
    }
    return fibo(b,a+b,i+1);
}
ll powerusingtail(ll b,ll p,ll r=1)
{
    if(p==0)
    {
        return r;
    }
    return powerusingtail(b,p-1,r*b);
    

}
int main()
{
    #ifndef ONLINE_JUDGE
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fastIO
   ll a,b;
    cin>>a>>b;
    cout<<powerusingtail(a,b,1);
}