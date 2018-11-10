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
struct peo{
	int x;
	int id;
	int id2;
}a[200005];
bool cmp(peo x1,peo y1){
	return x1.x<y1.x;
}
bool cmp2(peo x1,peo y1){
	return x1.id2<y1.id2;
}
int n,m;
int cnt[200005],l[200005],r[200005];
int main(){
	n=read();m=read();
	for1(i,n+m){
		a[i].x=read();
		a[i].id2=i;
	}
	for1(i,n+m)
		a[i].id=read();
	sort(a+1,a+n+m+1,cmp);
	int zid=0;
	for1(i,n+m)
		if(a[i].id==0){
			l[i]=zid;
		}
		else zid=i;
	int yid=0;
	for(int i=n+m;i>=1;i--)
		if(a[i].id==0){
			r[i]=yid;
		}
		else yid=i;
	for1(i,n+m)
		if(a[i].id==0){
			int t1=a[l[i]].x,t2=a[i].x,t3=a[r[i]].x;
			if(l[i]==0)cnt[a[r[i]].id2]++;
			else if(r[i]==0)cnt[a[l[i]].id2]++;
			else{
				if(t2-t1<=t3-t2)cnt[a[l[i]].id2]++;
				else cnt[a[r[i]].id2]++;
			}
			//cout<<t1<<" "<<t2<<" "<<t3<<endl;
		}
	sort(a+1,a+n+m+1,cmp2);
	for1(i,n+m)
		if(a[i].id==1)
			cout<<cnt[i]<<" ";
	return 0;
}


