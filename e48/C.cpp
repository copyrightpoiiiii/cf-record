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
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
int n;
ll a[300005][3];
ll t1[300005],t2[300005];
ll t[300005][2];
ll f[300005];
int main(){
	n=read();
	ll ans=0;
	for(int i=1;i<=n;i++){
		a[i][1]=read();
		ans+=a[i][1]*(i-1);
	}
	for(int i=1;i<=n;i++){
		a[i][0]=read();
		ans+=a[i][0]*(2*n-i);
	}
	for(int i=n;i>=1;i--){
		t[i][1]+=t[i+1][1]+a[i][0]*(2*n-i)+a[i][1]*(i-1);
		t[i][0]+=t[i+1][0]+a[i][1]*(2*n-i)+a[i][0]*(i-1);
		t1[i]=t1[i+1]+a[i][1];
		t2[i]=t2[i+1]+a[i][0];
	}
	int flag=1;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+a[i][flag]*(2*(i-1))+a[i][flag^1]*(2*(i-1)+1);
		ans=max(ans,f[i]+t[i+1][flag^1]+i*(t1[i+1]+t2[i+1]));
		flag^=1;
	}
	cout<<ans;
	return 0;
}

