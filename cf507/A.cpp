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
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
int gcd(int x,int y){return y?gcd(y,x%y):x;}

/*
void insert(int u,int v,int w){
	 e[++tot].go=v;e[tot].next=head[u];e[tot].w=w;head[u]=tot;
	 e[++tot].go=u;e[tot].next=head[v];e[tot].w=w;head[v]=tot;
}
*/
int n,a,b;
int t[1000];
int main(){
	n=read();a=read();b=read();
	for1(i,n)
		t[i]=read();
	int l=1,r=n;
	int cnt=0;
	while(l<r){
		if(t[l]!=t[r]){
			if(t[l]==2){
				if(t[r]==0)cnt+=a;
				else cnt+=b;
			}
			else if(t[r]==2){
				if(t[l]==0)cnt+=a;
				else cnt+=b;
			}
			else{
				cout<<"-1"<<endl;
				return 0;
			}
		}
		else if(t[l]==2){
			cnt+=min(a,b)*2;
		}
		l++;r--;
	}
	if(n%2==1&&t[1+(n/2)]==2)
		cnt+=min(a,b);
	cout<<cnt<<endl;
	return 0;
}

