#include<bits/stdc++.h>
#define inf 1000000000
#define maxn 300000+5
#define maxm 200000+5
#define eps 1e-10
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
struct edge{
	int go,next;
}e[2*maxm];
int tot,head[maxn],n,l,r,q[maxn],a[maxn];
bool book[maxn];
void insert(int u,int v){
	e[++tot].go=v;e[tot].next=head[u];head[u]=tot;
	e[++tot].go=u;e[tot].next=head[v];head[v]=tot;
}
void bfs(){
	l=0;r=1;
	int now=2;
	q[1]=a[1];
	book[a[1]]=1;
	while(l<=r){
		int x=q[++l];
		int cnt=0;
		for4(i,x)
			if(!book[y]){
				cnt++;
				book[y]=1;
				//cout<<x<<" "<<y<<endl;
			}
		for(int i=now;i<now+cnt;i++)
			if(!book[a[i]]){
				//cout<<now<<endl;
				cout<<"No"<<endl;
				return ;
			}
		for(int i=now;i<now+cnt;i++)
			q[++r]=a[i];
		now+=cnt;
	}
	cout<<"Yes"<<endl;
	return ;
}
int main(){
	n=read();
	for1(i,n-1){
		int x=read(),y=read();
		insert(x,y);
	}
	for1(i,n)
		a[i]=read();
	if(a[1]!=1){
		cout<<"No"<<endl;
		return 0;
	}
	bfs();
	return 0;
}

