#include <bits/stdc++.h>
using namespace std;

#include <algorithm>

long long countReachableCells(long long N, long long M, long long X0, long long Y0, long long L) {
    // Calculate the range of cells reachable horizontally and vertically
    long long x_range = std::min(X0 + L, N) - std::max(X0 - L, 1) + 1;//fix this
    
    long long y_range = std::min(Y0 + L, M) - std::max(Y0 - L, 1) + 1;

    // Return the count of cells in the reachable rectangular area
    return x_range * y_range;
}

int main() {
   
   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        long long N, M, X0, Y0, L;
        cin >> N >> M >> X0 >> Y0 >> L;

        if (L == 1) {
            cout << N * M << endl;
        } else {
            long long result = countReachableCells(N, M, X0, Y0, L);
            cout << result << endl;
        }
    }
    return 0;
}

