#include<bits/stdc++.h>
#define inf 1000000000
#define maxn 2000000+5
#define maxm 5000000+5
#define eps 1e-10
#define ll long long
#define for0(i,n) for(int i=0;i<=(n);i++)
#define for1(i,n) for(int i=1;i<=(n);i++)
#define for2(i,x,y) for(int i=(x);i<=(y);i++)
#define for3(i,x,y) for(int i=(x);i>=(y);i--)
#define for4(i,x) for(int i=head[x],y=e[i].go;i;i=e[i].next,y=e[i].go)
using namespace std;
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
ll a[maxn];
int main(){
	int n=read();
	for(int i=1;i<=n;i++){
		char ch=getchar();
		while(ch!='c')ch=getchar();
		ch=getchar();
		ll x=read();
		if(ch=='o'){
			a[i]=a[i-1]^x;
			printf("%lld\n",a[i]);
			//cout<<a[i]<<endl;
		}
		else{
			a[i]=a[x];
			printf("%lld\n",a[i]);
			//cout<<a[i]<<endl;
		}
	}
	return 0;
}

