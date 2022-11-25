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
ll sum[200005];
int n;
bool check(ll ans){
    sum[n]=sum[n-1]=0;
    for(int i=n;i>=3;i--){
        if(sum[i]+a[i]<ans)
            return false;
        else{
            if(sum[i]>=ans){
                sum[i-1] += a[i]/3;
                sum[i-2] = (a[i]/3)*2;
            }
            else{
                ll les = sum[i]+a[i]-ans;
                sum[i-1] += les/3;
                sum[i-2] = (les/3)*2;
            }
        }
    }
    for(int i=1;i<=2;i++)
        if(sum[i]+a[i]<ans)
            return false;
    return true;
}
void solve(){
    n = read();
    for(int i = 1 ;i<=n;i++){
        a[i]=readll();
    }
    ll l = 1,r=1e9;
    while(l!=r){
        ll mid = (l+r)>>1;
        if(check(mid))
            l=mid+1;
        else
            r=mid;
    }
    cout<<r-1<<endl;
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