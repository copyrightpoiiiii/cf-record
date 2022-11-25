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
int a[50005];
void solve(){
    int n=read();
    for(int i =1;i<=n;i++)
        a[i]=read();
    int x=read();
    for(int i =1;i<=n;i++){
        a[i]-=x;
    }
    int tot=1,mxsuf=a[1];
    for(int i=2;i<=n;i++){
        if(a[i]+mxsuf>=0){
            tot++;
            mxsuf=mxsuf+a[i];
        }
        else{
            mxsuf=0;
        }
    }
    cout<<tot<<endl;
    int tot2=1;mxsuf=a[2];
    for(int i=3;i<=n;i++){
        if(a[i]+mxsuf>=0){
            tot2++;
            mxsuf=mxsuf+a[i];
        }
        else{
            mxsuf=0;
        }
    }
    cout<<tot2<<endl;
    cout<<max(tot2,tot)<<endl;
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