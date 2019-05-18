/// Topics : Segment Tree(Lazy Propagation)
/// How to take inserval/Segment as node/point........


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
//const int sz=
map<int ,int> mp;
set<int> ans;
int *build(int n)
{
    int siz=(int)(ceil(log2(n)));
    siz=2*(pow(2,siz))-1;
    int *lazy=new int[siz];
    memset(lazy,0,sizeof lazy);
    return lazy;
}
void fun(int lazy[],int l,int r,int p,int q,int clr,int pos)
{

       if(r<p || q<l) return;
       else if(p<=l && r<=q) {
        lazy[pos]=clr;
        return;
       }
       int mid=(l+r)/2;
       int ls=2*pos+1;
       int rs=ls+1;
       if(lazy[pos]) lazy[ls]=lazy[rs]=lazy[pos];
       lazy[pos]=0;
       fun(lazy,l,mid,p,q,clr,ls);
       fun(lazy,mid+1,r,p,q,clr,rs);
}
void getsum(int lazy[],int l,int r,int pos)
{
    if(l==r){
        if(lazy[pos])  ans.insert(lazy[pos]);
        return ;
    }
    if(lazy[pos]) {
            ans.insert(lazy[pos]);
            return;
    }
    int mid=(l+r)/2;
    int ls=2*pos+1;
    int rs=ls+1;
    getsum(lazy,l,mid,ls);
    getsum(lazy,mid+1,r,rs);
    return ;
}
int main()
{
    LOL
    int a,b,c,i,j,k,q,p,x,y,sum,ct,ct1,m,l,r,x1,y1,mn,n,mx,h,sum1,len,in,z,mid;
    char ch;
    double d;
    string str1,str2,str;
    bool bl,bl1;
    int cs=1,t;
    set<int> test;
    sf("%d",&t);
    while(t--)
    {
        test.clear();
        mp.clear();
        ans.clear();
        sf("%d",&n);
        pii ara[n];
        for(i=0;i<n;i++)
        {
            sf("%d %d",&p,&q);
            --p,--q;
            test.insert(p);
            test.insert(q);
            ara[i]=mk(p,q);
        }
        k=0;
        for(auto xx:test){
            mp[xx]=k++;
        }
        int *lazy=build(k);

        for(i=0;i<n;i++){
            fun(lazy,0,k-1,mp[ara[i].f],mp[ara[i].s],i+1,0);
        }

        getsum(lazy,0,k-1,0);
        pf("%d\n",ans.size());
    }


}



