#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	int nums[100];
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&nums[i]);
	}
	sort(nums,nums+n,cmp);
	for(int i=0;i<n;i++)
	{
		printf("%d ",nums[i]);
	}
	return 0;
 } 
