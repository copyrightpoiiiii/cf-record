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
int n,A,b,s1;
ll sum;
int a[maxn];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	n=read();A=read();b=read();
	s1=read();
	ll ms=(ll)A*s1/b;
	sum=s1;
	for(int i=1;i<n;i++){
		a[i]=read();
		sum+=a[i];
	}
	//cout<<sum<<" "<<ms<<endl;
	if(sum<=ms){
		cout<<0<<endl;
	}
	else{
		sort(a+1,a+n);
		ll sum1=s1;
		for(int i=1;i<n;i++){
			sum1+=a[i];
			//cout<<sum1<<endl;
			if(sum1>ms){
				cout<<n-i<<endl;
				return 0;
			}
		}
	}
	return 0;
}

