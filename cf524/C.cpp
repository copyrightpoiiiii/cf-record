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
int gcd(int x,int y){return y?gcd(y,x%y):x;}
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
int t;
pair<ll,ll> query(pair<ll,ll> a,pair<ll,ll> b,int flag){
	ll sum1=0,sum2=0;
	ll z=abs(b.first-a.first+1)*abs(b.second-a.second+1);
	if(z%2==0){
		return make_pair(z/2,z/2);
	}
	if(!flag){
		return make_pair((ll)1+(z/2),z/2);
	}
	else return make_pair((z/2),(ll)1+(z/2));
}
int main(){
	t=read();
	while(t--){
		ll n=read(),m=read();
		pair<ll,ll> a,b,x,y,j1,j2;
		a.first=read();a.second=read();
		b.first=read();b.second=read();
		x.first=read();x.second=read();
		y.first=read();y.second=read();
		j1.first=max(a.first,x.first);j1.second=max(a.second,x.second);
		j2.first=min(b.first,y.first);j2.second=min(b.second,y.second);
		pair<ll,ll> sum=query(make_pair(1,1),make_pair(m,n),0);
		pair<ll,ll> ans=query(a,b,(a.first+a.second)%2);
		pair<ll,ll> ans1=query(x,y,(x.first+x.second)%2);
		//cout<<sum.first<<" "<<sum.second<<endl;
		//cout<<ans.first<<" "<<ans.second<<endl;
		//cout<<ans1.first<<" "<<ans1.second<<endl;
	//	cout<<j1.first<<" "<<j1.second<<endl;
			//cout<<j2.first<<" "<<j2.second<<endl;
		if(j1.first>j2.first||j1.second>j2.second){
			sum.first+=ans.second;
			sum.first-=ans1.first;
			sum.second-=ans.second;
			sum.second+=ans1.first;
			printf("%I64d %I64d\n",sum.first,sum.second);
		}
		else{
			//cout<<((j1.first+j1.second)%2)<<endl;
			pair<ll,ll> ans2=query(j1,j2,(j1.first+j1.second)%2);
			//cout<<ans2.first<<" "<<ans2.second<<endl;
			sum.first+=ans.second;
			sum.first-=ans1.first;
			sum.second-=ans.second;
			sum.second+=ans1.first;
			sum.first-=ans2.second;
			sum.second+=ans2.second;
			printf("%I64d %I64d\n",sum.first,sum.second);	
		}
		
	}
	return 0;
}


