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
int n,cnt;
int a[200005];
int c[200005];
ll s;
map<ll,int> b;
int main(){
	n=read();
	for1(i,n){
		a[i]=read();
		b[a[i]]++;
		s+=a[i];
	}
	for1(i,n){
		ll sum=s-a[i];
		//cout<<sum<<endl;
		//cout<<b[sum/2]<<endl;
		if(sum%2==0){
			if(b[sum/2]>1)
				c[++cnt]=i;
			else if(b[sum/2]==1&&a[i]!=sum/2)
				c[++cnt]=i;
		}
	}
	cout<<cnt<<endl;
	for1(i,cnt)
		printf("%d ",c[i]);
	return 0;
}


