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
int a[1000010],book[1000010],c[1000010];
int main(){
		freopen("input.in","r",stdin);
	freopen("ou.out","w",stdout);
	int T=read();
	while(T--){
		int n=read(),ansa=1,ansb=1000000,flag=0,mxl=0,ji=0,last=0;
		double sum=1e60;
		for(int i=1;i<=n;i++){
			int x=read();
			c[i]=x;
			a[x]++;
			if(a[x]==2){
				a[x]-=2;
				book[++mxl]=x;
			}
		}
		sort(book+1,book+mxl+1);
		for(int i=1;i<mxl;i++)
			if((double)book[i]/book[i+1]+(double)book[i+1]/book[i]<sum){
				sum=(double)book[i]/book[i+1]+(double)book[i+1]/book[i];
				ji=i;
			}
			printf("%d %d %d %d\n",book[ji],book[ji],book[ji+1],book[ji+1]);
			for(int i=1;i<=n;i++)a[c[i]]=0;
	}
	return 0;
}
