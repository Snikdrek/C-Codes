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
using namespace std;
//write a function that will return the multiplication of all the powers of prime factors of a number
ll primefactorpower(ll n)
{
    ll ans = 1;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ll count = 0;
            while (n % i == 0)
            {
                n /= i;
                count++;
            }
            ans *=(count+1);
        }
    }
    if (n > 1)//if n is prime then it will be left in the last so we will multiply it with ans
    {
        ans *= n;
    }
    ans++;
    ll df=ans/2;
    return df;
}
void solve()
{
    