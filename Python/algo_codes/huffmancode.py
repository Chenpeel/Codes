import heapq
from collections import defaultdict

# 节点类


class Node:
    def __init__(self, data, freq):
        self.data = data
        self.freq = freq
        self.left = None
        self.right = None

    def __lt__(self, other):  # 添加 __lt__ 方法来定义节点的比较操作
        return self.freq < other.freq

# 构建哈夫曼树


def build_huffman_tree(char_freq):
    min_heap = []

    # 将每个字符作为一个节点加入最小堆
    for data, freq in char_freq.items():
        node = Node(data, freq)
        heapq.heappush(min_heap, (node.freq, node))

    # 以贪心策略构建哈夫曼树
    while len(min_heap) > 1:
        freq1, left = heapq.heappop(min_heap)
        freq2, right = heapq.heappop(min_heap)

        parent = Node('$', freq1 + freq2)
        parent.left = left
        parent.right = right

        heapq.heappush(min_heap, (parent.freq, parent))  # 修改这行代码

    return min_heap[0][1]

# 生成字符的前缀编码


def generate_codes(root, code, codes):
    if root is None:
        return

    if root.left is None and root.right is None:
        codes[root.data] = code

    generate_codes(root.left, code + '0', codes)
    generate_codes(root.right, code + '1', codes)


if __name__ == '__main__':
    char_freq = {
        'a': 0.22, 'b': 0.13, 'c': 0.07, 'd': 0.06,
        'e': 0.2, 'f': 0.1, 'g': 0.07, 'h': 0.06,
        'i': 0.1, 'j': 0.07
    }

    root = build_huffman_tree(char_freq)

    codes = {}
    generate_codes(root, '', codes)

    for char, code in codes.items():
        print(f'{char}: {code}')
