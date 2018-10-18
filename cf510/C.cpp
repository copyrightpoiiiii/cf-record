#include<bits/stdc++.h>
#define inf 2000000000
#define maxn 300000+5
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
void insert(int u,int v,int w){
	 e[++tot].go=v;e[tot].next=head[u];e[tot].w=w;head[u]=tot;
	 e[++tot].go=u;e[tot].next=head[v];e[tot].w=w;head[v]=tot;
}
*/
int n;
ll a[maxn];
int book[maxn];
int findls(){
	int ans=-1;
	for1(i,n)
		if(book[i]==1)
			ans=i;
	return ans;
}
int main(){
	n=read();
	a[0]=inf;
	int sum=n-1;
	int cnt=0,cnt2=0,wei1=0,wei2=0;
	for1(i,n){
		a[i]=read();
		if(a[i]==0){
			cnt++;
			if(cnt>1){
				printf("1 %d %d\n",wei1,i);
				sum--;
				if(sum==0)
					return 0;
			}
			book[wei1]=0;
			wei1=i;
		}
		else if(a[i]<0){
			cnt2++;
			if(abs(a[i])<abs(a[wei2]))
				wei2=i;
		}
		book[i]=1;
	}
		if(cnt2%2==0){
			
			if(cnt){printf("2 %d\n",wei1);sum--;book[wei1]=0;}
			if(sum==0)
					return 0;
			n=findls();
			if(n==-1)return 0;
			for(int i=1;i<n;i++)
				if(book[i]==0)continue;
				else {printf("1 %d %d\n",i,n);sum--;if(sum==0)
					return 0;}
			return 0;
		}
		else {
			if(cnt){
				
			printf("1 %d %d\n",wei1,wei2);
			sum--;
			if(sum==0)
					return 0;
			book[wei1]=0;
		}
		book[wei2]=0;
		printf("2 %d\n",wei2);
		sum--;
		if(sum==0)
			return 0;
		n=findls();
			if(n==-1)return 0;
			for(int i=1;i<n;i++)
				if(book[i]==0)
					continue;
				else{ printf("1 %d %d\n",i,n);sum--;if(sum==0)
					return 0;}
		}
	return 0;
}

