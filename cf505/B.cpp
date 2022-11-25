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
struct nu{
	ll a,b;
}a[150005];
ll ans[1000000];
int tot;
int main(){
	int n=read();
	for(int i=1;i<=n;i++){
		a[i].a=read();a[i].b=read();
	}
	ll now=a[1].a,tmp=2;
	while(1){
		if(now%tmp==0){
			ans[++tot]=tmp;
			now/=tmp;
		}
		else tmp++;
		if(tmp>sqrt(a[1].a)){
			if(now!=1)ans[++tot]=now;
			break;
		}
	}
	now=a[1].b;tmp=2;
	while(1){
		if(now%tmp==0){
			ans[++tot]=tmp;
			now/=tmp;
		}
		else tmp++;
		if(tmp>sqrt(a[1].b)){
			if(now!=1)ans[++tot]=now;
			break;
		}
	}
	sort(ans+1,ans+1+tot);
	int m=unique(ans+1,ans+1+tot)-ans-1;
	for(int i=1;i<=m;i++){
		int flag=0;
		for(int j=2;j<=n;j++)
			if(a[j].a%ans[i]!=0&&a[j].b%ans[i]!=0){
				flag=1;
				break;
			}
		if(!flag){
			cout<<ans[i];
			return 0;
		}
	}
	cout<<"-1"<<endl;
	return 0;
}

