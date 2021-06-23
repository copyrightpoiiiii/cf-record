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
struct edge{
	int go,next;
}
void insert(int u,int v){
	 e[++tot].go=v;e[tot].next=head[u];head[u]=tot;
	 e[++tot].go=u;e[tot].next=head[v];head[v]=tot;
}
*/
int n,tot;
int a[100005];
int b[100005];
int ji[100005];
int ans[100005][6];
int pre[100005][6],t[100005];
int main(){
	n=read();
	for1(i,n)
		a[i]=read();
	ji[++tot]=1;
	int tt=0;
	for1(i,5)
	ans[1][i]=1;
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			b[i]=0;
			ji[++tot]=i;
		}
		else if(a[i]<a[i-1])
			b[i]=-1;
		else b[i]=1;
		tt+=b[i];
	}
	for(int i=2;i<=n;i++){
		if(b[i]==1){
			for(int j=1;j<=5;j++)
				if(ans[i-1][j]==1){
					for(int k=j+1;k<=5;k++){
						ans[i][k]=1;
						pre[i][k]=j;
					}
				}
		}
		else if(b[i]==-1){
			for(int j=1;j<=5;j++)
				if(ans[i-1][j]==1){
					for(int k=1;k<j;k++){
						ans[i][k]=1;
						pre[i][k]=j;
					}
				}
		}
		else{
			for(int j=1;j<=5;j++)
				if(ans[i-1][j]==1){
					for(int k=1;k<=5;k++)
					if(k!=j){
						ans[i][k]=1;
						pre[i][k]=j;
					}
				}
		}
	}
	int flag=0;
	for1(i,5){
		if(ans[n][i]==1)
			flag=i;
	}
	if(flag==0){
		cout<<"-1"<<endl;
		return 0;
	}
	int now=n;
	while(now>=1){
		t[now]=flag;
		flag=pre[now][flag];
		now--;
	}
	for1(i,n)
		printf("%d ",t[i]);
	return 0;
}


