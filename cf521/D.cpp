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
int n,k;
struct te{
	int s,id;
}a[200005];
bool cmp(te x,te y){
	return x.s>y.s;
}
bool judge(int t){
	int sum=0;
	for(int i=1;i<=200000;i++)
		if(a[i].s==0)
			break;
		else {
			sum+=a[i].s/t;
			if(sum>=k){
				return true;
			}
		}
	if(sum<k)return false;
	else return true;
}
void output(int t){
	int sum=0;
	for(int i=1;i<=200000;i++){
		while(a[i].s>=t){
			printf("%d ",a[i].id);
			a[i].s-=t;
			sum++;
			if(sum==k)return ;
		}
	}
}
int main(){
	n=read();k=read();
	for1(i,n){
		int x=read();
		a[x].s++;
		a[x].id=x;
	}
	sort(a+1,a+200000+1,cmp);
	int l=1,r=2000000;
	while(l<=r){
		int mid=(l+r)>>1;
		if(judge(mid))l=mid+1;
		else r=mid-1;
	}
	if(judge(l))
	output(l);
	else if(judge(r))
	output(r);
	else if(judge((l+r)>>1))
	output((l+r)>>1);
	return 0;
}


