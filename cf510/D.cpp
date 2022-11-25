#include<bits/stdc++.h>
#define inf 1000000000
#define maxn 200000+5
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
ll n,m,tot,l[maxm],r[maxm],s[maxm],rnd[maxm],w[maxm],v[maxm],root;
inline void pushup(ll k)
{s[k]=s[l[k]]+s[r[k]]+w[k];}
inline void rturn(ll &k)
{int t=l[k];l[k]=r[t];r[t]=k;s[t]=s[k];pushup(k);k=t;}
inline void lturn(ll &k)
{int t=r[k];r[k]=l[t];l[t]=k;s[t]=s[k];pushup(k);k=t;}
void ins(ll &k,ll num)
{
    if(!k)
    {k=++tot;v[k]=num;s[k]=w[k]=1;l[k]=r[k]=0;rnd[k]=rand();return;}
    s[k]++;
    if(v[k]==num)w[k]++;
    else if(num<v[k])
      {ins(l[k],num);if(rnd[l[k]]<rnd[k])rturn(k);}
    else
      {ins(r[k],num);if(rnd[r[k]]<rnd[k])lturn(k);}  
}
int rank1(ll k,ll num)
{
    if(!k) return 0;
    if(v[k]==num)return s[l[k]];
    else if(num<v[k])return rank1(l[k],num);
    else return s[l[k]]+w[k]+rank1(r[k],num);
}
int main(){
	n=read();ll t=read(),sum=0,ans=0;
	ins(root,0);
	for1(i,n){
		ll x=read();
		sum+=x;
		ans+=i-rank1(root,sum-t+1);
		
		ins(root,sum);
	}
	cout<<ans<<endl;
		
	return 0;
}

