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
int n,m;
string s;
int main(){
	n=read();m=read();
	getline(cin,s);
	int num=(n-m)/2,num2=(n-m)/2;
	int now=0;
	while(num+num2!=0){
		if(s[now]=='('&&num){
			num--;
			now++;
			continue;
		}
		if(s[now]==')'&&num2){
			num2--;
			now++;
			continue;
		}
		printf("%c",s[now]);
		now++;
	}
	for(int i=now;i<n;i++)
		printf("%c",s[i]);
	return 0;
}

