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
vector<ll> a[100005];
vector<ll> b[100005];
ll ss[100005];
int t[100005];
int n;
int m;
int minn;
bool cmp(ll x,ll y){
	return x>y;
}
ll judge(int x){
	ll sum=0;
	for1(i,m)
		if(a[i].size()>=x)
			if(b[i][x-1]>0){
				sum+=b[i][x-1];
			}
	return sum;
}
int main(){
	n=read();m=read();minn=200000;
	for1(i,n){
		int s=read(),r=read();
		t[s]++;
		a[s].push_back(r);
	}
	for1(i,m){
		sort(a[i].begin(),a[i].end(),cmp);
		if(t[i]>0){b[i].push_back(a[i][0]);if(b[i][0]>=0)ss[1]+=b[i][0];}
		for(int j=1;j<a[i].size();j++){
			b[i].push_back(b[i][j-1]+a[i][j]);
			if(b[i][j]>0)ss[j+1]+=b[i][j];

		}
	}
	ll ans=0;
	for1(i,n){
		ans=max(ans,ss[i]);
		//cout<<ss[i]<<endl;
	}
	cout<<ans<<endl;
	return 0;
}


