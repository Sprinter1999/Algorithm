#include <cstdio>
#include <string>
using namespace std;
int maps[5];

bool test(int t)
{
	string test=to_string(t);
	if(test.find("7")==-1) return false;
	else
		return true;
}

int main()
{
	int n;scanf("%d",&n);
	int cnt=0,i=0;
	while(cnt!=n)
	{
		int thisTurn=i%4;
		i++; 
		if(i%7==0 || test(i)==true)
		{
			maps[thisTurn]+=1;
//			printf("%d at %d\n",thisTurn,i); 
		}else{
			cnt++;	
		}
//		i++;
	}
	for(int i=0;i<4;i++)
	{
		printf("%d\n",maps[i]);
	}
	return 0;
} 
