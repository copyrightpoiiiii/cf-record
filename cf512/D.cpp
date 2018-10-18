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
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
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
ll n,m,k;
int main(){
	n=read();m=read();k=read();
	ll x=gcd(max(n*m,k),min(n*m,k));
	if(k/x>2){
		cout<<"NO"<<endl;
		return 0;
	}
	else if(k/x==2){
		ll t=k/2;
		for(ll i=1;i<=sqrt(t);i++)
			if(t%i==0){
				ll x1=n%i,x2=m%(t/i),y1=n%(t/i),y2=n%i;
				if(x1==0&&x2==0){
					cout<<"YES"<<endl;
					cout<<0<<" "<<0<<endl;
					cout<<n/i<<" "<<0<<endl;
					cout<<0<<" "<<m/(t/i)<<endl;	
					return 0;	
				}
				else if(y1==0&&y2==0){
					cout<<"YES"<<endl;
					cout<<0<<" "<<0<<endl;
					cout<<n/(t/i)<<" "<<0<<endl;
					cout<<0<<" "<<m/i<<endl;	
					return 0;	
				}
		}
	}
	else{
		ll t=k;
		for(ll i=1;i<=sqrt(t);i++)
			if(t%i==0){
				ll x1=n%i,x2=m%(t/i),y1=n%(t/i),y2=n%i;
				if(x1==0&&x2==0){
					if((n/i)*2>n&&(m/(t/i))*2>m)continue;
					cout<<"YES"<<endl;
					cout<<0<<" "<<0<<endl;
					if((n/i)*2>n)cout<<n/i<<" "<<0<<endl;
					else cout<<2*n/i<<" "<<0<<endl;
					if((n/i)*2<=n)cout<<0<<" "<<m/(t/i)<<endl;
					else 	cout<<0<<" "<<2*m/(t/i)<<endl;
					return 0;	
				}
				else if(y1==0&&y2==0){
					if((m/i)*2>m&&(n/(t/i))*2>n)continue;
					cout<<"YES"<<endl;
					cout<<0<<" "<<0<<endl;
					if((m/i)*2>m)cout<<0<<" "<<m/i<<endl;
					else cout<<0<<" "<<2*m/i<<endl;
					if((m/i)*2<=n)cout<<n/(t/i)<<" "<<0<<endl;
					else 	cout<<2*n/(t/i)<<" "<<0<<endl;
					return 0;	
				}
		}
	}
	return 0;
}

