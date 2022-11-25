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
int n,m,tot;
int num[3005];
int num2[3005];
ll w[3005][3005];
int book[3005];
struct st{
	int p,rank;
	ll c;
}a[3005];
bool cmp(st a,st b){
	return a.c<b.c;
}
bool judge(){
	int flag=0;
	for(int i=2;i<=m;i++)
		if(num[i]>=num[1]){
			flag=1;
			break;
		}
	return flag;
}
int main(){
	n=read();m=read();
	for(int i=1;i<=n;i++){
		int x=read();ll y=read();
		if(x==1)num[1]++;
		else{
			num[x]++;
			w[x][num[x]]=y;
			a[++tot].p=x;a[tot].c=y;
		}
	}
	int flag=0;
	for(int i=2;i<=m;i++)
		if(num[i]>=num[1]){
			flag=1;
			break;
		}
	if(!flag){
		cout<<0<<endl;
	}
	else{
		sort(a+1,a+tot+1,cmp);
		int mx_tmp=0;
		for(int i=2;i<=m;i++)
			mx_tmp=max(mx_tmp,num[i]);
		int mb=mx_tmp+1;
		ll ans=1;ans<<=60;
		//cout<<ans<<endl;
		for(int i=2;i<=m;i++)
			sort(w[i]+1,w[i]+num[i]+1);
		for(int i=2;i<=m;i++)
			for(int j=2;j<=num[i];j++)
				w[i][j]+=w[i][j-1];
		for(int i=1;i<=tot;i++){
			num2[a[i].p]++;
			a[i].rank=num2[a[i].p];
		}
			
		for(int i=num[1]+1;i<=mb;i++){
			ll tmp=0,nee=i-num[1];
			memset(book,0,sizeof(book));
			//cout<<i<<endl;
			for(int j=2;j<=m;j++)
				if(num[j]>=i){
					tmp+=w[j][num[j]-i+1];
					nee-=num[j]-i+1;
					book[j]=num[j]-i+1;
					//cout<<nee<<endl;
					
				}
			//cout<<tmp<<endl;
			//cout<<nee<<endl;
			if(nee>0){
				for(int j=1;j<=tot;j++){
					if(nee==0)break;
					if(a[j].rank>book[a[j].p]){
						tmp+=a[j].c;
						nee--;
					}
				}
			}
			ans=min(ans,tmp);
		}
		cout<<ans<<endl;
	}
	return 0;
}

