def lastSubstring(self, s: str) -> str:
    res = ''
    max_ch = max(s)
    i = 0
    for c in s:
        if c == max_ch and s[i:] > res:
            res = s[i:]
        i += 1
    return res
