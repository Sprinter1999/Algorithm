#include<stdio.h>
#define ISYEAR(x) x % 100 != 0 && x % 4 == 0 || x % 400 == 0 ? 1 : 0

int dayOfMonth[13][2]={
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
	31,31
};

struct Date {
	int day;
	int month;
	int year;
	
	void nextDay()
	{
		//calculate the date of next day
		day++;
		if(day>dayOfMonth[month][ISYEAR(year)])
		{
			day=1;
			month++;
			if(month>12){
				month=1;
				year++;
			}
		}
	}
};

int buf[5001][13][32]; //缓存预处理的天数 

int Abs(int x)
{
	return x<0?-x:x;
}

int main()
{
	Date temp;
	int cnt=0;
	temp.day=1;
	temp.month=1;
	temp.year=0; //start:0000-01-01
	while(temp.year!=5001)
	{
		buf[temp.year][temp.month][temp.day]=cnt;
		temp.nextDay();
		cnt++;
	} 
	int d1,m1,y1;
	int d2,m2,y2;
	while(scanf("%4d%2d%2d",&y1,&m1,&d1)!=EOF)
	{
		scanf("%4d%2d%2d",&y2,&m2,&d2);
		printf("%d\n",Abs(buf[y2][m2][d2]-buf[y1][m1][d1])+1);
	}
	return 0;
 } 
