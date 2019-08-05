### 通过这个月的学习总结，有五大算法Trick模板可以进行总结：
# 递归
```python
def recursion(level,parameter1,...)
{
    # Recursion Terminator
    if level>Max_level:
        print_result()
        return
    # do something
    process_data(...)
    
    #Drill down,maybe more than once self-recurse
    self.recursion(...)

    #if needed,do something
    reverse_state(level)

}
```
# DFS
DFS是一种很重要的算法，由于计算机本身支持堆栈，所以不必手动维护
```python
visited=set()
def dfs(node,visited):
    visited.add(node)

    #do something
    process_data()
    for next node in node.children():
        if not next_node in visited():
            dfs(next_node,visited)
```
# BFS
BFS相较于DFS更符合人的思维模式，但是由于系统不会支持队列式调用，所以一般需要我们手动维持一个队列用于搜索。
```python
def BFS(graph,start,end):
    queue=[]
    queue.append([start,])
    visited.add(start)

    while queue:
        node=queue.pop()
        visited.add(node)

        process_data(node)
        nodes=generate_following_nodes(node)
        queue.push(nodes)

    # maybe some other operations
```
# Binary Search
```python
left,right=0,len(array)-1
while left<=right:
    mid=left+(right-left)/2 
    if array[mid]==target:
        break or return result
    elif array[mid]<target:
        left=mid+1
    else:
        right=mid-1
```
# DP(正向 or 反向)
```Java
//Status statement
dp=new int[m+1][n+1]
//Status initialization,etc
dp[0][0]=x
dp[0][1]=y

for (i=0;i<=n<++i)
{
    for (j=0;j<=m;j++)
    {
        //...
        d[i][j]=min {dp[i-1][j],dp[i-1][j-1],etc} //etc
    }
}
return dp[m][n] //Optimal final answer
```

# Fast Bitwise
 - **X&1==1？or 0来判断奇偶** 优于 x%2==1 or 0
 - X=X&(X-1) 可用于清零最低位的1，比如就可快速判断一个数是否是2的幂次。
 - X&(-X) 可得到最低位的1，利用了补码特性
 - 可用位运算实现数字交换，当然python可以进行一行内同时赋值
    ```
    x=x&y
    y=x&y
    x=x&y
    ```