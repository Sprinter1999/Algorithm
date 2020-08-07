#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

map<int,int> M;

struct E
{
	int first;
	int second;
	
	bool operator < (const E &b) const
	{
		if(second!=b.second) return second > b.second;
		
		return first < b.first;
		;
	}
}list[1001];
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
		else
		{
			M[temp]+=1;
		}
	}
	
	map<int,int>::iterator iter;
	int index=0;
	for(iter=M.begin();iter!=M.end();iter++)
	{
//		printf("map pair: %d %d\n",iter->first,iter->second);
		list[index].first=iter->first;
		list[index].second=iter->second;
		index++;
	}
//	printf("%d pairs in list\n",index);
	sort(list,list+index);
	for(int i=0;i<index;i++)
	{
		E once=list[i];
		printf("%d %d\n",once.first,once.second);
	}
	
	return 0;
}
