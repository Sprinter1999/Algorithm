#include <cstdio>
#include <vector>
using namespace std;
vector<int> vec[21];
//90�֣�10��Ӧ�����п������벻��ȫ���룬�ټ�һ�������ok�� 
int main()
{
	for(int i=1;i<=20;i++)
	{
		vec[i].push_back((i-1)*5);
	}
	int n;
	scanf("%d",&n);
	int query[101];
	for(int i=1;i<=n;i++)
	{
		//��i������
		scanf("%d",&query[i]); 
	}
	
	for(int i=1;i<=n;i++)
	{
		int seats=query[i];
		for(int j=1;j<=20;j++)
		{
			if(vec[j].size()+seats<=6)
			{
				int size=vec[j].size();
				int base=vec[j][size-1];
				for(int t=1;t<=seats;t++)
				{
					int stuff=base+t;
					vec[j].push_back(stuff);
					printf("%d",stuff);
					if(t!=seats)
					{
						printf(" ");
					}else{
						printf("\n");
					}
				}
				break;
			}
			else
			{
				continue;
			}
		}
	}
	return 0;
}
