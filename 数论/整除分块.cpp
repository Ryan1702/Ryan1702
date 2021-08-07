int solve(int n)
{
    int ret=0;
    for(int L=1,R;L<=n;L=R+1)
    {
        R=n/(n/L);
        ret=(ret+(R-L+1)*(n/L))%2;
    }
    return ret;
}
