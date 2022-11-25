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
ll n,k,s;
ll cnt=0;
ll ans[200005];
int main(){
	n=read();k=read();s=read();
	ll now=1;
	while(s>0&&k>0){
		ll dis=max(abs(n-now),abs(1-now));
		if((s-n+1)>=0&&(s-n+1)>=k-1&&(now==1||now==n)){
			//cout<<s-dis<<" "<<s-dis-k<<endl;
			if(now==1){
				ans[++cnt]=n;
				now=n;
			}
			else {ans[++cnt]=1;now=1;}
			s-=dis;
			k--;
		}
		else{
			if(s==k){
				if(now==n){
					ans[++cnt]=now-1;
					now--;
					s--;
					k--;
				}
				else if(now==1){
					ans[++cnt]=now+1;
					now++;
					s--;
					k--;
				}
				else{
					ans[++cnt]=now+1;
					now++;
					s--;
					k--;
				}
			}
			else{
				dis=s-k+1;
				if(dis<=0){
					cout<<"NO"<<endl;
					return 0;
				}
				//cout<<dis<<endl;
				if(now-dis>=1){
					now-=dis;
					s-=dis;
					k--;
					ans[++cnt]=now;
				}
				else{
					now+=dis;
					s-=dis;
					k--;
					ans[++cnt]=now;
				}
			}
		}
		if(now<1||now>n){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	//int flag=(cnt!=1);
	if(ans[1]==1){
		cout<<"NO"<<endl;
		return 0;
	}
	for(int i=1;i<cnt;i++)
	if(ans[i]==ans[i+1]){
			cout<<"NO";
			return 0;
		}
	if(s!=0||k!=0){
		cout<<"NO"<<endl;
	}
	else{
		cout<<"YES"<<endl;
		for(int i=1;i<=cnt;i++)
			printf("%d ",ans[i]);
	}
	return 0;
}
