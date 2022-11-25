#include<bits/stdc++.h>
#define inf 1000000000
#define maxn 100000+5
#define maxm 5000000+5
#define eps 1e-10
#define mod 998244353
#define ll long long
#define for0(i,n) for(int i=0;i<=(n);i++)
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
int a[200005],b[200005];
struct tree{
    int l,r,sum;
}f[200005*4];
 
void pushup(int i){
    f[i].sum=(f[i*2+1].sum+f[i*2].sum);
}
 
void update(int i,int x)
{
    f[i].sum+=x*(f[i].r-f[i].l+1);
    return;
}
 
void build(int i,int left,int right){
    int mid=(left+right)/2;
    f[i].l=left;f[i].r=right;
    if(left==right){
        f[i].sum=0;
        return;
    }
    build(i*2,left,mid);
    build(i*2+1,mid+1,right);
    pushup(i);
}
 
void add(int i,int left,int right,int v){
    int mid=(f[i].l+f[i].r)/2;
    if(f[i].l==left&&f[i].r==right){
        f[i].sum=1;
        return;
    }
    if(mid>=right)add(i*2,left,right,v);  
    else if(mid<left)add(i*2+1,left,right,v);
    else add(i*2,left,mid,v),add(i*2+1,mid+1,right,v);
    pushup(i);
}
 
int query(int i,int left,int right) {
        int mid=(f[i].l+f[i].r)/2;
        if(f[i].l==left&&f[i].r==right) return f[i].sum;
        if(mid>=right) return query(i*2,left,right);
        if(mid<left) return query(i*2+1,left,right);
        return (query(i*2,left,mid)+query(i*2+1,mid+1,right));
}
ll inv[200005];
int n;
void getinv()
{
    inv[0]=inv[1]=1;
	for2(i,2,n)
	 inv[i]=((mod/i+1)*inv[i-mod%i])%mod;
}

int main(){
	//ios::sync_with_stdio(false);cin.tie(0);
	n=read();
	int tot=0;
	for1(i,n){
		a[i]=read();
		if(a[i]!=-1)b[++tot]=a[i];
	}
	sort(b+1,b+tot+1);
	build(1,1,n);
	getinv();
	ll ans=0,sum=0;
	for1(i,n)
	if(a[i]==-1){
		sum++;
	}
	else{
		ll tmp=query(1,a[i],n);
		int tt=lower_bound(b+1,b+tot+1,a[i])-b;
		//cout<<tt<<endl;
		ans=(ans+tmp)%mod;
		ans=(ans+((((n-a[i])-(tot-tt)+mod)*(sum)%mod)*(inv[n-tot]))%mod)%mod;
		//cout<<((n-a[i])-(tot-tt))<<endl;
		ans=(ans+((((a[i]-1)-tt+1+mod)*(n-tot-sum)%mod)*(inv[n-tot]))%mod)%mod;
		add(1,a[i],a[i],1);
		//cout<<ans<<endl;
	}
	//cout<<ans<<endl;
	ans=(ans+((sum*(sum-1)/2)%mod)*inv[2]%mod)%mod;
	cout<<ans<<endl;
	return 0;
}

