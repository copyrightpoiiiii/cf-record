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
string s;
char t[50000];
int n,k;
int main(){
	n=read();k=read();
	getline(cin,s);
	int len=n;
	for(int i=0;i<n;i++)
		t[i]=s[i];
	k--;
	while(k){
		int minpos=0;
		for(int i=1;i<n;i++){
			int flag=0;
			for(int j=0;j<i;j++){
				//cout<<j<<" "<<len-i+j<<endl;
				if(s[j]!=t[len-i+j]){
					flag=1;
					break;
				}
			}
			//cout<<flag<<endl;
			if(!flag)
				minpos=i;
		}
		for(int i=len;i<len+n-minpos;i++)
			t[i]=s[minpos+i-len];
		
		len+=n-minpos;
		k--;
	}
	for(int i=0;i<len;i++)
			cout<<t[i];
			cout<<endl;
	return 0;
}

