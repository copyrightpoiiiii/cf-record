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
void insert(int u,int v,int w){
	 e[++tot].go=v;e[tot].next=head[u];e[tot].w=w;head[u]=tot;
	 e[++tot].go=u;e[tot].next=head[v];e[tot].w=w;head[v]=tot;
}
*/
int n;
int a[200];
int b[200];
int main(){
	n=read();
	for1(i,n){
		char ch=getchar();
		while(ch<'0'||ch>'9')ch=getchar();
		a[i]=ch-'0';
	}
	for1(i,n)
		b[i]=b[i-1]+a[i];
	for(int i=1;i<n;i++){
		int sum=b[i],flag=0;
		int now=i+1,ns=0;
		//cout<<sum<<"ss"<<endl;
		while(1){
			while(now<=n){
				ns+=a[now];
				now++;
				if(ns>=sum)
					break;
			}
			while(now<=n&&a[now]==0&&ns==sum)
				now++;
			if(ns>sum){
				flag=1;
				break;
			}
			else if(now>n&&ns!=sum){
				flag=1;
				break;			
			}
			else ns=0;
			if(now>n)break;
		}
		if(!flag){
			cout<<"YES"<<endl;
			return 0;		
		}
	}
	cout<<"NO"<<endl;
	return 0;
}

