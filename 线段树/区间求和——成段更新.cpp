#include<iostream>
#include<cstdio>
#define Maxn 100000
using namespace std;
long long a[Maxn+5];
long long sum[Maxn<<2],lazy[Maxn<<2];
void build(long long l,long long r,long long x)
{
	if(l==r)
	{
		sum[x]=a[l];
		return ;
	}
	long long m=(l+r)>>1;
	build(l,m,x*2);
	build(m+1,r,x*2+1);
	sum[x]=sum[x*2]+sum[x*2+1];
}
void pushdown(long long x,long long l,long long r)
{
	long long m=(l+r)>>1;
	lazy[x*2]+=lazy[x];
	lazy[x*2+1]+=lazy[x];
	sum[x*2]+=lazy[x]*(m-l+1);
	sum[x*2+1]+=lazy[x]*(r-m);
	lazy[x]=0;
}
void modify(long long L,long long R,long long val,long long l,long long r,long long x)
{
	if(L<=l&&r<=R)
	{
		sum[x]+=val*(r-l+1);
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
	long long n;
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	build(1,n,1);
	long long q;
	scanf("%lld",&q);
	for(long long i=1;i<=q;i++)
	{
		char op[5];
		scanf("%s",op);
		if(op[0]=='C')
		{
			long long x,y,z;
			scanf("%lld %lld %lld",&x,&y,&z);
			modify(x,y,z,1,n,1);
		}
		else
		{
			long long x,y;
			scanf("%lld %lld",&x,&y);
			printf("%lld\n",query(x,y,1,n,1));
		}
	}
	return 0;
}
