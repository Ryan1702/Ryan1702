#include<bits/stdc++.h>
#define Maxn 500000
#define INF 1<<60
using namespace std;
int h[Maxn+5],b[Maxn+5];
stack<int> st;
ll dp[Maxn+5];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",h+i);
	for(int i=1;i<=n;i++) scanf("%d",b+i);
	build(1,n,1);
	st.push(0);
	h[0]=INF;
	for(int i=1;i<=n;i++)
	{
		int pre=-1;
		while(h[st.top()]<h[i])
		{
			if(pre!=-1) modify(1,n,1,st.top()+1,pre,h[i]-h[pre]);
			else pre=st.top();
			st.pop();
		}
		st.push(i);
		dp[i]=query(1,n,1,1,i);
	}
}
