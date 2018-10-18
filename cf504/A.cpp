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
string s,t;
int n,m;
int main(){
	n=read();m=read();
	//char ch=getchar();
	getline(cin,s);
	//cout<<s<<endl;
	getline(cin,t);
	if(n>m+1){
		cout<<"NO"<<endl;
		return 0;
	}
	if(s==t){
		cout<<"YES"<<endl;
		return 0;
	}
	int head=0,tail=0,flag1=0,flag2=0;
	while(s[head]==t[head]){
		flag1=1;
		head++;
		if(s[head]=='*')
			break;
	}
	if(s[0]=='*')
		flag1=1;
	while(s[n-tail-1]==t[m-tail-1]){
		flag2=1;
		tail++;
		if(s[n-tail-1]=='*')
			break;
	}
	if(s[n-1]=='*')
		flag2=1;
	//out<<s[head]<<" "<<s[n-tail-1]<<endl;
	if(head==n-tail-1&&flag1&&flag2){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	return 0;
}

