#include <iostream>
#include <stack>
using std::stack;
void t_recur(stack<char>&stk);
void print(stack<char>& stk){
    stack<char> temp = stk;
    while(!temp.empty()){
        std::cout << temp.top()<<',';
        temp.pop();
    }
}
void t_stack(stack<char>& stk) {
  stk.pop();
  t_recur(stk);
  stk.push('a');
}
void t_recur(stack<char>& stk) {
  stk.push('a');
  t_stack(stk);
  stk.pop();
}
int main() {
  stack<char> stk;
  t_recur(stk);
}