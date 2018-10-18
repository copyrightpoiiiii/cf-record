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
int n,s,hn,mn,ln,lm,flag;
int main(){
	n=read();s=read();
	ln=0;lm=0;
	for(int i=1;i<=n;i++){
		hn=read();mn=read();
		if(!flag){
			if(hn*60+mn>=s+1){
				cout<<0<<" "<<0<<endl;
				return 0;
			}
			flag=1;
		}
		if((hn-ln)*60+(mn-lm)>=s*2+2){
			lm++;
			lm+=s;
			ln+=lm/60;
			lm%=60;
			cout<<ln<<" "<<lm<<endl;
			return 0;
		}
		ln=hn;lm=mn;
	}
	mn++;
	mn+=s;
	hn+=mn/60;
	mn%=60;
	cout<<hn<<" "<<mn<<endl;
	return 0;
}

