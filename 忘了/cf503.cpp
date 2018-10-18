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
struct stu{
	int sum;
	int id;
}t[2000];
bool cmp(stu a,stu b){
	if(a.sum==b.sum)
		return a.id<b.id;
	else return a.sum>b.sum;
}
int main(){
	int n=read();
	for(int i=1;i<=n;i++){
		t[i].id=i;
		int x=0;
		for(int j=1;j<=4;j++){
			int tmp=read();
			x+=tmp;
		}
		t[i].sum=x;
	}
	sort(t+1,t+n+1,cmp);
	for(int i=1;i<=n;i++)
		if(t[i].id==1)
			cout<<i<<endl;
	return 0;
}

