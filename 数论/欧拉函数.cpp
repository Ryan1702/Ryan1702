void init(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!flag[i])
        {
            p[++cnt]=i;
            phi[i]=i-1;
        }
        for(int j=1;j<=cnt;j++)
        {
            if(i*p[j]>n) break;
            flag[i*p[j]]=true;
            if(i%p[j]==0)
            {
                phi[i*p[j]]=phi[i]*p[j];
                break;
            }
            phi[i*p[j]]=phi[i]*(p[j]-1);
        }
    }
}
