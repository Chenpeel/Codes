#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  float coefficient; // 系数
  int index;         // 指数 | 项数
  struct Node *next;
} Node;

Node *createNode(float coefficient, int index) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (!newNode) {
    printf("Memory alloc ERROR\n");
    exit(1);
  }
  newNode->coefficient = coefficient;
  newNode->index = index;
  newNode->next = NULL;
  return newNode;
}

Node *insertNode(Node **head, float coefficient, int index) {
  Node *newNode = createNode(coefficient, index);
  newNode->next = *head;
  *head = newNode;
  return *head;
}

Node *sortLink(Node **head) {
  if (*head == NULL || (*head)->next == NULL) {
    return *head;
  }

  Node *sorted = NULL;
  Node *current = *head;
  while (current != NULL) {
    Node *next = current->next;
    if (sorted == NULL || sorted->index < current->index) {
      current->next = sorted;
      sorted = current;
    } else {
      Node *temp = sorted;
      while (temp->next != NULL && temp->next->index > current->index) {
        temp = temp->next;
      }
      current->next = temp->next;
      temp->next = current;
    }
    current = next;
  }
  *head = sorted;
  return *head;
}

void printPoly(Node *head) {
  Node *current = head;
  while (current != NULL) {
    if (current->index != 0) {
      printf("%.1fx^%d ", current->coefficient, current->index);
    }
    current = current->next;
    if (current != NULL && current->index != 0) {
      printf("+ ");
    }
  }
  printf("\n");
}

Node *createLink() {
  int items = 0;
  printf("项数:");
  scanf("%d", &items);
  Node *head = NULL;
  float coefficient;
  int index;
  for (int i = 0; i < items; i++) {
    printf("输入每一项%d: ", i + 1);
    scanf("%f %d", &coefficient, &index);
    head = insertNode(&head, coefficient, index);
  }
  return head;
}

Node *plusLink(Node *h1, Node *h2) {
  Node *res = NULL;
  Node *p1 = h1, *p2 = h2;

  while (p1 != NULL || p2 != NULL) {
    if (p1 == NULL) {
      res = insertNode(&res, p2->coefficient, p2->index);
      p2 = p2->next;
    } else if (p2 == NULL) {
      res = insertNode(&res, p1->coefficient, p1->index);
      p1 = p1->next;
    } else if (p1->index == p2->index) {
      res = insertNode(&res, p1->coefficient + p2->coefficient, p1->index);
      p1 = p1->next;
      p2 = p2->next;
    } else if (p1->index > p2->index) {
      res = insertNode(&res, p1->coefficient, p1->index);
      p1 = p1->next;
    } else {
      res = insertNode(&res, p2->coefficient, p2->index);
      p2 = p2->next;
    }
  }
  return sortLink(&res);
}

Node *subLink(Node *h1, Node *h2) {
  Node *res = NULL;
  Node *p1 = h1, *p2 = h2;

  while (p1 != NULL || p2 != NULL) {
    if (p1 == NULL) {
      res = insertNode(&res, -p2->coefficient, p2->index);
      p2 = p2->next;
    } else if (p2 == NULL) {
      res = insertNode(&res, p1->coefficient, p1->index);
      p1 = p1->next;
    } else if (p1->index == p2->index) {
      res = insertNode(&res, p1->coefficient - p2->coefficient, p1->index);
      p1 = p1->next;
      p2 = p2->next;
    } else if (p1->index > p2->index) {
      res = insertNode(&res, p1->coefficient, p1->index);
      p1 = p1->next;
    } else {
      res = insertNode(&res, -p2->coefficient, p2->index);
      p2 = p2->next;
    }
  }

  return sortLink(&res);
}

void dropLink(Node **p, int polynomial) {
  for (int i = 0; i < polynomial; i++) {
    Node *current = p[i];
    while (current != NULL) {
      Node *temp = current;
      current = current->next;
      free(temp);
    }
  }
}

int main() {
  int polynomial = 0;
  printf("输入多项式个数:");
  scanf("%d", &polynomial);
  if (polynomial <= 0) {
    printf("Num > 0\n");
    return 1;
  }
  Node *p[polynomial];
  for (int i = 0; i < polynomial; i++) {
    printf("多项式 %d\n", i + 1);
    p[i] = createLink();
    sortLink(&p[i]);
  }
  printf("操作？加/减/打印 [ + / - / p ]: "); // Added missing semicolon
  char opt;
  scanf(" %c", &opt);
  switch (opt) {
  case '+':
    if (polynomial >= 2) {
      Node *result = p[0];
      for (int i = 1; i < polynomial; i++) {
        result = plusLink(result, p[i]);
      }
      printPoly(result);
      Node *current = result;
      while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
      }
    } else {
      printf("最少两个多项式相加\n");
    }
    break;
  case '-':
    if (polynomial == 2) {
      Node *result = subLink(p[0], p[1]);
      printPoly(result);

      Node *current = result;
      while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
      }
    } else {
      printf("必须两个多项式相减 p1-p2 \n");
    }
    break;
  case 'p':
    for (int i = 0; i < polynomial; i++) {
      printPoly(p[i]);
    }
  default:
    break;
  }
  dropLink(p, polynomial);
  return 0;
}
