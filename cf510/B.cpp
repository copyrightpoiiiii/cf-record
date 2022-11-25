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
int n;
struct{
	int w;
	int size;
}a[1005];
int f[1005][100];
int main(){
	n=read();
	for1(i,n){
		a[i].w=read();
		char ch=getchar();
		while(ch!='A'&&ch!='B'&&ch!='C')ch=getchar();
		while(ch=='A'||ch=='B'||ch=='C'){
			if(ch=='A')a[i].size|=(1);
			else if(ch=='B')a[i].size|=(1<<1);
			else if(ch=='C')a[i].size|=(1<<2);
			ch=getchar();
		}
		//cout<<a[i].size<<endl;
	}
	memset(f,0x3f,sizeof(f));
	for(int i=0;i<=n;i++)
		f[i][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=7;j++){
			f[i][j]=min(f[i][j],f[i-1][j]);
			f[i][j|a[i].size]=min(f[i][j|a[i].size],f[i-1][j]+a[i].w);
			//cout<<f[i][j|a[i].size]<<" "<< j <<endl;
		}
	if(f[n][7]==f[n][8])
		cout<<-1<<endl;
	else cout<<f[n][7]<<endl;
	return 0;
}

