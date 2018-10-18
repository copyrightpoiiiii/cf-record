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
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
int a[200000];
int b[200000];
int sum_z_and_o[200000];
int sum_o_and_o[200000];
int sum_o_and_z[200000];
int sum_z_and_z[200000];
ll ans;
int main(){
	int n=read();
	for(int i=1;i<=n;i++)
	{
		char ch=getchar();
		while(ch!='0'&&ch!='1')ch=getchar();
		if(ch=='0')a[i]=0;
		else a[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		char ch=getchar();
		while(ch!='0'&&ch!='1')ch=getchar();
		if(ch=='0')b[i]=0;
		else b[i]=1;
	}
	for(int i=1;i<=n;i++){
		sum_o_and_o[i]=sum_o_and_o[i-1];
		sum_z_and_z[i]=sum_z_and_z[i-1];
		sum_o_and_z[i]=sum_o_and_z[i-1];
		sum_z_and_o[i]=sum_z_and_o[i-1];
		if(a[i]==1){
			if(b[i]==1)
				sum_o_and_o[i]++;
			else
				sum_o_and_z[i]++;
		}
		else{
			if(b[i]==1)
				sum_z_and_o[i]++;
			else
				sum_z_and_z[i]++;
		}
	}
	for(int i=n;i>=1;i--){
		if(a[i]==0&&b[i]==1){
			ans+=sum_o_and_z[i-1];
		}
		if(a[i]==0&&b[i]==0){
			ans+=sum_o_and_z[i-1];
			ans+=sum_o_and_o[i-1];
		}
		if(a[i]==1&&b[i]==0){
			ans+=sum_z_and_z[i-1];
			ans+=sum_z_and_o[i-1];
		}
		if(a[i]==1&&b[i]==1)
			ans+=sum_z_and_z[i-1];
	}
	cout<<ans<<endl;
	return 0;
}

