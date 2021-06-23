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
int n;
int in[5],ou[5];
int mp[5][5];
int main(){
	//ios::sync_with_stdio(false);cin.tie(0);
	n=read();
	in[0]=in[1]=in[2]=2;
	ou[0]=ou[1]=ou[2]=2;
	for(int i=1;i<=2;i++){
		char ch=getchar();
		while(ch!='a'&&ch!='b'&&ch!='c')ch=getchar();
		int tmp1=ch-'a';
		ch=getchar();
		while(ch!='a'&&ch!='b'&&ch!='c')ch=getchar();
		int tmp2=ch-'a';
		mp[tmp1][tmp2]=-1;
		if(tmp1==tmp2)continue;
		else {
			in[tmp2]--;
			ou[tmp1]--;
		}
	}
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(i!=j){
				int fi=i,se=3-i-j,th=j;
				if(mp[fi][se]==0){
					if(mp[se][th]==0){
						if(mp[th][fi]==0){
							char s[3];
							s[0]='a'+fi;
							s[1]='a'+se;
							s[2]='a'+th;
							s[3]=0;
							cout<<"YES"<<endl;
							for(int k=1;k<=n;k++)
								printf("%s",s);
							return 0;
						}
					}
				}
			}
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(i!=j){
				int fi=i,se=3-i-j,th=j;
				if(mp[fi][se]==0){
					if(mp[se][th]==0){
						cout<<"YES"<<endl;
						for(int k=1;k<=n;k++)
							printf("%c",'a'+fi);
						for(int k=1;k<=n;k++)
							printf("%c",'a'+se);
						for(int k=1;k<=n;k++)
							printf("%c",'a'+th);
						return 0;
					}
				}
			}
	cout<<"NO"<<endl;
	return 0;
}



