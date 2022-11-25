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
int n;
struct te{
	ll fa,x;
};
map<ll,ll> a;
map<ll,ll> b;
ll last;
ll find2(ll x1){
	if(a[x1]==x1)return x1;
	else{
		ll te=a[x1];
		a[x1]=find2(a[x1]);
		b[x1]^=b[te];
		return a[x1];
	}
}
void merge(ll x,ll y){
	ll faa=find2(x),fab=find2(y);
	a[faa]=fab;
	b[faa]=b[faa]^b[y];
}
int main(){
	n=read();
	for1(i,n){
		int t=read();
		if(t==1){
			ll l=read()^last,r=read()^last,x1=read()^last;
			if(a.find(l-1)==a.end()){
				a[l-1]=l-1;
				b[l-1]=0;
			}
			if(a.find(r)==a.end()){
				a[r]=r;
				b[r]=x1;
			}
			merge(r,l-1);
		}
		else {
			ll l=read()^last,r=read()^last;
			if(a.find(l-1)!=a.end()&&a.find(r)!=a.end()&&find2(l-1)==find2(r)){
				printf("%lld\n",b[l-1]^b[r]);
				last=b[l-1]^b[r];
			}
			else {printf("-1\n");last=1;}
		}
	}
	return 0;
}


