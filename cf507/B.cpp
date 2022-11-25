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
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int n,k;
int a[2000];
int ans[2000005];
/*
void insert(int u,int v,int w){
	 e[++tot].go=v;e[tot].next=head[u];e[tot].w=w;head[u]=tot;
	 e[++tot].go=u;e[tot].next=head[v];e[tot].w=w;head[v]=tot;
}
*/
int main(){
	n=read();k=read();
	int last=n%(2*k+1);
	int cnt=0;
	if(last>k+1){
		ans[++cnt]=n-(last-k)+1;
		int now=k+1;
		for(int i=1;i<=n/(2*k+1);i++){
			ans[++cnt]=now;
			now+=2*k+1;
		}
	}
	else if(last==n){
		cout<<1<<endl;
		cout<<1+(n/2)<<endl;
		return 0;
	}
	else if(last!=0){
		int la=last/2+k+1,lb=last-(last/2)+k;
		ans[++cnt]=1+(last/2);
		ans[++cnt]=n-last+(last/2)+1;
		int now=la+1+k;
		for(int i=1;i<=(n/(2*k+1))-1;i++){
			ans[++cnt]=now;
			now+=2*k+1;
		}
	}
	else{
		int now=k+1;
		for(int i=1;i<=(n/(2*k+1));i++){
			ans[++cnt]=now;
			now+=2*k+1;
		}
	}
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++)	
		printf("%d ",ans[i]);
	return 0;
}

