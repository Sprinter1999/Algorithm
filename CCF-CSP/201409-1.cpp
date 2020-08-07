#include <stdio.h>
#include <map>
using namespace std;
map<int,int> M;
int nums[1001];
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
	} 
	int counter=0;
	for(int i=1;i<=n;i++)
	{
		int temp=nums[i];
		if(M.find(temp+1)!=M.end())
		{
			counter++;
		}
		if(M.find(temp-1)!=M.end())
		{
			counter++;
		}
	}
	printf("%d\n",counter/2);
	return 0;
}
