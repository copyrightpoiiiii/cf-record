#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
#define for4(i,x) for(int i=head[x],y=e[i].go;i;i=e[i].next,y=e[i].go)
#define maxn (400000+5)
#define mod (1000000007)
#define ll long long
#define inf 1000000000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
inline ll readll()
{
	ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
long long gcd(long long x,long long y){return y?gcd(y,x%y):x;}
long long power(long x,long y)
{
	long long t=1;
	for(;y;y>>=1,x=x*x%mod)
		if(y&1)t=t*x%mod;
	return t;
}
struct edge{int go,next,w;}e[2*maxn];
int n,m,k,tot,cnt,head[maxn],a[maxn],fr[maxn],to[maxn],ww[maxn],id[maxn],dep[maxn],fa[maxn];
bool xuanze[maxn];
ll dis[45][maxn],d[maxn],ss[maxn];
queue<int>q;
int f[maxn][18];
bool v[maxn];
void ins(int x,int y,int z)
{
	e[++tot].go=y;e[tot].w=z;e[tot].next=head[x];head[x]=tot;
}
void insert(int x,int y,int z)
{
	ins(x,y,z);ins(y,x,z);
}
void spfa(int s)
{
	for(int i=1;i<=n;++i) d[i]=(ll)inf*inf;
	memset(v,0,sizeof(v));
	q.push(s);d[s]=0;
	while(!q.empty())
	{
		int x=q.front(),y;q.pop();v[x]=0;
		for(int i=head[x];i;i=e[i].next)
		 if(d[x]+e[i].w<d[y=e[i].go])
		 {
		 	d[y]=d[x]+e[i].w;
		 	if(!v[y]){v[y]=1;q.push(y);}
		 }
	}
	rep(i,1,n)dis[id[s]][i]=d[i];//cout<<s<<' '<<i<<' '<<d[i]<<endl;
}
void dfs(int x)
{
    rep(i,1,16)
     f[x][i]=f[f[x][i-1]][i-1];
    for(int i=head[x],y=e[i].go;i;i=e[i].next,y=e[i].go)
     if(y!=f[x][0]) 
      {
          dep[y]=dep[x]+1;
          ss[y]=ss[x]+e[i].w;
          f[y][0]=x;
          dfs(y);
      }
}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int lca(int x,int y)
{
    if(dep[x]<dep[y])swap(x,y);
    int t=dep[x]-dep[y];
    rep(i,0,20)
     if(t&(1<<i))
      x=f[x][i];
    if(x==y)return x;
    for(int i=16;i>=0;i--)
     if(f[x][i]!=f[y][i])
      x=f[x][i],y=f[y][i];
    return f[x][0];    
}
ll dist(int x,int y)
{
	int z=lca(x,y);
	return ss[x]+ss[y]-ss[z]*2;
}
int main()
{
	n=read();m=read();
	rep(i,1,n)fa[i]=i;
	rep(i,1,m)
	{
		int x=read(),y=read(),w=read();
		fr[i]=x;to[i]=y;ww[i]=w;
		int xx=find(x),yy=find(y);
		insert(x,y,w);
		//cout<<i<<' '<<xx<<' '<<yy<<endl;
		if(xx!=yy)fa[xx]=yy,xuanze[i]=1;
		else
		{
			a[++cnt]=x;a[++cnt]=y;
		}
	}
	sort(a+1,a+cnt+1);
	cnt=unique(a+1,a+cnt+1)-a-1;
//	cout<<cnt<<endl;
	rep(i,1,cnt)id[a[i]]=i;//cout<<i<<"fuck"<<a[i]<<endl;
	rep(i,1,cnt)spfa(a[i]);
	tot=0;memset(head,0,sizeof(head));
	rep(i,1,m)if(xuanze[i])insert(fr[i],to[i],ww[i]);
	dfs(1);
	int T=read();
	while(T--)
	{
		int x=read(),y=read();
		ll ans=dist(x,y);
		rep(i,1,cnt)ans=min(ans,dist(x,a[i])+dis[i][y]);
		printf("%I64d\n",ans); 
	}
	return 0;
}

