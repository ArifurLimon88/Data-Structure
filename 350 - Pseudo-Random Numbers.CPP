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
//const int sz=;
int Z,M,L,I;
vector<int> raf;
void solve()
{
   // raf.clear();
    int p=(Z*L+I)%M;
    int q=(Z*L+I)%M;
    q=(Z*q+I)%M;
    while(p != q)
    {
        // raf.pb();
         p=(Z*p+I)%M;
         q=(Z*q+I)%M;
         q=(Z*q+I)%M;
    }
    int rakh=p;
    cout<<rakh<<endl;
    int cnt=0;
    p=L;
    q=rakh;
    while(p != q)
    {
        ++cnt;
        p=(Z*p+I)%M;
        q=(Z*q+I)%M;
    }
    int x=(Z*L+I)%M;
    while(x != rakh){
        ++cnt;
        x=(Z*x+I)%M;
    }
    cout<<cnt<<endl;
}
int main()
{
    LOL
    int a,b,c,i,j,k,q,p,x,y,sum,ct,ct1,m,l,r,len,x1,y1,mn,n,mx,ans,h,sum1;
    char ch;
    double d;
    string str1,str2,str;
    bool bl,bl1;
    int cs=1,t;
    while(cin>>Z>>I>>M>>L && (Z || I || M || L))
    {
        solve();
    }




}

