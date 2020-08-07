#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;

int main()
{
	char str[14];
	scanf("%s",str);
	char preProcess[14];
	int idx=0;
	for(int i=0;i<strlen(str);i++)
	{
		if(str[i]!='-')
		{
			preProcess[idx++]=str[i];
		}
	}
	string s=preProcess;
	int checkSum=0;
	for(int i=0;i<9;i++)
	{
		checkSum+=(s[i]-'0')*(i+1);
	}
	char moderBit=checkSum%11+'0';
	if(checkSum%11==10)
		moderBit='X';
	
	if(str[12]==moderBit)
	{
		printf("Right\n");
	}
	else
	{
		str[12]=moderBit;
		printf("%s",str);
	}
	return 0;
	
}

