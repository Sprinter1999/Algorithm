#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string pattern;
	cin>>pattern;
	int choice;
	scanf("%d",&choice);
	int n;
	scanf("%d",&n);
	if(choice==0)
	{
		transform(pattern.begin(),pattern.end(),pattern.begin(),::tolower);
	}
	
	for(int i=1;i<=n;i++)
	{
		string once;
		cin>>once; 
		if(choice==1)//¥Û–°–¥√Ù∏– 
		{
			if(once.find(pattern,0)!=-1)
				cout<<once<<endl;
		}
		else
		{
			string backup=once;
			transform(once.begin(),once.end(),backup.begin(),::tolower);
			if(backup.find(pattern,0)!=-1)
				cout<<once<<endl;
		}
	}
	return 0;
}
