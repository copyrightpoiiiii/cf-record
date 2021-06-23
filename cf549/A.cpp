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
#define pr1(i,x) cout<<i<<" "<<x<<endl
#define pr(x) cout<<x<<endl;
using namespace std;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
inline bool is_down(char x) { return ('a' <= x && x <= 'z'); }
inline bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
inline bool is_digit(char x) { return ('0' <= x && x <= '9'); }
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
inline ll readll(){
	ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
long long gcd(long long x,long long y){return y?gcd(y,x%y):x;}
long long power(long long x,long long y){
	long long t=1;
	for(;y;y>>=1,x=x*x%mod)
		if(y&1)t=t*x%mod;
	return t;
}
/*strcut edge{
    int go,next;
}e[2*maxm];
int tot,head[maxn];
void insert(int u,int v){
    e[++tot]=(edge){v,head[u]};head[u]=tot;
    e[++tot]=(edge){u,head[v]}lhead[v]=tot;
}*/
ll n,k;
ll a,b;
ll ss,mm;
int main(){
	//ios::sync_with_stdio(false);cin.tie(0);
	n=read();k=read();
	a=read();b=read();
	ss=n*k+1;
	ll s=a+1;
	for1(i,n){
		ll t1=(i-1)*k+b+1,t2=i*k+1-b;
		ll l1=(t1-s+n*k)%(n*k),l2=(t2-s+n*k)%(n*k);
		if(!l1)l1=n*k;
		if(!l2)l2=n*k;
		//cout<<l1<<" "<<l2<<endl;
		ll gc1=gcd(l1,n*k),gc2=gcd(l2,n*k);
		ll tm1=n*k/gc1,tm2=n*k/gc2;
		if(tm1<tm2)swap(tm1,tm2);
		ss=min(ss,tm2);
		mm=max(mm,tm1);
		l1=n*k-l1;l2=n*k-l2;
		if(!l1)l1=n*k;
		if(!l2)l2=n*k;
		gc1=gcd(l1,n*k);gc2=gcd(l2,n*k);
		tm1=n*k/gc1;tm2=n*k/gc2;
		if(tm1<tm2)swap(tm1,tm2);
		ss=min(ss,tm2);
		mm=max(mm,tm1);
	}
	s=k+1-a;
		for1(i,n){
		ll t1=(i-1)*k+b+1,t2=i*k+1-b;
		ll l1=(t1-s+n*k)%(n*k),l2=(t2-s+n*k)%(n*k);
		if(!l1)l1=n*k;
		if(!l2)l2=n*k;
		ll gc1=gcd(l1,n*k),gc2=gcd(l2,n*k);
		ll tm1=n*k/gc1,tm2=n*k/gc2;
		if(tm1<tm2)swap(tm1,tm2);
		ss=min(ss,tm2);
		mm=max(mm,tm1);
		l1=n*k-l1;l2=n*k-l2;
		if(!l1)l1=n*k;
		if(!l2)l2=n*k;
		gc1=gcd(l1,n*k);gc2=gcd(l2,n*k);
		tm1=n*k/gc1;tm2=n*k/gc2;
		if(tm1<tm2)swap(tm1,tm2);
		ss=min(ss,tm2);
		mm=max(mm,tm1);
	}
	cout<<ss<<" "<<mm;
	return 0;
}

