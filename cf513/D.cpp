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
void insert(int u,int v,int w){
	 e[++tot].go=v;e[tot].next=head[u];e[tot].w=w;head[u]=tot;
	 e[++tot].go=u;e[tot].next=head[v];e[tot].w=w;head[v]=tot;
}
*/
set< pair<ll,int> > l;
set< pair<ll,int> > r;
ll a[500005],b[500005];
int n;
int main(){
	n=read();
	for1(i,n){
		ll x=read(),y=read();
		l.insert(make_pair(x,i));
		a[i]=x;b[i]=y;
		r.insert(make_pair(y,i));
	}
	ll ans=n,tot=n;
	while(!l.empty()){
		pair<ll,int> x=*l.begin(),y=*r.begin();
		if(x.second==y.second){
			ans+=max(x.first,y.first);	
			l.erase(x);r.erase(y);	
		}
		else{
			ans+=max(x.first,y.first);
			l.insert(make_pair(a[y.second],++tot));
			r.insert(make_pair(b[x.second],tot));
			a[tot]=a[y.second];b[tot]=b[x.second];
			l.erase(x);r.erase(y);
			l.erase(make_pair(a[y.second],y.second));
			r.erase(make_pair(b[x.second],x.second));
		}
		
		
	}
	cout<<ans<<endl;
	return 0;
}

