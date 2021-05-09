#include<iostream>
#include<cstring>
#include<map>
#define Maxn 400000
using namespace std;
typedef long long ll;
ll a[Maxn+5],b[Maxn+5];
ll head[Maxn+5],to[Maxn+5],nex[Maxn+5],tot;
ll dep[Maxn+5],fa[Maxn+5];
ll ans[Maxn+5];
ll s[Maxn+5],f[Maxn+5];
map<pair<ll,ll>,ll> mp;
void init()
{
	memset(head,-1,sizeof(head));
	tot=0;
}
void add(ll x,ll y,ll xx,ll yy)
{
	to[++tot]=y;
	nex[tot]=head[x];
	head[x]=tot;
	mp[make_pair(x,y)]=tot;
	mp[make_pair(y,x)]=tot;
	s[tot]=xx;
	f[tot]=yy;
}
void dfs(ll x,ll father)
{
	for(ll i=head[x];i!=-1;i=nex[i])
	{
		if(to[i]==father) continue;
		dep[to[i]]=dep[x]+1;
		fa[to[i]]=x;
		dfs(to[i],x);
	}
}
void lca(ll x,ll y)
{
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]!=dep[y])
	{
		ans[mp[make_pair(x,fa[x])]]++;
		x=fa[x];
	}
	while(x!=y)
	{
		ans[mp[make_pair(x,fa[x])]]++;
		x=fa[x];
		ans[mp[make_pair(y,fa[y])]]++;
		y=fa[y];
	}
}
int main()
{
	init();
	ll n;
	scanf("%lld",&n);
	for(ll i=1;i<n;i++)
	{
		ll x,y,xx,yy;
		scanf("%lld %lld %lld %lld",&x,&y,&xx,&yy);
		add(x,y,xx,yy);
	}
	dep[1]=1;
	fa[1]=-1;
	dfs(1,-1);
	for(ll i=1;i<n;i++)
	{
		lca(i,i+1);
	}
	ll anss=0;
	for(ll i=1;i<=tot;i++)
	{
		cout<<ans[i]<<endl;
		anss+=min(s[i]*ans[i],f[i]);
	}
	printf("%lld\n",anss);
}
