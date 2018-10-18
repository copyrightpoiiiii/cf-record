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
int n;
int a[1000005],b[1000005];
int main(){
	n=read();
	for1(i,n){
		char ch=getchar();
		while(ch!='1'&&ch!='0')ch=getchar();
		if(ch=='1')
			a[i]=1;
		else a[i]=0;
	}
	for1(i,n){
		char ch=getchar();
		while(ch!='1'&&ch!='0')ch=getchar();
		if(ch=='1')
			b[i]=1;
		else b[i]=0;
	}
	int cnt=0,now=1;
	while(now<n){
		if(a[now+1]==b[now]&&a[now]==b[now+1]&&a[now]!=b[now]&&a[now+1]!=b[now+1]){
			cnt++;
			swap(a[now+1],a[now]);
		}
		now++;
	}
	for(int i=1;i<=n;i++)
		if(a[i]!=b[i])
			cnt++;
	cout<<cnt<<endl;
	return 0;
}

