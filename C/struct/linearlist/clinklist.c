#include "dlinklist.c"
#include "linklist.c"
#include <stdlib.h>
// use defined node

// 循环单链表
void initCircleList(LinkList *L) {
  (*L) = (LNode *)malloc(sizeof(LNode));
  (*L)->next = *L;
}
int emptyCList(LinkList L) { return L->next == L; }
void insertNextNodeC(LNode *node, ElemType const data) {
  LNode *new_node = (LNode *)malloc(sizeof(LNode));
  new_node->data = data;
  new_node->next = node->next->next;
  node->next = new_node;
}
void deleteNextNodeC(LNode *node) {
  if (node->next != node) {
    LNode *to_free = node->next;
    node->next = node->next->next;
    free(to_free);
  }
}
LNode *getTailNode(LinkList L) {
  LNode *node = L;
  while (node->next != L) {
    node = node->next;
  }
  return node;
}

// 循环双链表
void initDCircleList(DLinkList L) {
  L = (DNode *)malloc(sizeof(DNode));
  L->next = L;
  L->prior = L;
}
int emptyDCList(DLinkList L) { return L->prior == L && L->next == L; }
int isTailNode(DLinkList L, DNode *node) { return node->next == L; }
