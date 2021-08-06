#include<iostream>
#include<cstdio>
#include<cstring>
#define Maxn 200000
using namespace std;
long long head[Maxn+5],to[Maxn+5],nex[Maxn+5],tot;
long long a[Maxn+5];
long long q[Maxn+5],cnt;
long long sum[Maxn<<2];
long long lazy[Maxn<<2];
long long s[Maxn+5],f[Maxn+5];
long long sig[Maxn+5];
long long sign[Maxn<<2];
void init()
{
    memset(head,-1,sizeof(head));
    tot=0;
}
void add(long long x,long long y)
{
    to[++tot]=y;
    nex[tot]=head[x];
    head[x]=tot;
}
void dfs(long long x,long long fa)
{
    q[++cnt]=a[x];
    s[x]=cnt;
    sig[cnt]=1;
    for(long long i=head[x];i!=-1;i=nex[i])
    {
        if(to[i]==fa) continue;
        dfs(to[i],x);
    }
    q[++cnt]=-a[x];
    f[x]=cnt;
    sig[cnt]=-1;
}
void build(long long l,long long r,long long x)
{
    if(l==r)
    {
        sum[x]=q[l];
        if(sig[l]>0) sign[x]=1;
        else sign[x]=-1;
        return ;
    }
    long long m=(l+r)>>1;
    build(l,m,x*2);
    build(m+1,r,x*2+1);
    sum[x]=sum[x*2]+sum[x*2+1];
    sign[x]=sign[x*2]+sign[x*2+1];
}
void pushdown(long long x,long long l,long long r)
{
    lazy[x*2]+=lazy[x];
    lazy[x*2+1]+=lazy[x];
    sum[x*2]+=lazy[x]*sign[x*2];
    sum[x*2+1]+=lazy[x]*sign[x*2+1];
    lazy[x]=0;
}
void modify(long long L,long long R,long long val,long long l,long long r,long long x)
{
    if(L<=l&&r<=R)
    {
        sum[x]+=val*sign[x];
        lazy[x]+=val;
        return ;
    }
    long long m=(l+r)>>1;
    pushdown(x,l,r);
    if(L<=m)
    {
        modify(L,R,val,l,m,x*2);
    }
    if(R>m)
    {
        modify(L,R,val,m+1,r,x*2+1);
    }
    sum[x]=sum[x*2]+sum[x*2+1];
}
long long query(long long L,long long R,long long l,long long r,long long x)
{
    if(L<=l&&r<=R)
    {
        return sum[x];
    }
    long long m=(l+r)>>1;
    long long ret=0;
    pushdown(x,l,r);
    if(L<=m)
    {
        ret+=query(L,R,l,m,x*2);
    }
    if(R>m)
    {
        ret+=query(L,R,m+1,r,x*2+1);
    }
    return ret;
}
int main()
{
    init();
    long long n,m;
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    for(long long i=1;i<n;i++)
    {
        long long x,y;
        scanf("%lld %lld",&x,&y);
        add(x,y);
        add(y,x);
    }
    dfs(1,-1);
    build(1,cnt,1);
    for(long long i=1;i<=m;i++)
    {
        long long op;
        scanf("%lld",&op);
        if(op==1)
        {
            long long x,y;
            scanf("%lld %lld",&x,&y);
            modify(s[x],s[x],y,1,cnt,1);
            modify(f[x],f[x],y,1,cnt,1);
        }
        else if(op==2)
        {
            long long x,y;
            scanf("%lld %lld",&x,&y);
            modify(s[x],f[x],y,1,cnt,1);
        }
        else
        {
            long long x;
            scanf("%lld",&x);
            printf("%lld\n",query(1,s[x],1,cnt,1));
        }
    }
    return 0;
}
