#include<bits/stdc++.h>
#define inf 1000000000
#define maxn 200000
#define maxm 10
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
ll n,k;
ll a[200005];
ll b[200005];
int main(){
	n=read();k=read();
	if(n==1){
		cout<<"0"<<endl;
		return 0;
	}
	for1(i,n)
		a[i]=read();
	sort(a+1,a+n+1);
		if(a[1]==a[n]){
		cout<<"0"<<endl;
		return 0;
	}
	for1(i,n){
		b[1+a[i]]--;b[1]++;
	}
	ll ans=1,last=0;
	for1(i,maxn)
		b[i]+=b[i-1];
	for(int i=maxn;i>=1;i--){
		if(i==a[1])break;
		if(k<b[i]+last){
				ans++;
			last=b[i];
		}
		else{
			last+=b[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}


