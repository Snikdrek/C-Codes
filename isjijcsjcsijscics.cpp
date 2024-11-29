#include<bits/stdc++.h>
#define pb push_back
#define nl "\n"
#define ll long long
#define nl "\n"
#define pob pop_back
using namespace std;
int main()
{
     #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif
   ll t;
    cin>>t;
    while (t--)
    {
       ll n;
       cin>>n;
       vector<ll>arr(n);
       ll ans=0;
         for(ll i=0;i<n;i++)
         {
              cin>>arr[i];
              
         }
         sort(arr.begin(),arr.end());
         for(ll i=0;i<n;i++)
         {
         ans+=abs(arr[i]-i);
         }
         cout<<ans<<nl;
    }   
}