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
int n,m;
int a[1005][1005],b[1005][1005];
int fa[6010];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
	n=read();m=read();
	for1(i,n)
		for1(j,m)
			a[i][j]=read();
	for1(i,n)
		for1(j,m)
			b[i][j]=read();
	for(int i=1;i<=2*(n+m+5)+n;i++)
		fa[i]=i;
	for1(i,n)
		for1(j,m){
			int fai=find(i),faj=find(j+n);
			int faif=find(i+n+m),fajf=find(j+n+n+m);
			if(a[i][j]==b[i][j]){
				if(fai==fajf||faj==faif){
					cout<<"Budexing"<<endl;
					return 0;
				}
				else{
					fa[fai]=faj;
					fa[faif]=fajf;
				}
			}
			else{
				if(fai==faj||faif==fajf){
					cout<<"Budexing"<<endl;
					return 0;
				}
				else{
					fa[fai]=fajf;
					fa[faj]=faif;
				}
			}
		}
	cout<<"Koyi"<<endl;
	return 0;
}


