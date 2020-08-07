#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

struct Node{
	string name;
	int old;
	int grade;
	//char name[101];int temp=strcmp(str1,str2);
	bool operator < (const Node &b) const{
		if(grade!=b.grade) return grade<b.grade;
		if(name!=b.name) return name<b.name;
		else{
			return grade<b.grade;
		}
	};
	
	Node():name(),old(),grade(){}
	Node(string _n,int _o,int _g):name(_n),old(_o),grade(_g){}
}list[1000];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		string temp1;
		int temp2,temp3;
//		scanf("%s %d %d",temp1,temp2,temp3);
		cin>>temp1>>temp2>>temp3;
		Node node(temp1,temp2,temp3);
		list[i]=node;
	} 
	sort(list,list+n);
	for(int i=0;i<n;i++)
	{
		cout<<list[i].name<<endl;
		printf("%s\n",list[i].name.c_str());
	}
	return 0;
}
