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
int n,tot;
struct seg{
	ll s,t;
}a[200000],b[200000];

seg c[200000],d[200000];
seg add(seg x,seg y){
	seg ans;
	if(x.t<y.s||x.s>y.t||x.s==-1||y.s==-1){
		ans.s=-1;ans.s=-1;
	}
	else{
		ans.s=max(x.s,y.s);
		ans.t=min(x.t,y.t);
	}
	return ans;
}
int main(){
	n=read();
	ll ml=0,mr=0;
	for1(i,n){
		a[i].s=read();
		b[i].s=read();
		a[i].t=read();
		b[i].t=read();
		if(a[i].s>a[i].t)swap(a[i].s,a[i].t);
		if(b[i].s>b[i].t)swap(b[i].s,b[i].t);
		mr=max(mr,a[i].t);
		ml=max(ml,b[i].t);
	}
	c[0].s=d[n+1].s=0;c[0].t=d[n+1].t=mr;
	c[1].s=a[1].s;c[1].t=a[1].t;
	for(int i=2;i<=n;i++){
		c[i]=add(c[i-1],a[i]);
	}
	d[n].s=a[n].s;d[n].t=a[n].t;
	for(int i=n-1;i>=1;i--){
		d[i]=add(d[i+1],a[i]);
	}
	seg ans1;
	for(int i=1;i<=n;i++){
		seg tmp=add(c[i-1],d[i+1]);
		if(tmp.s!=-1){
			ans1.s=tmp.s;
			ans1.t=tmp.t;
		}
	}
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	c[0].s=d[n+1].s=0;c[0].t=d[n+1].t=ml;
	c[1].s=b[1].s;c[1].t=b[1].t;
	for(int i=2;i<=n;i++){
		c[i]=add(c[i-1],b[i]);
	}
	d[n].s=b[n].s;d[n].t=b[n].t;
	for(int i=n-1;i>=1;i--){
		d[i]=add(d[i+1],b[i]);
	}
	seg ans2;
	for(int i=1;i<=n;i++){
		seg tmp=add(c[i-1],d[i+1]);
		if(tmp.s!=-1){
			ans2.s=tmp.s;
			ans2.t=tmp.t;
			//cout<<"sss";
		}
	}
	cout<<ans1.s<<" "<<ans2.s<<endl;
	return 0;
}

