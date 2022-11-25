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
#define pr1(i,x) cout<<i<<" "<<x<<endl
#define pr(x) cout<<x<<endl;
using namespace std;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
inline bool is_down(char x) { return ('a' <= x && x <= 'z'); }
inline bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
inline bool is_digit(char x) { return ('0' <= x && x <= '9'); }
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
inline ll readll(){
	ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
long long gcd(long long x,long long y){return y?gcd(y,x%y):x;}
long long power(long long x,long long y){
	long long t=1;
	for(;y;y>>=1,x=x*x%mod)
		if(y&1)t=t*x%mod;
	return t;
}
struct edge{
    int go,next;
}e[2*maxm];
int n,m;
int mp[1005][1005];
int f[2005];
int a[1005][1005];
int b[2005][2005];
int v[2005],v2[2005];
int in[2005];
int val[2005];
int tot,head[maxn];
void insert(int u,int v){
    e[++tot]=(edge){v,head[u]};head[u]=tot;
}
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
void topsort(){
	int q[2005];
	int l=0,r=0;
	for(int i=1;i<=n+m;i++)
		if(in[i]==0&&find(i)==i){
			val[i]=1;
			q[++r]=i;
			//sum++;
		}
	while(l!=r){
		//cout<<"fuck"<<endl;
		int x=q[++l];
		v2[x]=1;
		//cout<<x<<endl;
		for4(i,x){
			in[y]--;
			val[y]=max(val[y],val[x]+1);
			if(in[y]==0){
				val[y]=max(val[y],val[x]+1);
				q[++r]=y;
				//sum++;
			}
		}
	}
}
int main(){
	//ios::sync_with_stdio(false);cin.tie(0);
	n=read();m=read();
	for(int i=1;i<=2004;i++)
		f[i]=i;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			char ch=getchar();
			while(ch!='<'&&ch!='>'&&ch!='=')ch=getchar();
			if(ch=='>')mp[i][j]=1;
			else if(ch=='<')mp[i][j]=-1;
			else{
				f[find(i)]=find(n+j);
			}
		}
	for1(i,n)
		for1(j,m)
			if(mp[i][j]==1){
				int x=find(i),y=find(j+n);
					insert(y,x);
					in[x]++;
			}
			else if(mp[i][j]==-1){
				int x=find(i),y=find(j+n);
					insert(x,y);
					in[y]++;
			}
	topsort();
	for(int i=1;i<=n+m;i++)
		if((!v2[i])&&(find(i)==i)){
			//cout<<i<<endl;
			cout<<"No"<<endl;
			return 0;
		}
		cout<<"Yes"<<endl;
		for(int i=1;i<=n;i++)
			cout<<val[find(i)]<<" ";
		cout<<endl;
		for(int i=1;i<=m;i++)
			cout<<val[find(i+n)]<<" ";
	return 0;
}

