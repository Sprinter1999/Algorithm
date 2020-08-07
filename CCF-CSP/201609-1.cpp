#include <cstdio>
#include <math.h>
int nums[1001];

int main() {
	int n;
	scanf("%d",&n);
	int pre,max=0;
	for(int i=1; i<=n; i++) {
		int temp;
		scanf("%d",&temp);
		nums[i]=temp;

		if(i>1) {
			pre=nums[i-1];
			int once=abs(temp-pre);

			max=max>once?max:once;
		}
	}
	printf("%d\n",max);
}
