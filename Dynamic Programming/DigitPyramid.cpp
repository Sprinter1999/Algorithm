/*
@题目描述：
问题描述：数字三角形问题

在上面的数字三角形中寻找一条从顶部到底部的路径，使得路径上所经过的数字只和最大。

路径上的每一步都只能往左下或右下走。只需要求出这个最大和即可，不必给出具体路径。

输入格式：

4//三角形行数。下面是三角形

	    	7

		3	 8

	8	  1	 	0

2	 7	 	4	  4

输出最长路径长度 
*/ 
#include<stdio.h>
#define Max 10 //根据测试数据初始化即可 
int maxSum[Max][Max]; //存放对应三角形元素到底部的值
int n;
int D[Max][Max];
 
int max(int x,int y ){
	return x>=y?x:y;
}
 
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=i;j++)
			scanf("%d",&D[i][j]);
	for(i=1;i<=n;i++)
		maxSum[n][i] = D[n][i];//最后一行到底部的值等于三角形底部行对应的值
	for(i=n-1;i>=1;i--)
		for(j=1;j<=i;j++)
			maxSum[i][j]=max(maxSum[i+1][j],maxSum[i+1][j+1])+D[i][j];//取较大值
	printf("%d",maxSum[1][1]);
}
