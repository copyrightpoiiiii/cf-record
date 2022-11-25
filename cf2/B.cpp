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
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
ll a[20],b[20],ans;
int main(){
	for(int i=1;i<=14;i++)
		a[i]=read();
	for(int i=1;i<=14;i++){
		ll num=a[i]/14,sh=a[i]%14;
		for(int j=1;j<=14;j++)
			b[j]=a[j];
		b[i]=0;
		for(int j=1;j<=14;j++)
			b[j]+=num;
		for(int j=1;j<=sh;j++){
			if(j+i>14){
				b[(j+i)%14]++;
			}
			else b[j+i]++;
		}
		ll tmp=0;
		for(int j=1;j<=14;j++)
			if((b[j]%2)==0)
				tmp+=b[j];
		ans=max(ans,tmp);
	}
	cout<<ans<<endl;
	return 0;
}

