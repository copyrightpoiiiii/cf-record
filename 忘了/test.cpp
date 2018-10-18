#include<bits/stdc++.h>
#define inf 1000000000
#define maxn 100000+5
#define maxm 6000000+5
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
}e[maxm];

int head[maxn],tot,cnt[maxn];
int v[maxn],sum,flag;
int n,m;

void insert(int u,int v){
	e[++tot].go=v;e[tot].next=head[u];head[u]=tot;
}

void dfs(int x,int t,int last){
	//if(t>3)return ;
	if(!v[x]){
		v[x]=1;
		cnt[x]=t;
	}
	else {
		if(t-cnt[x]==3){
			flag++;
		//	cout<<x<<endl;
			//cnt[x]=t;
			//t=1;
			return ;
		}
		//v[x]++;
		return ;
	}
	//for(int i=1;i<=n;i++)
	//	cout<<cnt[i]<<" ";
	//cout<<x<<endl;
	for(int i=head[x],y=e[i].go;i;i=e[i].next,y=e[i].go)
		if(y!=last)
			dfs(y,t+1,x);
}

int main(){
	n=read();m=read();
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		insert(x,y);
		insert(y,x);
	}
	for(int i=1;i<=n;i++)
		//{
			//memset(cnt,0,sizeof(cnt));
			//memset(v,0,sizeof(v));
		if(!v[i])
			dfs(i,1,0);
		//}
	//dfs(1,1);
	cout<<flag<<endl;
	//flag/=6;
	if(flag==1)printf("1");
	else printf("0");
	return 0;
}
/*
6 10
1 6
6 5
5 4
4 3
3 1
2 1
2 3
2 4
2 5
2 6
*/

