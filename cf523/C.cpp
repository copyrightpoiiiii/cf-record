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
int n;
int a[100005];
vector<int> ji[100005];
ll f[1000005];
int main(){
	n=read();
	for1(i,n){
		a[i]=read();
		int fi=sqrt(a[i]);
		for(int j=1;j<=fi;j++)
			if(a[i]%j==0){
				ji[i].push_back(j);
				if((a[i]/j)!=j)ji[i].push_back(a[i]/j);
		}
		sort(ji[i].begin(),ji[i].end());
	}
	f[0]=1;
	for(int i=1;i<=n;i++){
		int fi=ji[i].size();
		for(int j=fi-1;j>=0;j--){
			//cout<<ji[i][j]<<endl;
			if(i%2==0){
				f[ji[i][j]]+=f[ji[i][j]-1];
				//cout<<"ss"<<ji[i][j]<<endl;
				f[ji[i][j]]%=mod;
			}
			else {f[ji[i][j]]+=f[ji[i][j]-1];
				f[ji[i][j]]%=mod;
				//cout<<"s"<<ji[i][j]<<endl;
		}
		}
	}
	ll ans=0;
	for1(i,n)
		ans=(ans+f[i])%mod;
	
	cout<<ans<<endl;
	return 0;
}


