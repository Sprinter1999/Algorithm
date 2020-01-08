import java.util.Scanner;

public class Hanoi
{
    public static void main(String[] args) 
    {
        Scanner in=new Scanner(System.in);
        int n=in.nextInt();
        in.close();
        hanoi(n,'A','B','C');
    }
    public static void hanoi(int n,Character one,Character two,Character three)
    {
        if(n==1)
        {
            move(one,three);
        }
        else
        {
            hanoi(n - 1, one, three, two);
            move(one, three);
            hanoi(n - 1, two, one, three);
        }
    }
    public static void move(Character from,Character to)
    {
        System.out.printf("Move %c to %c\n",from,to);
    }
}