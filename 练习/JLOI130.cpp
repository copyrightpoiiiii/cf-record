#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (1000000+5)
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
int n,m;
ll c[maxn],a[maxn];
int lowbit(int x){
    return x & -x;
}

void add(int x,int k){
    while(x <= n){
        c[x] += k;
        x += lowbit(x);
    }
}

ll query(int x){
    ll ans = 0;
    while(x){
        ans += c[x];
        x -= lowbit(x);
    }
    return ans;
}

void build(){
    for(int i=1;i<=n;i++){
        c[i]+=a[i];
        int j = i + lowbit(i);
        if(j<=n) c[j]+=c[i];
    }
}

void solve(){
    n=read();m=read();
    for(int i=1;i<=n;i++)
        a[i]=read();
    build();
    while(m--){
        int x=read(),y=read(),z=read();
        if(x==1){
            add(y,z);
        }
        else{
            printf("%lld\n",query(z)-query(y-1));
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    solve();
    return 0;
}