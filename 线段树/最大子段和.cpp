#include<iostream>
#include<cstdio>
#define Maxn 50000
#define INF 1<<30
using namespace std;
struct node
{
    int maxsum,lsum,rsum,sum;
};
int a[Maxn+5];
node t[Maxn<<2];
void build(int l,int r,int x)
{
    if(l==r)
    {
        t[x].maxsum=t[x].lsum=t[x].rsum=t[x].sum=a[l];
        return ;
    }
    int m=(l+r)>>1;
    build(l,m,x*2);
    build(m+1,r,x*2+1);
    t[x].sum=t[x*2].sum+t[x*2+1].sum;
    t[x].lsum=max(t[x*2].lsum,t[x*2].sum+t[x*2+1].lsum);
    t[x].rsum=max(t[x*2+1].rsum,t[x*2+1].sum+t[x*2].rsum);
    t[x].maxsum=max(t[x*2].maxsum,t[x*2+1].maxsum);
    t[x].maxsum=max(t[x].maxsum,t[x*2].rsum+t[x*2+1].lsum);
}
node query(int L,int R,int l,int r,int x)
{
    if(L<=l&&r<=R)
    {
        return t[x];
    }
    int m=(l+r)>>1;
    node ret=t[x],p1,p2;
    if(R<=m)
    {
        ret=query(L,R,l,m,x*2);
    }
    if(L>m)
    {
        ret=query(L,R,m+1,r,x*2+1);
    }
    if(L<=m&&R>m)
    {
        p1=query(L,R,l,m,x*2);
        p2=query(L,R,m+1,r,x*2+1);
        ret.sum=p1.sum+p2.sum;
        ret.lsum=max(p1.lsum,p1.sum+p2.lsum);
        ret.rsum=max(p2.rsum,p2.sum+p1.rsum);
        ret.maxsum=max(p1.maxsum,p2.maxsum);
        ret.maxsum=max(ret.maxsum,p1.rsum+p2.lsum);
    }
    return ret;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    build(1,n,1);
    int q;
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        printf("%d\n",query(x,y,1,n,1).maxsum);
    }
    return 0;
}
