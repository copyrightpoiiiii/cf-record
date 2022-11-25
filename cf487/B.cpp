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
int n,p;
string s;
int main(){
	scanf("%d%d",&n,&p);
	getchar();
	getline(cin,s);
	int flag=0;
	for(int i=1;i<n-p;i++){
		if(s[i-1]!=s[i-1+p]){
			if(s[i-1]=='.'){
				if(s[i-1+p]=='0'){
					s[i-1]='1';
				}
				else s[i-1]='0';
			}
			else if(s[i-1+p]=='.'){
				if(s[i-1]=='0'){
					s[i-1+p]='1';
				}
				else s[i-1+p]='0';
			}
			flag=1;
			break;
		}
		else if(s[i-1]=='.'){
			s[i-1]='1';
			s[i-1+p]='0';
			flag=1;
			break;
		}
	}
	if(!flag){
		cout<<"No"<<endl;
		return 0;
	}
	for(int i=0;i<s.length();i++){
		if(s[i]=='.'){
			cout<<"1";
		}
		else cout<<s[i];
	}
	cout<<endl;
	return 0;
}

