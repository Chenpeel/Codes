#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10
typedef int ElemType;

// 静态数组实现
// 有浪费一个空间
typedef struct SqQueue {
  ElemType data[MaxSize];
  int front, rear;
  // 用于充分利用空间：
  // int size;  记录队长度
  // bool flag; 标志最近一次的出队或入队操作
} SqQueue;

void initSqQueue(SqQueue *SqQ) {
  (*SqQ).front = (*SqQ).rear = 0;
  // 指向队头
}

int emptySqQueue(SqQueue *SqQ) { return (*SqQ).front == (*SqQ).rear; }
int fullSqQueue(SqQueue *SqQ) {
  return (SqQ->rear + 1) % MaxSize == SqQ->front;
}
int lenSqQueue(SqQueue *SqQ) {
  return (SqQ->front + MaxSize - SqQ->rear) % MaxSize;
}
void enSqQueue(SqQueue *SqQ, ElemType const data) {
  if ((SqQ->rear + 1) % MaxSize == SqQ->front) {
    printf("Queue Full\n");
    exit(1);
  }
  (*SqQ).data[SqQ->rear] = data;
  SqQ->rear = (SqQ->rear + 1) % MaxSize;
}
ElemType deSqQueue(SqQueue *SqQ) {
  if (emptySqQueue(SqQ)) {
    printf("Queue is Empty\n");
    exit(1);
  }
  ElemType data = (*SqQ).data[SqQ->front];
  SqQ->front = (SqQ->front + 1) % MaxSize;
}

ElemType getSqQueueHead(SqQueue *SqQ) {
  if (emptySqQueue(SqQ)) {
    printf("Queue is Empty\n");
    exit(1);
  }
  return (*SqQ).data[SqQ->front];
}
