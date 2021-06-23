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
ll a[200005];
int n,sum;
ll ji[200005];
int main(){
	n=read();
	for1(i,n)
		ji[i]=read();
	sort(ji+1,ji+n+1);
	for1(i,n){
		if(ji[i]!=ji[i-1]){
			a[++sum]=1;
		}
		else a[sum]++;
	}
	sort(a+1,a+sum+1);
	ll ans=0;
	for(int i=1;i<=200000;i++){
		for(int j=max(1,sum-20);j<=sum;j++)
			if(a[j]>=i){
				ll tmp=0,now=j,tmp2=i;
				for(int k=j;k<=sum;k++)
					if(a[k]>=tmp2){
						tmp+=tmp2;
						tmp2*=2;
					}
				ans=max(ans,tmp);
				break;
			}
	}
	cout<<ans<<endl;
	return 0;
}


