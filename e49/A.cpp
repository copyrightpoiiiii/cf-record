#include<bits/stdc++.h>
#define inf 1000000000
#define maxn 100000+5
#define maxm 5000000+5
#define eps 1e-10
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
int n;
int book[1000];
string s;
int main(){
	int T=read();
	while(T--){
		memset(book,0,sizeof(book));
		n=read();
		getline(cin,s);
		int flag1=0;
		for(int i=0;i<(n/2);i++){
			//cout<<s[i]<<endl;
			book[s[i]+1]=i+1;
			book[s[i]-1]=i+1;
			int flag=0;
			if(book[s[n-i-1]-1]==i+1||book[s[n-i-1]+1]==i+1)
				flag=1;
			if(!flag){
				cout<<"NO"<<endl;
				flag1=1;
				break;
			}
		}
		if(flag1==0){
			cout<<"YES"<<endl;
		}
	}
	return 0;
}

