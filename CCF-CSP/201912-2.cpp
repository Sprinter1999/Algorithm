#include <cstdio>
//#include <utility>
#include <set>
#include <map>
using namespace std;

set<pair<int,int>> container;
int scores[5];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		pair<int,int> once(a,b);
		container.insert(once);
	}
	set<pair<int,int>>::iterator iter;
	for(iter=container.begin();iter!=container.end();iter++)
	{
		pair<int,int> once=*iter;
		int x=once.first;
		int y=once.second;
		int cnt=0;
		if(container.find(make_pair(x,y+1)) != container.end()
			&& container.find(make_pair(x,y-1))!=container.end()
			&& container.find(make_pair(x+1,y))!=container.end()
			&& container.find(make_pair(x-1,y))!=container.end()){
			if(container.find(make_pair(x-1,y-1))!=container.end())
				cnt++;
			if(container.find(make_pair(x-1,y+1))!=container.end())
				cnt++;
			if(container.find(make_pair(x+1,y-1))!=container.end())
				cnt++;
			if(container.find(make_pair(x+1,y+1))!=container.end())
				cnt++;
			scores[cnt]+=1;
		}
	}
	for(int i=0;i<=4;i++)
		printf("%d\n",scores[i]);
	return 0;
}
