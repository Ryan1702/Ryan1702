#include<iostream>
#include<cstdio>
#define Maxn 1000
using namespace std;
typedef long long ll;
ll dp[Maxn+5][Maxn+5];
ll ksm(ll a,ll b,ll m)
{
	ll ret=1;
	while(b)
	{
		if(b&1)
		{
			ret=(ret*a)%m;
		}
		b>>=1;
		a=(a*a)%m;
	}
	return ret;
}
int main()
{
	int a,b,k,n,m;
	scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
	for(int i=0;i<=k;i++)
	{
		dp[i][0]=1;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=i;j++)
		{
			dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%(10007*1ll);
		}
	}
	printf("%lld\n",(dp[k][n]*ksm(a,n,10007*1ll)*ksm(b,m,10007*1ll))%(10007*1ll));
	return 0;
}
