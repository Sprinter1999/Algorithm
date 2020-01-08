public class Permutation
{
    public static void main(String[] args)
    {
        Character[] a={'a','b','c','d'};
        perm(a,0,a.length-1);
        System.out.println("最开始的数组");//保证数组不改变顺序
        for(Character each:a)
        {
            System.out.print(each+" ");
        }
    }
    public static <T> void perm(T[] array, int start, int end) {
        if (start == end) { // 如果起始和结束位置相同说明一次排列已经完成
            for (T t : array) { // 输出排列信息
                System.out.print(t);
            }

            System.out.println();
        } else { // 否则排列没有完成
            for (int i = start; i <= end; i++) {
                swap(array, start, i); // 将第一个元素分别与区间后面的元素进行交换
                perm(array, start + 1, end); //往下探索乱序
                swap(array, start, i); // 现场还原,保证每一次探索都不会修改最开始的数组
            }
        }

    }
    private static <T> void swap(T[] array, int x, int y) {
        T temp = array[x];
        array[x] = array[y];
        array[y] = temp;
    }
}