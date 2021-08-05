#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#define Maxn 100000
using namespace std;
int head[Maxn+5],to[Maxn+5],nex[Maxn+5],tot;
int dfn[Maxn+5],low[Maxn+5],num;
int co[Maxn+5],col;
stack<int> st;
int inp[Maxn+5];
int siz[Maxn+5];
int ans,cnt;
void init()
{
	memset(head,-1,sizeof(head));
	tot=0;
}
void add(int x,int y)
{
	to[++tot]=y;
	nex[tot]=head[x];
	head[x]=tot;
}
void tarjan(int x)
{
	dfn[x]=low[x]=++num;
	st.push(x);
	for(int i=head[x];i!=-1;i=nex[i])
	{
		if(dfn[to[i]]==0)
		{
			tarjan(to[i]);
			if(low[to[i]]<low[x])
			{
				low[x]=low[to[i]];
			}
		}
		else if(co[to[i]]==0)
		{
			if(dfn[to[i]]<low[x])
			{
				low[x]=dfn[to[i]];
			}
		}
	}
	if(dfn[x]==low[x])
	{
		co[x]=++col;
		siz[col]++;
		while(st.top()!=x)
		{
			co[st.top()]=col;
			siz[col]++;
			st.pop();
		}
		st.pop();
	}
}
int main()
{
	init();
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		add(x,y);
	}
	for(int i=1;i<=n;i++)
	{
		if(dfn[i]==0)
		{
			tarjan(i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=head[i];j!=-1;j=nex[j])
		{
			if(co[i]!=co[to[j]])
			{
				inp[co[i]]++;
			}
		}
	}
	for(int i=1;i<=col;i++)
	{
		if(inp[i]==0)
		{
			ans=siz[i];
			cnt++;
		}
	}
	if(cnt<=1) printf("%d\n",ans);
	else printf("0\n");
	return 0;
}
