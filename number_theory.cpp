#include<bits/stdc++.h>
#define pb push_back
#define nl "\n"
#define pob pop_back
#define fire(n) for (ll i = 0; i < n; i++)
#define ou(n) cout << n << nl
#define ll long long
#define nd &&
#define orr ||
#define N 1000000
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mod 1000000007
using namespace std;
//write a function that will return the multiplication of all the powers of prime factors of a number
// ll primefactorpower(ll n)
// {
//     ll ans = 1;
//     for (ll i = 2; i * i <= n; i++)
//     {
//         if (n % i == 0)//checking if i is a prime factor of n if i=4 then 4 is not a prime factor of n so we will not include it in our ans so we will check if i is a prime factor of n or not by checking n%i==0 or not if it is true then i is a prime factor of n and we will include it in our ans and calculate its power 
//         {
//             ll count = 0;
//             while (n % i == 0)//counting the power of prime factor
//             {
//                 n /= i;
//                 count++;
//             }
//             ans *=(count+1);//multiplying the power of prime factor with ans and adding 1 to it because we have to multiply all the powers of prime factors so we will add 1 to it to include the power 0 also
//         }
//     }
//     if (n > 1)//if n is prime then it will be left in the last so we will multiply it with ans
//     {
//         ans *= n;
//     }
//     ans++;//adding 1 to the ans because we have to multiply all the powers of prime factors so we will add 1 to it to include the power 0 also
//     ll df=ans/2;//dividing the ans by 2 because we have to return the multiplication of all the powers of prime factors so we will divide it by 2 to get the multiplication of all the powers of prime factors of a number because we have added 1 to all the powers of prime factors so we will divide it by 2 to get the multiplication of all the powers of prime factors of a number
//     return ans;
// }
// void solve()
// {

// string s;

// while(cin>>s){
//     string p="";
//     ll i=2;
//     while(i<s.size())
//     {
//         p+=s[i];
//         i++;
//     }
//     //now convert p to integer
//     ll n=stoi(p);
//     ll h=n*n;
//     ll pr=primefactorpower(h);
//     cout<<pr<<nl;
// }
// }

// map<ll,ll> primefactorpower;

// void allprimefactorsandpowers(ll n)
// {
//     while(n%2==0)
//     {
//         primefactorpower[2]++;
//         n/=2;
//     }
//     for(ll i=3;i*i<=n;i+=2)
//     {
//         while(n%i==0)
//         {
//             primefactorpower[i]++;
//             n/=i;
//         }
//     }
//     if(n>2)
//     {
//         primefactorpower[n]++;
//     }

// }

// void solve()
// {
//     ll n;
//     while(cin>>n)
//     {
//         ll b=n;
//         // Calculate prime factors and their powers
//         allprimefactorsandpowers(n);
//         ll ans=1;
//         // Print prime factors and their powers
//         for(auto it = primefactorpower.begin(); it != primefactorpower.end(); it++)
//         {
//             ans*=pow(it->second,it->first);
//         }
//         cout<<b<<" "<<ans<< endl;

//         // Clear the map for the next input
//         primefactorpower.clear();
//     }
// }
//make a function to find twin primes example input 1 output 3 5 input 2 output 5 7 input 3 output 11 13 and so on
 bool isprime(ll n)
{
    if(n==1)
    {
        return false;
    }
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}
void solve()
{
    ll n;
    while(cin>>n){
    ll count=0;
    ll i=2;
    while(count<n)
    {
        if(isprime(i) and isprime(i+2))
        {
            count++;
            if(count==n)
            {
                cout<<"("<<i<<","<<" "<<i+2<<")"<<nl;
            }
        }
        i++;
    }
    }
}
int main() {
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    // fastIO;

    solve();
    return 0;
}
