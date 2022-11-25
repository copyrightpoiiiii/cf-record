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
int a[100005],b[100005];
int q[100005];
int f[100005];
int n,flag;
int main(){
	n=read();
	for1(i,n){
		a[i]=read();
		b[a[i]]=i;
	}
	f[n]=-1;
	for(int i=n;i>0;i--){
		//cout<<i<<" "<<"ss"<<endl;
		int now=b[i]+i;
		flag=0;
		while(now<=n){
			//cout<<now<<endl;
			if(a[now]>i&&f[a[now]]==-1){
				flag=1;
				break;
			}
			now+=i;
		}
		now=b[i]-i;
		while(now>0){
			//cout<<now<<endl;
			if(a[now]>i&&f[a[now]]==-1){
				flag=1;
				break;
			}
			now-=i;
		}
		if(flag==1){
			f[i]=1;
		}
		else f[i]=-1;
	}
	for1(i,n){
		if(f[a[i]]==1)
			cout<<"A";
		else cout<<"B";
		//cout<<f[a[i]]<<endl;
	}
	return 0;
}

