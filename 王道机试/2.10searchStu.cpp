#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;
struct Stu{
	string num;
	string name;
	string sex;
	int year;
	Stu():num(),name(),sex(),year() {}
	Stu(string nu,string na,string sex,int year):num(nu),name(na),sex(sex),year(year){}	
}list[1001];

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		string sex;
		string name;
		string num;
		int year;
//		scanf("%s %s %s %d",&num,&name,&sex,&year);
		cin>>num>>name>>sex>>year;
		Stu st(num,name,sex,year);
		int numer=atoi(num.c_str());
//		printf("%d\n",numer);
		list[numer]=st;
	}
	int M;
	scanf("%d",&M);
	for(int i=0;i<M;i++)
	{
		string search;
//		scanf("%s",search);
		cin>>search;
		int searchNum=atoi(search.c_str());
		printf("U search %d\n",searchNum);
		if(list[searchNum].year!=0)
		{
			Stu temp=list[searchNum];
//			printf("%s %s %s %d\n",temp.num,temp.name,temp.sex,temp.year);
			cout<<temp.num<<" "<<temp.name<<" "<<temp.sex<<" "<<temp.year<<endl;
		}
		else
		{
			printf("No Answer!\n");
		}
	}
	return 0;
 } 
