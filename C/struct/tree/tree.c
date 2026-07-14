typedef int TData;

typedef struct TNode {
  TData data;
  struct TNode *child1;
  struct TNode *child2;
  struct TNode *child3;
  // ...
} TNode, *T;
