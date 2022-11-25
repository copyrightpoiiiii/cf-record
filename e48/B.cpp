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
string s,t;
int n,m,q;
int a[2000];
int main(){
	n=read();m=read();q=read();
	//char ch=getchar();
	getline(cin,s);
	getline(cin,t);
	for(int i=m+1;i<=n+1;i++){
		a[i-1]=a[i-2];
		string tmp=s.substr(i-m-1,m);
		//cout<<tmp<<endl;
		if(tmp==t)
			a[i-1]++;
			//cout<<i-1<<" "<<a[i-1]<<endl;
	}
	for(int i=1;i<=q;i++){
		int l=read(),r=read();
		//cout<<a[r]<<" "<<a[min(r,l+m-2)]<<endl;
		printf("%d\n",a[r]-a[min(r,l+m-2)]);
	}
	return 0;
}

