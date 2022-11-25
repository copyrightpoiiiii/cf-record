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
struct edge{
	int u,v,w;
}e[200005];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int n,m;
struct aa{
	int w,id;
	ll ans;
}a[200005];
bool cmp1(aa a,aa b){
	return a.w<b.w;
}
bool cmp2(aa a,aa b){
	return a.id<b.id;
}
int fa[200005];
int su[200005];
int find(int x){
	if(fa[x]==x){
		return x;
	}
	else{
		int tmp=find(fa[x]);
		su[x]=su[tmp];
		return fa[x]=tmp;
	}
}
int main(){
	//ios::sync_with_stdio(false);cin.tie(0);
	n=read();m=read();
	for1(i,n-1){
		e[i].u=read();
		e[i].v=read();
		e[i].w=read();
		fa[i]=i;
		su[i]=1;
	}
	fa[n]=n;su[n]=1;
	for1(i,m){
		a[i].w=read();
		a[i].id=i;
	}
	sort(e+1,e+n,cmp);
	sort(a+1,a+m+1,cmp1);
	int l=1;
	ll sum=0;
	for1(i,m){
		while(e[l].w<=a[i].w&&l<=n-1){
			//cout<<i<<" "<<sum<<endl;
			int x=find(e[l].u),y=find(e[l].v);
			fa[x]=fa[y];
			sum-=(ll)su[x]*(su[x]-1)/2;
			sum-=(ll)su[y]*(su[y]-1)/2;
			su[y]+=su[x];
			sum+=(ll)su[y]*(su[y]-1)/2;
			l++;
		}
		a[i].ans=sum;
	}
	sort(a+1,a+m+1,cmp2);
	for1(i,m){
		printf("%I64d ",a[i].ans);
	}
	return 0;
}



