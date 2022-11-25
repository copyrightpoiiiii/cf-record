#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
#define for4(i,x) for(int i=head[x],y=e[i].go;i;i=e[i].next,y=e[i].go)
#define mod (1000000007)
#define ll long long
#define inf 1000000000
#define MAXN 15000000
#define maxn 300000+5
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
int a[maxn],p[MAXN+5],mi[MAXN+5],cnt[MAXN+5],mk[MAXN+5];
void get()
{
	int tot=0;
	rep(i,2,MAXN) 
	{
		if(!cnt[i])p[++tot]=i,mi[i]=i,mk[i]=i;
		//cout<<i<<' '<<mi[i]<<' '<<mk[i]<<' '<<tot<<endl;
		//if(i%1000000==0)cout<<i<<' '<<mk[i]<<' '<<mi[i]<<endl;
		//cout<<i<<' '<<mk[i]<<' '<<mi[i]<<' '<<tot<<endl;
	//	if(mk[i]==0||mi[i]==0)cout<<"FUCK"<<endl;
		rep(j,1,tot)
		{
		 	long long k=p[j]*i;
		 	if(k>MAXN)break;
		    cnt[k]=1;
		    if(i%p[j]==0)
			{
				mi[k]=mi[i]*p[j];
				mk[k]=p[j];
				//cout<<i<<' '<<j<<' '<<p[j]<<' '<<k<<endl;
				break;
			}else
			{
				mk[k]=p[j];
				if(mk[k/p[j]]==mk[k])mi[k]=mi[k/p[j]]*p[j];
				else mi[k]=p[j];
			}
		}
	}
}
int main()
{
	int n=read();
	get();
	rep(i,1,n)a[i]=read();
	memset(p,0,sizeof(p));
	memset(cnt,0,sizeof(cnt));
	int gc=0;
	rep(i,1,n)gc=gcd(gc,a[i]);
	rep(i,1,n)a[i]/=gc;
	rep(i,1,n){cout<<mk[a[i]]<<mi[a[i]]<<a[i]<<endl;p[a[i]]++;}
	//cout<<"FUCK"<<endl;
	per(i,MAXN,2)if(p[i])
	{
		//cout<<i<<endl;
		if(i%1000000==0)cout<<"FUCK"<<' '<<i<<' '<<mi[i]<<' '<<mk[i]<<endl;
		cnt[mk[i]]+=p[i];
		if(i<=15)cout<<cnt[mk[i]]<<endl;
		p[i/mi[i]]+=p[i];
	}
//	cout<<"FUCK"<<endl;
	int ans=n;
	rep(i,2,MAXN)ans=min(ans,n-cnt[i]);
//	cout<<"FUCK"<<endl;
	cout<<(ans==n?-1:ans)<<endl;
	return 0;
}


