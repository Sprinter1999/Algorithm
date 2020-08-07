#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
map<int,int> M; //钥匙扣位置：房间号

struct query {
	int room;
	int time;
	int isReturn; // 1表示归还 0表示借出
	bool operator < (const query &b) const {
		if(time!=b.time) return time<b.time;
		else {
			if(isReturn!=b.isReturn) {
				return isReturn > b.isReturn;
			} else {
				return room<b.room;
			}
		}
	}
	query() {}
	query(int _a,int _b,int _c): room(_a),time(_b),isReturn(_c) {}
} Q[1001];


int main() {
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=1; i<=m; i++) {
		M[i]=i;
	}
	int count=0;
	for(int i=1; i<=n; i++) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		Q[count++]=query(a,b,0);
		Q[count++]=query(a,b+c,1);
	}
	sort(Q,Q+count);
//	for(int i=0; i<count; i++) {
//		printf("room:%d time:%d isReturn;%d\n",Q[i].room,Q[i].time,Q[i].isReturn);
//	}
	for(int i=0; i<count; i++) {
		query once=Q[i];
		if(!once.isReturn) { //借走
			map<int,int>::iterator iter;
			for(iter=M.begin(); iter!=M.end(); iter++) {
				if(iter->second==once.room) {
					M[iter->first]=0;
//					printf("%d room's key has been taken at %d moment\n",once.room,once.time);
					//printf("now %d slot is %d\n",iter->first,iter->second);
					break;
				}
			}
		}
		if(once.isReturn==1) {
			map<int,int>::iterator iter;
			for(iter=M.begin(); iter!=M.end(); iter++) {
				if(iter->second==0) {
					M[iter->first]=once.room;
//					printf("%d room's key has been returned at %d moment\n",once.room,once.time);
					break;
				}
			}
		}
	}

	map<int,int>::iterator it;
	int cnt=1;
	for(it=M.begin(); it!=M.end(); it++) {
		printf("%d",it->second);
		if(cnt<m) {
			printf(" ");
		} else {
			printf("\n");
		}
		cnt++;
	}
	return 0;
}
