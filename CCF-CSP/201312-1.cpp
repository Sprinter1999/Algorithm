#include <stdio.h>
#include <map>
#include <iostream>
using namespace std;
map<int,int> M;
int nums[10001];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int temp;
		scanf("%d",&temp);
		nums[i]=temp;
		if(M.find(nums[i])==M.end())
		{
			M[nums[i]]=1;
		}
		else
		{
			M[nums[i]]=M[nums[i]]+1;
		}
	}
	map<int,int>::iterator iter;
//	for(iter=M.begin();iter!=M.end();iter++)
//	{
//		printf("#%d is %d times\n",iter->first,iter->second);
//	}
//	printf("REVERSE\n");
	map<int,int>::reverse_iterator rit;
	int maxi=0,ans=1;
	for(rit=M.rbegin();rit!=M.rend();rit++)
	{
		int keyOnce=rit->first,valOnce=rit->second;
		if(valOnce>=maxi)
		{
			maxi=valOnce;
			ans=keyOnce;
		}
	}
	printf("%d\n",ans);
	return 0;
}
 
