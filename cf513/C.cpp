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
int read(){
    int x=0,f=1;char ch=getchar();
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
/*
void insert(int u,int v,int w){
	 e[++tot].go=v;e[tot].next=head[u];e[tot].w=w;head[u]=tot;
	 e[++tot].go=u;e[tot].next=head[v];e[tot].w=w;head[v]=tot;
}
*/
ll n,m;
ll x;
ll a[2005],b[2005];
ll sa[2005],sb[2005];
ll ma[2005],mb[2005];
int main(){
	n=read();m=read();
	for1(i,n){
		a[i]=read();
		sa[i]=sa[i-1]+a[i];
	}
	for1(i,m){
		b[i]=read();
		sb[i]=sb[i-1]+b[i];
	}
	ll x=read();
	memset(ma,0x3f,sizeof(ma));
	memset(mb,0x3f,sizeof(mb));
	for(int i=1;i<=n;i++)
		for(int j=1;i+j-1<=n;j++)
			ma[i]=min(ma[i],sa[i+j-1]-sa[j-1]);
	for(int i=1;i<=m;i++)
		for(int j=1;i+j-1<=m;j++)
			mb[i]=min(mb[i],sb[i+j-1]-sb[j-1]);
	ll ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			//cout<<ma[i]<<" "<<mb[j]<<" "<<i<<" "<<j<<endl;
			if(ma[i]*mb[j]<=x)
				ans=max(ans,(ll)i*j);
			}
	cout<<ans<<endl;
	return 0;
}

