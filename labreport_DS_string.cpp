#include <bits/stdc++.h>
#define pb push_back
#define nl "\n"
#define ll long long
using namespace std;
// void solve() {
//     map<char,int> m;
//     vector<int> v;
//     string s;
//     getline(cin, s);
//     char *p = &s[0];
//     int count = 0;

//     for (int i = 0; i < s.size(); i++) {
//         if (s[i] != ' ') {
//             m[*p]++;
//             if(m[*p]>1)
//             {
//             count += m[*p];
//         } 
//         }else {
//             p++;
//             v.pb(count);
//             count = 0;
//             m.clear();
//         }
//         p++;
//     }
//     v.pb(count); // for the last word
//     int mx = 0;
//     int maxIdx = -1;
//     for (int i = 0; i < v.size(); i++) {
//         if (v[i] > mx) {
//             mx = v[i];
//             maxIdx = i;
//         }
//     }
//     cout << "Word with maximum repeated characters: ";
//     if (maxIdx != -1) {
//         stringstream ss(s);
//         string word;
//         for (int i = 0; i <= maxIdx; i++) {
//             ss >> word;
//         }
//         cout << word << nl;
//     } else {
//         cout << "None" << nl;
//     }
// }
// void solve()
// {
//     string s;
//     cin>>s;
//     char *f=&s[0];
//     char *l=&s[s.size()-1];
//     //reverse the string
//     while(f<l)
//     {
//         char temp=*f;
//         *f=*l;
//         *l=temp;
//         f++;
//         l--;
//     }
//     cout<<s<<nl;
// }
// string insertatpositionusingpointer(string s, char c, int m) {
//     string prefix = "";
//     for (int i = 0; i < m; i++) {
//         prefix += s[i];
//     }
    
//     int n = s.length();
//     char *p = &s[0];
//     char *start = p;
//     char *end = p + n - 1;
//     while (end >= start + m) {
//         *(end + 1) = *end;
//         end--;
//     }
//     *(start + m) = c;
    
//     string suffix = "";
//     for (int i = m; i < n+1; i++) {
//         suffix += *(start + i); // Append characters from modified string
//     }
    
//     return prefix + suffix;
// }


// void solve()
// {
//    string s;
//     int pos;
//     char ch;
//     cin>>s>>ch>>pos;
//     cout<<insertatpositionusingpointer(s,ch,pos-1)<<nl;

// }
// #include <iostream>
// using namespace std;

void removeCharAtPosition(string &s, int pos) {
    if (pos < 0 || pos >= s.size()) {
        cout << "Invalid position" << endl;
        return;
    }
    
    char *p = &s[0]; // Pointer to the beginning of the string
    char *end = &s[s.size() - 1]; // Pointer to the end of the string

    // Shift characters to the left starting from position pos
    while (p + pos < end) {
        *(p + pos) = *(p + pos + 1); // Move character at pos+1 to pos
        pos++;
    }

    // Null terminate the string to truncate the last character
    *(p + pos) = '\0';
    s.resize(s.size() - 1); // Resize the string to remove the last character
}


void solve() {
    string s;
    int pos;
    cin >> s >> pos;

    removeCharAtPosition(s, pos);
    cout << s << endl; // Print the modified string
}

int main() {
    
        solve();
    return 0;
}

