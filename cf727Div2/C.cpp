#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (300000+5)
#define mod 1000000007
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int power(int x,int y){
    int t=1;
    for(;y;y>>=1,x=x*x%mod)
        if(y&1)t=t*x%mod;
    return t;
}
/*int n,m,tot,head[maxn];
struct edge{
    int go,next;
}e[maxn*2];
void insert(int u,int v){
    e[++tot].go=v;e[tot].next=head[u];head[u]=tot;
    e[++tot].go=u;e[tot].next=head[v];head[v]=tot;
}*/
int n;
ll k,x;
ll a[maxn];
ll f[maxn];
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    n=read();k=read();x=read();
    for(int i=1;i<=n;i++)
        a[i]=read();
    sort(a+1,a+n+1);
    ll sum = 1;
    for(int i=2;i<=n;i++)
        if(a[i]-a[i-1] > x){
            f[sum]=(a[i]-a[i-1]-1)/x;
            sum++;
        }
    sort(f+1,f+sum);
    ll ans=0;
    for(int i=1;i<=sum;i++){
        ans+=f[i];
        if(ans>k){
            cout<<sum-i+1;
            return 0;
        }
    }
    if(ans <= k){
        cout<<1;
    }
    else cout<<sum;
    return 0;
}