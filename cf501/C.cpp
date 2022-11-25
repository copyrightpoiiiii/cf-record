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
ll n,m;
ll a[100005];
int main(){
	n=read();m=read();
	for1(i,n){
		ll x=read(),y=read();
		m-=x;
		a[i]=x-y;
	}
	if(m>=0){
		cout<<0<<endl;
		return 0;
	}
	else{
		sort(a+1,a+n+1);
		for(int i=n;i>=1;i--){
			m+=a[i];
			if(m>=0){
				cout<<n-i+1<<endl;
				return 0;
			}
		}
		cout<<-1<<endl;
	}
	return 0;
}

