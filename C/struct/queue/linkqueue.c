#include "../linearlist/linklist.c"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  LNode *front, *rear;
  // int length;  频繁使用长度时，用于提升效率
} LinkQueue, *LQueue;
void initLQueue(LQueue *LQ) {
  // 带头节点
  (*LQ)->front = (*LQ)->rear = (LNode *)malloc(sizeof(LNode));
  (*LQ)->front->next = NULL;
  // (*LQ)->length =0;
}
int emptyLQueue(LQueue *LQ) {
  return (*LQ)->front == NULL;
  // return (*LQ)->length == 0;
}

void enLQueue(LQueue *LQ, ElemType const data) {
  LNode *new_node = (LNode *)malloc(sizeof(LNode));
  new_node->data = data;
  new_node->next = NULL;
  (*LQ)->rear->next = new_node;
  (*LQ)->rear = new_node;
  // (*LQ)->length ++;
}
ElemType deLQueue(LQueue *LQ) {
  if (!(*LQ)->front->next) {
    printf("There\'s no elem in LQ\n");
    exit(1);
  }
  LNode *to_free = (*LQ)->front->next;
  ElemType data = to_free->data;
  (*LQ)->front->next = to_free->next;
  free(to_free);
  // (*LQ)->length--;
  return data;
}

// 双端队列
typedef struct DoubleSideQueue {
  LNode *lside, *rside;
  // int length;
} DsQueue, *DsQue;
