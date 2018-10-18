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
int n,m;
int a[1005][1005];
int b[1005][1005];
bool judge(int x,int y){
	if(x+1>n||x+2>n)
		return 0;
	if(y+1>m||y+2>m)
		return 0;
	int tmp=a[x][y]+a[x+1][y]+a[x+2][y]+a[x][y+1]+a[x][y+2];
	tmp+=a[x+2][y+1]+a[x+1][y+2]+a[x+2][y+2];
	if(tmp==8)return 1;
	else return 0;
}
void change(int x,int y){
	b[x][y]=b[x+1][y]=b[x+2][y]=1;
	b[x][y+1]=b[x+2][y+1]=1;
	b[x][y+2]=b[x+1][y+2]=b[x+2][y+2]=1;
}
int main(){
	n=read();m=read();
	for1(i,n)
		for1(j,m){
			char ch=getchar();
			while(ch!='#'&&ch!='.')ch=getchar();
			if(ch=='.')a[i][j]=0;
			else a[i][j]=1;
		}
	for1(i,n)
		for1(j,m){
			if(judge(i,j))
				change(i,j);	
		}
	for1(i,n)
		for1(j,m)
			if(a[i][j]!=b[i][j]){
				cout<<"NO"<<endl;
				return 0;
			}
	cout<<"YES"<<endl;
	return 0;
}

