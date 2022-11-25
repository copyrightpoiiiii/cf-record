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
char *a[30]={"Alfa","Bravo","Charlie","Delta","Echo","Foxtrot","Golf","Hotel","India","Juliett","Kilo","Lima","Mike","November","Oscar","Papa","Quebec","Romeo","Sierra","Tango","Uniform","Victor","Whiskey","Xray","Yankee","Zulu"};
char *b[15]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
char c[105];
int main(){
	while(scanf("%s",c)!=EOF){
		cout<<"CQCQCQ this is "<<c<<" ";
		for(int i=0;i<strlen(c);i++){
			char ch=c[i];
			if(ch>='0'&&ch<='9')
				cout<<b[ch-'0']<<" ";
			else if(ch>='a'&&ch<='z')
				cout<<a[ch-'a']<<" ";
			else cout<<a[ch-'A']<<" ";
		}
		cout<<c<<endl;
	}
	return 0;
}

