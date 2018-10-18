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
int n;
ll dp[maxn];
struct poi{ll x,y,z;}a[maxn];
bool cmp(poi a, poi b)
{
	if(a.z!=b.z)return a.z<b.z;
	else if(a.x!=b.x)return a.x<b.x;
	else return a.y>b.y;
}
ll dis(poi a,poi b)
{
	return abs(a.x-b.x)+abs(a.y-b.y);
}
int main()
{
	n=read();
	rep(i,1,n)a[i].x=read(),a[i].y=read(),a[i].z=max(a[i].x,a[i].y);;
	sort(a+1,a+n+1,cmp);
	//rep(i,1,n)cout<<i<<' '<<a[i].x<<' '<<a[i].y<<endl;
	memset(dp,63,sizeof(dp));
	dp[0]=0;
	int l=0,r=0;
	a[0].x=a[0].y=a[0].z=0;
	for(int i=1,j;i<=n;i=j+1)
	{
		j=i;
		while(j<n&&a[j+1].z==a[i].z)j++;
		rep(k,l,r)
		{
			dp[i]=min(dp[i],dp[k]+dis(a[i],a[k]));
			dp[j]=min(dp[j],dp[k]+dis(a[j],a[k]));
		}
		ll t1=dp[i]+dis(a[i],a[j]),t2=dp[j]+dis(a[i],a[j]);
		dp[i]=t2;
		dp[j]=t1;
		rep(k,i+1,j-1)dp[k]=min(dp[i]+dis(a[i],a[k]),dp[j]+dis(a[j],a[k]));
		l=i;r=j;
		//rep(k,i,j)cout<<k<<' '<<dp[k]<<endl;
	}
	ll ans=(ll)inf*inf;
	rep(k,l,r)ans=min(ans,dp[k]);
	cout<<ans<<endl;
	return 0;
}
