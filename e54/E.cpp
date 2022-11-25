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

struct edge{
	int go,next;
}e[600005];
int tot,head[300005];
void insert(int u,int v){
	 e[++tot].go=v;e[tot].next=head[u];head[u]=tot;
	 e[++tot].go=u;e[tot].next=head[v];head[v]=tot;
}
int n,m;
struct te{
	int to,dis,w;
}a[300005];
int next2[300005],head2[300005];
ll s[300005],ans[300005];
int dep[300005];
ll query(int x){
	ll ret=0;
	while(x){
		ret+=s[x];
		x-=x&(-x);
	}
	return ret;
}
void add(int x,int y){
	for(;x<=n;x+=x&(-x))s[x]+=y;
}
void dfs1(int x,int fa){
	for4(i,x)
		if(y!=fa){
			dep[y]=dep[x]+1;
			dfs1(y,x);
		}
		//cout<<dep[x]<<endl;
}
void dfs(int x,int fa){
	for(int i=head2[x];i;i=next2[i]){
		//cout<<dep[x]+a[i].dis<<endl;
		add(min(n,dep[x]+a[i].dis),a[i].w);
	}
	//cout<<query(n)<<endl;
	ans[x]=query(n)-query(dep[x]-1);
	for4(i,x)
		if(y!=fa){
			dfs(y,x);
		}
	for(int i=head2[x];i;i=next2[i])
		add(min(n,dep[x]+a[i].dis),-a[i].w);
}
int main(){
	n=read();
	for1(i,n-1){
		int x=read(),y=read();
		insert(x,y);
	}
	m=read();
	for1(i,m){
		a[i].to=read();a[i].dis=read();a[i].w=read();
		next2[i]=head2[a[i].to];head2[a[i].to]=i;
		//cout<<head[a[i].to]<<endl;
	}
	dep[1]=1;
	dfs1(1,0);
	dfs(1,0);
	for1(i,n)
		printf("%I64d ",ans[i]);
	return 0;
}


