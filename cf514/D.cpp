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
double mi=1e15;
double x[maxn],y[maxn];
double dist(double x1,double y1,double x2,double y2)
{
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
bool cheche(double xx,double yy)
{
	rep(i,1,n)if(dist(x[i],y[i],xx,yy)>yy*yy)return 0;
	return 1;
}
double cal(double xx)
{
	double l=0,r=1e15;
	while((r-l)/max(1.0,r)>1e-7)
	{
		//cout<<l<<' '<<r<<endl;
		//printf("%.10f %.10f\n",l,r);
		double mid=(r+l)/2;
		if(cheche(xx,mid))r=mid;else l=mid;
	}
	return l;
}
int main()
{
	n=read();
	int cnt=0;
	double l=1e7,r=-1e7;
	rep(i,1,n)
	{
		x[i]=read(),y[i]=read();
		if(y[i]>0)cnt++;
		if(y[i]<0)y[i]=-y[i];
		l=min(l,x[i]);
		r=max(r,x[i]);
	}
	if(cnt!=0&&cnt!=n)
	{
		cout<<-1<<endl;
		return 0;
	}
	double t=cal(l),tt;
	while((r-l)>1e-8)
	{
	//	cout<<l<<' '<<r<<endl;
		double mid=(l+r)/2,midmid=(mid+r)/2;
		t=cal(mid),tt=cal(midmid);
		mi=min(mi,t);
		mi=min(mi,tt);
		if(t<tt)r=midmid;else l=mid;
	}
	printf("%.7f\n",t);
	return 0;
}

