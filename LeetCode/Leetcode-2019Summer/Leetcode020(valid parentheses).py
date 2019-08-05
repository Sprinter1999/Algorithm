class Solution:
    def isValid(self, s: str) -> bool:
        stack=[]
        paren_map={')':'(',']':'[','}':'{'}
        for c in s:
            if c not in paren_map:
                stack.append(c)
            elif not stack or paren_map[c]!=stack.pop():#非空才能pop
                return False
        return not stack

# public boolean isValid(String s)
# {
#     int length;
#     def {
#         length=s.length();
#         s=s.replace("()","").replace("{}","").replace("[]","");
#     }while(length!=s.length());

#     return s.length()==0;
     
# }
# 但其实他的时间复杂度是很高的，O（n2），没堆栈好
