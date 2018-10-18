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
int n,m;
long double a[1005],b[1005];
long double c[2010];
int main(){
	n=read();m=read();
	int flag=0;
	for1(i,n){
		a[i]=read();
		if(a[i]==1){
			cout<<"-1"<<endl;
			return 0;
		}
	}
	for1(i,n){
		b[i]=read();
		if(b[i]==1){
			cout<<"-1"<<endl;
			return 0;
		}
	}
	long double now=(long double)m;
	int tot=0;
	c[++tot]=b[1];
	long double need=now/(c[tot]-1);
	now+=need;
	for(int i=n;i>1;i--){
		c[++tot]=a[i];
		need=now/(c[tot]-1);
		now+=need;
		c[++tot]=b[i];
		need=now/(c[tot]-1);
		now+=need;
	}
	c[++tot]=a[1];
	need=now/(c[tot]-1);
	now+=need;
	//cout<<now-m<<endl;
	printf("%.10Lf",(long double)now-(long double)m);
	return 0;
}

