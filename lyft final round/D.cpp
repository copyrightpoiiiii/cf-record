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
}e[5000];
int tot,head[1005];
void insert(int u,int v){
	 e[++tot].go=v;e[tot].next=head[u];head[u]=tot;
	 e[++tot].go=u;e[tot].next=head[v];head[v]=tot;
}

int T;
int n,an,bn;
int a[1005],b[1005],ji[1005];
bool book[1005];
void init(){
	memset(e,0,sizeof(e));
	memset(head,0,sizeof(head));
	memset(book,0,sizeof(book));
	memset(ji,0,sizeof(ji));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	tot=0;
	cin>>n;
	for1(i,n-1){
		int u,v;
		cin>>u>>v;
		insert(u,v);
	}
	an=read();
	for1(i,an){
		int x;
		cin>>x;
		a[x]=1;
	}
	bn=read();
	for1(i,bn){
		cin>>b[i];
		ji[b[i]]=1;
	}
}
void bfs(int y){
	queue<int> q;
	q.push(y);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for4(i,x)
			if(!book[y]){
				q.push(y);
				if(a[y]==1){
					cout<<"A "<<y<<endl;
					int ss;
					cin>>ss;
					if(!ji[ss])cout<<"C -1"<<endl;
					else cout<<"C "<<y<<endl;
					return ;
				}
				book[y]=1;
			}
	}
}
int main(){
	cin>>T;
	while(T--){
		init();
		int x1=rand()%bn+1;
		cout<<"B "<<b[x1]<<endl;
		int st;
		cin>>st;
		if(a[st]==1){
			cout<<"C "<<st<<endl;
		}
		else bfs(st);
	}
	return 0;
}


