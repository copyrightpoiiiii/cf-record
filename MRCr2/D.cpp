#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
#define for4(i,x) for(int i=head[x],y=e[i].go;i;i=e[i].next,y=e[i].go)
#define maxn (400000+5)
#define mod (1000000007)
#define ll long long
#define inf 1000000000
#define upmo(a,b) (((a)=((a)+(b))%mo)<0?(a)+=mo:(a))
#define mmo(a,b) (((a)=1ll*(a)*(b)%mo)<0?(a)+=mo:(a))
template<typename T,typename S>inline bool upmin(T&a,const S&b){return a>b?a=b,1:0;}
template<typename T,typename S>inline bool upmax(T&a,const S&b){return a<b?a=b,1:0;}
using namespace std;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
inline bool is_down(char x) { return ('a' <= x && x <= 'z'); }
inline bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
inline bool is_digit(char x) { return ('0' <= x && x <= '9'); }
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
long long power(long long x,long long y)
{
	long long t=1;
	for(;y;y>>=1,x=x*x%mod)
		if(y&1)t=t*x%mod;
	return t;
}
/*
struct edge
{
	int go,next;
}e[2*maxn];
void insert(int x,int y)
{
	e[++tot]=(edge){y,head[x]};head[x]=tot;
	e[++tot]=(edge){x,head[y]};head[y]=tot;
}
*/
struct segment
{
	struct seg{int l,r,mi,tag;}t[4*1005];
	inline void pushup(int k)
	{
	    t[k].mi=min(t[k<<1].mi,t[k<<1|1].mi);
	}
	inline void update(int k,int z)
	{
	    t[k].mi=min(t[k].mi,z);
	    t[k].tag=min(t[k].tag,z);
	}
	inline void pushdown(int k)
	{
	    if(t[k].tag==inf)return ;
	    update(k<<1,t[k].tag);
	    update(k<<1|1,t[k].tag);
	    t[k].tag=inf;
	}
	inline void build(int k,int x,int y)
	{
	    int l=t[k].l=x,r=t[k].r=y,mid=(l+r)>>1;t[k].tag=inf;
	    if(l==r){t[k].mi=l==0?0:inf;return ;}
	    build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	    pushup(k);
	}
	inline ll query(int k,int x)
	{
	    int l=t[k].l,r=t[k].r,mid=(l+r)>>1;
	    if(l==r)return t[k].mi;
	    pushdown(k);
	    if(x<=mid)return query(k<<1,x);else return query(k<<1|1,x);
	}
	inline void change(int k,int x,int y,int z)
	{
	    int l=t[k].l,r=t[k].r,mid=(l+r)>>1;
	    if(l==x&&r==y){update(k,z);return;}
	    pushdown(k);
	    if(y<=mid)change(k<<1,x,y,z);
	    else if(x>mid)change(k<<1|1,x,y,z);
	    else change(k<<1,x,mid,z),change(k<<1|1,mid+1,y,z);
	    pushup(k);
	}
}tree[3005];
int n,m,s,zyf;
struct rec{int l,r;}c[maxn];
int a[maxn],b[maxn],sum[maxn];
int dp[1505][1505];
bool cmp(rec a,rec b)
{
	if(a.l==b.l)return a.r<b.r;else return a.l<b.l;
}
int getsum(int l,int r)
{
	return sum[r]-sum[l-1]; 
} 
bool check(int x)
{
	rep(i,1,n)sum[i]=sum[i-1]+(a[i]<=x); 
	memset(dp,1,sizeof(dp));
	rep(i,1,2*n)tree[i].build(1,1,n);
	dp[0][0]=0;
	int j=1;
	rep(i,1,n)
	{
		for(;c[j].l==i;j++)
		{
			for(int k=0;k<=n;k++)if(dp[c[j].l-1][k]<m)
			{
				tree[k-sum[i-1]+n].change(1,c[j].l,c[j].r,dp[c[j].l-1][k]+1);
			}
		}
		rep(k,0,n)dp[i][k]=min(dp[i][k],dp[i-1][k]);
		rep(k,0,2*n)if(k-n+sum[i]<=n)
		{
			int x=tree[k].query(1,i);
			dp[i][k-n+sum[i]]=min(dp[i][k-n+sum[i]],x);
		}
	}
	rep(i,zyf,n)if(dp[n][i]<=m)return 1;
	return 0;
} 
int main()
{
	n=read(),s=read(),m=read(),zyf=read();
	rep(i,1,n)a[i]=read(),b[i]=a[i];
	sort(b+1,b+n+1);
	rep(i,1,n)a[i]=lower_bound(b+1,b+n+1,a[i])-b;
	//rep(i,1,n)cout<<i<<' '<<a[i]<<endl;
	rep(i,1,s)c[i].l=read(),c[i].r=read();
	sort(c+1,c+s+1,cmp);
	//rep(i,1,s)cout<<i<<' '<<c[i].l<<' '<<c[i].r<<endl;
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))r=mid-1;else l=mid+1;
	}
	//cout<<l<<' '<<r<<endl;
	if(l>n)cout<<-1<<endl;else cout<<b[l]<<endl;
	return 0;
}
