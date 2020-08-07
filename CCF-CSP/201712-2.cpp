#include <cstdio>
#include <map>
using namespace std;

map<int,int> M;

int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	if(n==1)
	{
		printf("1\n");
		return 0;
	}
	for(int i=1; i<=n; i++) {
		M[i]=i;
	}
	
	int it=1+n;
	int remain=n;
	while(remain>1) {
		map<int,int>::iterator iter;
		if(remain!=n) {
			for(iter=M.begin(); iter!=M.end(); iter++) {
				M[iter->first]=it;
				it++;
			}
		}
		for(iter=M.begin(); iter!=M.end();) {
			int key=iter->first;
			int val=iter->second;
			//printf("PAIR is %d : %d\n",iter->first,iter->second);
			if(val%k==0||(val%10)==k) {
				M.erase(iter++);
				remain--;
			}else
			{
				iter++;
			}
		}
	}
	map<int,int>::iterator iterr;
	int ans=M.begin()->first;
	printf("%d\n",ans);
	return 0;
}
