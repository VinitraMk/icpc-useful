ll dp[N];
void lis(ll a[],ll n)
{
    ll i,j;
    dp[0]=1;
    for(i=1;i<n;i++)
    {
        dp[i]=1;
        for(j=0;j<i;j++)
        {
            if((a[i]>a[j]) && (dp[i]<dp[j]+1))
                dp[i]=dp[j]+1;
        }
    }
}

