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
int n;
ll k;
ll a[200005],sum[15][200005];
int tot[15];
int find(ll x){
	int tt=0;
	while(x){
		tt++;
		x/=10;
	}
	return tt;
}
int main(){
	n=read();k=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++){
		ll tmp=1;
		for(int j=1;j<=12;j++){
			sum[j][++tot[j]]=((a[i]%k)*(tmp%k))%k;
			tmp*=10;
			tmp%=k;
		}
	}
	for(int i=1;i<=12;i++){
		sort(sum[i]+1,sum[i]+1+tot[i]);
		sum[i][0]=-1;sum[i][tot[i]+1]=-1;
	}
	/*for(int i=1;i<=5;i++){
		for(int j=1;j<=tot[i];j++)
			cout<<sum[i][j]<<" ";
		cout<<endl;
	}*/
	ll ans=0;
	for(int i=1;i<=n;i++){
		ll tmp=(k-a[i]%k)%k;
		int x=find(a[i])+1;
		ll tmp2=a[i];
		for(int j=1;j<x;j++){
			tmp2*=10;
			tmp2%=k;
		}
		//cout<<ans<<endl;
	//	cout<<a[i]<<" "<<tmp2<<endl;
		
		if((tmp2+a[i])%k==0)
			ans--;
		//	cout<<ans<<endl;
		int st=lower_bound(sum[x]+1,sum[x]+1+tot[x],tmp)-sum[x];
		int ed=upper_bound(sum[x]+1,sum[x]+1+tot[x],tmp)-sum[x];
			//	cout<<x<<" "<<tmp<<" "<<ed<<" "<<st<<endl;
		if(ed-st>=0&&sum[x][st]==tmp)
			ans+=(ll)ed-st;
	}
	cout<<ans;
	return 0;
}

