#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int main()
{
    int a[7]={2,3,1,4,5,6,7};
    int n=7;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
            }
        }
    }
    cout<<"Sorted array is: ";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}