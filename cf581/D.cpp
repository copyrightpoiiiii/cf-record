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
inline ll read(){
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
/*
struct edge{
	int go,next;
}e[2*maxn];
void insert(int x,int y){
	e[++tot]=(edge){y,head[x]};head[x]=tot;
	e[++tot]=(edge){x,head[y]};head[y]=tot;
}
*/
string s;
int a[100005];
int ans[100005];
struct num{
	int w,pos;
};
stack<num> sta;
int main(){
	//ios::sync_with_stdio(false);cin.tie(0);
	cin>>s;
	for(int i=0;i<s.length();i++){
		a[i+1]=(s[i]=='1');
		ans[i]=-1;
	}
	num tmp;
	for(int i=1;i<=s.length();i++){
		if(a[i]==1){
			tmp.pos=i;
			tmp.w=1;
			sta.push(tmp);
		}
		else{
			if(!sta.empty()&&sta.top().w==1){
				tmp=sta.top();
				sta.pop();
				ans[i]=0;
				ans[tmp.pos]=1;
			}
			else{
				tmp.pos=i;
				tmp.w=0;
				sta.push(tmp);
			}
		}
	}
	for(int i=1;i<=s.length();i++){
		if(ans[i]==0||ans[i]==-1)
			printf("0");
		else printf("1");
	}
	return 0;
}


