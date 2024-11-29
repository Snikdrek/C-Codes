#include <bits/stdc++.h>
#define ll long long
#define nl "\n"
using namespace std;

bool isprime(ll n) {
    if (n < 2) {
        return false;
    }
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool sumofdigits_is_prime(ll n) {
    ll s = 0;
    while (n != 0) {
        s += n % 10;
        n /= 10;
    }
    return isprime(s);
}

ll seive(ll l, ll r) {
    vector<bool> flag(r - l + 1, true);
    if (l == 1) flag[0] = false; // 1 is not a prime number

    for (ll i = 2; i * i <= r; i++) {
        for (ll j = max(i * i, (l + i - 1) / i * i); j <= r; j += i) {
            flag[j - l] = false;
        }
    }

    ll tot = 0;
    for (ll i = l; i <= r; i++) {
        if (flag[i - l] && sumofdigits_is_prime(i)) {
            tot++;
        }
    }
    return tot;
}

int main() {
     #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll f, l;
    cin >> f >> l;
    cout << seive(f, l) << nl;
    return 0;
}
