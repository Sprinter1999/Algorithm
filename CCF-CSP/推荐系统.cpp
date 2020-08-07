#include<bits/stdc++.h> 
using namespace std;
#define maxn 30005
#define maxm 55
#define inf 2000000000
#define IOS ios::sync_with_stdio(false)

struct G{
	int be;
	int id;
	int score;
}; 

struct cmp
{
	bool operator ()(G a,G b){
		if(a.score==b.score)
		{
			if(a.be==b.be)
				return a.id<b.id;
			else
				return a.be<b.be;
		}
        return a.score>b.score;
    }
};

int main()
{
	IOS;
	int m,n;
	cin>>m>>n;
	set<G,cmp> tt;
	map<pair<int,int>,int>mm;
	for(int i=0;i<n;i++)
	{
		int id,score;
		cin>>id>>score;
		for(int j=0;j<m;j++)
		{
			tt.insert(G{j,id,score});
			mm[make_pair(j,id)]=score;
		}
	}
	
	int op;
	cin>>op;
	for(int i=0;i<op;i++)
	{
		int ch;
		cin>>ch;
		if(ch==1)//增加 
		{
			int be,id,score;
			cin>>be>>id>>score;
			mm[make_pair(be,id)]=score;
			tt.insert(G{be,id,score});
		}
		if(ch==2)//删除 
		{
			int be,id;
			cin>>be>>id;
			int score=mm[make_pair(be,id)];
			tt.erase(G{be,id,score});
		}
		if(ch==3)//查询 
		{
			int k;
			cin>>k;
			int ff[maxm]={0};
			int cnt[maxm]={0};
			for(int j=0;j<m;j++)
				cin>>ff[j];
			vector<int>V[m];
			
			int sum=0;
			for(set<G,cmp>::iterator p=tt.begin();p!=tt.end();p++)
			{
				int be=(*p).be;
				if(sum<k)
				{
					if(cnt[be]<ff[be])
					{
						sum++;
						cnt[be]++;
						V[be].push_back((*p).id);
					}
				}
				else
					break;
				
				/*这一段代码不加，只有八十分，算一下复杂度，感觉最后两个数据没卡我，就这样过了*/
				bool flag=true;
				for(int j=0;j<m;j++)
					if(cnt[j]!=ff[j])
					{
						flag=false;
						break;
					}
				if(flag)
					break;
			}
			
			for(int j=0;j<m;j++)
			{
				if(V[j].size()==0)
					cout<<-1;
				else
				{
					for(int k=0;k<V[j].size();k++)
						cout<<V[j][k]<<" ";
				}
				cout<<"\n";
			}
		}
	}
    return 0;
}

