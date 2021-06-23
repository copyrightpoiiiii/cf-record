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
/*
struct edge{
	int go,next;
}
void insert(int u,int v){
	 e[++tot].go=v;e[tot].next=head[u];head[u]=tot;
	 e[++tot].go=u;e[tot].next=head[v];head[v]=tot;
}
*/
int n,m,K;
struct edge{
	int u,v;ll w;
}e[100005];
int fa[100005];
int p[100005],v[100005];
int s[100005],d[100005];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
	n=read();m=read();K=read();
	for1(i,K){
		p[i]=read();
		v[p[i]]=1;
		s[p[i]]=1;
	}
	for1(i,m){
		e[i].u=read();e[i].v=read();e[i].w=read();
	}
	sort(e+1,e+m+1,cmp);
	for1(i,n){
		fa[i]=i;
	}
	ll ans=0;
	for1(i,m){
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx==fy)
			continue;
		else{
			s[fx]+=s[fy];
			fa[fy]=fx;
			if(s[fx]==K){
				ans=e[i].w;
				break;
			}
		}
	}
	for1(i,K)
	 cout<<ans<<" ";
	return 0;
}


