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
int t[100],t2[100];
int n;
string s1,s2;
int book[100];
int ans[100005];
int main(){
	n=read();
	getline(cin,s1);getline(cin,s2);
	for(int i=0;i<n;i++)
		t[s1[i]-'a']++;
	for(int i=0;i<n;i++)
		t2[s2[i]-'a']++;
	int flag=0;
	for(int i=0;i<=30;i++)
		if(t[i]!=t2[i]){
			flag=1;
			break;
		}
	if(flag){
		cout<<"-1"<<endl;
		return 0;
	}
	else{
		int cnt=0;
		for(int i=0;i<n;i++)
			for(int j=i;j<n;j++)
				if(s1[j]==s2[i]){
					if(i==j)break;
					for(int k=j-1;k>=i;k--){
						ans[++cnt]=k;
						swap(s1[k],s1[k+1]);
					}
					break;
				}
		cout<<cnt<<endl;
		for(int i=1;i<=cnt;i++)
			printf("%d ",ans[i]+1);
			//cout<<s1<<endl;
	}
	return 0;
}

