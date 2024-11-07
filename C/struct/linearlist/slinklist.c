#include "linklist.c"
#include <stdio.h>
#define MaxSize 10
typedef int Offset;

typedef enum { INIT, END_LIST } PtrDirect;
typedef struct SNode {
  ElemType data;
  Offset next;
} SNode;
typedef struct SNode SLinkList[MaxSize];

//  logical mem:
//  [ head | &e1 ] --> [ e1 data | &e2 ] --> [ e2 data | &e3 ] --> [ e3 data |
//  END ]
//
//  real mem:
//  [ head |  3  ]
//  [ &e2  |  6  ]
//  [      |     ]
//  [ &e1  |  1  ]
//  [      |     ]
//  [      |     ]
//  [ &e3  | END ]

void initSLinkList(SLinkList *L) {
  for (int i = 0; i < MaxSize - 1; i++) {
    (*L + i * sizeof(Offset))->next = INIT;
  }
  L[MaxSize - 1].next = END_LIST;
}
int emptySList(SLinkList *L) { return L[0]->next == INIT; }

int firstEmptySNode(SLinkList *L) {
  for (int i = 0; i < MaxSize; i++) {
    if (L[i]->next == INIT) {
      return i < MaxSize ? i : -1;
    }
  }
}

void insertSNode(SLinkList *L, ElemType const data, int const pos) {
  // pos 是插入结点的逻辑位置，而不是物理位置
  if (pos < 0 || pos >= MaxSize) {
    printf("Pos out of bounds\n");
    return;
  }
  int i = 0;
  if (!emptySList(L)) {
    SNode *tmp = L[0];
    while (i < pos - 1 && tmp->next != END_LIST) {
      tmp = L[tmp->next];
    }
    int ofs = firstEmptySNode(L);
    if (ofs != -1) {
      L[ofs]->data = data;
      L[ofs]->next = tmp->next;
      tmp->next = ofs;
    } else {
      printf("No empty node available\n");
    }
  } else {
    int ofs = firstEmptySNode(L);
    if (ofs != -1) {
      L[ofs]->data = data;
      L[ofs]->next = END_LIST;
      L[0]->next = ofs;
    } else {
      printf("No empty node available\n");
    }
  }
}
