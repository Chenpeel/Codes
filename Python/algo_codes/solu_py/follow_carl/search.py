import random

# 随机一个十位list
l = [random.randint(0, 100) for i in range(10)]
print(l)

# list search查找~=list.index(element),时间复杂度O(n)
# list.index(element) , O(n)


def linear_search(li: list, val: int) -> bool:
    for ind, v in enumerate(li):
        if v == val:
            return ind
    else:
        return None


# binary_search 二分查找
def binary_search(li: list, val: int) -> bool | int:
    left = 0
    right = len(li) - 1
    list.sort(l)
    while left <= right:
        # if without the "=" may not find the element which exist in the list
        mid = (left + right)//2
        if li[mid] == val:
            return mid
        elif li[mid] < val:
            left = mid+1  # if right = mid the process could not cut
            mid = (left+right)//2
        elif li[mid] > val:
            right = mid-1  # if right = mid the process could not cut
            mid = (left+right)//2
        else:
            return False
        
# if binary_search(l , 3):
#     print("sorted pos : {}".format(binary_search(l,3)))
# del l

