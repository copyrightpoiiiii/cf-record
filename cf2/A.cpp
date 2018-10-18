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
char ch[2000];
int t[30];
ll ans[2005];
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		scanf("%s",ch);
		memset(t,0,sizeof(t));
		for(int j=0;j<strlen(ch);j++)
			t[ch[j]-'a'+1]=1;
		ll tmp=1;
		for(int j=1;j<=26;j++){
			ans[i]+=tmp*t[j];
			tmp<<=1;
		}
	}
	sort(ans+1,ans+1+n);
	int sum=0;
	for(int i=1;i<=n;i++)
		if(ans[i]!=ans[i-1])
			sum++;
	printf("%d",sum);
	return 0;
}

