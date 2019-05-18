/// topic : Segment Tree
/// How to put vector in each node of tree;

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
const int sz= 70000;
vector<int> node[sz];
int ara[30005];
void build(int l,int r,int pos)
{
    if(l==r){
        node[pos].pb(ara[l]);
        return ;
    }
    int mid=(l+r)/2;
    int ls=2*pos+1;
    int rs=ls+1;
    build(l,mid,ls);
    build(mid+1,r,rs);
    merge(node[ls].begin(),node[ls].end(),node[rs].begin(),node[rs].end(), back_inserter(node[pos]));
    return ;
}
int getsum(int l,int r,int p,int q,int val,int pos)
{
    if(r<p || q<l)  return 0;
    else if(p<=l && r<=q)
    {
        auto it=upper_bound(node[pos].begin(),node[pos].end(),val);
        if(it==node[pos].end())   return 0;
        return (node[pos].end()-it);
    }
    int mid=(l+r)/2;
    int ls=2*pos+1;
    int rs=ls+1;
    return getsum(l,mid,p,q,val,ls)+getsum(mid+1,r,p,q,val,rs);
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
    sf("%d",&n);
    for(i=0;i<n;i++)   sf("%d",&ara[i]);
    build(0,n-1,0);
    int prev=0;
    sf("%d",&m);
    while(m--)
    {
        sf("%d %d %d",&a,&b,&x);
        a=a^prev,b=b^prev;
        --a,--b;
        if(a>b){
            pf("0\n");
            prev=0;
            continue;
        }
        if(1>a) a=0;
        if(b>n) b=n-1;
        p=getsum(0,n-1,a,b,prev^x,0);
        pf("%d\n",p);
        prev=p;
    }

}

