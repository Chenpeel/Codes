#include "./struct/stack/sqstack.c"

// symbals: ["+","-","*","/","(",")","[","]","{","}"]
// numbers: ["0","1","2","3","4","5","6","7","8","9"]
int is_formula_valued(char str[], int length) {
  SqStk stk;
  initSqStk(&stk);
  for (int i = 0; i < length; i++) {
    if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
      pushSqStk(&stk, str[i]);
      // printf("%c\n", str[i]);
    } else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
      if (emptySqStk(&stk))
        return 0;
      char topChar = popSqStk(&stk);
      // printf("%c\n", topChar);
      if (str[i] == ')' && topChar != '(')
        return 0;
      if (str[i] == ']' && topChar != '[')
        return 0;
      if (str[i] == '}' && topChar != '{')
        return 0;
    }
  }
  // printf("empty: %d\n", emptySqStk(&stk));
  return emptySqStk(&stk);
}

int len_formula(char str[]) {
  int count = 0;
  while (str[count] != '\0') {
    count++;
  }
  printf("%d\n", count);
  return count;
}

float test() {
  char test_formula[] = {'1', '0', '*', '{', '[', '(', '1', '7', '-', '5',
                         ')', '/', '3', ']', '+', '1', '2', '}', '\0'};
  char wrong_formula[] = {'1', '0', '*', '{', '[', '(', '1', '7', '-',
                          '5', ')', '/', '3', ']', '+', '1', '2', '\0'};
  int tf = is_formula_valued(test_formula, len_formula(test_formula));
  int wf = is_formula_valued(wrong_formula, len_formula(wrong_formula));
  printf("tf,wf\t%d,%d\n", tf, wf);
  return 0;
}

int main() {
  test();
  return 0;
}
