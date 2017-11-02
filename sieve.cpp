#include<iostream>
#include<cstdio>
using namespace std;

bool isPrime[N];
void sieve()
{
    fill_n(isPrime,N,true);
    isPrime[0]=isPrime[1]=false;
    for(llu i=2;i*i<=N;i++)
    {
        if(isPrime[i]==true)
        {
            for(int j=2*i;j<=N;j+=i)
            {
                isPrime[j]=false;
            }
        }
    }
}
