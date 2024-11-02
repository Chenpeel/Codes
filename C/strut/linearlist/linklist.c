#include <stdio.h>
#include <stdlib.h>

// 单向链表
typedef int LElemType;

typedef struct LNode {
  LElemType data;
  struct LNode *next;
} LNode, *LinkList;

/**
struct LNode{
  LElemType data;
  struct LNode *next;
};
typedef struct LNode LNode;
typedef struct LNode *LinkList;
*/

// --------------------------------------------------------------------------------
// 无头节点
void initList(LinkList L) { L = NULL; }
int emptyList(LinkList L) { return L == NULL; }
void insertNextNode(LNode *const node, const LElemType data) {
  LNode *new_node = (LNode *)malloc(sizeof(LNode));
  if (new_node != NULL) {
    new_node->data = data;
    new_node->next = node->next;
    node->next = new_node;
  }
}
void insertPriorNode_p(LinkList L, const LNode *const node,
                       const LElemType data) {
  LNode *tmp = L;
  if (node == L) {
    LNode *new_node = (LNode *)malloc(sizeof(LNode));
    new_node->data = data;
    new_node->next = node;
    L = new_node;
    return;
  }
  while (tmp != NULL && tmp->next != node) {
    tmp = tmp->next;
  }
  if (tmp != NULL) {
    LNode *new_node = (LNode *)malloc(sizeof(LNode));
    new_node->data = data;
    new_node->next = tmp->next;
    tmp->next = new_node;
  }
}
void insertPriorNode_l(LNode *const node, const LElemType data) {
  // 逻辑前插
  if (node != NULL) {
    LNode *new_node = (LNode *)malloc(sizeof(LNode));
    new_node->data = node->data;
    node->data = data;
    new_node->next = node->next;
    node->next = new_node;
  }
}
void insertList(LinkList L, const LElemType data, const int pos) {
  if (pos < 1) {
    printf("Underflow!\n");
    exit(-1);
  } else if (pos == 1) {
    insertPriorNode_l(L, data);
    // LNode *new_node = (LNode *)malloc(sizeof(LNode));
    // new_node->data = data;
    // new_node->next = L;
    // L = new_node;
    return;
  }
  LNode *tmp = L;
  int i = 1;
  while (tmp != NULL && i < pos - 1) {
    i++;
    tmp = tmp->next;
  }
  if (tmp == NULL) {
    printf("Overflow!\n");
    exit(-1);
  }
  insertNextNode(tmp, data);
  // LNode *new_node = (LNode *)malloc(sizeof(LNode));
  // new_node->data = data;
  // new_node->next = tmp->next;
  // tmp->next = new_node;
}

LElemType deleteNextNode(LNode *const node) {
  if (node && node->next) {
    LElemType data = node->next->data;
    node->next = node->next->next;
    return data;
  }
  return NULL;
}
LElemType deleteNode_p(LinkList L, LNode *node) {
  LNode *tmp = L;
  LElemType data = node->data;
  if (node == L) {
    L = node->next;
    return data;
  }
  while (tmp && tmp->next != node) {
    tmp = tmp->next;
  }
  LNode *to_free = node;
  tmp->next = node->next;
  free(to_free);
  return data;
}
LElemType deleteNode_l(LNode *const node) {
  // 逻辑删除node节点
  if (node && node->next->next) {
    LElemType data = node->data;
    node->data = node->next->data;
    node->next = node->next->next;
    return data;
  }
  return NULL;
}
LElemType deleteListNode(LinkList L, const int pos) {
  if (pos < 1) {
    printf("Underflow!\n");
    return NULL;
  }
  LNode *tmp = L;
  LElemType data;
  int i = 0;
  while (tmp != NULL && i < pos - 1) {
    i++;
    tmp = tmp->next;
  }
  if (!tmp) {
    data = tmp->next->data;
    tmp->next = tmp->next->next;
    LNode *to_free = tmp->next;
    free(to_free);
    return data;
  }
  return NULL;
}

LNode *getElem(const LinkList L, const int pos) {
  if (pos < 1) {
    printf("Underflow!\n");
    return NULL;
  }
  LNode *tmp = L;
  int i = 0;
  while (tmp && i < pos - 1) {
    tmp = tmp->next;
  }
  return tmp;
}

