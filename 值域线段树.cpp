#include<iostream>
#include<cstdio>
#include<map>
#define Maxn 100000
using namespace std;
map<int,int> mp,mp2;
int a[Maxn+5],num[Maxn+5];
int sum[Maxn<<2];
void modify(int pos,int val,int l,int r,int x)
{
    if(l==r)
    {
        sum[x]+=val;
        return ;
    }
    int m=(l+r)>>1;
    if(pos<=m)
    {
        modify(pos,val,l,m,x*2);
    }
    else
    {
        modify(pos,val,m+1,r,x*2+1);
    }
    sum[x]=sum[x*2]+sum[x*2+1];
}
int query(int pos,int l,int r,int x)
{
    if(l==r)
    {
        return mp2[l];
    }
    int m=(l+r)>>1;
    if(pos<=sum[x*2])
    {
        return query(pos,l,m,x*2);
    }
    else
    {
        return query(pos-sum[x*2],m+1,r,x*2+1);
    }
}
int main()
{
    int q;
    scanf("%d",&q);
    int cnt=1;
    for(int i=1;i<=q;i++)
    {
        char op[10];
        scanf("%s",op);
        if(op[0]=='i')
        {
            scanf("%d",&a[i]);
            num[i]=2;
            mp[a[i]]=1;
        }
        else if(op[0]=='o')
        {
            num[i]=1;
            while(num[cnt]!=2) cnt++;
            a[i]=a[cnt++];
        }
        else
        {
            num[i]=0;
        }
    }
    for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
    {
        it->second=++cnt;
        mp2[cnt]=it->first;
    }
    int n=0;
    for(int i=1;i<=q;i++)
    {
        if(num[i]==2)
        {
            n++;
            modify(mp[a[i]],1,1,cnt,1);
        }
        else if(num[i]==1)
        {
            n--;
            modify(mp[a[i]],-1,1,cnt,1);
        }
        else
        {
            printf("%d\n",query(n/2+1,1,cnt,1));
        }
    }
    return 0;
}
