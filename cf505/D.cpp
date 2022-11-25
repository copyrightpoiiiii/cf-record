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
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
ll n,a[maxn];
bool f[705][705][3];
ll t[705][705];
ll gcd(ll a,ll b){
	if(a>b)swap(a,b);
	if(!a)return b;
	else return gcd(b%a,a);
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=n+1;j++){
			t[i][j]=gcd(a[i],a[j]);
			f[i][j][0]=f[i][j][1]=1;
		}
	for(int l=1;l<=n;l++)
		for(int i=1;i+l-1<=n;i++){
			int j=i+l-1;
			f[i][j][0]=f[i][j][1]=0;
			if(i==1)f[i][j][0]=0;
			else{
				for(int k=i;k<=j;k++)
					if(t[i-1][k]>1)
						f[i][j][0]|=(f[i][k-1][1]&&f[k+1][j][0]);
			}
			if(j==n)f[i][j][1]=0;
			else{
				for(int k=i;k<=j;k++)
					if(t[j+1][k]>1)
						f[i][j][1]|=(f[i][k-1][1]&&f[k+1][j][0]);
			}
		}
	bool ans=0;
	for(int i=1;i<=n;i++)ans|=(f[1][i-1][1]&f[i+1][n][0]);
	cout<<(ans?"Yes":"No")<<endl;
	return 0;
}

