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
int a[200];
int w[200];
int t[5000];
int n,m,q;
int ans[5000][200];
int main(){
	n=read();m=read();q=read();
	for(int i=0;i<n;i++)
		w[i]=read();
	for(int i=1;i<=m;i++){
		int tmp=1<<(n-1),tmp2=0;
		for(int j=1;j<=n;j++){
			char ch=getchar();
			while(ch!='0'&&ch!='1')ch=getchar();
			tmp2+=tmp*(ch-'0');
			tmp>>=1;
		}
		//cout<<tmp2<<endl;
		t[tmp2]++;
	}
	int mx=1<<(n);
	//mx-=1;
	//cout<<mx<<" "<<mx-1<<endl;
	for(int i=0;i<mx;i++)
		for(int j=0;j<mx;j++)
			if(t[j]){
				unsigned int tmp=i^j;
				unsigned int k=1;
				int sum=0;
				for(int kk=0;kk<n;kk++){
					if((k&tmp)==0)
						sum+=w[n-1-kk];
					k<<=1;
					//if(sum>100)break;
				}
				//if(sum>100)continue;
				ans[i][sum]+=t[j];
			}
	for(int i=0;i<mx;i++)
		for(int j=1;j<=100;j++)
			ans[i][j]+=ans[i][j-1];
	for(int i=1;i<=q;i++){
		int tmp=1<<(n-1),tmp2=0;
		for(int j=1;j<=n;j++){
			char ch=getchar();
			while(ch!='0'&&ch!='1')ch=getchar();
			tmp2+=tmp*(ch-'0');
			tmp>>=1;
		}
		tmp=read();
		printf("%d\n",ans[tmp2][tmp]);
	}
	return 0;
}

