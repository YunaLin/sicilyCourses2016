//  中缀表达式转后缀表达式
// 测试样例:A+B*C-D-E/F
// 输出结果:ABC*+D-EF/-
#include <iostream>
#include <string>
#include <stack>
using namespace std;
class MidToLast {
  public:
    string transfer(string str);
};
bool isOperator(char ch) {
  if (ch == '+'||ch == '-'||ch == '('||ch == ')'||ch == '*'||ch == '/'||ch == '%')
  return true;
  else
  return false;
}
//  cur大于pre为true, cur小于或者是等pre为false
bool isHigherPriority(char cur, char pre) {
  if (cur == '(' || pre == '(') return true;
  else if ((cur == '*' || cur == '/'||cur == '%')
          &&(pre == '+'||pre == '-'))
    return true;
  else
    return false;
}
bool isNum(char ch) {
  if (ch >= '0' && ch <= '9') return true;
  if (ch >= 'A' && ch <= 'Z') return true;
  if (ch >= 'a' && ch <= 'z') return true;
  else return false;
}
//  重点是括号的处理,左括号直接入栈,知道遇到有括号在出栈
string MidToLast::transfer(string str) {
  if (str == "") return "";
  int l = str.size();
  char* result = new char[l + 1];
  stack<char> _stack;  //  存放操作符
  int j = 0;
  for (int i = 0; i < l; ++i) {
    if (isNum(str[i])) {
      result[j++] = str[i];
    }
    if (isOperator(str[i])) {
      //  最开始为空的情况
      if (_stack.empty()) {
        if (str[i] == ')')
          return "";
        else
          _stack.push(str[i]);
      //  栈不为空时首先考虑是否遇到括号的情况,遇到有括号首先要判断栈中
      //  是否有左括号
      } else if (str[i] == ')') {
        bool leftBrace = false;
        while (!_stack.empty()) {
          if (_stack.top() == '(') {
            _stack.pop();
            leftBrace = true;
            break;
          }
          result[j++] = _stack.top();
          _stack.pop();
        }
        if (!leftBrace) return "";
      } else {
        if (isHigherPriority(str[i], _stack.top())) {
          _stack.push(str[i]);
        } else {
          while (!_stack.empty()) {
            if (isHigherPriority(str[i], _stack.top())) {
              break;
            }
            result[j++] = _stack.top();
            _stack.pop();
          }
          _stack.push(str[i]);
        }
      }
    }
  }
  while (!_stack.empty()) {
    result[j++] = _stack.top();
    _stack.pop();
  }
  //   字符串以'\0'结束
  result[j] = '\0';
  string conversion(result);
  delete []result;
  return conversion;
}

int main() {
  string str;
 // string d;
  stack<char> s;
  getline(cin, str);
  MidToLast mtl;
  string strtemp = mtl.transfer(str);
  cout << strtemp;
  return 0;
}