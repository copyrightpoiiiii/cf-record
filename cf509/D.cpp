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
/*
void insert(int u,int v,int w){
	 e[++tot].go=v;e[tot].next=head[u];e[tot].w=w;head[u]=tot;
	 e[++tot].go=u;e[tot].next=head[v];e[tot].w=w;head[v]=tot;
}
*/
ll n,h;
ll a[200005];
struct {
	ll s,t;
}b[200005];
int main(){
	n=read();h=read();
	for1(i,n){
		b[i].s=read();b[i].t=read();
		a[i]=b[i].t-b[i].s;
	}
	for(int i=2;i<=n;i++)
		a[i]+=a[i-1];
	ll ans=0;
	for1(i,n){
		int l=i,r=n;
		while(l<=r){
			int mid=(l+r)>>1;
			if(h+a[mid]-a[i-1]>b[mid].t-b[i].s)
				l=mid+1;
			else r=mid-1;
		}
		//cout<<l<<" "<<r<<endl;
		ans=max(ans,h+a[r]-a[i-1]);
	}
	cout<<ans<<endl;
	return 0;
}

