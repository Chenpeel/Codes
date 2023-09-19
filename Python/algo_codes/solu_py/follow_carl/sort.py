import random

# 随机一个十位list
l = [random.randint(0, 100) for i in range(10)]
print(l)

'''
sort_basic 
O(n^2)
'''

# bubble_sort 冒泡排序


def bubble_sort(li: list) -> list:
    for i in range(len(li)-1):
        exchange = False
        for j in range(len(li)-i-1):
            if li[j] > li[j+1]:
                li[j], li[j+1] = li[j+1], li[j]
                exchange = True
        if not exchange:
            return li
        print(li)

    return li
# print(bubble_sort(l))


# select_sort_simple 选择排序
def select_sort_sim(li: list) -> list:
    li_new = []
    for i in range(len(li)):
        min_val = min(li)  # O(n)
        li.new.append(min_val)  # O(n)
        li.remove(min_val)  # O(n)
    return li_new


def select_sort(li: list) -> list:
    for i in range(len(li)-1):
        min_pos = i
        for j in range(i+1, len(li)):
            if li[j] < li[min_pos]:
                min_pos = j
        li[i], li[min_pos] = li[min_pos], li[i]
    return li

# print(select_sort(l))


# insert_sort 插入排序
def insert_sort(li: list) -> list:
    for i in range(1, len(li)):
        temp = li[i]
        j = i-1
        while j >= 0 and li[j] > temp:
            li[j+1] = li[j]
            j -= 1
        li[j+1] = temp
    return li
# print(insert_sort(l))


'''
sort_pro
O(nlog(n)) ~ O(n^2)
'''


# quick_sort 快速排序
# 非常依赖中心点的选择
# 不稳定，可以使用随机中心点或者三点中值作为中心点

def quick_sort(li: list) -> list:
    def partition(li: list, left: int, right: int) -> list:
        temp = li[left]
        while left < right:
            while left < right and li[right] >= temp:
                right -= 1
            li[left] = li[right]
            while left < right and li[left] <= temp:
                left += 1
            li[right] = li[left]
        li[right] = temp
        return left

    def _quick_sort(li: list, left: int, right: int) -> None:
        if left < right:
            mid = partition(li, left, right)
            _quick_sort(li, left, mid-1)
            _quick_sort(li, mid+1, right)
    _quick_sort(li, 0, len(li)-1)
    return li
 
# print(quick_sort(l))

# heap_sort 堆排序
# 也可以使用基于优先队列的heapq算法
# import heapq


def __heapify(li: list, n: int, i: int) -> None:    # 大根堆建立,从小到大
    lagest = i
    left = 2 * i + 1
    right = 2 * i + 2

    if left < n and li[lagest] < li[left]:
        lagest = left
    if right < n and li[lagest] < li[right]:
        lagest = right
    if lagest != i:
        li[i], li[lagest] = li[lagest], li[i]
        __heapify(li, n, lagest)


def heapify(li: list, n: int, i: int) -> None:      # 小根堆建立，从大到小
    lagest = i
    left = 2 * i + 1
    right = 2 * i + 2

    if left < n and li[lagest] > li[left]:
        lagest = left
    if right < n and li[lagest] > li[right]:
        lagest = right
    if lagest != i:
        li[i], li[lagest] = li[lagest], li[i]
        heapify(li, n, lagest)


def __heap_sort(li: list) -> list:
    n = len(li)
    for i in range(n//2-1, -1, -1):
        __heapify(li, n, i)
    for i in range(n-1, 0, -1):
        li[i], li[0] = li[0], li[i]
        __heapify(li, i, 0)
    return li


def heap_sort(li: list) -> list:
    n = len(li)
    for i in range(n//2-1, -1, -1):
        heapify(li, n, i)
    for i in range(n-1, 0, -1):
        li[i], li[0] = li[0], li[i]
        heapify(li, i, 0)
    return li
# print(__heap_sort(l))     #打印'<'排序
# print(heap_sort(l))       #打印'>'排序


# merge_sort 归并排序
def merge_sort(li: list) -> list:
    if len(li) > 1:
        mid = len(li)//2
        left_half = li[:mid]
        right_half = li[mid:]
        merge_sort(left_half)
        merge_sort(right_half)
        i, j, k = 0, 0, 0
        while i < len(left_half) and j < len(right_half):
            if left_half[i] <= right_half[j]:
                li[k] = left_half[i]
                i += 1
            else:
                li[k] = right_half[j]
                j += 1
            k += 1
        while i < len(left_half):
            li[k] = left_half[i]
            i += 1
            k += 1
        while j < len(right_half):
            li[k] = right_half[j]
            j += 1
            k += 1
    return li
# print(merge_sort(l))


'''
other sort 
'''

# https://en.wikipedia.org/wiki/Shellsort


def shell_sort(li: list) -> list:
    n = len(li)
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            temp = li[i]
            j = i

            while j >= gap and li[j-gap] > temp:
                li[j] = li[j-gap]
                j -= gap

            li[j] = temp
        gap //= 2
    return li


# print(shell_sort(l))


# O(n) 但耗费空间
def count_sort(li: list) -> list:
    largest_num = max(li)
    counts = [0] * (largest_num+1)

    for num in li:
        counts[num] += 1

    result = []
    for i in range(largest_num+1):
        result.extend([i]*counts[i])
    return result


# print(count_sort(l))


def bucket_sort(li: list) -> list:
    num_buckets = 10
    buckets = [[] for _ in range(num_buckets)]

    for num in li:
        i = num//10
        buckets[i].append(num)

    for bucket in buckets:
        for i in range(1, len(bucket)):
            key = bucket[i]
            j = i-1
            while j >= 0 and bucket[j] > key:
                bucket[j+1] = bucket[j]
                j -= 1
            bucket[j+1] = key

    sorted_l = []
    for bucket in buckets:
        sorted_l += bucket

    return sorted_l

# print(bucket_sort(l))


def radix_sort(li: list) -> list:
    max_num = max(li)
    exp = 1
    while max_num // exp > 0:
        buckets = [[] for _ in range(10)]
        for num in li:
            digit = (num//exp) % 10
            buckets[digit].append(num)
        li.clear()
        for bucket in buckets:
            li.extend(bucket)
        exp *= 10
    return li
