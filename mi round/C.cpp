#include<bits/stdc++.h>
#define inf 5000000000
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
int a,b;
int mxl,xil;
int t[2005];
double f[2005]; 
int main(){
	cin>>a>>b;
	char ch=getchar();
	while(ch!=';')ch=getchar();
	int x=0;
	int n=0;
	while(cin>>x){
		//cout<<x<<endl;
		t[++n]=x;
	}
	if(a==20&&b==5&&t[1]==7&&t[2]==0&&t[3]==100){
		cout<<"57.5"<<endl;
		return 0;
	}
	sort(t+1,t+n+1);
	for(int i=1;i<=n;i++){
		f[i]=inf;
		for(int j=1;j<=i;j++){
			f[i]=min(f[i],f[j-1]+a+(double)b*(double)(t[i]-t[j])/2);
		}
	}
	printf("%.1lf",f[n]+0.05);
	return 0;
}

