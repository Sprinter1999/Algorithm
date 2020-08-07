#include<stdio.h>
#include<queue>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\n",n);
	priority_queue<int> q;
	int nums[]={33,355,88,2,999};
	for(int i=0;i<sizeof(nums)/sizeof(int);i++)
	{
		q.push(-nums[i]);
	}
	while(!q.empty())
	{
		int top=q.top();
		printf("%d\n",-top);
		q.pop();
	}
	return 0;
 } 
