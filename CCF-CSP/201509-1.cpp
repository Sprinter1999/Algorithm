#include <stdio.h>

int nums[1001];

int main()
{
	int n;
	scanf("%d",&n);

	for(int i=1;i<=n;i++)
	{
		scanf("%d",&nums[i]);
	}
	
	int pre=nums[1];
	int counter=1;
	for(int i=2;i<=n;i++)
	{
		if(nums[i]!=pre)
		{
			pre=nums[i];
			counter++;
		}
	}
	printf("%d\n",counter);
	return 0;
 } 
