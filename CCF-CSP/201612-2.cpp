#include <stdio.h>
#include <memory.h>
int main()
{
    int i;
    int t;
    int tmp;
    scanf("%d",&t);
    int sum;
    if(t<=3500)
    {
        printf("%d\n",t);
        return 0;
    }

    for(i=3600;; i+=100)
    {
        tmp=i-3500;

        if(tmp<=1500)
            sum=tmp*0.03;
        if(tmp>1500&&tmp<=4500)
            sum=1500*0.03+(tmp-1500)*0.1;
        if(tmp>4500&&tmp<=9000)
        {
            sum=1500*0.03+3000*0.1+(tmp-4500)*0.2;

        }

        if(tmp>9000&&tmp<=35000)
            sum=1500*0.03+3000*0.1+(9000-4500)*0.2+(tmp-9000)*0.25;
        if(tmp>35000&&tmp<=55000)
            sum=1500*0.03+3000*0.1+(9000-4500)*0.2+(35000-9000)*0.25+(tmp-35000)*0.3;
        if(tmp>55000&&tmp<=80000)
            sum=1500*0.03+3000*0.1+(9000-4500)*0.2+(35000-9000)*0.25+(55000-35000)*0.3+(tmp-55000)*0.35;
        if(tmp>80000)
            sum=1500*0.03+3000*0.1+(9000-4500)*0.2+(35000-9000)*0.25+(55000-35000)*0.3+(80000-55000)*0.35+(tmp-80000)*0.45;


        if(t==i-sum)
        {
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}
