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
ll power(ll x,ll y){
	ll t=1;
	for(;y;y>>=1,x=x*x)
		if(y&1)t=t*x;
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
int t;
int main(){
	t=read();
	while(t--){
		ll n=read(),k=read();
		if(n>=(ll)32){
			cout<<"YES "<<n-1<<endl;
		}
		else{
			ll sum=pow(4,n)-1;
			int flag=0;
			sum/=3;//cout<<sum<<endl;
			for(ll mid=0;mid<n;mid++){
				ll sum2=pow(2,n-mid+1)-n+mid-2;
				ll sum3=(pow(4,mid)-1)/3;
				ll sum4=pow(2,n-mid+1)-1;
				sum3*=sum4;
				if(sum2<=k&&k-sum2<=sum-sum2-sum3){
					cout<<"YES "<<mid<<endl;
					flag=1;
					break;
				}
			}
			if(!flag){
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}


