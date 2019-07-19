public class Solution 
{
    /**
     * @param A: an integer array
     * @return: nothing
     */
    public void sortIntegers(int[] A) 
    {
        if(A == null || A.length <= 1)//对输入数据进行检查
        {
            return;
        }
        int[] tempA = new int[A.length];//一个临时数组，在这里申请，可以反复利用，提高效率
        mergeSort(A, tempA, 0, A.length - 1);
    }
    
    private void mergeSort(int[] A, int[] tempA, int left, int right)
    {
        if(left == right)//递归退出的条件（只有一个元素时，不需要再拆分
        {
            return;
        }
        int middle = (left + right)/2;
        mergeSort(A, tempA, left, middle);//左边拆分
        mergeSort(A, tempA, middle + 1, right);//右边拆分
        merge(A, tempA, left, middle, right);//合并两个有序数组
    }
    
    /**
    * 合并两个有序数组
    * 这两个有序数组在A中，
    * left和right分别为两个子数组的左右边界，middle为这两个数组的分界点
    * tempA为临时数组，排序后暂存在此数组中，排序后再赋给A
    */
    private void merge(int[] A, int[] tempA, int left, int middle, int right)
    {
        int i = left;//i指向左数组的第一位
        int j = middle + 1;//j指向右数组的第一位
        int k = 0;//用来方便将排序后的数存放到tempA
        while(i <= middle && j <= right)
        {
            if(A[i] < A[j])
            {
                tempA[k] = A[i];
                i++;
            }
            else
            {
                tempA[k] = A[j];    
                j++;
            }
            k++;
        }
        
        while(i <= middle)//如果左数组有剩余，全部加入tempA
        {
            tempA[k++] = A[i++];
        }
        
        while(j <= right)//如果右数组有剩余，全部加入tempA
        {
            tempA[k++] = A[j++];
        }
        
        //将排序后的数替换A中未排序的数，注意：不是整个替换
        for(int index = 0; index < k; index++)
        {
            A[left + index] = tempA[index];//注意A的索引，[left + index];
        }
    }
}
