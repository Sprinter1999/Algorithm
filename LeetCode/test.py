a={1:11,2:44,3:88,4:99,5:33}
a=sorted(a.items(),key=lambda a:a[1],reverse=True)
print(a[0][0])
print(type(a[0][0]))