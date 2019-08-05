def myPow(self,x,n):
    if n<0:
        x=1/x
        n=-n
    pow=1
    while n:
        if n&1:
            pow*=x
        x*=x
        n>>=1
    return pow

def myPow2(self,x,n):
    if not n:
        return 1
    if n<0:
        return 1/self.myPow2(x,-n)
    if n%2:
        return x*self.myPow2(x,n-1)
    return self.myPow2(x*x,n/2)