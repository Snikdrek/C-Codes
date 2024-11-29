#include <bits/stdc++.h>
#define ll long long
#define nl "\n"
using namespace std;


ll BigMod(ll b, ll p, ll m) {
    ll res;
    if (p == 0) return 1;
    else if (p & 1) {
        res = ((b % m) * (BigMod(b, p - 1, m) % m)) % m;

    }
    else {
        res = BigMod(b, p / 2, m);
        res = ((res % m) * (res % m)) % m;

    }
    return res;

}

void solve() {

    ll b, p, m;
    cin >> b >> p >> m;
    ll ans = BigMod(b, p, m);
    cout << ans << nl;

}
int main() {
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t ;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
