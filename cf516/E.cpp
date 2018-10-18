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
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
ll readll(){
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
string s;
int ss;
int main(){
	int n=read(),now=0;
	ll l=0,r=1e9;
	cout<<0<<" "<<0<<endl;
	cin>>s;
	if(s[0]=='b')now=1;
	if(n==1){
		cout<<1<<" "<<0<<" "<<0<<" "<<1<<endl;
		return 0;
	}
	n--;
	ss=1;
	if(n>2){
		int tt=0;
		cout<<3<<" "<<0<<endl;
		cin>>s;
		if(s[0]=='b')tt=1;
		if(tt==now){
			ss=4;
		}
		else ss=2;
		n--;
	}
	while(n--){
		ll mid=(l+r)/2;int tmp=0;
		cout<<0<<" "<<mid<<endl;
		cin>>s;
		if(s[0]=='b')tmp=1;
		if(tmp!=now)r=mid;
		else l=mid+1;
	}
	cout<<ss<<" "<<0<<" "<<0<<" "<<(l+r)/2<<endl;
	return 0;
}


