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
struct edge{
	int go,next;
}e[200005];
int tot,n,q,head[100005];
int dep[100005];
int rk[100005],cnt=0,fan[100005];
int pr[100005][20];
void insert(int u,int v){
	 e[++tot].go=v;e[tot].next=head[u];head[u]=tot;
	 e[++tot].go=u;e[tot].next=head[v];head[v]=tot;
}
void dfs(int x,int fa){
	rk[++cnt]=x;
	fan[x]=cnt;
	for4(i,x)
		if(y!=fa){
			dep[y]=dep[x]+1;
			dfs(y,x);
		}
}
void rmq(){
	memset(pr,0x3f,sizeof(pr));
 	for(int i=1;i<=n;i++)pr[i][0]=rk[i];
    for(int i=1;i<=floor(log(n)/log(2));i++)
    	for(int j=1;j<=n-(1<<i)+1;j++)
    		if(dep[pr[j][i-1]]<dep[pr[j+(1<<(i-1))][i-1]])
    			pr[j][i]=pr[j][i-1];
    		else pr[j][i]=pr[j+(1<<(i-1))][i-1];
}
int query(int x,int y){
	x=fan[x];y=fan[y];
	//cout<<x<<" "<<y<<endl;
	if(x>y)swap(x,y);
	int z=floor(log(y-x+1)/log(2));
    return dep[pr[x][z]]<dep[pr[y-(1<<z)+1][z]]?pr[x][z]:pr[y-(1<<z)+1][z];
}
struct tree{
    int l,r,mi;
}f[100005*4];
 
void pushup(int i){
    f[i].mi=query(f[i*2].mi,f[i*2+1].mi);
}
 
void build(int i,int left,int right){
    int mid=(left+right)/2;
    f[i].l=left;f[i].r=right;
    if(left==right){
        f[i].mi=left;
        return;
    }
    build(i*2,left,mid);
    build(i*2+1,mid+1,right);
    pushup(i);
}
int qmin(int i,int left,int right){
    int mid=(f[i].l+f[i].r)/2;
    if(f[i].l==left&&f[i].r==right) return f[i].mi;
    if(mid>=right) return qmin(i*2,left,right);
    if(mid<left) return qmin(i*2+1,left,right);
    return query(qmin(i*2,left,mid),qmin(i*2+1,mid+1,right));
}
int main(){
	n=read();q=read();
	for(int i=2;i<=n;i++){
		int x=read();
		insert(i,x);
	}
	dfs(1,0);
	rmq();
	build(1,1,n);
	//cout<<"sss"<<endl;
	for1(i,q){
		int l=read(),r=read();
		int jil=l,jiy=r;
		int ans1=qmin(1,l,r);
		while(l<=r){
			int mid=(l+r)>>1;
			//cout<<l<<" "<<r<<" "<<mid<<endl;
			int zlca=qmin(1,jil,mid);
			
			//cout<<"fc"<<" "<<zlca<<" "<<ylca<<" "<<ans1<<endl;
			if(zlca==ans1)
				break;
			else if(zlca==ans1)
				r=mid;
			else l=mid+1;
		}
		int tmp1=qmin(1,jil,l-1),tmp2=qmin(1,l+1,jiy);
		int ans=qmin(1,min(tmp1,tmp2),max(tmp1,tmp2));
		printf("%d %d\n",jil,dep[ans]);
	}
	return 0;
}


