#include<iostream>
#include<cstdio>
#include<cstring>
#define Maxn 200000
using namespace std;
void check_min(int &x,int y)
{
    if(y<x) x=y;
}
int head[Maxn+5],to[Maxn+5],nex[Maxn+5],tot;
int dfn[Maxn+5],low[Maxn+5],num;
int root;
int cnt;
int ans;
void init()
{
    memset(head,-1,sizeof(head));
    tot=0;
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    num=0;
    ans=0;
}
void add(int x,int y)
{
    to[++tot]=y;
    nex[tot]=head[x];
    head[x]=tot;
}
void tarjan(int x,int fa)
{
    bool flag=false;
    dfn[x]=low[x]=++num;
    for(int i=head[x];i!=-1;i=nex[i])
    {
        if(to[i]==fa) continue;
        if(x==root&&dfn[to[i]]==0) cnt++;
        if(dfn[to[i]]==0)
        {
            tarjan(to[i],x);
            check_min(low[x],low[to[i]]);
            if(x!=root&&low[to[i]]>=dfn[x]) flag=true;
        }
        else
        {
            check_min(low[x],dfn[to[i]]);
        }
    }
    if(flag) ans++;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        if(n==0) break;
        int x;
        init();
        while(scanf("%d",&x)==1)
        {
            if(x==0) break;
            while(getchar()==' ')
            {
                int y;
                scanf("%d",&y);
                add(x,y);
                add(y,x);
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(dfn[i]==0)
            {
                root=i;
                cnt=0;
                tarjan(i,-1);
                if(cnt>=2) ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
