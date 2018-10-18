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
int n,m;
ll k;
ll a[200005];
bool check(int st){
	int sum=0,now=1;
	for(int i=st;i<=n;i++){
			if(sum+a[i]<=k)
				sum+=a[i];
			else{
				sum=a[i];
				now++;
			}
			//cout<<sum<<endl;
		}
	//	cout<<now<<endl;
	if(now<=m)return 1;
	return 0;
}
int main(){
	n=read();m=read();k=read();
	for1(i,n)
		a[i]=read();
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
	//	cout<<mid<<" "<<l<<" "<<r<<endl;
		if(check(mid)){
			ans=max(ans,n-mid+1);
			r=mid-1;
		}
		else l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}


