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
int read(){
    int x=0,f=1;char ch=getchar();
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
void insert(int u,int v,int w){
	 e[++tot].go=v;e[tot].next=head[u];e[tot].w=w;head[u]=tot;
	 e[++tot].go=u;e[tot].next=head[v];e[tot].w=w;head[v]=tot;
}
*/
//int f[105][105][105];
int t[105],a[105],b[105];
char ans[105];
int main(){
	int n=read();
	for1(i,n){
		a[i]=read();
		b[i]=a[i];
		t[a[i]]++;
	}
	int cnt1=0,cnt2=0,cnt3=0;
	for1(i,100)
		if(t[i]==1)cnt1++;
		else if(t[i]==2)cnt2++;
		else if(t[i]==3)cnt3++;
	if(cnt1%2==1&&cnt3<1){
		cout<<"NO"<<endl;
	}
	else{
		if(cnt1%2==1){
			int side=0,flag=0;
			for(int i=1;i<=n;i++)
				if(t[a[i]]==1){
					if(side)
						ans[i]='A';
					else ans[i]='B';
					side^=1;
				}
				else if(t[a[i]]==2)
					ans[i]='B';
				else if(!flag){
					ans[i]='A';
					flag=1;
				}
				else ans[i]='B';
		}
		else{
			int side=0,flag=0;
			for(int i=1;i<=n;i++)
				if(t[a[i]]==1){
					if(side)
						ans[i]='A';
					else ans[i]='B';
					side^=1;
				}
				else ans[i]='B';
		}
		cout<<"YES"<<endl;
		for(int i=1;i<=n;i++)
			cout<<ans[i];
	}
	return 0;
}

