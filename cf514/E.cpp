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
struct edge{
	ll go,next;
}e[200005];
ll n,l,ss,tot,ans,h,t;
ll a[100005],head[100005],fa[100005];
ll d[100005],he[100005],s[100005];
ll book[100005],ji[100005];
bool vis[100005];
ll q[300005];
void insert(ll u,ll v){
	 e[++tot].go=v;e[tot].next=head[u];head[u]=tot;
	 e[++tot].go=u;e[tot].next=head[v];head[v]=tot;
}
void dfs(int x){
	for4(i,x)
		if(y!=fa[x]){
			fa[y]=x;
			dfs(y);
		}
}
ll find(ll x){
	return d[x]==x?x:d[x]=find(d[x]);
}
int main(){
	n=read();l=read();ss=read();
	for1(i,n)
		d[i]=i;
	for1(i,n){
		a[i]=read();
		//d[i]=find(a[i]);
		if(a[i]>ss){
			cout<<-1<<endl;
			return 0;
		}
	}
	he[1]=1;s[1]=a[1];
	for(int i=2;i<=n;i++){
		ll x=read();
		fa[i]=x;
		ji[x]++;
		s[i]=s[x]+a[i];
		he[i]=he[x]+1;
		
	}
	for1(i,n)
		if(!ji[i]){
			q[++t]=i;
		}
	while(h!=t){
		ll x=q[++h];
		if(vis[x])continue;
		ll tmp=0,now=x,len=0;
		ans++;
		while(tmp<=ss){
			//book[now]=1;
			tmp+=s[now]-s[find(now)];
			if(tmp>ss-a[now])break;
			//vis[now]=1;
			len+=he[now]-he[find(now)];
			if(len>l-1)break;
		
			tmp+=a[find(now)];
			vis[find(now)]=1;
			len+=1;
			ji[fa[find(now)]]--;
				ll test=find(now);
				
			if(!vis[fa[test]]){
				if(fa[test]&&ji[fa[test]]==0)
					q[++t]=fa[test];
				}
			d[test]=find(fa[test]);	
			now=fa[test];
			if(!now)
				break;
		}
		
	}
	cout<<ans<<endl;
	return 0;
}

