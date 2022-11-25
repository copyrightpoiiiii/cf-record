#include<bits/stdc++.h>
#define inf 1000000000
#define maxn 100000+5
#define maxm 5000000+5
#define eps 1e-10
#define mod 1000000007
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
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
int power(int x,int y){
	int t=1;
	for(;y;y>>=1,x=x*x%mod)
		if(y&1)t=t*x%mod;
	return t;
}
/*
struct edge{
	int go,next;
}
void insert(int u,int v){
	 e[++tot].go=v;e[tot].next=head[u];head[u]=tot;
	 e[++tot].go=u;e[tot].next=head[v];head[v]=tot;
}
*/
ll la,ra,ta,lb,rb,tb;
ll tmp1,tmp2;
ll tmp3,tmp4;
int main(){
	la=read();ra=read();ta=read();
	lb=read();rb=read();tb=read();
	tmp1=gcd(tb,ta);tmp2=tmp1+((la-lb)%tmp1);
	tmp2%=tmp1;
	tmp3=gcd(tb,ta);
	tmp4=tmp3+((lb-la)%tmp3);
	tmp4%=tmp3;
	//cout<<tmp3<<" "<<tmp4<<endl;
	tmp2=min(1+rb-lb-tmp2,1+ra-la);
	tmp4=min(1+ra-la-tmp4,1+rb-lb);
	ll ans=max(tmp2,tmp4);
	ans=ans<0?0:ans;
	cout<<ans<<endl;
	return 0;
}


