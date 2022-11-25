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
ll n,h,a,b,k;
int main(){
	n=read();h=read();a=read();b=read();k=read();
	b=min(b,h);
	for(int i=1;i<=k;i++){
		ll x1=read(),y1=read(),x2=read(),y2=read();
		ll ans=0;
		if(x1!=x2){
		if(y1>=a&&y1<=b){
			y1=y1;
		}	
		else if(y1<a){
			ans+=a-y1;
			y1=a;
		}
		else{
			ans+=y1-b;
			y1=b;
		}
	}
		ans+=abs(x2-x1);
		ans+=abs(y1-y2);
		printf("%lld\n",ans);
	}
	return 0;
}

