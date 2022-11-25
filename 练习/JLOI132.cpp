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
ll b[maxn],ib[maxn],a[maxn];
int lowbit(int x){
    return x & -x;
}

void add(int x,int k){
    ll k2 = (ll)x*k;
    while(x <= n){
        b[x] += k;
        ib[x] += k2;
        x += lowbit(x);
    }
}

ll query(int x,ll* arr){
    ll ans = 0;
    while(x){
        ans += arr[x];
        x -= lowbit(x);
    }
    return ans;
}

void addseg(int l, int r, int w){
    add(l,w);
    add(r+1,-w);
}

ll queryseg(int l,int r){
    return a[r]-a[l-1]+query(r,b)*(r+1)-query(r,ib)-query(l-1,b)*l+query(l-1,ib);
}

void solve(){
    n=read();m=read();
    for(int i=1;i<=n;i++)
        a[i]=a[i-1] + read();
    while(m--){
        int x=read(),y=read(),z=read();
        if(x==1){
            int w=read();
            addseg(y,z,w);
        }
        else{
            printf("%lld\n",queryseg(y,z));
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    solve();
    return 0;
}