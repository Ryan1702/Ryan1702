#include<iostream>
#include<cstdio>
#define Maxn 1000000
#define Mod 998244353
using namespace std;
typedef long long ll;
int n;
int a[Maxn+5];
ll fac[Maxn+5];
ll t[Maxn+5];
void init(int n)
{
    fac[0]=1ll;
    for(int i=1;i<=n;i++)
    {
        fac[i]=(fac[i-1]*i)%Mod;
    }
}
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int k)
{
    for(int i=x;i<=n;i+=lowbit(i)) t[i]=(t[i]+(ll)k)%Mod;
}
ll ask(int x)
{
    ll ret=0ll;
    for(int i=x;i>0;i-=lowbit(i)) ret=(ret+t[i])%Mod;
    return ret;
}
int main()
{
    scanf("%d",&n);
    init(n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        add(i,1);
    }
    ll ans=1ll;
    for(int i=1;i<=n;i++)
    {
        add(a[i],-1);
        ans=(ans+(ask(a[i])*fac[n-i])%Mod)%Mod;
    }
    printf("%lld\n",ans);
    return 0;
}
