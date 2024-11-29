#include <bits/stdc++.h>
#define pb push_back
#define nl "\n"
#define pob pop_back
#define fire(n) for (int i = 0; i < n; i++)
#define ou(n) cout << n << nl
#define ll long long
#define nd &&
#define orr ||
using namespace std;
vector <ll> binary__digit;
 
void binary_(){
    binary__digit.pb(10);
    binary__digit.pb(11);
    binary__digit.pb(100);
    binary__digit.pb(101);
    binary__digit.pb(110);
    binary__digit.pb(111);
    binary__digit.pb(1000);
    binary__digit.pb(1001);
    binary__digit.pb(1010);
    binary__digit.pb(1011);
    binary__digit.pb(1100);
    binary__digit.pb(1101);
    binary__digit.pb(1110);
    binary__digit.pb(1111);
    binary__digit.pb(10000);
    binary__digit.pb(10001);
    binary__digit.pb(10010);
    binary__digit.pb(10011);
    binary__digit.pb(10100);
    binary__digit.pb(10101);
    binary__digit.pb(10110);
    binary__digit.pb(10111);
    binary__digit.pb(11000);
    binary__digit.pb(11001);
    binary__digit.pb(11010);
    binary__digit.pb(11011);
    binary__digit.pb(11100);
    binary__digit.pb(11101);
    binary__digit.pb(11110);
    binary__digit.pb(11111);
    binary__digit.pb(100000);
    
}
 
void solve(){
    
     
      string s;
      getline(cin,s);
      ll l = s.length();
      bool hobe =true;
      for(int i=0;i<l;i++){
         if(s[i]!='1' && s[i]!='0'){
            hobe = false;
            break;
         }
      }
      if(hobe){
        cout << "YES" << endl;
        return;
      }
      else{
       
        ll num = stoi(s);
        
       for(int i=0;i<binary__digit.size();i++){
          if(num%binary__digit[i]==0){
            while(num%binary__digit[i]==0){
              num/=binary__digit[i];
            }
          }
       }
       if(num==1){
        cout << "YES" << endl;
       }
       else{
        cout << "NO" << endl;
       }

      }

}


int main()
{  
   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif

    ll t;
    cin >> t;
    cin.ignore();
    binary_();
    while(t--){
        solve();
    }
    
}
