#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;
map<string,string> M;
vector<string> vec;
 
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	getchar();
	for(int i=1;i<=m;i++)
	{
		string temp;
		getline(cin,temp);
		vec.push_back(temp);	
	}
	for(int i=1;i<=n;i++)
	{
		string temp;
		getline(cin,temp);
		int quoterFir=temp.find('"');
		temp.erase(quoterFir,1);
		quoterFir=temp.find('"');
		temp.erase(quoterFir,1);
		
		int p=temp.find(" ");
		string key="{{ "+temp.substr(0,p)+" }}";
		string value=temp.substr(p+1);
		
		M[key]=value;
	}
	map<string,string>::iterator iter;
	for(int i=0;i<vec.size();i++)
	{
		string once=vec[i];
		
		for(iter=M.begin();iter!=M.end();iter++)
		{
			string keyOnce=iter->first;
			string valOnce=iter->second;
			
			while(once.find(keyOnce)!=-1)
			{
				int pos=once.find(keyOnce);
				once.erase(pos,keyOnce.size());
				once.insert(pos,valOnce);
			}
			
			if(once.find("{{")==-1)
				break;
		}
		
		while(once.find("{{")!=-1)
		{
			int posA=once.find("{{");
			int posB=once.find("}}");
			once.erase(posA,posB-posA+2);
		}
		
		cout<<once<<endl;
	}
	
	return 0;
}
