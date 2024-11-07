#include "../linearlist/linklist.c"
#include <stdio.h>
#include <stdlib.h>
void initLinkStk(LinkList *lstk) {
  *lstk = (LNode *)malloc(sizeof(LNode));
  if (*lstk) {
    printf("LStk mem alloc failed\n");
    exit(1);
  }
  (*lstk)->next = NULL;
}
int emptyLinkStk(LinkList *lstk) { return (*lstk)->next == NULL; }
void pushLinkStk(LinkList *lstk, ElemType const data) {
  LNode *new_node = (LNode *)malloc(sizeof(LNode));
  new_node->data = data;
  new_node->next = (*lstk)->next;
  (*lstk)->next = new_node;
}

ElemType popLinkStk(LinkList *lstk) {
  if (emptyLinkStk(lstk)) {
    printf("Empty Stack\n");
    exit(2);
  }
  LNode *tmp = (*lstk)->next;
  ElemType data = tmp->data;
  tmp->next = NULL;
  (*lstk)->next = (*lstk)->next->next;
  free(tmp);
  return data;
}
ElemType getTopLinkStk(LinkList *lstk) { return (*lstk)->next->data; }
