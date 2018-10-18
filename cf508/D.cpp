#include<bits/stdc++.h>
#define inf 1000000005
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
ll a[500005];
ll miz[500005],miy[500005];
ll sumz[500005],sumy[500005];
ll aa[500005];
bool cz[500005],cy[500005];
ll ansz[500005],ansy[500005];
int main(){
	string s;
	cin>>s;
	cout<<s<<endl;
	cout<<"²âÊÔ"; 
	n=read();
	miz[0]=inf;
	for1(i,n){
		a[i]=read();
		if(a[i-1]<0)cz[i]=1;
		else cz[i]=cz[i-1];
		aa[i]=abs(a[i]);
		ansz[i]=aa[i-1]+ansz[i-1];
		miz[i]=min(miz[i-1],aa[i]);
		//cout<<miz[i]<<endl;
		//sumz[i]=sumz[i-1]+a[i-1];
		//cout<<sumz[i]<<endl;
	}
	miy[n+1]=inf;
	for(int i=n;i>=1;i--){
		if(a[i+1]<0)cy[i]=1;
		else cy[i]=cy[i+1];
		miy[i]=min(miy[i+1],aa[i]);
		//cout<<miy[i]<<endl;
		//sumy[i]=sumy[i+1]+a[i+1];
		ansy[i]=aa[i+1]+ansy[i+1];
		//cout<<sumy[i]<<endl;
	}
	//miz[0]=miy
	ll ans=-inf;
	if(cy[1]){
		ans=ansy[1]+a[1];
	}
	else{
		ans=ansy[1]-miy[2]-miy[2]+a[1];
	}
	if(cz[n]){
		ans=max(ans,ansz[n]+a[n]);
	}
	else{
		ans=max(ans,ansz[n]-miz[n-1]-miz[n-1]+a[n]);
	}
	for(int i=2;i<n;i++){
		ll tmpz=0,tmpy=0;
		if(cz[i]){
			tmpz=ansz[i];
			
		}//ÄãºÃ 
		else{
			tmpz=ansz[i]-miz[i-1]-miz[i-1];
		}
		if(cy[i]){
			tmpy=ansy[i];
		}
		else{
			tmpy=ansy[i]-miy[i-1]-miy[i-1];
		}
		ans=max(ans,tmpz+tmpy+a[i]);
	}
	cout<<ans<<endl;
	return 0;
}
