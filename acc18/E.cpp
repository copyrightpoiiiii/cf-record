#include<bits/stdc++.h>
#define inf 1e13
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
int n;
ll a[200005];
ll b[200005];
bool judge(ll a,ll b){
	if(sqrt(a+b)*sqrt(a+b)!=(a+b))
		return false;
	return true;
}
int main(){
	n=read();
	for1(i,n/2)
		a[i]=read();
	ll now=1;
	
	ll sum=0;
	for(int i=1;i<=n/2;i++){
		while(1){
			if(inf<now*now-sum*sum-a[i]){
				cout<<"No"<<endl;
				return 0;
			}
			else
				if(((ll)sqrt(a[i]+now*now)*(ll)sqrt(a[i]+now*now))==(a[i]+now*now)){
					//cout<<sss<<endl;
					b[i]=now*now-sum*sum;
					
					
					sum=sqrt(a[i]+now*now);
					
					now=sum+1;
					break;
				}
				now++;
			
			//now++;
		}
	}
	cout<<"Yes"<<endl;
	for1(i,n)
		if(i%2==0)
			printf("%I64d ",a[i/2]);
		else printf("%I64d ",b[(i+1)/2]);
	return 0;
}


