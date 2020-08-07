#include <stdio.h>
#include <string.h>
char str[20];
int main()
{
	scanf("%s",str);
	int n=strlen(str);
	int count=0;
	for(int i=0;i<n;i++)
	{
		count+=str[i]-'0';
	}
	printf("%d\n",count);
	return 0;
} 
