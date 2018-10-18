#include<bits/stdc++.h>
#define inf 1000000000
#define maxn 200000+5
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
int n,q;
ll a[maxn];
int main(){
	n=read();q=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		a[i]+=a[i-1];
	}
	ll shang=a[1],now=1;
	for(int i=1;i<=q;i++){
		ll b=read();
		//cout<<b<<" "<<shang<<endl;
		if(b<shang){
			shang-=b;
			printf("%d\n",n-now+1);
			continue;
		}
		if(b==shang){
			now++;
			if(now>n)now=1;
			shang=a[now]-a[now-1];
			printf("%d\n",n-now+1);
			continue;
		}
		if((b-shang)>=(a[n]-a[now])){
			shang=a[1];now=1;
			printf("%d\n",n);
		}
		else {
			b-=shang;now++;
			int l=now,r=n,flag=1;
			while(l<=r){
				int mid=(l+r)>>1;
				if(a[mid]-a[now-1]==b){
					shang=a[mid+1]-a[mid];now=mid+1;
					printf("%d\n",n-now+1);
					flag=0;
					break;
				}
				if(a[mid]-a[now-1]>b)r=mid-1;
				else l=mid+1;
			}
			if(flag){
				//cout<<i<<" "<<l<<" "<<now<<" "<<shang<<endl;
				while((a[l-1]-a[now-1])>b)l--;
				while((a[l]-a[now-1])<b&&l<n)l++;
				//cout<<i<<" "<<l<<" "<<now<<" "<<shang<<endl;
				shang=a[l]-a[now-1]-b;now=l;
				printf("%d\n",n-now+1);
			}
		}
	}
	return 0;
}

