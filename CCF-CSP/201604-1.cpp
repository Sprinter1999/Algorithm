#include <stdio.h>
int nums[1001];
bool trend[1001]= {0}; //0表示增，1表示减

int main() {
	int n;
	scanf("%d",&n);

	for(int i=1; i<=n; i++) {
		int temp;
		scanf("%d",&temp);
		nums[i]=temp;
	}

	if(n==1||n==2) {
		printf("0\n");
		return 0;
	}

	int pre=nums[2];
	int counter=0;
	trend[2]=(nums[2]>nums[1]?0:1);

	for(int i=3; i<=n; i++) {
		int once=nums[i];
		if(once>pre) {
			trend[i]=0;
		} else {
			trend[i]=1;
		}

		if(trend[i]!=trend[i-1]) {
//			printf("%d \n",i); 
			counter++;	
		}
		pre=once;
	}
	printf("%d\n",counter);
	
	return 0;
}
/*

#include <stdio.h>  
 
#define N 1000
int s[N + 1];
  
int main(void)  
{
	int n,i,count=0;
	
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&s[i]);
	}
	
	for(i=1;i<n-1;i++){
		if(s[i-1] > s[i] && s[i] < s[i+1]){
			count++;
		}
		if(s[i-1] < s[i] && s[i] > s[i+1]){
			count++;
		}		
	}
	
	printf("%d\n",count);
 
	return 0;
}

*/
