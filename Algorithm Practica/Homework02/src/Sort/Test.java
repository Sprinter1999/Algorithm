package Sort;

public class Test {
    public static void main(String[] args) {
        int[] scales={2000,5000,10000,15000,20000,30000};
        for(int testTurn=0;testTurn<scales.length;testTurn++)
            for(int turnTime=0;turnTime<5;turnTime++)
            {
                int length=scales[testTurn];
                int[] test=ArrayGenerator.geneArray(length);
                int ADD=ArrayGenerator.cal_ADD(test);

                //普通快排测试
                System.out.printf("普通快速排序 ");
                QuickSort.depth=0;
                int[] QsortTest=ArrayGenerator.CopyArray(test);
                long startsTime=System.nanoTime();
                QuickSort.qsort(0,length-1,QsortTest,0);
                long endsTime=System.nanoTime();
                System.out.printf("%d %d %d %d ",testTurn+1,turnTime+1,ADD,
                        (endsTime-startsTime)/1000);
                System.out.println(" "+QuickSort.depth);
                //随机快排测试
                QuickSortRandom.depth=0;
                System.out.printf("随机快排测试 ");
                int[] QsortRanTest=ArrayGenerator.CopyArray(test);
                startsTime=System.nanoTime();
                QuickSortRandom.randomizedQuickSort(0,length-1,QsortRanTest,0);
                endsTime=System.nanoTime();
                System.out.printf("%d %d %d %d ",testTurn+1,turnTime+1,ADD,
                        (endsTime-startsTime)/1000);
                System.out.println(" "+QuickSort.depth);

                //归并排序测试
                MergeSort.depth=0;
                System.out.printf("归并排序测试 ");
                int[] MergeSortTest=ArrayGenerator.CopyArray(test);
                startsTime=System.nanoTime();
                MergeSort.mergesort(MergeSortTest,0,length-1,0);
                endsTime=System.nanoTime();
                System.out.printf("%d %d %d %d ",testTurn+1,turnTime+1,ADD,
                        (endsTime-startsTime)/1000);
                System.out.println(" "+QuickSort.depth);
                //归并排序非递归测试
                System.out.printf("归并非递归排序测试 ");
                int[] NonRecurTest=ArrayGenerator.CopyArray(test);
                startsTime=System.nanoTime();
                MergeSortNonRecur.sort(NonRecurTest);
                endsTime=System.nanoTime();
                System.out.printf("%d %d %d %d\n",testTurn+1,turnTime+1,ADD,
                        (endsTime-startsTime)/1000);

                //标准输出再保存到文件中，再写一个Python脚本分析即可
            }
    }
}
