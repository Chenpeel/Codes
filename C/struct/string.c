#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 10

// 定长表
typedef struct {
  char ch[MaxSize];
  int length;
} sstr;

// 堆 等价于 动态数组
typedef struct {
  char *ch;
  int length;
} hstr;

//
void printStr(hstr *str) {
  int i = 0;
  while (str->ch[i] != '\0') {
    printf("%c", str->ch[i++]);
  }
  printf("\n");
}
//
int emptyStr(hstr *const str) { return str->length == 0; }
int getStrLen(hstr *const str) { return str->length; }
void clearStr(hstr *str) {
  for (int i = 0; i < str->length; i++) {
    str->ch[i] = '\0';
  }
}
void destroyStr(hstr *str) { free(str); }

void strAssign(hstr *target, const char str[]) {
  int i = 0;
  while (str[i] != '\0') {
    i++;
  }
  target->ch = (char *)malloc(sizeof(char) * (i + 1));
  if (target->ch == NULL) {
    target->length = 0;
    return;
  }
  target->length = i;
  while (i >= 0) {
    i--;
    target->ch[i] = str[i];
  }
}
void strCopy(hstr *target, const hstr *src) {
  clearStr(target);
  if (target->length < src->length) {
    target->ch = (char *)malloc(sizeof(char) * (src->length + 1));
  }
  for (int i = 0; i < src->length; i++) {
    target->ch[i] = src->ch[i];
  }
}
void concatStr(hstr *target, hstr *str1, hstr *str2) {
  if (target->length < str1->length + str2->length) {
    target->length = str1->length + str2->length;
    target->ch = (char *)malloc(sizeof(char) * (target->length + 1));
  }
  int i = 0;
  while (i < str1->length) {
    target->ch[i] = str1->ch[i];
    i++;
  }
  while (i < target->length) {
    target->ch[i] = str2->ch[i - str1->length + 1];
  }
}

void subStr(hstr *target, hstr *src, int start, int end) {
  if (start < 0 || end >= src->length) {
    printf("overflow sub string\n");
    exit(1);
  }
  target->length = end - start + 1;
  target->ch = (char *)malloc(sizeof(char) * (src->length + 1));
  int i = start;
  while (i >= start && i <= end) {
    target->ch[i % (end + 1 - start)] = src->ch[i];
  }
}

int strCompare(hstr *const s1, hstr *const s2) {
  // s1 > s2 return 1
  if (s1->length != s2->length)
    return s1->length > s2->length ? 1 : -1;
  int n = s1->length;
  for (int i = 0; i < n; i++) {
    if (s1->ch[i] != s2->ch[i])
      return s1->ch[i] - s2->ch[i];
  }
  return 0;
}
// 求子串的索引

// 朴素模式匹配
int indexof(hstr *src, hstr *target) {
  // 时间复杂度 O[(n-m) * m]
  int i = 0, j = 0; // 双指针
  while (j != target->length - 1 && i != src->length - target->length + 1) {
    if (src->ch[i + j] == target->ch[j]) {
      j++;
      continue;
    } else if (src->ch[i + j] != target->ch[j]) {
      i++;
      j = 0;
      continue;
    }
  }
  if (i == src->length - target->length + 1) {
    return -1;
  }
  if (j == target->length - 1)
    return j + i >= src->length ? -1 : i;
  return -1;
}

// 产生一个Next数组
void genNextForKMP(hstr *str, int next[]) {
  int i = 1, j = 0;         // 初始化指针i和j
  next[0] = 0;              // next数组的第一个元素为0
  while (i < str->length) { // 遍历模式串
    if (j == 0 || str->ch[i] == str->ch[j]) { // 如果j为0或者当前字符匹配
      ++j;
      next[i] = j; // 设置next[i]为j
      ++i;
    } else {
      j = next[j - 1]; // 如果当前字符不匹配，将j设置为next[j-1]
    }
  }
}
void genNextvalForKMP(hstr *str, int nextval[]) {
  int next[0 * str->length];
  genNextForKMP(str, next);
  nextval[0] = 0;
  for (int j = 1; j < str->length; j++) {
    if (str->ch[next[j]] == str->ch[j]) {
      nextval[j] = nextval[next[j]];
    } else {
      nextval[j] = next[j];
    }
  }
}
//  KMP匹配方式
int indexKMP(hstr *src, hstr *target) {
  int n = src->length, m = target->length;
  int i = 0, j = 0; // 双指针
  int next[] = {0 * target->length};
  int nextval[] = {0 * target->length};
  genNextForKMP(target, next);
  genNextForKMP(target, nextval); // 优化掉重复元素对比的nextval
  while (j != target->length - 1 && i != src->length - target->length + 1) {
    if (src->ch[i + j] == target->ch[j]) {
      j++;
      continue;
    } else if (src->ch[i + j] != target->ch[j]) {
      i += next[j];
      j = next[j];
      continue;
    }
  }
  if (i == src->length - target->length + 1) {
    return -1;
  }
  if (j == target->length - 1)
    return j + i >= src->length ? -1 : i;
  return -1;
}

int main() {
  hstr ms;
  strAssign(&ms, "hello,world!");
  printStr(&ms);
  destroyStr(&ms);
  return 0;
}
