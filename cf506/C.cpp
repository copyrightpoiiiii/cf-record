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
struct seg{
	ll l,r;
}a[300005],b[300005];
int n;
seg c[300005];
seg add(seg x,seg y){
	seg ans;
	if(x.r<=y.l||x.l>=y.r){
		ans.l=x.r;ans.r=x.r;
	}
	else{
		ans.l=max(x.l,y.l);
		ans.r=min(x.r,y.r);
	}
	return ans;
}
int main(){
	n=read();
	ll ml=0,mr=0;
	for(int i=1;i<=n;i++){
		c[i].l=read();c[i].r=read();
		mr=max(mr,c[i].r);
	}
	a[0].l=b[n+1].l=0;a[0].r=b[n+1].r=mr;
	a[1].l=c[1].l;a[1].r=c[1].r;
	for(int i=2;i<=n;i++){
		a[i]=add(a[i-1],c[i]);
	}
	b[n].l=c[n].l;b[n].r=c[n].r;
	for(int i=n-1;i>=1;i--){
		b[i]=add(b[i+1],c[i]);
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		seg tmp=add(a[i-1],b[i+1]);
		ans=max(ans,tmp.r-tmp.l);
	}
	cout<<ans<<endl;
	return 0;
}

