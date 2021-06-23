#include<bits/stdc++.h>
#define inf 1e10
#define maxn 100000+5
#define maxm 5000000+5
#define eps 1e-10
#define mod 1000000007
#define ll long long
#define pa pair<int,int>
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
	int go,next,w,id;
}e[600005];
int ans[300005];
int n,m,K,tot,sum;
ll d[300005],head[300005];
int t[300005];
ll d2[300005];
bool v[300005];
int book[300005];
void insert(int u,int v,int w,int z){
	 e[++tot].go=v;e[tot].next=head[u];head[u]=tot;e[tot].w=w;e[tot].id=z;
	 e[++tot].go=u;e[tot].next=head[v];head[v]=tot;e[tot].w=w;e[tot].id=z;
}
void dijkstra(){
	int tmp=0;
    priority_queue<pa,vector<pa>,greater<pa> >q;
    for(int i=1;i<=n;i++)d[i]=(ll)inf*(ll)inf;
    memset(v,0,sizeof(v));
    d[1]=0;q.push(make_pair(0,1));
    while(!q.empty()){
        int x=q.top().second;q.pop();
        if(v[x])continue;v[x]=1;
        for(int i=head[x],y;i;i=e[i].next)
            if(d[x]+e[i].w<d[y=e[i].go]){
                d[y]=d[x]+e[i].w;
                q.push(make_pair(d[y],y));
            }
        t[++tmp]=x;
    }
}
void dijkstra2(){
	memset(v,0,sizeof(v));
    v[1]=1;
    for1(i,n){
		int x=t[i];
		for4(j,x)
			if(!v[y]&&d[y]==d[x]+e[j].w){
				ans[e[j].id]=1;
				sum++;
				v[y]=1;
				if(sum==K)return ;
			}
	}
}
int main(){
	n=read();m=read();K=read();
	for1(i,m){
		int u=read(),v=read(),w=read();
		insert(u,v,w,i);
	}
	dijkstra();
	dijkstra2();
	cout<<sum<<endl;
	for1(i,m)
	if(ans[i])
		printf("%d ",i);	
	return 0;
}


