#include <iostream>
#include <cstring> // for memset
using namespace std;

const int mod = 1000000007;
const int MAX_N = 1000005; // Adjust this as needed

long long dp[MAX_N];

long long fib(int n) {
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];

    return dp[n] = (fib(n - 1) + fib(n - 2)) ;
}

int main() {
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    memset(dp, -1, sizeof(dp)); // Initialize dp array
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}
