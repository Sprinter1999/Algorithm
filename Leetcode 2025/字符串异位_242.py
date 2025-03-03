class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        from collections import Counter
        counter = Counter(s)
        print(counter)
        counter.subtract(t)

        print(counter)
        return all(v == 0 for v in counter.values())