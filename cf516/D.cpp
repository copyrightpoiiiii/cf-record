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
#define pa pair<int,int>
using namespace std;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
ll readll(){
    ll x=0,f=1;char ch=getchar();
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
	int go,next,w;
}e[40000005];
int d[4003005],head[4003005];
bool v[4003005];
int n,m,r,c,st,tot;
ll x,y;
int mp[2005][2005];
void insert(int u,int v,int w){
	 e[++tot].go=v;e[tot].next=head[u];e[tot].w=w;head[u]=tot;
	 //e[++tot].go=u;e[tot].next=head[v];e[tot].w=w;head[v]=tot;
}
void dijkstra(){
    priority_queue<pa,vector<pa>,greater<pa> >q;
    for(int i=1;i<=n*m+m;i++)d[i]=inf;
    memset(v,0,sizeof(v));
    d[st]=0;q.push(make_pair(0,st));
    while(!q.empty()){
        int x=q.top().second;q.pop();
        if(v[x])continue;v[x]=1;
        for(int i=head[x],y;i;i=e[i].next)
            if(d[x]+e[i].w<d[y=e[i].go]){
                d[y]=d[x]+e[i].w;
                q.push(make_pair(d[y],y));
            }
    }
}
int main(){
	n=read();m=read();
	r=read();c=read();
	x=readll();y=readll();
	for1(i,n)
		for1(j,m){
			char ch=getchar();
			while(ch!='.'&&ch!='*')ch=getchar();
			if(ch=='.')mp[i][j]=-1;
			else mp[i][j]=1;
			if(mp[i][j]==-1){
				if(mp[i][j-1]==-1){
					insert(i*m+j,i*m+j-1,1);
					insert(i*m+j-1,i*m+j,0);
				}
				if(mp[i-1][j]==-1){
					insert(i*m-m+j,i*m+j,0);
					insert(i*m+j,i*m-m+j,0);
				}
			}
		}
	st=m*(r)+c;
	dijkstra();
	int ans=0;
	for1(i,n)
		for1(j,m)
			if(mp[i][j]==-1){
			
			int po=(i)*m+j;	//cout<<i<<" "<<j<<" "<<d[po]<<endl;
			if(d[po]<=x){
				int yu=0;
				if(j<=c){
					yu=j-c+d[po];
				}
				else {
					yu=j-c+d[po];
				}
				//
				//cout<<i<<" "<<j<<" "<<yu<<endl;
				if(yu<=y){
					ans++;
					//
				}
			}
		}
	cout<<ans<<endl;
	return 0;
}


