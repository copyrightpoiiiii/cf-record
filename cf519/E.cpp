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
int n,m;
struct stu{
	ll a,b;
	int id;
}c[300005],d[300005];
//ll a[300005],b[300005];
ll f[300005],f2[300005],ans[300005];
bool cmp(stu x,stu y){
	return x.a+y.b<x.b+y.a;
}
int main(){
	n=read();m=read();
	for1(i,n){
		c[i].a=read();c[i].b=read();
		c[i].id=i;
		d[i]=c[i];
		//a[i]=c[i].a;b[i]=c[i].b;
	}
	sort(c+1,c+n+1,cmp);
	for1(i,n){
		f[i]=f[i-1]+c[i].a;
		f2[i]=f2[i-1]+c[i].b;
	}
	for1(i,n){
		ans[c[i].id]=f[i]+f2[n]-f2[i-1];
	}
	for1(i,m){
		int x=read(),y=read();
		ll tmp=min(d[x].a+d[y].b,d[x].b+d[y].a);
		ans[x]-=tmp;ans[y]-=tmp;
	}
	for1(i,n)
		cout<<ans[i]<<" ";
	return 0;
}


