#include <cstdio>

int main()
{
	int input=0;
	int score=0,i=0;
	int nums[31];
	while(scanf("%d",&input)&&input!=0)
	{
		nums[i++]=input;
	}
	int len=i,pre=nums[0];
	int index=0;
	if(pre==1)
	{
		score=1;
		index=0;
	}else{
		score=2;
		index=1;
	}
	
	for(int i=1;i<len;i++){
		if(nums[i]==1)
		{
			index=0;
			score++;
			pre=nums[i];
			continue;
		}
		if(nums[i]==2&&pre==2)
		{
			index++;
			score+=2*index; 
			pre=nums[i];
			continue;
		}
		if(nums[i]==2&&pre==1)
		{
			index=1;
			score+=2;
			pre=nums[i];
			continue;
		}
	}
	
	printf("%d\n",score);
	return 0;
}
