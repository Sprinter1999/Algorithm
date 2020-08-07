#include <stdio.h>
#include <string>
#include <string.h>
#include <map>
#include <vector>
#include <iostream>
using namespace std;
map<string,int> isArg;

vector<string> split(string s,char delim)
{
	vector<string> sequence;
	int first=s.find(delim);
	while(first>=0)
	{
		string temp(s,0,first);
		sequence.push_back(temp);
		s.erase(0,first+1);
		first=s.find(delim);
	}
	if(s!="")
	{
		sequence.push_back(s);
	}
	return sequence;
}


int main()
{
	string pattern;
	cin>>pattern;
	for(int i=0;i<pattern.size();i++)
	{
		string temp="1";
		temp[0]=pattern[i];
		if(temp!=":"&&isArg.find("-"+temp)==isArg.end())
		{
			isArg["-"+temp]=0;//0表示无参选项 
		}
		else
		{
			temp[0]=pattern[i-1];
			isArg["-"+temp]=1;//1表示有参选项 
		}
	}
	
	int n;
	scanf("%d",&n);
	getchar();
	for(int i=1;i<=n;i++)
	{
		string aLine;
		getline(cin,aLine);
		map<string,string> M; //用于映射 
		vector<string> temp=split(aLine,' ');
		if(temp.size()==1)
		{
			cout<<"Case "<<i<<": "<<endl;
			continue;
		}
		int pos=0;
		bool flag=false;
		
		while(pos!=temp.size())
		{
			if(pos==0)
				pos=1;
				
			string once=temp[pos];
			string second;
			if(pos!=temp.size()-1)
				second=temp[pos+1];
				
			if(isArg.find(once)!=isArg.end())
			{
				//说明在参数表中
				int args=isArg[once];
				if(args==0)
				{
					//说明是无参数 
					if(M.find(once)==M.end())
						M[once]="-1"; //遇到-1最后单独处理 
					pos++;
					if(second.find('-')!=0)
					{
						//说明有问题 
						break;
					}
				}
				else
				{
					//说明是有参数
					if(pos!=temp.size()-1&&second.find('-')==0)
					{
						//说明仍然是选项,存疑 
						break;
					}
					M[once]=second;
					pos=pos+2;
				}
			}
			else
			{
				//说明参数表不包含输入的选项 
				break;
			} 
		}
		
		map<string,string>::iterator iter;
		cout<<"Case "<<i<<": ";
		int count=0;
		for(iter=M.begin();iter!=M.end();iter++,count++)
		{
			if(iter->second=="-1")
				cout<<iter->first;
			else
			{
				cout<<iter->first<<" "<<iter->second; 
			}
			if(count!=M.size()-1)
				cout<<" ";	
		}
		cout<<endl;
		M.clear();

	}

	return 0;
}
