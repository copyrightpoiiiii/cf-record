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
int n,r,l;
int a[1005];
int main(){
	n=read();r=read();
	for1(i,n){
		int x=read();
		if(x)a[++l]=i;
	}
	if(l==0){
		cout<<-1<<endl;
		return 0;
	}
	int ans=0,now=1,t=1;
	while(1){
		while(a[t+1]-r+1<=now){
			t++;
			if(t>=l){
				if(now>=a[t]-r+1&&n<=a[t]+r-1){
					cout<<ans+1<<endl;
					return 0;
				}
				else{
					cout<<-1<<endl;
					return 0;
				}
			}
		}
		if(t>=l){
				if(now>=a[t]-r+1&&n<=a[t]+r-1){
					cout<<ans+1<<endl;
					return 0;
				}
				else{
					cout<<-1<<endl;
					return 0;
				}
			}
		if(a[t]-r+1>now){
			cout<<-1<<endl;
			return 0;
		}
		ans++;
		now=a[t]+r;
		if(now>n)
			break;
	}
	cout<<ans<<endl;
	return 0;
}


