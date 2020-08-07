#include <stdio.h>
#include <map>
#include <iostream>
using namespace std;
map<int,int> M;
int nums[1001];
int ans[1001];

int main()
{
	int n;
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	{
		int temp;
		scanf("%d",&temp);
		nums[i]=temp;
		
		if(M.find(temp)==M.end())
		{
			M[temp]=1;
		}
		else
		{
			M[temp]+=1;
		}
		ans[i]=M[temp];
	}
	
	for(int i=1;i<n;i++)
	{
		printf("%d ",ans[i]);
	}
	printf("%d\n",ans[n]);
	return 0;
}
