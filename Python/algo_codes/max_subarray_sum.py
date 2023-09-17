# dc
def max_subarray_sum_DC(A: list) -> int:
    n = len(A)
    def max_crossing_sum(arr, l, m, h):
        # 找到包含中间元素的子数组的最大和（向左向右查找）
        sm = 0
        left_sum = float('-inf')
        for i in range(m, l-1, -1):
            sm += arr[i]
            if sm > left_sum:
                left_sum = sm
        sm = 0
        right_sum = float('-inf')
        for i in range(m+1, h+1):
            sm += arr[i]
            if sm > right_sum:
                right_sum = sm
        return left_sum + right_sum
    def max_subarray_sum(arr, l, h):
        # 递归计算最大子段和
        if l == h:  # 只有一个元素的情况
            return arr[l]
        m = (l + h) // 2
        # 分别找到左子数组、右子数组和包含中间元素的子数组的最大子段和
        left_sum = max_subarray_sum(arr, l, m)
        right_sum = max_subarray_sum(arr, m + 1, h)
        cross_sum = max_crossing_sum(arr, l, m, h)
        return max(left_sum, right_sum, cross_sum)


# dp
def max_subarray_sum_DP(A: list) -> int:
    n = len(A)
    max_so_far = A[0]
    curr_max = A[0]

    for i in range(1, n):
        curr_max = max(A[i], curr_max + A[i])
        max_so_far = max(max_so_far, curr_max)

    return max_so_far


# 测试代码
if __name__ == '__main__':
    arr = [-2, -5, 6, -2, -3, 1, 5, -6]
    max_sum = max_subarray_sum_DC(arr)
    print('最大子段和为：', max_sum)
    arr = [-2, -5, 6, -2, -3, 1, 5, -6]
    max_sum = max_subarray_sum_DP(arr)
    print('最大子段和为：', max_sum)