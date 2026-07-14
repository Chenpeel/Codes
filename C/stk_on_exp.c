#include "./struct/stack/sqstack.c"
#include <ctype.h>
#include <stdio.h>

// symbals: ["+","-","*","/","(",")","[","]","{","}"]
// numbers: ["0","1","2","3","4","5","6","7","8","9"]
int is_braces_valued(char str[], int length) {
  SqStk stk;
  initSqStk(&stk);
  for (int i = 0; i < length; i++) {
    if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
      pushSqStk(&stk, str[i]);
    } else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
      if (emptySqStk(&stk))
        return 0;
      char topChar = popSqStk(&stk);
      if (str[i] == ')' && topChar != '(')
        return 0;
      if (str[i] == ']' && topChar != '[')
        return 0;
      if (str[i] == '}' && topChar != '{')
        return 0;
    }
  }
  return emptySqStk(&stk);
}

int len_exp(char str[]) {
  int count = 0;
  while (str[count] != '\0') {
    count++;
  }
  printf("%d\n", count);
  return count;
}

int precedence(char op) {
  switch (op) {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  default:
    return 0;
  }
}

void exp_op_mid2suffix(char infix[], char postfix[], int len) {
  SqStk stk;
  initSqStk(&stk);
  int k = 0;
  for (int i = 0; i < len; i++) {
    if (isdigit(infix[i])) {
      while (isdigit(infix[i])) {
        postfix[k++] = infix[i++];
      }
      postfix[k++] = ' ';
      i--;
    } else if (infix[i] == '(' || infix[i] == '[' || infix[i] == '{') {
      pushSqStk(&stk, infix[i]);
    } else if (infix[i] == ')' || infix[i] == ']' || infix[i] == '}') {
      char openBrace;
      if (infix[i] == ')')
        openBrace = '(';
      if (infix[i] == ']')
        openBrace = '[';
      if (infix[i] == '}')
        openBrace = '{';
      while (!emptySqStk(&stk) && getTopSqStk(&stk) != openBrace) {
        postfix[k++] = popSqStk(&stk);
        postfix[k++] = ' ';
      }
      popSqStk(&stk);
    } else if (infix[i] == ' ') {
      continue;
    } else {
      while (!emptySqStk(&stk) &&
             precedence(getTopSqStk(&stk)) >= precedence(infix[i])) {
        postfix[k++] = popSqStk(&stk);
        postfix[k++] = ' ';
      }
      pushSqStk(&stk, infix[i]);
    }
  }
  while (!emptySqStk(&stk)) {
    postfix[k++] = popSqStk(&stk);
    postfix[k++] = ' ';
  }
  postfix[k - 1] = '\0';
}

float compute_suffix_exp(char str[], int len) {
  SqStk stk;
  initSqStk(&stk);
  for (int i = 0; i < len; i++) {
    if (isdigit(str[i])) {
      float num = 0;
      while (isdigit(str[i])) {
        num = num * 10 + (str[i++] - '0');
      }
      i--;
      pushSqStk(&stk, num);
    } else if (str[i] == ' ') {
      continue;
    } else {
      float val2 = popSqStk(&stk);
      float val1 = popSqStk(&stk);
      switch (str[i]) {
      case '+':
        pushSqStk(&stk, val1 + val2);
        break;
      case '-':
        pushSqStk(&stk, val1 - val2);
        break;
      case '*':
        pushSqStk(&stk, val1 * val2);
        break;
      case '/':
        pushSqStk(&stk, val1 / val2);
        break;
      }
    }
  }
  return popSqStk(&stk);
}

int main() {
  char test_exp[] = "10 * [( 17 - 5 ) / 3 + 12]";
  int len = len_exp(test_exp);
  int te = is_braces_valued(test_exp, len);
  printf("is te valued:\t%d\n", te);
  if (te) {
    char postfix[len * 2];
    exp_op_mid2suffix(test_exp, postfix, len);
    printf("Postfix expression: %s\n", postfix);
    float result = compute_suffix_exp(postfix, len_exp(postfix));
    printf("Result: %.2f\n", result);
  } else {
    printf("The expression has invalid braces.\n");
  }
  return 0;
}
