#include<bits/stdc++.h>
#define inf 1000000000
#define maxn 100000+5
#define maxm 5000000+5
#define eps 1e-10
#define ll unsigned long long
#define for0(i,n) for(int i=0;i<=(n);i++)
#define for1(i,n) for(int i=1;i<=(n);i++)
#define for2(i,x,y) for(int i=(x);i<=(y);i++)
#define for3(i,x,y) for(int i=(x);i>=(y);i--)
#define for4(i,x) for(int i=head[x],y=e[i].go;i;i=e[i].next,y=e[i].go)
using namespace std;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
ll a,b,n,s0,sum;
long long l;
ll ans[50000005],sl;
int main(){
	cin>>a>>b>>l>>n>>s0;
	ll tmp=-1;
	ll cnt=(tmp/n)*l;
	cout<<(tmp/n)*(l/2)<<endl;
	cout<<(tmp/n)*(l)<<endl;
	cout<<(tmp/n)*(l*1.5)<<endl;
	cout<<cnt<<endl;
	for(int i=1;i<=n;i++){
		cout<<(tmp/n)*(l-1)<<endl;
		if((long long)s0<((long long)(tmp/n)*(l-1)))sl++;
		else if((long long)s0<((long long)(tmp/n)*(l+1)))ans[++sum]=s0;
		s0=s0*a+b;
	}
	cout<<sum<<endl;
	sort(1+ans,1+sum+ans);
	ll fid=l-sl;
	cout<<ans[fid];
	return 0;
}

