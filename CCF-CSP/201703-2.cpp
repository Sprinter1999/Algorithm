#include <cstdio>
#include <vector>
using namespace std;
vector<int> que;
int search(int p)
{
	for(int i=1;i<=que.size();i++)
	{
		if(que[i]==p)
		{
			return i;
		}
	}
	return -1;
}
int main() {
	int n,q;
	scanf("%d",&n);
	scanf("%d",&q);
	que.push_back(0);
	for(int i=1; i<=n; i++)
		que.push_back(i);
	for(int m=1; m<=q; m++) {
		int p,place;
		scanf("%d%d",&p,&place);
		int pp=search(p);
		int temp=que[pp];
		que.erase(que.begin()+pp,que.begin()+pp+1);
		que.insert(que.begin()+pp+place,temp);
//		printf("IN %d turn:",m);
//		for(int i=1; i<=n; i++) {
//			printf("%d",que[i]);
//			if(i!=n) {
//				printf(" ");
//			} else {
//				printf("\n");
//			}
//		}
	}
	for(int i=1; i<=n; i++) {
		printf("%d",que[i]);
		if(i!=n) {
			printf(" ");
		} else {
			printf("\n");
		}
	}
	return 0;
}
