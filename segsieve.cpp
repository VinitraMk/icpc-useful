void segsieve(llu n,llu m)
{
    llu i,j,d=floor(sqrt(m));
    for(i=2;i<=d;i++)
    {
        if(isPrime[i])
        {
            for(j=(n-(n%i));j<=m;j+=i)
            {
                if(j>=n && isPrime[j] && j!=i)
                    isPrime[j]=false;
            }
        }
    }
}    
int main()
{
    llu t,i,j,k,l,m,n;
    init();
    sieve();
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&m);
        if(m>sq2)
            segsieve(n,m);
        for(i=n;i<=m;i++)
        {
            if(isPrime[i]==true)
                printf("%lld\n",i);
        }
        printf("\n");
    }
    return 0;
} 

