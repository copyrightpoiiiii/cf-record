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
char s[200010];
int main(){
	scanf("%s",s);
	int n=strlen(s);
	int now=1;
	int ans=0;
	for(int i=0;i<n;i++)
		s[n+i]=s[i];
	n*=2;
	for(int i=1;i<n;i++)
		if(s[i]!=s[i-1])
			now++;
		else{
			ans=max(now,ans);
			now=1;
		}
	cout<<min(ans,n/2);
	return 0;
}

