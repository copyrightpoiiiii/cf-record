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
void insert(int u,int v,int w){
	 e[++tot].go=v;e[tot].next=head[u];e[tot].w=w;head[u]=tot;
	 e[++tot].go=u;e[tot].next=head[v];e[tot].w=w;head[v]=tot;
}
*/
int n;
ll b[300005];

ll a[300005];
ll c[300005];
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		ll x=read();
		while(x){
			if(x%2==1)b[i]++;
			x/=2;
		}
		//cout<<b[i]<<endl;
	}
	for(int i=1;i<=n;i++){
		a[i]=a[i-1]+b[i];
		c[i]=c[i-1];
		if(a[i]%2==1)
			c[i]++;
	}
	ll tot=0;
	for(int i=1;i<=n;i++){
		ll mx=0,sum=0;
		for(int j=1;j<=100;j++){
			if(i-j+1<=0)
				break;
			//cout<<i<<" "<<i-j+1<<endl;
			mx=max(mx,b[i-j+1]);
			sum+=b[i-j+1];
			//cout<<i<<" "<<j<<" "<<mx<<" "<<sum<<endl;
			if(mx<=(sum/2)&&((sum%2)==0))
				tot++;
		}
		if(i-100>=0){
			//cout<<i-5<<" "<<c[i-5]<<" "<<c[i]<<endl;
			if(a[i]%2==1){
				tot+=c[i-100];
			}
			else tot+=i-99-c[i-100];
		}
	}
	cout<<tot<<endl;
	return 0;
}

