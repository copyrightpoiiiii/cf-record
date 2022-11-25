#include<bits/stdc++.h>
#define inf 70000000
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
struct poi{
	vector<int> div;
}p[200005];
int cnt=0;
int dfs(int x,int y){
	int sum=0;
	for1(i,k){
		if(y&1)sum=sum+p[x].div[i-1];
		else sum-=p[x].div[i-1];
		y>>=1;
	}
	return sum;
}
struct tree{
    struct stree{int l,r,mx,mi;}f[4*200005];

void pushup(int i){
    f[i].mx=max(f[i*2+1].mx,f[i*2].mx);
    f[i].mi=min(f[i*2+1].mi,f[i*2].mi);
}
 
void build(int i,int left,int right){
    int mid=(left+right)/2;
    f[i].l=left;f[i].r=right;
    if(left==right){
        f[i].mx=-inf;
        f[i].mi=inf;
        return;
    }
    build(i*2,left,mid);
    build(i*2+1,mid+1,right);
    pushup(i);
}

void add(int i,int left,int v){
    int mid=(f[i].l+f[i].r)/2;
    if(f[i].l==left&&f[i].r==left){
        f[i].mx=v;
        f[i].mi=v;
        return;
    }
    if(mid>=left)add(i*2,left,v);  
    else add(i*2+1,left,v);
    pushup(i);
}

int qmax(int i,int left,int right){
    int mid=(f[i].l+f[i].r)/2;
    if(f[i].l==left&&f[i].r==right) return f[i].mx;
    if(mid>=right) return qmax(i*2,left,right);
    if(mid<left) return qmax(i*2+1,left,right);
    return max(qmax(i*2,left,mid),qmax(i*2+1,mid+1,right));
}

int qmin(int i,int left,int right){
    int mid=(f[i].l+f[i].r)/2;
    if(f[i].l==left&&f[i].r==right) return f[i].mi;
    if(mid>=right) return qmin(i*2,left,right);
    if(mid<left) return qmin(i*2+1,left,right);
    return min(qmin(i*2,left,mid),qmin(i*2+1,mid+1,right));
}
}F[33];
int main(){
	n=read();k=read();cnt=1<<k;
	cnt--;
	for1(i,n){
		for1(j,k){
			int x=read();
			p[i].div.push_back(x);
		}
		//a[i].first=-inf;a[i].second=inf;
		//dfs(i,0,0);
		//cout<<a[i].first<<" "<<a[i].second<<endl;
	}
	for(int i=0;i<=cnt;i++)
		F[i].build(1,1,n);
	for1(i,n){
		for(int j=0;j<=cnt;j++){
			//cout<<dfs(i,j);
			F[j].add(1,i,dfs(i,j));
		}
	}
	int q=read();
	while(q--){
		int tm=read();
		if(tm==1){
			int x=read();
			for0(i,k-1)
				p[x].div[i]=read();
				for(int j=0;j<=cnt;j++){
			F[j].add(1,x,dfs(x,j));
		}
		}
		else{
			int l=read(),r=read(),ans=0;
			for(int i=0;i<=cnt;i++){
				int mx=F[i].qmax(1,l,r),mi=F[i].qmin(1,l,r);
				ans=max(ans,mx-mi);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}


