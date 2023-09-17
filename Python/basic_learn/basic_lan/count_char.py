def count(string: str):
    char, num, space, other = 0, 0, 0, 0
    for i in string:
        if i.isalpha():  # isalpha() 方法检测字符串是否只由字母组成
            char += 1
        elif i.isdigit():  # 如果 string 只包含数字则返回 True 否则返回 False
            num += 1
        elif i.isspace():  # 如果 string 中只包含空格，则返回 True，否则返回 False.
            space += 1
        else:
            other += 1
    print(f"在您输入的字符中，共含文字{char}个，数字{num}个，空格{space}个，其他字符{other}。")


text = input()
count(text)