LNode *locateElem(const LinkList L, LElemType data) {
  LNode *tmp = L;
  while (tmp && tmp->data != data) {
    tmp = tmp->next;
  }
  return tmp;
}

int lenLinkList(const LinkList L) {
  int len = 0;
  LNode *tmp = L;
  while (tmp != NULL) {
    tmp = tmp->next;
    len++;
  }
  return len;
}

// --------------------------------------------------------------------------------
// 有头节点
void initList_h(LinkList L) {
  L = (LNode *)malloc(sizeof(LNode));
  L->next = NULL;
}
int emptyList_h(LinkList L) { return L->next == NULL; }

void insertList_h(LinkList L, const LElemType data, const int pos) {
  if (pos < 1) {
    printf("Underflow!\n");
    exit(-1);
  }
  LNode *tmp = L;
  int i = 0;
  while (tmp != NULL && i < pos - 1) {
    tmp = tmp->next;
    i++;
  }
  if (tmp == NULL) {
    printf("Overflow!\n");
    exit(-1);
  }
  LNode *new_node = (LNode *)malloc(sizeof(LNode));
  new_node->data = data;
  new_node->next = tmp->next;
  tmp->next = new_node;
}
void insertNextNode_h(LNode *const node, const LElemType data) {
  LNode *new_node = (LNode *)malloc(sizeof(LNode));
  new_node->data = data;
  new_node->next = node->next;
  node->next = new_node;
}
void insertPriorNode_h_p(LinkList L, const LNode *const node,
                         const LElemType data) {
  LNode *tmp = L;
  while (tmp->next != node) {
    tmp = tmp->next;
  }
  if (node) {
    LNode *new_node = (LNode *)malloc(sizeof(LNode));
    new_node->data = data;
    new_node->next = tmp->next;
    tmp->next = new_node;
  }
}
void insertPriorNode_h_l(LNode *const node, const LElemType data) {
  LNode *new_node = (LNode *)malloc(sizeof(LNode));
  new_node->data = node->data;
  node->data = data;
  new_node->next = node->next;
  node->next = new_node;
}

LElemType deleteNextNode_h(LNode *const node) {
  LElemType data = node->next->data;
  if (node->next) {
    LNode *to_free = node->next;
    node->next = node->next->next;
    free(to_free);
  }
  return data;
}

LElemType deleteNode_h_p(LinkList L, LNode *node) {
  LNode *tmp = L;
  LElemType data = node->data;
  while (tmp->next != node) {
    tmp = tmp->next;
  }
  LNode *to_free = tmp->next;
  tmp->next = node->next;
  free(to_free);
  return data;
}

LElemType deleteNode_h_l(LinkList L, LNode *const node) {
  if (node->next != NULL) {
    LNode *to_free = node->next;
    LElemType data = node->data;
    node->data = to_free->data;
    node->next = to_free->next;
    free(to_free);
  }
}
LElemType deleteListNode_h(LinkList L, const int pos) {
  if (pos < 1) {
    printf("Underflow!\n");
    return NULL;
  }
  LNode *tmp = L;
  LElemType data;
  int i = 0;
  while (tmp != NULL && i < pos - 1) {
    tmp = tmp->next;
  }
  if (tmp->next) {
    LNode *to_free = tmp->next;
    data = to_free->data;
    tmp->next = tmp->next->next;
    free(to_free);
    return data;
  }
  return NULL;
}

LNode *getElem_h(const LinkList L, const int pos) {
  if (pos < 1) {
    printf("Underflow!\n");
    return NULL;
  }
  LNode *tmp = L;
  int i = 0;
  while (tmp->next && i < pos) {
    tmp = tmp->next;
    i++;
  }
  return tmp;
}

LNode *locateElem_h(const LinkList L, const LElemType data) {
  LNode *tmp = L->next;
  while (tmp && tmp->data != data) {
    tmp = tmp->next;
  }
  return tmp;
}
int lenLinkList_h(const LinkList L) {
  int len = 0;
  LNode *tmp = L->next;
  while (tmp) {
    tmp = tmp->next;
    len++;
  }
  return len;
}

// 初始化要抹除脏数据
// 头插法可用于逆置
