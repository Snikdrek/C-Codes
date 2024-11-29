#include <bits/stdc++.h>
#define ll long long
#define nl "\n"
using namespace std;
void solve()
{

    vector<ll>v(10);
    for(ll i=0;i<10;i++)
    {
        cin>>v[i];
    }
    ll target;
    cin>>target;
  ll l=0;
  ll r=9;
 auto lb = lower_bound(v.begin(), v.end(), target);
    auto ub = upper_bound(v.begin(), v.end(), target);
    if (lb == v.end() || *lb != target) {
        cout << "Target not found" << nl;
    } else {
        int first = lb - v.begin();
        int last = ub - v.begin() - 1;

        cout << "First occurrence at index " << first << nl;
        cout << "Last occurrence at index " << last << nl;
    }
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
        solve();
    
    return 0;
}
