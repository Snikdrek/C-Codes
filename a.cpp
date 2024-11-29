#include<bits/stdc++.h>
#define int long long
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
#define int long long
int n,m,q;
bool fl[8];
string s[8][4];
void solve(){
    cin>>n>>m>>q;
    cout<<8<<"\n";
    for(int i=0;i<8;i++)fl[i]=1;        //initially all the values are true
    while(q--){
        int x,y;
        string p;
        cin>>x>>y>>p;
        x--,y--;
        //square-0
        //circle-1
        x%=4,y%=4;
        for(int i=0;i<8;i++){
            if(s[i][x][y]!=(p=="square"?'0':'1')){//if the value is not equal to the value of the given cell
                fl[i]=0;
            }
        }
        cout<<accumulate(fl,fl+8,0ll)<<"\n";
    }
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    s[0][0]="0011";s[0][1]="1100";s[0][2]="0011";s[0][3]="1100";s[1][0]="0101";s[1][1]="0101";s[1][2]="1010";s[1][3]="1010";s[2][0]="0101";s[2][1]="1010";s[2][2]="1010";s[2][3]="0101";s[3][0]="0110";s[3][1]="1001";s[3][2]="0110";s[3][3]="1001";s[4][0]="1001";s[4][1]="0110";s[4][2]="1001";s[4][3]="0110";s[5][0]="1010";s[5][1]="0101";s[5][2]="0101";s[5][3]="1010";s[6][0]="1010";s[6][1]="1010";s[6][2]="0101";s[6][3]="0101";s[7][0]="1100";s[7][1]="0011";s[7][2]="1100";s[7][3]="0011";
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}