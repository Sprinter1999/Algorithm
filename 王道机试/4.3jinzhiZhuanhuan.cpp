#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
int trans(char c)
{
	if(c>='0'&&c<='9')
		return c-'0';
	else if(c=='A'||c=='a') return 10;
	else if(c=='B'||c=='b') return 11;
	else if(c=='C'||c=='c') return 12;
	else if(c=='D'||c=='d') return 13;
	else if(c=='E'||c=='e') return 14;
	else if(c=='F'||c=='f') return 15;
}

char tran(int c)
{
	if(c>=0&&c<=9)
		return c+'0';
	else if(c==10) return 'A';
	else if(c==11) return 'B';
	else if(c==12) return 'C';
	else if(c==13) return 'D';
	else if(c==14) return 'E';
	else if(c==15) return 'F';
}
int main()
{
	long a,b;
	string num;
	cin>>a>>num>>b;
	long ans=0;
	for(int i=0;i<num.size();i++)
	{
		ans*=a;
		ans+=trans(num[i]);
	}
	vector<char> an;
	while(ans)
	{
		int temp=ans%b;
		an.push_back(tran(temp));
		ans/=b;
	}
	for(int i=an.size()-1;i>=0;i--)
	{
		printf("%c",an[i]);
	}
	printf("\n");
	return 0;
}
