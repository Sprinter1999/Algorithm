#include <cstdio>
#include <map>
using namespace std;
int nums[1001];
map<int,int> M;

int main()
{
	int n;
	int total;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int temp;
		scanf("%d",&temp);
		nums[i]=temp;
		total+=1;
		if(M.find(temp)==M.end())
		{
			M[temp]=1;
		}else{
			M[temp]++;
		}
	}
	int ans=-1;
	int size=M.size();
	int left=0,right=total;
	map<int,int>::iterator iter;
	for(iter=M.begin();iter!=M.end();iter++)
	{
		if(left==right-iter->second)
		{
			ans=iter->first;
		}
		
		left+=iter->second;
		right-=iter->second;
	}
	printf("%d\n",ans);
	return 0;
}
