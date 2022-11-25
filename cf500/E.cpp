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
int f[5005][5005][5];
int a[5005];
int main(){
	n=read();
	for1(i,n)
		a[i]=read();
	memset(f,0x3f,sizeof(f));
	for(int i=0;i<=n;i++)
		f[i][0][0]=f[i][0][1]=f[i][0][2]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=(n+1)/2;j++){
			f[i][j][0]=min(f[i-1][j][1],min(f[i-1][j][0],f[i-1][j][2]));
			if(a[i]>a[i-1]&&a[i]>a[i+1])
				f[i][j][1]=f[i-1][j-1][0];
			else if(a[i]<=a[i+1]){
				if(a[i]<=a[i-1]){
					if(i-2>0&&a[i-1]>=a[i-2])
						f[i][j][2]=min(f[i-2][j-1][2],f[i-2][j-1][0])+1;
					else f[i][j][2]=f[i-1][j-1][0]+1+1;
				}
				else f[i][j][2]=f[i-1][j-1][0]+1;
			}
			else if(a[i]<=a[i-1]){
				if(i-2>0&&a[i-1]>=a[i-2])
					f[i][j][1]=min(f[i-2][j-1][2],f[i-2][j-1][0]);
				else f[i][j][1]=f[i-1][j-1][0]+1;
			}
			else f[i][j][1]=f[i-1][j-1][0];
			cout<<i<<" "<<j<<" "<<f[i][j][0]<<" "<<f[i][j][1]<<" "<<f[i][j][2]<<endl;
		}
	for(int i=1;i<=(n+1)/2;i++)
		cout<<min(f[n][i][0],f[n][i][1])<<" ";
	return 0;
}

