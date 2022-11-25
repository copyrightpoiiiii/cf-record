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
string s;
bool judge(int n,int m){
	if(n*m<s.length())return false;
	else {
		for(int i=1;i<=m;i++){
			int z=n*i;
			if(s.length()-z>=0&&s.length()-z<=n)
				return true;
		}
	}
	return false;
}
void output(int n,int m){
	int shi=0;
	for(int i=1;i<=m;i++){
		int z=n*i;
		if(s.length()-z>=0&&s.length()-z<=n)
		{
			shi=i;
			break;
		}
	}
	int tmp=s.length()-n*shi;
	int now=0;
	for(int i=1;i<=n;i++){
		int j=0;
		for(j=1;j<=shi;j++)
			cout<<s[now++];
		if(tmp>0){
			cout<<s[now++];
			tmp--;j++;
		}
		for(;j<=m;j++)
			cout<<'*';
		cout<<endl;
	}
}
int main(){
	cin>>s;
	for(int i=1;i<=5;i++)
		for(int j=1;j<=20;j++)
			if(judge(i,j)){
				cout<<i<<" "<<j<<endl;
				output(i,j);
				return 0;
			}
	return 0;
}


