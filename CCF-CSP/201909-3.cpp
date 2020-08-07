#include <cstdio>
#include <algorithm>
using namespace std;

struct item{
	int type;
	int id;
	int score;
	
	item():type(),id(),score(){}
	item(int _m,int _i,int _s):type(_m),id(_i),score(_s){}
	
	bool operator < (const item &A) const{
		if(type!=A.type) return type<A.type;
		if(score!=A.score) return score>A.score;
		else
			return id<A.id;
	}
};

vector<item> list;

int N;

int main()
{
	int types,n;
	scanf("%d%d",&types,&n);
	N=types*n;
//	int cnt=0;
	for(int i=1;i<=n;i++) //1# ~ n#
	{
		int a,b; //id,score
		scanf("%d%d",&a,&b);
		for(int j=0;j<types;j++) //type 1# ~ type type#
		{
			item it(j,a,b);
			list.push_back(it);
			N++;
		}
	}
	sort(list.begin(),list.end());
	
	int opts;
	scanf("%d",&opts);
	for(int t=1;t<=opts;t++)
	{
		int opt;
		scanf("%d",&opt);
		if(opt==1)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			item it(x,y,z);
			list.push_back(it);
			N++;
		}
		else if(opt==2)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			int target=0;
			for(int i=0;i<N;i++)
			{
				item once=list[i];
				if(once.type==x && once.id==y)
				{
					target=i;
					break;
				}
			}
			list.erase(list.begin()+target);
			N--;
		}else if(opt==3)
		{
			sort(list.begin(),list.end());
			int K[50];
			int kk;
			int kkCount=0;
			scanf("%d",&kk);
			for(int i=0;i<types;i++)
			{
				scanf("%d",&K[i]);
			}
			int typeCnt=0;
			int ptr=0;
			vector<int> ans[50];
			while(typeCnt<=types && ptr!=N)
			{
				item it=list[ptr];
				int ty=it.type,idd=it.id;
				int curSiz=ans[typeCnt].size();
				if(K[typeCnt]==0)
				{
					typeCnt++;
				}
				if(kkCount>=kk)
				{
					break;
				}
				if(ty!=typeCnt)
				{
					ptr++;
					continue;
				}
				if(ty==typeCnt && curSiz<K[typeCnt] )
				{
					ans[ty].push_back(idd);
					ptr++;
					if(curSiz+1==K[typeCnt])
					{
						typeCnt+=1;
					}
					kkCount++;
					continue;
				}
			}
			
			for(int i=0;i<types;i++)
			{
				if(ans[i].size()==0)
					printf("-1\n");
				else{
					sort(ans[i].begin(),ans[i].end());
					for(int j=0;j<ans[i].size();j++)
					{
						printf("%d",ans[i][j]);
						if(j!=ans[i].size()-1)
							printf(" ");
						else
							printf(" \n"); //这里应该没问题 
					}
			}
			}
		}
//		printf("CURRENT LIST SIZE:%d\n=================\n",list.size());
//		for(int i=0;i<list.size();i++)
//		{
//			item once=list[i];
//			printf("type: %d , id: %d ,score: %d\n",once.type,once.id,once.score);
//		}
	}  
	return 0;
}
