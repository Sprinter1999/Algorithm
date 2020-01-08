   #include <stdio.h>
   void move(char getone, char putone)
	{
	    printf("%c--->%c\n", getone, putone);     //将一个盘从getone取走，放到putone
	}
	
 
    void hanoi(int n, char one, char two, char three) 
     //将n个盘从one杆，借助two杆，到达three杆子
	{
        if (n == 1) move(one, three);
        else
        {
            hanoi(n - 1, one, three, two);
            move(one, three);
            hanoi(n - 1, two, one, three);
        }
	}
 
 
	int main(void)
	{
        //汉诺塔问题
        int m;
        printf("Input the number of disks:");
        scanf("%d", &m);
        printf("The steps to moving the %d disks are as follows:\n", m);
        hanoi(m, 'A', 'B', 'C');
        system("pause");
        return 0;
	}