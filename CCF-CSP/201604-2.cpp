#include <cstdio>

struct node {
	int x;
	int y;
} list[5];

int map[16][11];
int b[5][5];
int col;

int main() {
	for(int i=1; i<=15; i++) {
		for(int j=1; j<=10; j++) {
			scanf("%d",&map[i][j]);
		}
	}
	int cnt=0;
	for(int i=1; i<=4; i++) {
		for(int j=1; j<=4; j++) {
			scanf("%d",&b[i][j]);
			if(b[i][j]) {
				list[cnt].x=i;
				list[cnt++].y=j;
			}
		}
	}
	scanf("%d",&col);
	for(int i=0; i<4; i++)
		list[i].y+=col-1;

	while(list[0].x<15&&list[1].x<15&&list[2].x<15&&list[3].x<15) {
		if(!map[list[0].x + 1][list[0].y] && !map[list[1].x + 1][list[1].y] && !map[list[2].x + 1][list[2].y] && !map[list[3].x + 1][list[3].y]) {
			list[0].x++;
			list[1].x++;
			list[2].x++;
			list[3].x++;
		} else break;
	}

	map[list[0].x][list[0].y] = map[list[1].x][list[1].y] = map[list[2].x][list[2].y] = map[list[3].x][list[3].y] =  1;
	for(int i = 1; i <= 15; ++i) {
		printf("%d",map[i][1]);
		for(int j = 2; j <= 10; ++j)
			printf(" %d",map[i][j]);
		printf("\n");
	}
	return 0;
}
