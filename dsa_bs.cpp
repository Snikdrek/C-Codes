#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int main()
{
    int a[7]={1,2,3,4,5,6,7};
    int key=6;
    int n=7;
    int l=0;
    int r=n-1;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(a[mid]==key)
        {
            cout<<"Element found at index "<<mid;
            return 0;
        }
        else if(a[mid]<key)
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }

}