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
struct edge{
	int go,next;
}e[400005];
int head[200005],tot,n;
ll ans,cnt;
int son[200005],s[200005];
void insert(int u,int v){
	 e[++tot].go=v;e[tot].next=head[u];head[u]=tot;
	 e[++tot].go=u;e[tot].next=head[v];head[v]=tot;
}
void dfs1(int x,int fa){
	for4(i,x)
		if(y!=fa){
			son[x]++;
			s[x]++;
			dfs1(y,x);
			son[x]+=son[y];
			//cout<<y<<" "<<son[y]<<endl;
			ans+=(son[y]+1)*(n-son[y]-1);
			//cout<<ans<<endl;
		}
}
void dfs2(int x,int fa){
	for4(i,x)
		if(y!=fa){
			cnt+=(n-son[y]-2);
			cnt+=(son[y]);
			dfs2(y,x);
		}
}
int main(){
	freopen("input.txt","r",stdin);
	n=read();
	for1(i,n-1){
		int a=read(),b=read();
		insert(a,b);
	}
	dfs1(1,0);
	//cout<<ans<<endl;
	dfs2(1,0);
	//cout<<cnt<<endl;
	cout<<ans-(cnt/2)<<endl;
	return 0;
}

