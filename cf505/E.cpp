long long gcd(long long x,long long y){return y?gcd(y,x%y):x;}
int a[maxn],b[maxn][maxn],dp[maxn][maxn][2];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=n+1;j++)
		{
			b[i][j]=gcd(a[i],a[j]);
			dp[i][j][0]=dp[i][j][1]=1;
			//cout<<i<<' '<<j<<' '<<b[i][j]<<endl;
		}
	for(int l=1;l<=n;l++)
		for(int i=1;i+l-1<=n;i++)
		{
			int j=i+l-1;
			dp[i][j][0]=dp[i][j][1]=0;
			if(i==1)dp[i][j][0]=0;
			else
			{
				for(int k=i;k<=j;k++)
					if(b[i-1][k]>1)
						dp[i][j][0]|=(dp[i][k-1][1]&&dp[k+1][j][0]);
			}
			if(j==n)dp[i][j][1]=0;
			else
			{
				for(int k=i;k<=j;k++)
					if(b[j+1][k]>1)
						dp[i][j][1]|=(dp[i][k-1][1]&&dp[k+1][j][0]);
			}
			//cout<<i<<' '<<j<<' '<<dp[i][j][0]<<' '<<dp[i][j][1]<<endl;
		}
	bool ans=0;
	for(int i=1;i<=n;i++)ans|=(dp[1][i-1][1]&dp[i+1][n][0]);
	cout<<(ans?"Yes":"No")<<endl;
	return 0;
}
