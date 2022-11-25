#include<bits/stdc++.h>
#define inf 1000000000
#define maxn 100000+5
#define maxm 5000000+5
#define eps 1e-10
#define mod 1000000007
#define ll long long
#define for0(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=(n);i++)
#define for2(i,x,y) for(int i=(x);i<=(y);i++)
#define for3(i,x,y) for(int i=(x);i>=(y);i--)
#define for4(i,x) for(int i=head[x],y=e[i].go;i;i=e[i].next,y=e[i].go)
#define pr1(i,x) cout<<i<<" "<<x<<endl
#define pr(x) cout<<x<<endl;
using namespace std;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
inline bool is_down(char x) { return ('a' <= x && x <= 'z'); }
inline bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
inline bool is_digit(char x) { return ('0' <= x && x <= '9'); }
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
inline ll readll(){
	ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
long long gcd(long long x,long long y){return y?gcd(y,x%y):x;}
long long power(long long x,long long y){
	long long t=1;
	for(;y;y>>=1,x=x*x%mod)
		if(y&1)t=t*x%mod;
	return t;
}
/*strcut edge{
    int go,next;
}e[2*maxm];
int tot,head[maxn];
void insert(int u,int v){
    e[++tot]=(edge){v,head[u]};head[u]=tot;
    e[++tot]=(edge){u,head[v]}lhead[v]=tot;
}*/
int n,m,q;
int a[200005];
int t[200005];
int b[200005];
int fa[200005],r[200005];
int l1[200005],l[200005],w[200005];
struct tree{
    int l,r,sum,mx,mi,lazy;
}f[200005*4];
 
void pushup(int i){
    f[i].sum=(f[i*2+1].sum+f[i*2].sum);
    f[i].mx=max(f[i*2+1].mx,f[i*2].mx);
    f[i].mi=min(f[i*2+1].mi,f[i*2].mi);
}
 
void update(int i,int x)
{
    f[i].sum+=x*(f[i].r-f[i].l+1);
    f[i].mi+=x;
    f[i].mx+=x;
    f[i].lazy+=x;
    return;
}
 
void pushdown(int i){
    if(f[i].lazy!=0){
        update(i*2,f[i].lazy);
        update(i*2+1,f[i].lazy);
        f[i].lazy=0;
        return;
    }
    else return;
}
 
void build(int i,int left,int right){
    int mid=(left+right)/2;
    f[i].lazy=0;f[i].mx=0;f[i].mi=inf;
    f[i].l=left;f[i].r=right;
    if(left==right){
        f[i].sum=l[left];
        f[i].mx=l[left];
        f[i].mi=l[left];
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
 
int query(int i,int left,int right) {
        int mid=(f[i].l+f[i].r)/2;
        if(f[i].l==left&&f[i].r==right) return f[i].sum;
        pushdown(i);
        if(mid>=right) return query(i*2,left,right);
        if(mid<left) return query(i*2+1,left,right);
        return (query(i*2,left,mid)+query(i*2+1,mid+1,right));
}
 
int qmax(int i,int left,int right){
    int mid=(f[i].l+f[i].r)/2;
    if(f[i].l==left&&f[i].r==right) return f[i].mx;
    pushdown(i);
    if(mid>=right) return qmax(i*2,left,right);
    if(mid<left) return qmax(i*2+1,left,right);
    return max(qmax(i*2,left,mid),qmax(i*2+1,mid+1,right));
}

int qmin(int i,int left,int right){
    int mid=(f[i].l+f[i].r)/2;
    if(f[i].l==left&&f[i].r==right) return f[i].mi;
    pushdown(i);
    if(mid>=right) return qmin(i*2,left,right);
    if(mid<left) return qmin(i*2+1,left,right);
    return min(qmin(i*2,left,mid),qmin(i*2+1,mid+1,right));
}
int main(){
	//ios::sync_with_stdio(false);cin.tie(0);
	n=read();m=read();q=read();
	for0(i,n){
		a[i]=read();
		t[a[i]]=i;
	}
	for1(i,m)
		b[i]=read();
	int sum=0;
	for(int i=m;i>=1;i--){
		int id=t[b[i]];
		fa[i]=r[a[(id+1)%n]]+1;
		r[b[i]]=fa[i];
		if(w[a[(id+1)%n]]!=0)l1[i]=l1[w[a[(id+1)%n]]]+w[a[(id+1)%n]]-i;
		if(fa[i]>=n){
			l[i]=l1[i];
		}
		else l[i]=inf;
		//cout<<l1[i]<<endl;
		w[b[i]]=i;
	}
	for1(i,n)
		l[i]+=i;
	build(1,1,m);
	for1(i,q){
		int x=read(),y=read();
		if(qmin(1,x,y)<=y)printf("1");
		else printf("0");
	}
	return 0;
}

