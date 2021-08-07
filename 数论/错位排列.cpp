void init(int n)
{
    dp[1]=0;
    dp[2]=1;
    for(int i=3;i<=n;i++)
    {
        dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
    }
}
