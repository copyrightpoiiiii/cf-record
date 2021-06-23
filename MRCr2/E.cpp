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
struct tree{
   int l,r,sum,lazy,mi;
}f[2000*4];
void pushup(int i){
    f[i].mi=min(f[i*2+1].mi,f[i*2].mi);
}
 
void update(int i,int x)
{
    f[i].mi=min(f[i].mi,x);
    f[i].lazy=min(f[i].lazy,x);
    return;
}
 
void pushdown(int i){
    if(f[i].lazy!=99999999){
        update(i*2,f[i].lazy);
        update(i*2+1,f[i].lazy);
        f[i].lazy=99999999;
        return;
    }
    else return;
}
 
void build(int i,int left,int right){
    int mid=(left+right)/2;
    f[i].lazy=99999999;f[i].l=left;f[i].r=right;f[i].mi=99999999;
    if(left==right){
        f[i].mi=99999999;
        f[i].lazy=99999999; 
        return;
    }
    build(i*2,left,mid);
    build(i*2+1,mid+1,right);
    pushup(i);
}
 
void add(int i,int left,int right,int v){
    int mid=(f[i].l+f[i].r)/2;
    if(f[i].l==left&&f[i].r==right){
        update(i,v);
        return;
    }
    pushdown(i);
    if(mid>=right)add(i*2,left,right,v);  
    else if(mid<left)add(i*2+1,left,right,v);
    else add(i*2,left,mid,v),add(i*2+1,mid+1,right,v);
    pushup(i);
}

int query(int i,int left,int right){
    int mid=(f[i].l+f[i].r)/2;
    //if(left<m) return 0;
    if(f[i].l==left&&f[i].r==right) return f[i].mi;
    pushdown(i);
    if(mid>=right) return query(i*2,left,right);
    if(mid<left) return query(i*2+1,left,right);
    return min(query(i*2,left,mid),query(i*2+1,mid+1,right));
}

int n,m,s,k;
int a[2000];
int c[2000];
struct meg{
	int l,r;
}b[2000];
int q1[2000][2000];
int q[2000][2000];
int dp[2000][2000];
void pre(){
	for1(i,n)
		for1(j,n)
			if(a[j]<=a[i])
				q1[i][j]=q1[i][j-1]+1;
			else q1[i][j]=q1[i][j-1];
}
bool cmp(meg x1,meg x2){
	return x1.l<x2.l;
}
bool check(int t){
	//memset(f,0,sizeof(f));
	//build(1,1,n);
	memset(dp,0x3f,sizeof(dp));
	for1(i,n)
		dp[i][0]=0;
	int h=0;
	for1(i,s){
		for1(j,t)
			if(j>=q[t][i]){
			dp[b[i].r][j]=min(dp[b[h].r][j],dp[b[h].r][j-q[t][i]]+1);
		}
		while(b[h+1].r<b[i].l){
			cout<<i<<" "<<h<<endl;
			
			h++;
			for1(j,t)
			if(j>=q[t][i]){
			dp[b[i].r][j]=min(dp[b[h].r][j],dp[b[h].r][j-q[t][i]]+1);
		}
			if(h==i)break;
		}
	}
	for1(i,n)
		if(dp[i][t]<=m)
			return true;
	return false;
}
int main(){
	n=read();s=read();m=read();k=read();
	for1(i,n){
		a[i]=read();
		c[i]=a[i];
	}
	pre();
	for1(i,s){
		b[i].l=read();
		b[i].r=read();
	}
	sort(b+1,b+s+1,cmp);
	for1(i,s)
		for1(j,n)
			q[j][i]=q1[j][b[i].r]-q1[j][b[i].l-1];
	sort(c+1,c+n+1);
	int l=k,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	if(check(l))cout<<c[l]<<endl;
	else cout<<-1<<endl;
	return 0;
}


