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
struct edge{
	int go,next;
}
void insert(int u,int v){
	 e[++tot].go=v;e[tot].next=head[u];head[u]=tot;
	 e[++tot].go=u;e[tot].next=head[v];head[v]=tot;
}
*/
int n;
int a[505];
int ji1[505],ji2[505];
int sum,sum1,sum2,ss;
int main(){
	n=read();
	for1(i,n){
		a[i]=read();
		sum+=a[i];
		if(a[i]==1){sum1++;ji1[sum1]=i;}
		else {sum2+=a[i],ss++;ji2[ss]=i;}
	}
	if(sum<2*(n-1)||sum>n*(n-1)){
		cout<<"NO"<<endl;
		return 0;
	}
	if(2*(ss-1)+sum1>sum2){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES ";
	if(sum1>=2)cout<<ss+1<<endl;
	else if(sum1==1)cout<<ss<<endl;
	else cout<<ss-1<<endl;
	cout<<ss-1+sum1<<endl;
	if(ss>1){
		if(ss==2){
			a[ji2[1]]--;
			a[ji2[2]]--;
		}
		else{
			for(int i=1;i<=ss;i++)
				a[ji2[i-1]]--,a[ji2[i+1]]--;
		}
	}
	int now=1;
	for(int i=1;i<sum1;i++){
		while(a[ji2[now]]==0)now++;
		printf("%d %d\n",ji1[i],ji2[now]);
		a[ji2[now]]--;
	}
	if(sum1>0)printf("%d %d\n",ji1[sum1],ji2[ss]);
	for(int i=1;i<ss;i++)
		printf("%d %d\n",ji2[i],ji2[i+1]);
	return 0;
}


