#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;
int nums[1001];

int main() {
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&nums[i]);
	 } 
	sort(nums,nums+n);
	int pre=nums[0];
	int ans=0x3fffff;
	for(int i=1;i<n;i++)
	{
		int temp=nums[i]-pre;
		if(abs(temp)<ans)
		{
			ans=abs(temp);
		}
		pre=nums[i];
	}
	printf("%d\n",ans);
	return 0;
}
