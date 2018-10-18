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
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
ll n,s;
ll a[200005];
int main(){
	n=read();s=read();
	for1(i,n)
		a[i]=read();
	sort(a+1,a+1+n);
	ll cnt=abs(a[(n/2)+1]-s);
	for(int i=n/2;i>=1;i--)
		if(a[i]>s)
			cnt+=abs(a[i]-s);
	for(int i=(n/2)+2;i<=n;i++)
		if(a[i]<s)
			cnt+=abs(a[i]-s);
	cout<<cnt<<endl;
	return 0;
}

