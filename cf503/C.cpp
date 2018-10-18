#include<bits/stdc++.h>
#define inf 1000000000
#define maxn 100000+5
#define maxm 5000000+5
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
int a[200000],book[200000];
int n,step;
void dfs(int w){
	if(w>n)return ;
	else{
		a[w]=w;
		dfs(w<<1);
		dfs(w<<1|1);
	}
}
int main(){
	n=read();
	int tmp=n;
	dfs(1);
	step=sqrt(n);
	while(tmp>=1){
		int tmp2=max(tmp-step+1,1);
		for(int i=tmp2;i<=tmp;i++)
			cout<<i<<" ",book[i]=1;
		tmp-=step;
	}
	for(int i=1;i<=n;i++)
		if(!book[i])
			cout<<i<<" "<<endl;
	return 0;
}

