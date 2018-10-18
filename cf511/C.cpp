#include<bits/stdc++.h>
#define inf 15000005
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
int n,tot;
int a[300005];
int p[15000005];
int ji[15000005],ji2[inf];
int check[15000005];
int main(){
	n=read();
	int mx=0;
	int gc,flag=1;
	for1(i,n){
		a[i]=read();
		mx=max(mx,a[i]);
		if(i==1)gc=a[i];
		else gc=gcd(gc,a[i]);
		if(a[i]!=1)flag=0;
	}
	if(flag){
		cout<<"-1"<<endl;
		return 0;
	}
	for1(i,n)
		a[i]/=gc;
	for(ll i=2;i<=inf-5;i++){
		if(!check[i]){p[++tot]=i;ji2[i]=i;ji[i]=i;}
		for(ll j=1;j<=tot;j++){
		 	ll k=p[j]*i;
		 	if(k>inf)break;
		 	check[k]=1;
		 	//if(!ji[k])ji[k]=p[j];
		 	if((i%p[j])!=0){
		 		ji[k]=p[j];
				if(ji[k]!=ji[k/p[j]])ji2[k]=p[j];
				else ji2[k]=ji2[k/p[j]]*p[j];
			}else{
				ji[k]=p[j];
				ji2[k]=p[j]*ji2[i];
				break;
			}
		    
		 }
	}
	memset(p,0,sizeof(p));
	memset(check,0,sizeof(check));
	int tot2=0;
	for(int i=1;i<=n;i++){
		//cout<<ji[a[i]]<<ji2[a[i]]<<a[i]<<endl;
		check[a[i]]++;
	}
		for(int i=inf-5;i>=2;i--)
			if(check[i]){
				//int now=ji[i],now2=i/ji2[i];
			p[ji[i]]+=check[i];check[i/ji2[i]]+=check[i];
		//	if(i<=15)cout<<ji[i]<<p[ji[i]]<<endl;
		tot2=max(tot2,p[ji[i]]);
	}
	//for(int i=2;i<=inf;i++)
	//	tot2=max(tot2,p[i]);
	if(tot2==0)cout<<"-1"<<endl;
	else cout<<n-tot2<<endl;
	return 0;
}

