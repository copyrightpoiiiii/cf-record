#include<bits/stdc++.h>
#define inf 1000000000
#define maxn 100000+5
#define maxm 5000000+5
#define eps 1e-10
#define mod 998244353
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
ll f[1005][2005][5];
int n,k;
int main(){
	n=read();k=read();
	f[1][1][0]=f[1][1][3]=1;
	f[1][2][1]=f[1][2][2]=1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=k;j++){
			f[i][j][0]=(f[i-1][j][0]+f[i-1][j][1]+f[i-1][j][2]+f[i-1][j-1][3])%mod;
			f[i][j][3]=(f[i-1][j-1][0]+f[i-1][j][1]+f[i-1][j][2]+f[i-1][j][3])%mod;
			f[i][j][1]=(f[i-1][j][1]+f[i-1][j-1][0]+f[i-1][max(0,j-2)][2]+f[i-1][j-1][3])%mod;
			f[i][j][2]=(f[i-1][j][2]+f[i-1][j-1][0]+f[i-1][max(0,j-2)][1]+f[i-1][j-1][3])%mod;
		}
		/*else{
			f[i][j][0]=(f[i-1][j][0]+f[i-1][j][1]+f[i-1][j][2]+f[i-1][j-1][3])%mod;
			f[i][j][3]=(f[i-1][j-1][0]+f[i-1][j][1]+f[i-1][j][2]+f[i-1][j][3])%mod;
			f[i][j][1]=(f[i-1][j][1]+f[i-1][j-1][0]+f[i-1][j-2][2]+f[i-1][j-1][3])%mod;
			f[i][j][2]=(f[i-1][j][2]+f[i-1][j-1][0]+f[i-1][j-2][1]+f[i-1][j-1][3])%mod;
		}*/
	ll ans=0;
	for(int i=0;i<=3;i++)
		ans+=f[n][k][i];
	cout<<ans%mod<<endl;
	return 0;
}

