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
ll n,k,m;
ll a[500005];
ll b[500005];
int main(){
	//ios::sync_with_stdio(false);cin.tie(0);
	n=read();k=read();m=read();
	for1(i,n)
		a[i]=read();
	sort(a+1,a+n+1);
	for1(i,n)
		b[i]=b[i-1]+a[i];
	double ans=0,sum=0;
	for(int i=1;i<=n;i++){
		sum=b[n]-b[i-1];
		double sum2=0;
		ll last=m-i+1;
		if(k*(n-i+1)>=last)sum2=last;
		else sum2=k*(n-i+1);
		sum+=sum2;
		//cout<<sum2<<" "<<endl;
		ans=max(ans,sum/((double)n-i+1));
	}
	printf("%.20lf",ans);
	return 0;
}
