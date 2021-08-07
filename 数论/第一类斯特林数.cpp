void init(int n)
{
    dp[0][0]=dp[1][1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            dp[i][j]=dp[i-1][j]*(i-1)+dp[i-1][j-1];
        }
    }
}
