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
ll a[200005];
void solve(){
    ll n=read(),x=read();
    ll mi=99999999,mx=0;
    ll ami=9999999,amx=-1;
    ll sum=0;
    for(int i=1;i<=n;i++){
        a[i]=read();
        ami = min (a[i],ami);
        amx = max(a[i],amx);
        sum+=abs(a[i]-a[i-1]);
    }
    sum-=a[1];
    for(int i=2;i<=n;i++){
        mi = min(mi,a[i]+a[i-1]-abs(a[i]-a[i-1]));
        mx = max(mx,a[i]+a[i-1]+abs(a[i]-a[i-1]));
    }
    ll ans;
    if(ami == 1){
        if(amx >= x){
            cout<<sum<<endl;
            return;
        }
        ans = sum + min(x - a[1],x - a[n]);
        ans = min(ans, sum + x + x -mx);
        cout<<ans<<endl;
        return ;
    }
    else if (amx >= x){
        ans = sum + min(a[1]-1,a[n]-1);
        ans = min(ans, sum + mi - 2);
        cout<<ans<<endl;
        return ;
    }
    ans=sum+2*x-mx+mi - 2;
    ans = min(ans,min(sum+x+a[1]-2,sum+x+x-a[1]-1));
    ans = min(ans,min(sum+x+a[n]-2,sum+x+x-a[n]-1));
    ans = min(ans,min(a[1],a[n])+sum+x+x-mx-1);
    ans = min(ans,min(x-a[1],x-a[n]+sum+mi-2));
    cout<<ans<<endl;

}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T = read();
    while(T--){
        solve();
    }
    return 0;
}