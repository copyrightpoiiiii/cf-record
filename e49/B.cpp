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
int main(){
	ll n=read(),q=read(),sum;
	if((n*n)%2==0)
		sum=n*n/2;
	else sum=1+(n*n/2);
	for(int i=1;i<=q;i++){
		ll x=read(),y=read();
		if((x+y)%2==0){
			ll tmp=0;
			if((x+1)%2==0){
				tmp=y/2+1;
			}
			else tmp=y/2;
			if(n%2==0){
				tmp+=(n/2)*(x-1);
			}
			else tmp+=n*((x-1)/2)+((x-1)%2)*(1+(n/2));
			printf("%lld\n",tmp);
		}
		else{
			ll tmp=0;
			if((x+1)%2==0){
				tmp=y/2;
			}
			else tmp=y/2+1;
			if(n%2==0){
				tmp+=(n/2)*(x-1);
			}
			else tmp+=n*((x-1)/2)+((x-1)%2)*((n/2));
			printf("%lld\n",tmp+sum);
		}
	}
	return 0;
}

