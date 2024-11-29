#include <bits/stdc++.h>
#include <math.h>
#include <algorithm>
using namespace std;

#define SIZE_N 1000
#define SIZE_P 1000

bool flag[SIZE_N+5];
int primes[SIZE_P+5];

int seive()
{
    int i,j,total=0,val;
    for(i=2; i<=SIZE_N; i++) flag[i]=1;
    val=sqrt(SIZE_N)+1;
    for(i=2; i<val; i++)
        if(flag[i])
            for(j=i; j*i<=SIZE_N; j++)
                flag[i*j]=0;
    for(i=2; i<=SIZE_N; i++)
        if(flag[i])
            primes[total++]=i;
    return total;
}

int D[SIZE_N +5];
void NumberofDivisorGenerate(int n){
    int i,j,val,N,M,count;
    D[1]=1;
    for(i=2; i<=n; i++){
        N=M=i;
        val=sqrt(N)+1;//Optimization
        for(j=0; primes[j]<val; j++){//Optimization 
            if(M%primes[j]==0){
                count=0;
                while(M%primes[j]==0)
                {
                    M/=primes[j];
                    count++;
                }
                D[N]=(count+1)*D[M];
                break;
                
            }
        }
        if(M==N)D[N]=2; //Special Case if N equal prime
    }
}


int main()
{

    int total=seive();
    int n,i;
    scanf("%d",&n);
    NumberofDivisorGenerate(n);
    for(int i =1;i<=n;i++)
        printf("The number of divisor of %d is : %d\n",i,D[i]);
    return 0;
}
