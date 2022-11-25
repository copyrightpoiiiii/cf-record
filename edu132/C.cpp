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
int n,m;
int a[200005];
int f[200005][20];
void solve(){
    n=read();m=read();
    for(int i=1;i<=m;i++){
        a[i]=read();
        f[i][0]=a[i];
    }
    for(int i=1;i<=log2(m);i++)
        for(int j=1;j+(1<<i)-1<=m;j++)
            f[j][i]=max(f[j][i-1], f[j+(1<<(i-1))][i-1]);
    int T=read();
    while(T--){
        int xs=read(),ys=read(),xf=read(),yf=read();
        int k=read();
        int xcha=abs(xs-xf),ycha=abs(ys-yf);
        int lo = log2(abs(yf-ys)+1);
        if(xcha%k!=0){
            cout<<"NO"<<endl;
        }
        else if(ycha%k!=0){
            cout<<"NO"<<endl;
        }
        else{
            int maxh = n - (n-xs)%k;
            int miny=min(ys,yf),maxy=max(ys,yf);
            int maxhh = max(f[miny][lo],f[maxy-(1<<lo)+1][lo]);
            //cout<<maxh<<" "<<maxhh<<endl;
            if(maxhh>=maxh){
                cout<<"NO"<<endl;
            }
            else{
                cout<<"YES"<<endl;
            }
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    solve();
    return 0;
}