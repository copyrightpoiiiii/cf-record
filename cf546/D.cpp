#include<bits/stdc++.h>
#define inf 1000000000
#define maxn 500000+5
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
struct edge{
    int go,next;
}e[500005];
int tot,head[maxn];
void insert(int u,int v){
    e[++tot]=(edge){v,head[u]};head[u]=tot;
}
int n,m,sum;
int a[500005];
int s[500005];
int t[500005];
int fin;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	//ios::sync_with_stdio(false);cin.tie(0);
	n=read();m=read();
	for1(i,n)
		a[i]=read(),t[a[i]]=i;
	fin=a[n];
	s[++sum]=n;
	for1(i,m){
		int x,y;
		x=read();y=read();
		insert(x,y);
		//if(x==fin)s[++sum]=t[y];
		if(y==fin)s[++sum]=t[x];
	}
	sort(s+1,s+sum+1);sum--;
	int now=0,tt=0;
	memset(t,0,sizeof(t));
	for(int i=sum;i>=1;i--){
		int ttt=0;
		int r=s[i+1]-1,l=s[i]+1;
		while(l<=r){
			now++;
			t[a[l]]=1;
			l++;
		}
		int tmp=a[s[i]];
		for4(j,tmp)
			if(t[y])
				ttt++;
		if(ttt!=now){
			now++;
			t[tmp]=1;
		}
		else tt++;
	}
	cout<<tt<<endl;
	return 0;
}

