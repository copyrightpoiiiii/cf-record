#include<bits/stdc++.h>
#define inf 2e9
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
ll n,m,tot,head[100005],d[45][100005],head2[100005],tot2;
ll dep[100005],de[100005];
ll fa[100005],f[100005][30];
bool a[100005];
struct edge{
	ll go,next,w;
}e[200100],e2[200100];
void insert(int u,int v,ll w){
	 e[++tot].go=v;e[tot].next=head[u];e[tot].w=w;head[u]=tot;
	 e[++tot].go=u;e[tot].next=head[v];e[tot].w=w;head[v]=tot;
}
void insert2(int u,int v,ll w){
	 e2[++tot2].go=v;e2[tot2].next=head2[u];e2[tot2].w=w;head2[u]=tot2;
	 e2[++tot2].go=u;e2[tot2].next=head2[v];e2[tot2].w=w;head2[v]=tot2;
}
void dfs(int x){
    for1(i,20)
     	if(dep[x]>=(1<<i))
     		f[x][i]=f[f[x][i-1]][i-1];
     	else break;
    for4(i,x)
    	if(dep[y=e[i].go]==0) {
        	dep[y]=dep[x]+1;
        	de[y]=de[x]+e[i].w;
          	f[y][0]=x;
          	dfs(y);
      	}
}
int lca(int x,int y)
{
    if(dep[x]<dep[y])swap(x,y);
    int t=dep[x]-dep[y];
    for0(i,20)
     if(t&(1<<i))
      x=f[x][i];
    if(x==y)return x;
    for(int i=20;i>=0;i--)
     if(f[x][i]!=f[y][i])
      x=f[x][i],y=f[y][i];
    return f[x][0];    
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
bool v[100005];
int q[1000005];
void spfa(int s,ll* d){
    for(int i=1;i<=n;++i) d[i]=inf*inf;
    memset(v,0,sizeof(v));
    int l=0,r=1,x,y;q[1]=s;d[s]=0;
    while(l!=r)
    {
        x=q[++l];if(l==1000005)l=0;v[x]=0;
        for(int i=head2[x];i;i=e2[i].next)
         if(d[x]+e2[i].w<d[y=e2[i].go])
         {
            d[y]=d[x]+e2[i].w;
            if(!v[y]){v[y]=1;q[++r]=y;if(r==maxn)r=0;}
         }
    }
}
vector<int> ji;
int main(){
	n=read();m=read();
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for1(i,m){
		int u=read(),v=read();ll w=read();
		if(find(u)!=find(v)){insert(u,v,w);fa[find(u)]=find(v);}
		else {
			if(!a[u])
				ji.push_back(u);
			if(!a[v])
				ji.push_back(v);
			a[u]=1;a[v]=1;
		}
		insert2(u,v,w);
	}
	for(int i=0;i<ji.size();i++)
		spfa(ji[i],d[i+1]);
	dep[1]=1;
	dfs(1);
	int Q=read();
	while(Q--){
		int u=read(),v=read();
		ll ans=0;
		int lc=lca(u,v);
		ans=de[u]+de[v]-2*de[lc];
		//cout<<ans<<endl;
		for(int i=1;i<=ji.size();i++){
			ans=min(ans,d[i][u]+d[i][v]);
			//cout<<d[i][u]+d[i][v]<<endl;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

