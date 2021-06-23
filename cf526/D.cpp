#include<bits/stdc++.h>
#define inf 1000000000
#define maxn 100000+5
#define maxm 5000000+5
#define eps 1e-10
#define mod 1000000007
#define ll long long
#define for0(i,n) for(int i=0;i<=(n);i++)
#define for1(i,n) for(int i=1;i<=(n);i++)
#define for2(i,x,y) for(int i=(x);i<=(y);i++)
#define for3(i,x,y) for(int i=(x);i>=(y);i--)
#define for4(i,x) for(int i=head[x],y=e[i].go;i;i=e[i].next,y=e[i].go)
using namespace std;
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
int tot,head[300005];
struct edge{
	ll go,next,w;
}e[600005];
void insert(int u,int v,int w){
	 e[++tot].go=v;e[tot].next=head[u];head[u]=tot;e[tot].w=w;
	 e[++tot].go=u;e[tot].next=head[v];head[v]=tot;e[tot].w=w;
}
int n;
ll ans;
ll f[300005];
ll d[300005];
void dp(int x,int fa){
	for4(i,x)
		if(y!=fa){
			dp(y,x);
			ll tmp1=f[y]-e[i].w;
			ans=max(tmp1+f[x]+d[x],ans);
			f[x]=max(tmp1,f[x]);
		}
	f[x]+=d[x];
	ans=max(f[x],ans);
}
int main(){
	n=read();
	for1(i,n)
		d[i]=read();
	for1(i,n-1){
		int u=read(),v=read();ll w=read();
		insert(u,v,w);
	}
	dp(1,0);
	cout<<ans<<endl;
	return 0;
}


