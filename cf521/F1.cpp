#include<bits/stdc++.h>
#define inf 6000000000000
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
/*
struct edge{
	int go,next;
}
void insert(int u,int v){
	 e[++tot].go=v;e[tot].next=head[u];head[u]=tot;
	 e[++tot].go=u;e[tot].next=head[v];head[v]=tot;
}
*/
int n,x,K;
ll a[5005];
ll f[5005][5005];
ll t[5005],ans=-1;
int q[5005];
int main(){
	n=read();K=read();x=read();
	for1(i,n)
		a[i]=read();
	for0(i,5001)
		for0(j,5001)
			f[i][j]=-inf;
	f[0][0]=0;
	for(int j=1;j<=x;j++){
		int head=1,tail=1;
		q[1]=0;
		for(int i=1;i<=n;i++){
			while(q[head]+K+1<=i)head++;
			int last=q[head];
			f[i][j]=f[last][j-1]+a[i];
			while(f[i][j-1]>=f[q[tail]][j-1]&&head<=tail)
				tail--;
			q[++tail]=i;
		}
	}
	for(int i=1;i<=K;i++)
		ans=max(ans,f[n-i+1][x]);
	cout<<ans<<endl;
	return 0;
}


