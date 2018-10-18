#include<bits/stdc++.h>
#define inf 1000000000
#define maxn 1000000+5
#define maxm 5000000+5
#define eps 1e-10
#define ll long long
#define for0(i,n) for(int i=0;i<=(n);i++)
#define for1(i,n) for(int i=1;i<=(n);i++)
#define for2(i,x,y) for(int i=(x);i<=(y);i++)
#define for3(i,x,y) for(int i=(x);i>=(y);i--)
#define for4(i,x) for(int i=head[x],y=e[i].go;i;i=e[i].next,y=e[i].go)
using namespace std;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
//ll f[1005];
//ll sum[1005];
ll mod=1000000007;
ll qpow(ll a,ll b){
	if(b==1)return a;
	else{
		ll x=qpow(a,b/2)%mod;
		if(b%2==0)return (x*x)%mod;
		else return (((x*x)%mod)*a)%mod;
	}
}
int main(){
	ll n;
	/*sum[0]=1;
	for(int i=1;i<=1000;i++)
		sum[i]=(i*sum[i-1])%mod;
	for(int i=1;i<=1000;i++){
		ll t=((i-1)*i/2)%mod;
		f[i]=(f[i-1]*i)%mod;
		f[i]+=(t*sum[i-1])%mod;
		f[i]%=mod;
		//cout<<f[i]<<endl;
	}*/
	while(scanf("%lld",&n)!=EOF){
		ll ans=(n-1)*n;
		/*for(int i=1;i<=n;i++){
			ll tmp=0;
			ll t=((i-1)*i/2)%mod;
			tmp=(ans*i)%mod;
			tmp+=(t*last)%mod;
			tmp%=mod;
			ans=tmp;
			last=(last*i)%mod;
		}*/
		if(ans%4==0)printf("%lld\n",ans/4);
		else printf("%lld\n",(ans*qpow(4,1000000005))%mod);
	}
	return 0;
}

