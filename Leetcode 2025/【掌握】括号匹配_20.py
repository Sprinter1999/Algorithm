class Solution:
    def isValid(self, s: str) -> bool:
        parsed = []

        matches= {"{":"}", "(":")", "[":"]"}

        for c in s:
            # if current char is left ones
            if c in matches.keys():
                parsed.append(c)
                continue
            
            # then it is the right ones

            # add one right leads to False
            if len(parsed)==0:
                return False
            
            fetch_latest = parsed[-1]
            fetch_latest_correlated_val = matches[fetch_latest]

            if fetch_latest_correlated_val!=c:
                return False
            else:
                parsed.pop()
        
        return len(parsed)==0
