#include<iostream>
#include<cstdio>
#define Maxn 100000
#define INF 1<<30
using namespace std;
int a[Maxn+5];
int mn[Maxn<<2];
int lazy[Maxn<<2];
void build(int l,int r,int x)
{
    if(l==r)
    {
        mn[x]=a[l];
        return ;
    }
    int m=(l+r)>>1;
    build(l,m,x*2);
    build(m+1,r,x*2+1);
    mn[x]=min(mn[x*2],mn[x*2+1]);
}
void pushdown(int x,int l,int r)
{
    lazy[x*2]+=lazy[x];
    mn[x*2]+=lazy[x];
    lazy[x*2+1]+=lazy[x];
    mn[x*2+1]+=lazy[x];
    lazy[x]=0;
}
void modify(int L,int R,int val,int l,int r,int x)
{
    if(L<=l&&r<=R)
    {
        mn[x]+=val;
        lazy[x]+=val;
        return ;
    }
    int m=(l+r)>>1;
    pushdown(x,l,r);
    if(L<=m)
    {
        modify(L,R,val,l,m,x*2);
    }
    if(R>m)
    {
        modify(L,R,val,m+1,r,x*2+1);
    }
    mn[x]=min(mn[x*2],mn[x*2+1]);
}
int query(int L,int R,int l,int r,int x)
{
    if(L<=l&&r<=R)
    {
        return mn[x];
    }
    int m=(l+r)>>1;
    int ret=INF;
    pushdown(x,l,r);
    if(L<=m)
    {
        ret=min(ret,query(L,R,l,m,x*2));
    }
    if(R>m)
    {
        ret=min(ret,query(L,R,m+1,r,x*2+1));
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
        int x,y,z=INF;
        scanf("%d %d",&x,&y);
        x++;
        y++;
        if(getchar()!='\n') scanf("%d",&z);
        if(z!=INF)
        {
            modify(x,y,z,1,n,1);
        }
        else
        {
            printf("%d\n",query(x,y,1,n,1));
        }
    }
    return 0;
}
