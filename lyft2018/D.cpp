#include<bits/stdc++.h>
#define inf 1000000000
#define maxn 100000+5
#define maxm 5000000+5
#define eps 1e-10
#define mod 998244353
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
ll gcd(ll x,ll y){if(x<y)swap(x,y);return y?gcd(y,x%y):x;}
int power(int x,int y){
	int t=1;
	for(;y;y>>=1,x=x*x%mod)
		if(y&1)t=t*x%mod;
	return t;
}
/*
struct edge{
	int go,next;
}
void insert(int u,int v){
	 e[++tot].go=v;e[tot].next=head[u];head[u]=tot;
	 e[++tot].go=u;e[tot].next=head[v];head[v]=tot;
}
*/
int n,tot;
ll a[600];
ll ans[300005];
int ji[600];
map<ll,int> b;
int find(ll x,ll y){
	
}
int main(){
	n=read();
	for1(i,n)
		a[i]=read();
	for1(i,n)
		if(!ji[i]){
		for1(j,n)
			if(i!=j&&!ji[j]){
				cout<<i<<" "<<j<<endl;
			ll tmp=gcd(a[i],a[j]);
			if(tmp==1)continue;
	}
}
	ll sum=1;
	for(int i=1;i<=n;i++)
		if(!ji[i]){
			sum=(sum*4)%mod;
		}
	for(int i=1;i<=tot;i++)
		if(ans[i]!=1){
		cout<<ans[i]<<" "<<b[ans[i]]<<endl;
		sum=(sum*(b[ans[i]]+1))%mod;
	}
	cout<<sum<<endl;
	return 0;
}

