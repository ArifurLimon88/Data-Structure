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
const int sz= 30010;
pair<int,int> ara[sz];
void fun(int tree[],int l,int r,int pos)
{
    if(l==r)
    {
        tree[pos]=1;
        return ;
    }
    int ls=2*pos+1;
    int rs=ls+1;
    int mid=(l+r)/2;
    fun(tree,l,mid,ls);
    fun(tree,mid+1,r,rs);
    tree[pos]=tree[ls]+tree[rs];
    return;
}

int *build(int n)
{
    int siz=(int)(ceil(log2(n)));
    siz=2*(pow(2,siz))-1;
    int *tree=new int[siz];
    fun(tree,0,n-1,0);

    return tree;
}
void update(int tree[],int l,int r,int in,int pos)
{
     if(l==r && l==in){
        tree[pos]=0;
        return ;
     }
     int mid=(l+r)/2;
     int ls=2*pos+1;
     int rs=ls+1;
     if(in<=mid) update(tree,l,mid,in,ls);
     else update(tree,mid+1,r,in,rs);

     tree[pos]=tree[ls]+tree[rs];
     return;
}
int getsum(int tree[],int l,int r,int p,int q,int pos)
{
    if(r<p || q<l)   return 0;
    else if(p<=l && r<=q)  return tree[pos];
    int mid=(l+r)/2;
    int lc=2*pos+1;
    int rc=lc+1;
    return getsum(tree,l,mid,p,q,lc)+getsum(tree,mid+1,r,p,q,rc);
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
    for(i=0;i<n;i++){

        sf("%d",&x);
        ara[i]=mk(x,i);
    }
     sf("%d",&q);
     pii pr[q];
     pii IN[q];
     for(i=0;i<q;i++){

        sf("%d %d %d",&a,&b,&x);
        pr[i]=mk(x,i);
        IN[i]=mk(a,b);
     }
     sort(ara,ara+n);
     sort(pr,pr+q);

     int *tree=build(n);
     pii ans[q];
     int pos=0;
     for(i=0;i<q;i++){

        while(pos<n && ara[pos].f<=pr[i].f){
            update(tree,0,n-1,ara[pos].s,0);
            ++pos;
        }
        in=pr[i].s;
        a=IN[in].f,b=IN[in].s;
        sum=getsum(tree,0,n-1,a-1,b-1,0);
        ans[i]=mk(in,sum);
     }

     sort(ans,ans+q);

     for(i=0;i<q;i++){
        pf("%d\n",ans[i].s);
     }


}


