///Problem: https://www.spoj.com/problems/DQUERY/

/// ** My personal Code for MO's Algorithm :


#include<bits/stdc++.h>
using namespace std;
#define LOL ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int
#define llu long long unsigned int
#define pf printf
#define sf scanf
#define f first
#define s second
#define pb push_back
#define mk make_pair
#define pii pair<int ,int>
const int sz=30010;
const int sz1=1e6+100;
int mark[sz1];
pair<int,pii> pr[200010];
int ara[sz];
int ans[200010];
int n,Q;
int block;
bool cmp(pair<int,pii> a,pair<int,pii> b)
{
    if((a.s.f/block)!= (b.s.f/block))  return a.s.f<b.s.f;
    else return (a.s.s<b.s.s);
}
void cholo()
{
    int ct,i,j,l,r,cr,cl,p;
    cr=cl=ct=0;
    for(i=0;i<Q;i++)
    {
       l=pr[i].s.f;
       r=pr[i].s.s;
       while(cl<l)
       {
           p=ara[cl];
           --mark[p];
           if(mark[p]==0) --ct;
           ++cl;
       }
       while(cl>l)
       {
           p=ara[cl-1];
           ++mark[p];
           if(mark[p]==1) ++ct;
           --cl;
       }
       while(cr<=r)
       {
           p=ara[cr];
           ++mark[p];
           if(mark[p]==1) ++ct;
           ++cr;
       }
       while(r+1<cr)
       {
           p=ara[cr-1];
           --mark[p];
           if(mark[p]==0) --ct;
           --cr;
       }
       ans[pr[i].f]=ct;
    }
}
int main()
{
    LOL
    int a,b,c,i,j,k,q,p,x,y,sum,ct,ct1,m,l,r,len,x1,y1,mn,mx,h,sum1;
    char ch;
    double d;
    string str1,str2,str;
    bool bl,bl1;
    int cs=1,t;
    sf("%d",&n);
    for(i=0;i<n;i++){
            sf("%d",&ara[i]);
    }

    sf("%d",&Q);
    for(i=0;i<Q;i++)
    {
        sf("%d %d",&x,&y);
        pr[i]=mk(i,mk(x-1,y-1));
    }
    block=sqrt(n);
    sort(pr,pr+Q,cmp);
    memset(mark,0,sizeof mark);
    cholo();
    for(i=0;i<Q;i++)
    {
        pf("%d\n",ans[i]);
    }


}

