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
ll a,b,mx;
bool book[200005];
int main(){
	a=read();b=read();
	ll n=sqrt((ll)2*(a+b));
	while((n+1)*(n+2)<=(ll)2*(a+b))
		n++;
		while((n)*(n+1)>(ll)2*(a+b))
		n--;
	ll ans=0;
	for(int i=1;i<=n;i++)
		if(ans+i<=a){
			ans+=i;
			book[i]=1;
			mx=i;
		}
		else break;
	if(ans!=a){
		ll cha=a-ans;
		for(int i=1;i<=n;i++)
			if(book[i]&&i+cha>mx){
				book[i]=0;
				book[i+cha]=1;
				break;
			}
		cout<<mx<<endl;
		for1(i,n)
			if(book[i])
				cout<<i<<" ";
		cout<<endl;
		cout<<n-mx<<endl;
		for1(i,n)
			if(!book[i])
				cout<<i<<" ";
	}
	else{
		cout<<mx<<endl;
		for1(i,n)
			if(book[i])
				cout<<i<<" ";
		cout<<endl;
		cout<<n-mx<<endl;
		for1(i,n)
			if(!book[i])
				cout<<i<<" ";
	}
	return 0;
}

