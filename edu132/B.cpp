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
ll suma[200005],sumb[200005];
void solve(){
    int n=read(),m=read();
    for(int i=1;i<=n;i++)
        a[i]=readll();
    for(int i=2;i<=n;i++){
        suma[i] = suma[i-1];
        if(a[i]<a[i-1])
            suma[i]+=a[i-1]-a[i];
    }
    for(int i=n-1;i>=1;i--){
        sumb[i]=sumb[i+1];
        if(a[i]<a[i+1])
            sumb[i]+=a[i+1]-a[i];
    }
    for(int i=1;i<=m;i++){
        int x=read(),y=read();
        if(x<y){
            cout<<suma[y]-suma[x]<<endl;
        }
        else{
            cout<<sumb[y]-sumb[x]<<endl;
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    solve();
    return 0;
}