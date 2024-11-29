#include <bits/stdc++.h>
#define pb push_back
#define nl "\n"
#define pob pop_back
#define fire(n) for (int i = 0; i < n; i++)
#define ou(n) cout << n << nl
#define ll long long
#define nd &&
#define orr ||
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


using namespace std;

vector<ll>bin_digits;
void binary()
{
    bin_digits.pb(10);
    bin_digits.pb(11);
    bin_digits.pb(100);
    bin_digits.pb(101);
    bin_digits.pb(110);
    bin_digits.pb(111);
    bin_digits.pb(1000);
    bin_digits.pb(1001);
    bin_digits.pb(1010);
    bin_digits.pb(1011);
    bin_digits.pb(1100);
    bin_digits.pb(1101);
    bin_digits.pb(1110);
    bin_digits.pb(1111);
    bin_digits.pb(10000);
    bin_digits.pb(10001);
    bin_digits.pb(10010);
    bin_digits.pb(10011);
    bin_digits.pb(10100);
    bin_digits.pb(10101);
    bin_digits.pb(10110);
    bin_digits.pb(10111);
    bin_digits.pb(11000);
    bin_digits.pb(11001);
    bin_digits.pb(11010);
    bin_digits.pb(11011);
    bin_digits.pb(11100);
    bin_digits.pb(11101);
    bin_digits.pb(11110);
    bin_digits.pb(11111);
    bin_digits.pb(100000);

}
void solve() {
    
    string s;
   getline(cin,s);

   bool flag=true;
    for (ll i = 0; i < s.size(); i++) {
        if (s[i] != '1' and s[i] != '0') {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << "YES" << endl;
        return;
    } else {
        ll no = stoll(s);
        for (ll i = 0; i < bin_digits.size(); i++) {
            if (no % bin_digits[i] == 0) {
                while (no % bin_digits[i] == 0) {
                    no = no / bin_digits[i];
                }
            }
        }
        if (no == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
int main()
{
   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif
   fastIO
    ll t;
    cin >> t;
    cin.ignore();
    binary();
    while (t--)
    {
        solve();
    }
    return 0;
}
