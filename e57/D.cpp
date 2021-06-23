#include<bits/stdc++.h>
#define inf 1e10
#define maxn 100000+5
#define maxm 5000000+5
#define eps 1e-10
#define mod 998244353
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
int n;
ll a[100005];
ll f[100005][5];
bool book[1000];
string s;
int judge(char tmp){
	if(tmp=='a')
		return 1;
	if(tmp=='h')
		return 1;
	if(tmp=='r')
		return 1;
	if(tmp=='d')
		return 1;
	return 0;
}
int main(){
	//ios::sync_with_stdio(false);cin.tie(0);
	n=read();
	cin>>s;
	for0(i,n)
	 	a[i]=read();
	ll ans=inf;
	for0(i,n)
		if(judge(s[i])){
			for0(j,4)
				f[i][j]=f[i-1][j];
			if(s[i]=='h'){
				f[i][0]+=a[i];
				//book['h']=1;
			}
			if(s[i]=='a'){
				f[i][1]=min(f[i-1][0],f[i][1]+a[i]);
			}
			if(s[i]=='r'){
					f[i][2]=min(f[i-1][1],f[i][2]+a[i]);
					
			}
			if(s[i]=='d'){
				//if(book['h']&&book['a']&&book['r']){
					f[i][3]=min(f[i-1][2],f[i][3]+a[i]);
				//	book['d']=1;
				//}
			}
			//for0(j,4)
			//	cout<<f[i][j]<<" ";
				
			//cout<<endl;
		}
		else if(i>0){
			for0(j,4)
				f[i][j]=f[i-1][j];
		}
	cout<<min(min(f[n-1][0],f[n-1][1]),min(f[n-1][2],f[n-1][3]));
	return 0;
}

