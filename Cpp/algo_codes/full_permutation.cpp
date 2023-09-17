
#include <iostream>

// 递归 全排列 (full permutation)
void perm(int list[], int k, int m) {
  if (k == m) {
    for (int i = k; i <= m; i++) {
      cout << list[i];
    }
    cout << endl;
  } else {
    for (int i = k; i <= m; i++) {
      swap(list[k], list[i]);
      perm(list, k + 1, m);
      swap(list[k], list[i]);
    }
  }
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

#endif
