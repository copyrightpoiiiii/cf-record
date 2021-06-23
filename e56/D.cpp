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
struct edge{
	int go,next;
}e[600100];
int head[400005],tot,n,m,t,v[400005],cnt1,cnt2,v1[400005];ll flag;
ll ans[400005];
void insert(int u,int v){
	 e[++tot].go=v;e[tot].next=head[u];head[u]=tot;
	 e[++tot].go=u;e[tot].next=head[v];head[v]=tot;
}
void dfs(int x){
	if(v[x]==1)cnt1++;
	if(v[x]==-1)cnt2++;
	for4(i,x)
		if(v[y]==0){
			v[y]=-v[x];
			dfs(y);
		}
		else if(v[y]==v[x]){
			flag=0;
			//break;
		}
}
int main(){
	t=read();
	while(t--){
		flag=1;
		n=read();m=read();
		for1(i,m){
			int x=read(),y=read();
			insert(x,y);
		}
		ll sum=1;
		for1(i,n)
			if(v[i]==0){
				cnt1=0;cnt2=0;
				v[i]=1;
				dfs(i);
				sum=(sum*(power(2,cnt1)+power(2,cnt2))%mod)%mod;
			}
		cout<<(mod+(sum*flag)%mod)%mod<<endl;
		tot=0;
		for1(i,n){
			v[i]=v1[i]=ans[i]=0;head[i]=0;
		}
	}
	return 0;
}


