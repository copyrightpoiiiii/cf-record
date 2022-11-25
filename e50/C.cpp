#include<bits/stdc++.h>
#define inf 1000000000
#define maxn 100000+5
#define maxm 5000000+5
#define eps 1e-10
#define mod 1000000007
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
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int power(int x,int y){
	int t=1;
	for(;y;y>>=1,x=x*x%mod)
		if(y&1)t=t*x%mod;
	return t;
}
/*
void insert(int u,int v,int w){
	 e[++tot].go=v;e[tot].next=head[u];e[tot].w=w;head[u]=tot;
	 e[++tot].go=u;e[tot].next=head[v];e[tot].w=w;head[v]=tot;
}
*/
int n;
ll l,r;
ll cl[20];
int a1[20],b1[20],a[20],b[20];
int dig(ll x,int y){
	int cnt=0;
	if(y==1){
	while(x){
			a[++cnt]=x%10;
			x/=10;
		}
	}
	else{
	while(x){
			b[++cnt]=x%10;
			x/=10;
		}
	}
	return cnt;
}

int main(){
	n=read();
	cl[1]=1;cl[0]=1;
	for(int i=2;i<=20;i++){
		cl[i]=(ll)i*cl[i-1];
	}
	while(n--){
		ll ans=0;
		l=read();r=read();
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(a1,0,sizeof(a1));
		memset(b1,0,sizeof(b1));
		int dx=dig(l,1),dy=dig(r,2);
		/*for1(i,dx)
			a[i]=a1[dx-i+1];
		for1(i,dy)
			b[i]=b1[dy-i+1];*/
		for(int i=dx;i<=dy;i++){
			if(i>3){
				int ca=max(0,i-1);
				ll tmp=0;
				if(i>dx){
					if(i<dy){
						tmp=ca*(ca-1)/2;
						tmp*=81*9;
						tmp+=9;
					}
					else{
						for(int j=dy-1;j>=1;j--)
							if(b[j]==0){
							continue;
						}
						else{
							tmp+=b[j];
							tmp+=max(0,j-1)*9;
						}
						//cout<<b[dy]<<endl;
						tmp+=(b[dy]-1)*(dy-1)*9;
						tmp+=b[dy];
					}
				}else{
					if(i<dy){
						for(int j=dx-1;j>=1;j--)
								if(a[j]==0){
									tmp+=9;
								}
								else {
									for(int t=j-1;j>=1;j--){
										if(a[t]!=0){
											tmp-=10-a[j]-1;
											break;
										}
									}
									tmp+=10-a[j]-1;
									break;
								}
						//tmp+=(10-b[dy]+1)*(dy-1)*9;
						//tmp+=10-a[dx];
					}
					else{
						for(int j=a[dx]+1;j<b[dy];j++)
							tmp+=(dx-1)*9;
						if(a[dx]!=b[dy]){
							for(int j=dx-1;j>=1;j--)
								if(a[j]==0){
									tmp+=9;
								}
								else {
									tmp+=10-a[j]-1;
									break;
								}
							for(int j=dy-1;j>=1;j--)
								if(b[j]==0){
									continue;
								}
								else {
									tmp+=a[j];
									tmp+=(ll)max((ll)0,(ll)j-1)*9;
									break;
								}
							//tmp+=abs(a[dx]-b[dy]);
						}
						else{
							int cnt2=0;
							for(int j=dx;j>=1;j--)
								if(a[j]!=b[j]){
									tmp+=abs(a[j]-b[j])+1;
									break;
								}
								else{
									if(a[j]!=0)cnt2++;
									if(cnt2>3)break;
									if(j==1)tmp++;
								}
							//tmp++;
						}
					}
				}
				ans+=tmp;
			}
			else{
				if(i==1){
					ans+=min((ll)10,r+1)-l;
				}
				else if(i==2){
					ans+=min((ll)100,r+1)-max(l,(ll)10);
				}
				else if(i==3){
					ans+=min((ll)1000,r+1)-max(l,(ll)100);
				}
			}
			//cout<<ans<<endl;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}

