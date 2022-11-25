#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (300000+5)
#define mod 1000000007
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
ll readll(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int power(ll x,ll y){
    ll t=1;
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
ll a[1000005],b[1000005];
ll f[1000005];
ll n,k;
void init(){
    n=readll();k=readll();f[0]=1;
    a[0]=1;b[0]=power(1,1000000007-2);
    for(int i=1;i<=n;i++){
        a[i]=(a[i-1]*i)%1000000007;
        b[i]=power(a[i],1000000007-2);
        f[i]=f[i-1]*3%mod;
    }
}
ll co(ll x,ll y){
    if(y>x)
        return 0;
    if(!y)
        return 1;
    return a[x]*b[y]%mod*b[x-y]%mod;
}
void solve(){
    init();
    if(k>0){
        ll sum =0;
        for(int i=1;i<=k;i++){
            if(i<=n-k+1){
                sum =  ((f[n+1-(i<<1)]%mod)*(co(n-k,i-1)*co(k-1,i-1)%mod)%mod)%mod + sum%mod;
                sum%=mod;
                sum = (f[n-(i<<1)]*(co(k-1,i-1)%mod*co(n-k,i)%mod)%mod + sum%mod)%mod;
            }
            else{
                cout<< sum<<endl;
                return;
            }
        }
        cout<< sum<<endl;
        return;
    }
    else{
        cout<<power(3,n)<<endl;
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}