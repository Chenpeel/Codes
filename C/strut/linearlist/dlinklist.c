#include <stdio.h>
#include <stdlib.h>

typedef int DElemType;

typedef struct DNode {
  DElemType data;
  struct DNode *prior, *next;
} DNode, *DLinkList;

// default with head node
void initDLinkList(DLinkList L) {
  L = (DNode *)malloc(sizeof(DNode));
  if (L) {
    L->next = L->prior = NULL;
  }
}

int insertNextNodeD(DNode *node, DNode *new_node) {
  if (node && new_node) {
    node->next = new_node;
    if (node->next)
      node->next->prior = new_node;
    new_node->prior = node;
    node->next = new_node;
    return 1;
  }
  return 0;
}
int insertPriorNodeD(DNode *node, DNode *new_node) {
  if (node->prior && new_node && node) {
    new_node->prior = node->prior;
    node->prior->next = new_node;
    node->prior = new_node;
    new_node->next = node;
    return 1;
  }
  return 0;
}
int deleteNextNodeD(DNode *node) {
  if (node->next) {
    DNode *to_free = node->next;
    node->next = node->next->next;
    free(to_free);
    return 1;
  }
  return 0;
}
int deletePriorNodeD(DNode *node) {
  if (node->prior) {
    DNode *to_free = node->prior;
    node->prior = node->prior->prior;
    node->prior->next = node;
    free(to_free);
    return 1;
  }
  return 0;
}
void PrintList(const DLinkList L) {
  DNode *tmp = L;
  while (tmp->next) {
    tmp = tmp->next;
    printf("%d", tmp->data);
  }
}
void PrintFromAny(DNode *const node) {
  // 寻头
  DNode *tmp = node;
  while (tmp->prior != NULL) {
    tmp = tmp->prior;
  }
  PrintList(tmp);
}
