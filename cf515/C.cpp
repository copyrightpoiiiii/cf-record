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
int n;
int l[200005],r[200005];
int a[200005],s[200005];
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		char ch=getchar();
		while(ch!='L'&&ch!='R'&&ch!='?')ch=getchar();
		int x=read();
		l[i]=l[i-1];
		r[i]=r[i-1];
		if(ch=='L'){
			a[x]=i;
			s[x]=1;
			l[i]++;
		}
		else if(ch=='R'){
			a[x]=i;
			s[x]=0;
			r[i]++;
		}
		else{
			int fi=a[x];
			int al=0,ar=0;
			if(s[x]==1)
				al=l[i]-l[fi],ar=l[fi-1]+r[i];
			else al=r[fi-1]+l[i],ar=r[i]-r[fi];
			cout<<min(al,ar)<<endl;
		}
	}
	return 0;
}


