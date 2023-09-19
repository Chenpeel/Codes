class Solutions:

    '''
    520
    https://leetcode.cn/problems/detect-capital/
    '''

    def _detectCapitalUse(self, word: str) -> bool:
        if word == word.upper():
            return True
        elif word == word[0].upper()+word[1:].lower():
            return True
        elif word == word.lower():
            return True
        return False

    def detectCapitalUse(self, word: str) -> bool:
        t, index = 0, -1
        n = len(word)
        for i in range(n):
            if word[i] == word[i].upper():
                t += 1
                index = i  # 标记是否为第一个字符
        return t == len(word) or t == 0 or (t == 1 and index == 0)

    '''
    125
    https://leetcode.cn/problems/valid-palindrome/
    '''
    # 1.移除非字符位 -> 2.判断回文

    def isPalindrome(self, s: str) -> bool:
        res = []
        for i in s:
            if 'a' < i < 'z' or 'A' < i < 'Z':
                res.append(i.lower())
            elif '0' <= i <= '9':
                res.append(i)
        return res == res[::-1]

    '''
    14
    https://leetcode.cn/problems/longest-common-prefix/
    '''

    def longestCommonPrefix(self, strs: list[str]) -> str:
        if not strs:
            return ""
        s1 = max(strs)
        s2 = min(strs)
        for i in range(len(s1)):
            if s1[i] != s2[i]:
                return s1[:i]
        return s1
    '''
    434
    https://leetcode.cn/problems/number-of-segments-in-a-string/description/
    '''
    def __countSegments(self,s:str)->int:
        return len(s.split())
        
    def _countSegments(self, s: str) -> int:
        s += ' '
        n = len(s)
        res = 0
        for i in range(n):
            if s[i] != ' ' and s[i+1] == ' ':
                res += 1
        return res

    def countSegments(self, s: str) -> int:
        flag = 1
        res = 0
        for i in s:
            if i != ' ' and flag:
                flag = 0
                res += 1
            if i == ' ':
                flag = 1
        return res
    def lengthOfLastWord(self,s:str)->int:
        res =0
        for i in s[::-1]:
            if i ==' 'and res!=0:
                return res
            elif i=='' :
                res+1
            elif i!=' ':
                res+=1
        return res
    def reverseString(self,s:list[str])->None:
        s.reverse()