#有效的字母异位词
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        dic1,dic2={},{}
        for item in s:
            dic1[item]=dic1.get(item,0)+1
        for item in t:
            dic2[item]=dic2.get(item,0)+1
        return dic1==dic2
    def isAnagram2(self,s:str,t:str) ->bool:
        return sorted(s)==sorted(t)