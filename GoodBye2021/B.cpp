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
char a[100005];
void solve(){
    int n =read();
    char ch = getchar();
    while(ch<'a'||ch>'z')ch=getchar();
    a[1]=ch;
    int sum=1,flag=0;
    for(int i = 2;i<=n;i++){
        ch=getchar();
        while(ch<'a'||ch>'z')ch=getchar();
        a[i]=ch;
        if(a[i]>a[i-1]){
            flag=1;
        }
        if(!flag)
            sum++;
    }
    if(n>1 && a[1]==a[2]){
        cout<<a[1]<<a[1];
    }
    else{
    for(int i=1;i<=sum;i++)
        cout<<a[i];
    for(int i=sum;i>=1;i--)
        cout<<a[i];
    }
    cout<<endl;
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