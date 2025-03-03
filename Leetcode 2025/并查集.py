N=100
Tree = [-1 for i in range(N)]

def findRoot(x:int):
    if(Tree[x]==-1):
        return x
    else:
        tmp = findRoot(Tree[x])
        Tree[x]=tmp
        return tmp