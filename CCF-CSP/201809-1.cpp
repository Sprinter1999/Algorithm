#include <cstdio>
#include <math.h>

int main()
{
	int n;
	int nums[1001];
	int ans[1001];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&nums[i]);
	}
	ans[1]=(nums[1]+nums[2])/2;
	ans[n]=(nums[n]+nums[n-1])/2;
	
	for(int i=2;i<n;i++)
	{
		ans[i]=(nums[i]+nums[i-1]+nums[i+1])/3;
	}
	
	for(int i=1;i<=n;i++)
	{
		printf("%d",ans[i]);
		if(i==n)
		{
			printf("\n");
		}
		else{
			printf(" ");
		}
	}
	return 0;
 } 
