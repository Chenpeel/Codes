#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
#define initSize 20

// 静态
typedef struct {
  ElemType data[initSize];
  int length;
} static_sqlist;

void initStaticSqList(static_sqlist *L) {
  for (int i = 0; i < initSize; i++) {
    L->data[i] = 0;
  }
  L->length = 0;
}

void insertStaticSqList(static_sqlist *L, const int i, const ElemType e) {
  if (i >= L->length - 1) {
    printf("i overflow\n");
  } else if (i < 0) {
    printf("i underflow\n");
  }
  for (int j = L->length; j >= i; j--) {
    L->data[j] = L->data[j - 1];
  }
  L->data[i - 1] = e;
  L->length++;
}
ElemType getElemStaticSqList(static_sqlist *L, const int i) {
  // 按位查找
  if (i >= L->length || i < 0) {
    printf("Index out of bounds\n");
    return -1;
  }
  return L->data[i - 1];
}
int locateElemStaticSqList(static_sqlist *L, const ElemType e) {
  // 按值查找
  for (int i = 0; i < L->length; i++) {
    if (L->data[i] == e)
      return i + 1;
  }
  return -1;
}
ElemType deleteElemStaticSqList(static_sqlist *L, const int i) {
  if (i >= L->length || i < 0) {
    printf("Index out of bounds\n");
    return -1;
  }
  ElemType e;
  for (int j = 0; j <= i - 1; j++) {
    if (j == i - 1) {
      e = L->data[j];
    }
  }
  for (int j = i - 1; j < L->length; j++) {
    L->data[j] = L->data[j + 1];
    if (j == L->length - 1)
      L->data[j] = 0;
  }
  L->length -= 1;
  return e;
}
void destoryStaticSqList(static_sqlist *L) { L->length = 0; }
void printAllElemsS() {}
// 动态
#define IncreaseSize 10
typedef struct {
  ElemType *data;
  int length;
  int MaxSize;
} dynamic_sqlist;

void initDynamicSqList(dynamic_sqlist *L) {
  // malloc 申请连续的内存空间
  L->data = (ElemType *)malloc(sizeof(ElemType) * initSize);
  L->length = 0;
  L->MaxSize = initSize;
}
void increaseSize(dynamic_sqlist *L) {
  int *tmp = L->data;
  L->data = (ElemType *)malloc(sizeof(ElemType) * IncreaseSize);
  // 全部迁移
  for (int i = 0; i < L->length; i++) {
    L->data[i] = tmp[i];
  }
  L->MaxSize += IncreaseSize;
}
void insertDynamicSqList(dynamic_sqlist *L, const int i, const ElemType e) {
  if (i < 0) {
    printf("i underflow\n");
  } else if (i >= L->length - 1) {
    increaseSize(L);
  }
  for (int j = L->length; j >= i; j--) {
    L->data[j] = L->data[j - 1];
  }
  L->data[i - 1] = e;
  L->length++;
}
ElemType getElemDynamicSqList(dynamic_sqlist *L, const int i) {
  if (i >= L->length || i < 0) {
    printf("Index out of bounds\n");
    return -1;
  }
  return L->data[i - 1];
}
int locateElemDynamicSqList(dynamic_sqlist *L, const ElemType e) {
  for (int i = 0; i < L->length; i++) {
    if (L->data[i] == e)
      return i + 1;
  }
  return -1;
}
ElemType deleteElemDynamicSqList(dynamic_sqlist *L, const int i) {
  if (i >= L->length || i < 0) {
    printf("Index out of bounds\n");
    return -1;
  }
  ElemType e;
  for (int j = 0; j <= i - 1; j++) {
    if (j == i - 1) {
      e = L->data[j];
    }
  }
  for (int j = i - 1; j < L->length; j++) {
    L->data[j] = L->data[j + 1];
    if (j == L->length - 1)
      L->data[j] = 0;
  }
  L->length -= 1;
  return e;
}
void destoryDynamicSqList(dynamic_sqlist *L) {
  for (int i = 0; i < L->length; i++) {
    if (L->data != NULL) {
      free(L->data);
      L->data = NULL;
    }
    L->length = 0;
    L->MaxSize = 0;
  }
}

void printAllElemsD() {}
