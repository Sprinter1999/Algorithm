#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	int m;
	int a,b;
	
	scanf("%d%d%d",&m,&a,&b);
	int c=a+b;
	vector<int> ans;
	while(c>0)
	{
		int temp=c%m;
		ans.push_back(temp);
		c/=m;
	}
	for(int i=ans.size()-1;i>=0;i--)
	{
		printf("%d",ans[i]);
	}
	printf("\n");
	return 0;
}
