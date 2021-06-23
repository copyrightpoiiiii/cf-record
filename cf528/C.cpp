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
int t,n;
string s,a,b;
int p[35];
int book[35];
bool judgex(string tmp){
	for(int i=0;i<=n;i++)
		p[i]=-1;
	p[s[0]-'a']=a[0]-'a';
	tmp[0]=a[0];
	int flag=0;
	for(int i=0;i<=29;i++)
		book[i]=0;
	book[a[0]-'a']=1;
	for(int i=1;i<s.length();i++)
	if(is_down(s[i]))
		if(p[s[i]-'a']==-1){
			if(!flag){
				int flag2=0;
				for(int j=a[i]-'a';j<='z'-'a';j++)
					if(!book[j]){
						p[s[i]-'a']=j;
						if(j!=a[i]-'a')
							flag=1;
						tmp[i]=(char)('a'+j);
						book[j]=1;
						flag2=1;
						break;
					}
				if(!flag2)
					return false;
			}
			else{
				int flag2=0;
				for(int j=0;j<='z'-'a';j++)
					if(!book[j]){
						p[s[i]-'a']=j;
						tmp[i]=(char)('a'+j);
						flag2=1;
						book[j]=1;
						break;
					}
				if(!flag2)
					return false;
			}
		}
		else tmp[i]=(char)(p[s[i]-'a']+'a');
	if((tmp>=a)&&(tmp<=b))
		return true;
		else return false;
}
bool judges(string tmp){
	for(int i=0;i<=n;i++)
		p[i]=-1;
	p[s[0]-'a']=b[0]-'a';
	tmp[0]=b[0];
	int flag=0;
	for(int i=0;i<=29;i++)
		book[i]=0;
	book[b[0]-'a']=1;
	for(int i=1;i<s.length();i++)
	if(is_down(s[i]))
		if(p[s[i]-'a']==-1){
			if(!flag){
				int flag2=0;
				for(int j=b[i]-'a';j>=0;j--)
					if(!book[j]){
						p[s[i]-'a']=j;
						if(j!=b[i]-'a')
							flag=1;
						tmp[i]=(char)('a'+j);
						flag2=1;
						book[j]=1;
						break;
					}
				if(!flag2)
					return false;
			}
			else{
				int flag2=0;
				for(int j='z'-'a';j>=0;j--)
					if(!book[j]){
						p[s[i]-'a']=j;
						tmp[i]=(char)('a'+j);
						flag2=1;
						book[j]=1;
						break;
					}
				if(!flag2)
					return false;
			}
		}
		else tmp[i]=(char)(p[s[i]-'a']+'a');
	if((tmp>=a)&&(tmp<=b))
		return true;
		else return false;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
    t=read();
    while(t>0){
    	t--;
		n=read();
		cin>>s>>a>>b;
		for(int i=0;i<=n;i++)
			p[i]=-1;
		memset(book,0,sizeof(book));
		if(abs(a[0]-b[0])>1){
			cout<<"YES"<<endl;
			int yy=min(a[0]-'a',b[0]-'a')+1;
			p[s[0]-'a']=yy;
			int cnt=0;
			for(int i=0;i<n;i++)
				if(p[i]==-1){
					if(cnt==yy)cnt++;
					p[i]=cnt;
					cnt++;
				}
			for(int i=0;i<n;i++)
				cout<<(char)(p[i]+'a');
			cout<<endl;
		}
		else{
			if(judgex(s)){
				int cnt=0;
				for(int i=0;i<n;i++)
					if(p[i]==-1){
						while(book[cnt])cnt++;
						p[i]=cnt;
						cnt++;
					}
				cout<<"YES"<<endl;
				for(int i=0;i<n;i++)
					cout<<(char)(p[i]+'a');
				cout<<endl;
			}
			else if(judges(s)){
				int cnt=0;
				for(int i=0;i<n;i++)
					if(p[i]==-1){
						while(book[cnt])cnt++;
						p[i]=cnt;
						cnt++;
					}
				cout<<"YES"<<endl;
				for(int i=0;i<n;i++)
					cout<<(char)(p[i]+'a');
				cout<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}
