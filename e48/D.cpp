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
int n,m,a[200],b[200];
int ans1,ans2;
int main(){
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		ans1^=a[i];
	}
	for(int i=1;i<=m;i++){
		b[i]=read();
		ans2^=b[i];
	}
	if(ans1!=ans2){
		cout<<"NO"<<endl;
		return 0;
	}
	else {
		cout<<"YES"<<endl;
		for(int i=1;i<=n-1;i++){
			cout<<a[i];
			for(int j=2;j<=m;j++)
				cout<<" 0";
			cout<<endl;
		}
		ans1^=a[n];//ans2^=b[n];
		//ans2^=ans1;
		cout<<(b[1]^ans1);
		for(int j=2;j<=m;j++)
			cout<<" "<<b[j];
		//cout<<" "<<(ans2^a[n]);
	}
	return 0;
}

