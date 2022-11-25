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
int n,tot;
int t[1005];
struct edge{
	int a,b;
}e[2000];
int main(){
	n=read();
	for(int i=1;i<n;i++){
		int x=read(),y=read();
		t[x]++;
		t[y]++;
	}
	for(int i=1;i<n;i++)
		if(t[i]){
			int last=n;
			for(int j=1;j<i;j++)
				if(t[j]==0){
					if(t[i]==1)
						break;
					e[++tot].a=last;
					e[tot].b=j;
					last=j;
					t[i]--;
					t[j]=-1;
				}
			if(t[i]!=1){
				cout<<"NO"<<endl;
				return 0;
			}	
			else {
				e[++tot].a=last;
				e[tot].b=i;
			}
		}
	cout<<"YES"<<endl;
	for1(i,tot)
		cout<<e[i].a<<" "<<e[i].b<<endl;
		for(int i=1;i<n;i++)
			if(t[i]==0)
				cout<<i<<" "<<n<<endl;
	return 0;
}

