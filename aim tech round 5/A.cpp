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
int n,m;
int a[200][200];
int c[200][200],d[200][200];
int main(){
	n=read();m=read();
	for1(i,n)
		for1(j,m){
			char ch=getchar();
			while(ch!='W'&&ch!='B')ch=getchar();
			if(ch=='W')a[i][j]=0;
			else a[i][j]=1;
			c[i][j]=c[i][j-1]+a[i][j];
			d[i][j]=d[i-1][j]+a[i][j];
		}
	for1(i,n)
		for1(j,m)
		if(c[i][j]){
			if(c[i][j-1]==(c[i][m]-1)/2){
				if(d[i-1][j]==(d[n][j]-1)/2){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}
	return 0;
}

