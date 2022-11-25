#include<bits/stdc++.h>
#define inf 1000000000
#define maxn 100000+5
#define maxm 5000000+5
#define eps 1e-10
#define mod 998244353
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
inline ll read(){
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
/*
struct edge{
	int go,next;
}e[2*maxn];
void insert(int x,int y){
	e[++tot]=(edge){y,head[x]};head[x]=tot;
	e[++tot]=(edge){x,head[y]};head[y]=tot;
}
*/
int n;
int a[300005];
int b[300005];
ll jie[300005];
ll suma,sumb,sumc;
struct num{
	int x,y;
}c[300005];
bool cmp(num xx,num yy){
	if(xx.x!=yy.x)
		return xx.x<yy.x;
	else return xx.y<yy.y;
}
int main(){
	//ios::sync_with_stdio(false);cin.tie(0);
	n=read();
	jie[0]=1;
	for1(i,n){
		c[i].x=read();
		c[i].y=read();
		a[c[i].x]++;
		b[c[i].y]++;
		jie[i]=(jie[i-1]*i)%mod;
	}
	suma=1;sumb=1;
	for1(i,n){
		suma=(suma*jie[a[i]])%mod;
		sumb=(sumb*jie[b[i]])%mod;
	}
	sort(c+1,c+n+1,cmp);
	int st=1,stb=1,sumt=0;
	ll tmp=1,tmp2=1;
	for(int i=1;i<=n;i++){
		if(c[i].x==c[st].x){
			if(c[i].y==c[stb].y){
				sumt++;
			}
			else{
				tmp=(tmp*jie[sumt])%mod;
				sumt=1;
				stb=i;
			}
		}
		else{
			tmp=(tmp*jie[sumt])%mod;
			tmp2=(tmp2*tmp)%mod;
			st=i;stb=i;sumt=1;
			tmp=1;
			if(c[i-1].y>c[i].y)
				tmp2=0;
		}
	}
	//cout<<suma<<" "<<sumb<<" "<<tmp2<<endl;
	cout<<jie[n]-suma-sumb+tmp2;
	return 0;
}



