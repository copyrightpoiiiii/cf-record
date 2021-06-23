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
ll read(){
    ll x=0,f=1;char ch=getchar();
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
double ans;
double fabs(double tmp){
	return tmp<0?-tmp:tmp;}
double dis(double x,double y,double z,double zz){
	return sqrt((x-z)*(x-z)+(y-zz)*(y-zz));
}
int main(){
	double a,b,c;
double x1,y1,x2,y2;
	cin>>a>>b>>c;
	cin>>x1>>y1>>x2>>y2;
	ans=abs(x1-x2)+abs(y1-y2);
	if(a==0||b==0){
		printf("%.10f",ans);
		return 0;
	}
	double a1=x1,b1=(-c-a*x1)/b;
	double a2=(-c-b*y1)/a,b2=y1;
	double c1=x2,d1=(-c-a*x2)/b;
	double c2=(-c-b*y2)/a,d2=y2;
	double tmp=fabs(b1-y1)+fabs(d1-y2)+dis(a1,b1,c1,d1);
	ans=min(tmp,ans);
	tmp=fabs(b1-y1)+fabs(c2-x2)+dis(a1,b1,c2,d2);
	ans=min(tmp,ans);
	tmp=fabs(a2-x1)+fabs(c2-x2)+dis(a2,b2,c2,d2);
	ans=min(tmp,ans);
	tmp=fabs(a2-x1)+fabs(d1-y2)+dis(a2,b2,c1,d1);
	ans=min(tmp,ans);
	printf("%.10f",ans);
	return 0;
}


