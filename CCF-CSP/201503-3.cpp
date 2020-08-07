#include <stdio.h> 
#define ISYEAR(x) x%100!=0&&x%4==0 || x%400==0?1:0

int daysOfMonth[13][2]=
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

struct Date
{
	int Day;
	int Month;
	int Year;
	
	void nextDay()
	{
		Day++;
		//跨月了 
		if(Day>daysOfMonth[Month][ISYEAR(Year)])
		{
			Day=1;
			Month++;
			if(Month>12)
			{
				Month=1;
				Year++;
			} 
		}
	}
};


int buf[2060][13][32];
//处理星期几的映射 
int mapper(int x)
{
	int ans=0;
	switch(x)
	{
		case 0:ans=2;break;
		case 1:ans=3;break;
		case 2:ans=4;break;
		case 3:ans=5;break;
		case 4:ans=6;break;
		case 5:ans=7;break;
		default:ans=1;break;
	};
	return ans;
}

int main()
{
	int count=0;
	Date temp;
	temp.Year=1850;
	temp.Month=1;
	temp.Day=1;
	while(temp.Year!=2060)
	{
		buf[temp.Year][temp.Month][temp.Day]=count;
		temp.nextDay();
		count++;
	}
	
	int tMonth,tWeek,tWeekday,yearA,yearB;
	scanf("%d%d%d%d%d",&tMonth,&tWeek,&tWeekday,&yearA,&yearB);
	
	for(int curYear=yearA;curYear<=yearB;curYear++)
	{
		int curMonth=tMonth;
		int initialWeekday=mapper((buf[curYear][curMonth][1]-buf[1850][1][1])%7);
		int days=daysOfMonth[curMonth][ISYEAR(curMonth)];
		int weekdays[days+1];
		int curWeek=0;
		for(int i=1;i<=days;i++)
		{
			weekdays[i]=mapper((buf[curYear][curMonth][i]-buf[1850][1][1])%7);
		}
		int flag=0; //bucunzai 
		for(int i=1;i<=days;i++)
		{
			if(weekdays[i]==tWeekday)
			{
				curWeek++;
				if(curWeek==tWeek)
				{
					printf("%04d/%02d/%02d\n",curYear,curMonth,i);
					flag=1;
					break;
				}
			}		
		}
		if(flag==0)
		{
			printf("none\n");
		}
		
	}

	return 0;
}
