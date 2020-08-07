#include <cstdio>
int nums[1001];

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) 
		scanf("%d",&nums[i]);
		
	int ans=0,once=0;
	for(int i=1;i<=n;i++)
	{
		once+=nums[i];
		if(i==n)
		{
			ans+=1;
			break;
		}
		if(once>=k)
		{
			ans+=1;
			once=0;
		}
	}
	printf("%d\n",ans);
	return 0;
 } 
