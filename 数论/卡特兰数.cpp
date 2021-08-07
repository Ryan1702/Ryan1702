#include<iostream>
#include<cstdio>
#include<cstring>
#define Maxn 2000000
#define Mod 1000000007
using namespace std;
typedef long long ll;
char s[Maxn+5];
ll fac[Maxn+5];
void init(int n)
{
    fac[0]=1ll;
    for(int i=1;i<=n;i++)
    {
        fac[i]=(fac[i-1]*(ll)i)%Mod;
    }
}
ll ksm(ll a,ll b,ll m)
{
    ll ret=1ll;
    while(b)
    {
        if(b&1) ret=(ret*a)%m;
        a=(a*a)%m;
        b>>=1;
    }
    return ret;
}
int main()
{
    int n;
    init(2000000);
    while(scanf("%d",&n)==1)
    {
        scanf("%s",s);
        if(n%2==1)
        {
            printf("0\n");
            continue;
        }
        int a=0,b=0;
        int len=(int)strlen(s);
        int num=0;
        bool f=false;
        for(int i=0;i<len;i++)
        {
            if(s[i]=='(')
            {
                num++;
                a++;
            }
            else
            {
                if(num<=0)
                {
                    printf("0\n");
                    f=true;
                    break;
                }
                num--;
                b++;
            }
        }
        if(f) continue;
        a=n/2-a;
        b=n/2-b;
        printf("%lld\n",fac[a+b]*(b-a+1)%Mod*ksm(fac[a]*fac[b+1]%Mod,Mod-2ll,Mod)%Mod);
    }
    return 0;
}
