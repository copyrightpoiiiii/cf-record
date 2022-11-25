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
ll power(ll x,ll y){
	ll t=1;
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
int n,q;
int a[100005];
int f[100005];
int main(){
	n=read();q=read();
	for1(i,n){
		char ch=getchar();
		while(ch!='0'&&ch!='1')ch=getchar();
		a[i]=ch-'0';
		f[i]=f[i-1]+a[i];
	}
	for1(i,q){
		int l=read(),r=read();
		int tmp1=f[r]-f[l-1],tmp0=r-l+1-tmp1;
		//cout<<tmp1<<endl;
		ll ans=power(2,(ll)tmp1)%mod;
		ans--;
		ans=(ans+mod)%mod;
		ans*=power(2,(ll)tmp0)%mod;
		ans%=mod;
		printf("%I64d\n",ans);
	}
	return 0;
}


