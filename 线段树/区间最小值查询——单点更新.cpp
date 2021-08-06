#include<iostream>
#include<cstdio>
#define Maxn 100000
#define INF 1<<30
using namespace std;
int a[Maxn+5];
int mn[Maxn<<2];
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
void modify(int l,int r,int pos,int val,int x)
{
    if(l==r)
    {
        mn[x]+=val;
        return ;
    }
    int m=(l+r)>>1;
    if(pos<=m)
    {
        modify(l,m,pos,val,x*2);
    }
    else
    {
        modify(m+1,r,pos,val,x*2+1);
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
        int op,x,y;
        scanf("%d %d %d",&op,&x,&y);
        if(op==1)
        {
            x++;
            modify(1,n,x,y,1);
        }
        else
        {
            x++;
            y++;
            printf("%d\n",query(x,y,1,n,1));
        }
    }
    return 0;
}
