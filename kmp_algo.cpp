#include <bits/stdc++.h>
#define Ns 100005
#define ll long long
#define pb push_back
#define nl "\n"
using namespace std;

vector<int> computeLPSArray(string pattern) {
    int M = pattern.size();
    vector<int> lps(M);
    int length = 0;  // length of the previous longest prefix suffix
    int i = 1;
    lps[0] = 0;  // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    while (i < M) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

void KMP(string txt, string pat) {
    int N = txt.size();
    int M = pat.size();

    // create lps[] that will hold the longest prefix suffix values for pattern
    vector<int> lps = computeLPSArray(pat);

    int i = 0;  // index for txt[]
    int j = 0;  // index for pat[]
    bool found = false;

    while (i < N) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }

        if (j == M) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
            found = true;
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    if (!found) {
        cout << "Pattern not found" << endl;
    }
}

void solve() {
    string txt, pattern;
    cin >> txt >> pattern;

    // Compute LPS array and print it
    vector<int> lpsArray = computeLPSArray(pattern);
    for (auto x : lpsArray) {
        cout << x << " ";
    }
    cout << nl;

    // Perform KMP search
    KMP(txt, pattern);
}

int main() {
   
    solve();

    return 0;
}
