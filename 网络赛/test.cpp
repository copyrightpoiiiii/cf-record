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
int ans[10],book[10];//book[i]==1 i������Ѿ���ʹ�ù��ˣ�book[i]==0 i�����û�б�ʹ�ù� 
void dfs(int x){//dfs��x����ʾ�Ѿ�����x����λ 
	if(x==n+1){
		for(int i=1;i<=n;i++)
			printf("%d ",ans[i]);//��������ҵ���һ��ȫ����
		printf("\n");
		return ; 
	}
	else {
		for(int i=1;i<=n;i++)
			if(book[i]==0)//��i����û�б�ʹ�õĻ�
			{
				ans[x]=i;//�ѵ�i�����ַ��� 
				book[i]=1;//��ʾ��i�����ֱ�ѡ��
				cout<<"���ǵ�"<<x<<"λ��ѡ�����"<<endl;
				for(int j=1;j<=x;j++)
					cout<<ans[j]<<" ";
				printf("\n");
				cout<<i<<endl; 
				dfs(x+1);
				book[i]=0;//ʹ��i����������֮��ѡ�� 
			} 
	}
}
int main(){
	cin>>n;
	dfs(1);
	return 0;
}

