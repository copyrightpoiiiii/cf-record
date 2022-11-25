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
int t;
string s;
int a[30];
int main(){
	t=read();
	while(t--){
		memset(a,0,sizeof(a));
		cin>>s;
		for(int i=0;i<s.length();i++)
			a[s[i]-'a']++;
		int num=0;
		for(int i=0;i<=26;i++)
			if(a[i]!=0)
				num++;
		if(num<=1){
			cout<<-1<<endl;
		}
		else{
			char st,ed;
			num=0;
			for(int i=0;i<=26;i++)
				if(a[i]!=0){
					num++;
					if(num>1){
						st='a'+i;
						a[i]--;
						break;
					}
					else{
						ed='a'+i;
						a[i]--;
					}
				}
			cout<<ed;
			for(int i=0;i<=26;i++)
				for1(j,a[i])
					cout<<(char)('a'+i);
			cout<<st<<endl;
		}
	}
	return 0;
}


