// #include <iostream>
// #include <vector>
// #include <string>

// using namespace std;

// vector<int> computeLPS(const string& pattern) {
//     int n = pattern.length();
//     vector<int> lps(n, 0);
//     int len = 0;
//     int i = 1;

//     while (i < n) {
//         if (pattern[i] == pattern[len]) {
//             len++;
//             lps[i] = len;
//             i++;
//         } else {
//             if (len != 0) {
//                 len = lps[len - 1];
//             } else {
//                 lps[i] = 0;
//                 i++;
//             }
//         }
//     }

//     return lps;
// }

// void KMP(const string& text, const string& pattern) {
//     int n = text.length();
//     int m = pattern.length();
//     vector<int> lps = computeLPS(pattern);
//     int i = 0;
//     int j = 0;

//     while (i < n) {
//         if (pattern[j] == text[i]) {
//             j++;
//             i++;
//         }

//         if (j == m) {
//             cout << "Pattern found at index " << i - j << endl;
//             j = lps[j - 1];
//         } else if (i < n && pattern[j] != text[i]) {
//             if (j != 0) {
//                 j = lps[j - 1];
//             } else {
//                 i++;
//             }
//         }
//     }
// }

// int main() {
//     string text = "ABABDABACDABABCABAB";
//     string pattern = "ABABCABAB";
//     KMP(text, pattern);
//     return 0;
//     //time complexity is O(n+m)
//     //space complexity is O(m)
    
// }
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     string a="abcabaabcabaac";
//     string b="abaa";
//     int n=a.length();
//     int m=b.length();
//     int i=0;
//     int j=0;
//     //find all the occurences of pattern in the text
//    for(i=0;i<n;i++)
//     {
//         for(j=0;j<m;j++)
//         {
//             if(a[i+j]!=b[j])
//             {
//                 break;
//             }
//             if(j==m-1)
//             {
//                 cout<<"Pattern found at index "<<i<<endl;
//             }
            
//         }
//           }

    
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
vector<int>prefix_function(string s)
{
    int n=s.length();
    vector<int>pi(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(s.substr(0,j)==s.substr(i-j+1,j))
            {
                pi[i]=j;
            }
        }
    }
    return pi;
}
int main()
{
    string s="aabcaabd";
    vector<int>pi=prefix_function(s);
    for(int i=0;i<pi.size();i++)
    {
        cout<<pi[i]<<" ";
    }
}
