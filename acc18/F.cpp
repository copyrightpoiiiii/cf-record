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
int n,t,tt,flag;
int a[500];
void ask(int l,int r){
	cout<<"? "<<l<<" "<<r<<endl;
}
int main(){
	cin>>n>>t;
	tt=t;
	int sum=0;
	//n=read();t=read();
	for(int i=n-1;i>=1;i--){
		int tmp,t2;
		for1(j,20){
			ask(1,i);
			cin>>tmp;
			ask(1,i);
			cin>>tmp;
			t2=tmp;
			if(tmp!=t)
				break;
		}
		tmp=tmp-sum-t;if(tmp!=1){sum=1-sum;a[i+1]=1;}else{sum=-sum-1; a[i+1]=0;}
		tt-=a[i+1];
		t=t2;
		//tmp=tmp-t;
	}
	cout<<"! ";
	a[1]=tt;
	for1(i,n)
		if(a[i]==1)
			cout<<"1";
		else cout<<"0";
	cout<<endl;
	return 0;
}


