#include <stdio.h>
#define MaxSize 20
typedef char ElemType;
// 顺序栈
typedef struct SqStack {
  ElemType data[MaxSize];
  int top;
} SqStk;
void initSqStk(SqStk *stk) {
  stk->top = -1;
  // stk->top = 0; 指向栈顶后一个
}
int emptySqStk(SqStk *stk) { return stk->top == -1; }

void pushSqStk(SqStk *stk, ElemType const data) {
  if (stk->top == MaxSize - 1) {
    printf("Stack Overflow\n");
    return;
  }
  stk->data[++stk->top] = data;
}
ElemType popSqStk(SqStk *stk) {
  if (emptySqStk(stk)) {
    printf("Stack is Empty\n");
    return '\0';
  }
  return stk->data[stk->top--];
}
ElemType getTopSqStk(SqStk *stk) { return stk->data[stk->top]; }

// 共享栈
typedef struct ShareStack {
  ElemType data;
  int top0;
  int top1;
} ShrStk;
void initShrStk(ShrStk *shrstk) {
  shrstk->top0 = -1;
  shrstk->top1 = MaxSize;
}
int emptyShrStk(ShrStk *shrstk) {
  return shrstk->top0 == -1 && shrstk->top1 == MaxSize;
}
int fullShrStk(ShrStk *shrstk) { return shrstk->top0 + 1 == shrstk->top1; }
