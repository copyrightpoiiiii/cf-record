#include<bits/stdc++.h>
#define inf 1000000000
#define maxn 100000+5
#define maxm 5000000+5
#define eps 1e-10
#define mod 1000000007
#define ll long long
#define ull unsigned long long
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
struct edge{
	int go,next;
}
void insert(int u,int v){
	 e[++tot].go=v;e[tot].next=head[u];head[u]=tot;
	 e[++tot].go=u;e[tot].next=head[v];head[v]=tot;
}
*/
int n,m=0,ans;
int a[105],b[105];
ull f[105][10005];
ull C[200][200];
int main()
{
	n=read();f[0][0]=1;C[0][0]=1;
	for1(i,n){
		a[i]=read();
		m+=a[i];
		b[a[i]]++;
	}
	for1(i,n)
		for(int j=m;j>=a[i];j--)
			for1(k,i){
				f[k][j]=f[k][j]+f[k-1][j-a[i]];
	}
	for1(i,n){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<=i-1;j++){
			C[i][j]+=C[i-1][j-1];
			C[i][j]+=C[i-1][j];
		}
	}
	for(int i=1;i<=100;i++)
		for(int j=1;j<=b[i];j++)
			if(C[b[i]][j]==f[j][j*i]){
				if(j>ans)
					ans=j;
			}
	cout<<ans<<endl;
	return 0;
}



