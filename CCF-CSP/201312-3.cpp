#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int nums[1001];
int dp[1001];

int main()
{
	int ans=1;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&nums[i]);
	}
	
	for(int i=1;i<=n;i++)
	{
		dp[i]=nums[i];
		int minus=nums[i];
//		printf("%d\n",i);
		for(int j=i;j<=n;j++)
		{
//			printf("%d %d turn\n",i,j); 
			minus=min(minus,nums[j]);
			int localRec=minus*(j-i+1);
			dp[i]=max(localRec,dp[i]);
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		ans=max(dp[i],ans);
	}
	printf("%d\n",ans);
}
