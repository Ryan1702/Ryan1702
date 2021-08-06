int exgcd(int a,int b,int &x,int &y)
{
    int d=a;
    if(b!=0)
    {
        d=exgcd(b,a%b,x,y);
        x-=(a/b)*y;
        swap(x,y);
    }
    else
    {
        x=1;
        y=0;
    }
    return d;
}
