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
int n;
int ans[10],book[10];//book[i]==1 i这个数已经被使用过了，book[i]==0 i这个数没有被使用过 
void dfs(int x){//dfs（x）表示已经坐了x个座位 
	if(x==n+1){
		for(int i=1;i<=n;i++)
			printf("%d ",ans[i]);//输出我们找到的一个全排列
		printf("\n");
		return ; 
	}
	else {
		for(int i=1;i<=n;i++)
			if(book[i]==0)//第i个数没有被使用的话
			{
				ans[x]=i;//把第i个数字放入 
				book[i]=1;//表示第i个数字被选了
				cout<<"这是第"<<x<<"位的选择情况"<<endl;
				for(int j=1;j<=x;j++)
					cout<<ans[j]<<" ";
				printf("\n");
				cout<<i<<endl; 
				dfs(x+1);
				book[i]=0;//使第i个数可以在之后被选择 
			} 
	}
}
int main(){
	cin>>n;
	dfs(1);
	return 0;
}

