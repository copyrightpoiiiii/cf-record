#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//using namespace std;
//int next[6][4];
int ans[3][10];
int main(){
	int next[6][4];
	memset(next,0,sizeof(0));
	int now=0,now2=1,flag=1;
	for(int i=1;i<25;i+=5){
		for(int j=0;j<5;j++){
			printf("%d ",i+j);
		}
		printf("\n");
		fflush(stdout);
		for(int j=0;j<5;j++){
			int x;scanf("%d",&x);
			if(x==1||x==2){
				ans[x][now2]=i+j;
			}
		}
		now2++;
	}
	now=0;
	for(int i=1;i<=5;i++)
		printf("%d ",ans[1][i]);
	printf("\n");
	fflush(stdout);
	int n1=0,n2=0;
	for(int i=1;i<=5;i++){
		int x;scanf("%d",&x);
		if(x==1){
			n1=ans[1][i];
			ans[1][6]=ans[2][i];
		}
		else
			ans[x][6]=ans[1][i];
	}
	for(int i=1;i<=5;i++)
		printf("%d ",ans[i][6]);
	printf("\n");
	fflush(stdout);
	for(int i=1;i<=5;i++){
		int x;scanf("%d",&x);
		if(x==1)n2=ans[i][6];
	}
	printf("%d %d 0 0 0\n",n1,n2);  
	fflush(stdout);  
	fflush(stdout); 
	return 0;
}

