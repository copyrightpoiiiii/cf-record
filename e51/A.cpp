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
void insert(int u,int v,int w){
	 e[++tot].go=v;e[tot].next=head[u];e[tot].w=w;head[u]=tot;
	 e[++tot].go=u;e[tot].next=head[v];e[tot].w=w;head[v]=tot;
}
*/
string s;
int main(){
	int n=read();
	while(n--){
		getline(cin,s);
		int num=10,flag=0;
		string ans;
		for(int i=0;i<s.length();i++){
			for(int j=1;j<=3;j++){
				if(i+j-1>=s.length())
					continue;
				int a=0,b=0,c=0;
				for(int k=0;k<i;k++)
					if(s[k]>='0'&&s[k]<='9')
						a=1;
					else if(s[k]>='a'&&s[k]<='z')
						b=1;
					else c=1;
				for(int k=i+j;k<s.length();k++)
					if(s[k]>='0'&&s[k]<='9')
						a=1;
					else if(s[k]>='a'&&s[k]<='z')
						b=1;
					else c=1;
				//cout<<i<<" "<<a<<" "<<b<<" "<<c<<endl;
				if(a==1&&b==1&&c==1){
					ans=s;
					num=0;
					flag=1;
					break;
				}
				else{
					int t[5];
					string tmp=s;
					int cnt=0;
					memset(t,0,sizeof(t));
					for(int k=i;k<=i+j-1;k++)
					if(s[k]>='0'&&s[k]<='9')
						{
							t[1]++;
							a=1;
							if(t[1]>1){
								if(!b){
									tmp[k]='a';
									cnt++;
									b=1;
								}
								else if(!c){
									tmp[k]='A';
									cnt++;
									c=1;
								}
							}
						}
					else if(s[k]>='a'&&s[k]<='z')
						{
							t[2]++;
							b=1;
							if(t[2]>1){
								if(!a){
									tmp[k]='1';
									cnt++;
									a=1;
								}
								else if(!c){
									tmp[k]='A';cnt++;
									c=1;
								}
							}
						}
					else {
							t[3]++;
							c=1;
							if(t[3]>1){
								if(!a){
									tmp[k]='1';cnt++;
									a=1;
								}
								else if(!b){
									tmp[k]='a';cnt++;
									b=1;
								}
							}
						}
					//cout<<cnt<<" "<<tmp<<endl;
					//cout<<a<<b<<c<<endl;
					if(cnt<num&&a==1&&b==1&&c==1){
						num=cnt;
						ans=tmp;
					}
				}
			}
			if(flag)
				break;
		}
		cout<<ans<<endl;
	}
	return 0;
}

