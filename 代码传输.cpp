#include<iostream>
#include<cstdio>
#include<algorithm>
#define Maxn 200000
using namespace std;
struct node
{
    int lev,age,l,r;
}a[Maxn+5];
int qus[Maxn+5];
struct LEVEL
{
    int Lev,id;
    bool operator<(const LEVEL &x)const
    {
        return Lev<x.Lev;
    }
    LEVEL(int _Lev=0,int _id=0):Lev(_Lev),id(_id){}
}L[Maxn+5];
int cnt_L;
struct AGE
{
    int Age,op,id;
    bool operator<(const AGE &x)const
    {
        return Age<x.Age;
    }
    AGE(int _Age=0,int _op=0,int _id=0):Age(_Age),op(_op),id(_id){}
}A[Maxn+5];
int cnt_A;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i].lev);
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i].age);
            a[i].l=a[i].age-k;
            a[i].r=a[i].age+k;
        }
        for(int i=1;i<=n;i++)
        {
            L[++cnt_L]=LEVEL(a[i].lev,i);
            A[++cnt_A]=AGE(a[i].age,1,i);
            A[++cnt_A]=AGE(a[i].l,2,i);
            A[++cnt_A]=AGE(a[i].r,3,i);
        }
        sort(L+1,L+1+cnt_L);
        sort(A+1,A+1+cnt_A);
        int val_L=0,val_A=0;
        for(int i=1;i<=cnt_L;i++)
        {
            if(L[i].Lev!=L[i-1].Lev) L[i].Lev=++val_L;
            else L[i].Lev=val_L;
        }
        for(int i=1;i<=cnt_A;i++)
        {
            if(A[i].Age!=A[i-1].Age) A[i].Age=++val_A;
            else A[i].Age=val_A;
        }
        for(int i=1;i<=cnt_L;i++)
        {
            a[L[i].id].lev=L[i].Lev;
        }
        for(int i=1;i<=cnt_A;i++)
        {
            if(A[i].op==1) a[A[i].id].age=A[i].Age;
            else if(A[i].op==2) a[A[i].id].l=A[i].Age;
            else a[A[i].id].r=A[i].Age;
        }
        
        int q;
        scanf("%d",&q);
        for(int i=1;i<=q;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            qus[i]=max(a[x].lev,a[y].lev);
        }
    }
    return 0;
}
