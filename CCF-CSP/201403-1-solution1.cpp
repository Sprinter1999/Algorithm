#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;
map<int,int> M;
int nums[501];
//使用map实现，可以学习set之后采用set实现一次 
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int temp;
		scanf("%d",&temp);
		nums[i]=temp;
		if(temp>=0&&M.find(temp)==M.end())
			M[temp]=1;
	}
	sort(nums+1,nums+n+1);
	
//	map<int,int>::iterator iter;
//	for(iter=M.begin();iter!=M.end();iter++)
//	{
//		printf("#%d is %d\n",iter->first,iter->second);
//	}

	int counter=0;
	for(int i=1;i<=n&&nums[i]<=0;i++)
	{
		if(M[-nums[i]]==1)
		{
			counter++;
		}
	}
	printf("%d\n",counter);
	return 0;
} 
