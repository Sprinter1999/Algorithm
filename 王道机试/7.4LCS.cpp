#include <stdio.h>
#include <string.h>
int dp[101][101];
int max(int a,int b){
	return a>b?a:b;
}

int main()
{
	char str1[101],str2[101];
	while(scanf("%s%s",str1,str2)!=EOF)
	{
		int L1=strlen(str1);int L2=strlen(str2);
		for(int i=0;i<L1;i++) dp[i][0]=0;
		for(int i=0;i<L2;i++) dp[0][i]=0;
		
		for(int i=1;i<=L1;i++)
		{
			for(int j=1;j<=L2;j++)
			{
				if(str1[i-1]!=str2[j-1]) //字符下标事从0开始的
				{
					dp[i][j] = max(dp[i][j - 1],dp[i - 1][j]);
				}else{
					dp[i][j]=dp[i-1][j-1]+1;
				} 
			}
		}
		printf("%d\n",dp[L1][L2]);
	}
	return 0;
}
