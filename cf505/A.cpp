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
int a[100];
int main(){
	int n=read();
	if(n==1){
		cout<<"Yes";
		return 0;
	}
	for(int i=1;i<=n;i++){
		char ch=getchar();
		while(ch<'a'||ch>'z')ch=getchar();
		a[ch-'a']++;
	}
	int flag=0;
	for(int i=0;i<=26;i++)
		if(a[i]>1)
			flag=1;
	if(flag)cout<<"Yes";
	else cout<<"No";
	return 0;
}

