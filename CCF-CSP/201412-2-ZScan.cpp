#include <iostream>

using namespace std;

const int EAST=0;
const int SOUTH=1;
const int SOUTHWEST=2;
const int NORTHEAST=3;

struct {
	int drow;
	int dcol;
}direct[]={{0,1},{1,0},{1,-1},{-1,1}};

const int N=501;
int map[N][N];

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>map[i][j];
			
	int row=1,col=1,next=EAST;
	cout<<map[row][col];
	if(n==1)
		return 0;
		
	while(1)
	{
		row += direct[next].drow;
        col += direct[next].dcol;
        cout << " " << map[row][col];
        
        if(row==n&&col==n)
        	break;
 
        if(next == EAST && row == 1)
            next = SOUTHWEST;
        else if(next == EAST && row == n )
            next = NORTHEAST;
        else if(next == SOUTH && col == 1)
            next = NORTHEAST;
        else if(next == SOUTH && col == n )
            next = SOUTHWEST;
        else if(next == SOUTHWEST && row == n )
            next = EAST;
        else if(next == SOUTHWEST && col == 1)
            next = SOUTH;
        else if(next == NORTHEAST && col == n )
            next = SOUTH;
        else if(next == NORTHEAST && row == 1)
            next = EAST;

	}
	cout<<endl;
	return 0;
}
