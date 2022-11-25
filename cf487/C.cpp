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
char mp[55][55];
struct flo{
	int sum;
	char ch;
}flow[5];
bool cmp(flo a,flo b){
	return a.sum<b.sum;
}
int main(){
	for(int i=1;i<=50;i++)
		for(int j=1;j<=50;j++)
			mp[i][j]='0';
	for(int i=1;i<=4;i++){
		flow[i].sum=read();
	}
	flow[1].ch='A';
	flow[2].ch='B';
	flow[3].ch='C';
	flow[4].ch='D';
	sort(flow+1,flow+5,cmp);
	int n=4,m=0;
	for(int i=1;i<49;i+=2){
		if(flow[1].sum==1)
			break;
		if(flow[1].sum==2){
			mp[2][i]=flow[1].ch;
			m=i;
			flow[1].sum--;
		}
		else if(flow[1].sum>2){
			mp[2][i]=mp[3][i+1]=flow[1].ch;
			m=i+1;
			flow[1].sum-=2;
		}
	}
	if(flow[1].sum>1){
		n=7;
		for(int i=1;i<49;i+=2){
		if(flow[1].sum==1)
			break;
		if(flow[1].sum==2){
			mp[5][i]=flow[1].ch;
			flow[1].sum--;
		}
		else if(flow[1].sum>2){
			mp[5][i]=mp[6][i+1]=flow[1].ch;
			flow[1].sum-=2;
		}
	}
	}
	if(flow[1].sum>1){
		n=10;
		for(int i=1;i<49;i+=2){
		if(flow[1].sum==1)
			break;
		if(flow[1].sum==2){
			mp[8][i]=flow[1].ch;
			flow[1].sum--;
		}
		else if(flow[1].sum>2){
			mp[8][i]=mp[9][i+1]=flow[1].ch;
			flow[1].sum-=2;
		}
	}	
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m+1;j++){
			if(mp[i][j]!=flow[1].ch)
				mp[i][j]=flow[2].ch;
		}
	m++;
	n+=2;int nowl=1;
	flow[2].sum--;
	for(int i=1;i<=flow[2].sum;i++){
		mp[n][nowl]=flow[2].ch;
		nowl+=2;
		if(nowl>=50){
			n+=2;
			nowl=1;
		}
	}
	for(int i=1;i<=flow[3].sum;i++){
		mp[n][nowl]=flow[3].ch;
		nowl+=2;
		if(nowl>=50){
			n+=2;
			nowl=1;
		}
	}
	for(int i=1;i<=flow[4].sum;i++){
		mp[n][nowl]=flow[4].ch;
		nowl+=2;
		if(nowl>=50){
			n+=2;
			nowl=1;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=50;j++)
			if(mp[i][j]=='0')
				mp[i][j]=flow[1].ch;
	cout<<n<<' '<<"50"<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=50;j++)
			cout<<mp[i][j];
		cout<<endl;
	}
	return 0;
}

