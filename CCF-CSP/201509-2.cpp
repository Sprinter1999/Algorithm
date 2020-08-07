#include <stdio.h>
#define ISYEAR(x) x%100!=0&&x%4==0||x%400==0?1:0

int days[13][2]=
{
	0,0,
	31,31,
	28,29,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31, 
};

int main()
{
	int y,d;
	scanf("%d%d",&y,&d);
	int targetMonth=0;
	int counter;
	int targetDay=0;
	for(int i=1;i<=12;i++)
	{
		counter+=days[i][ISYEAR(y)];
		if(d>counter)
		{
			continue;
		}
		else
		{
			targetMonth=i;
			targetDay=days[i][ISYEAR(y)]-(counter-d)+1;
			break;
		}
	}
	
	printf("%d\n%d\n",targetMonth,targetDay);
	return 0;
}
