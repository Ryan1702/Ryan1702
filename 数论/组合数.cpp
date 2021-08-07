void init(int n)
{
    C[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        C[i][i]=C[i][0]=1;
        for(int j=1;j<i;j++)
        {
            C[i][j]=C[i-1][j]+C[i-1][j-1];
        }
    }
}
