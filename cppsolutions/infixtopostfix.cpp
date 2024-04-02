#include <iostream>
#include <cctype>

#define MAX_SIZE 100
using namespace std;
class Stack {
public:
  char arr[MAX_SIZE];
  int top;

public:
  Stack() : top(-1) {}

  void push(char item) {
    if (top == MAX_SIZE - 1) {
      cout << "Stack Overflow\n";
      return; 
    }
    arr[++top] = item;
  }

  char pop() {
    if (top == -1) {
      cout << "Stack Underflow\n";
      return -1;
    }
    return arr[top--];
  }

};

bool isAlphanumeric(char c) {
    return (c >= 'A' && c <= 'Z') ||
           (c >= 'a' && c <= 'z') ||
           (c >= '0' && c <= '9');
}


int precedence(char op) {
  if (op == '+' || op == '-') return 1;
  if (op == '*' || op == '/') return 2;
  return 0;
}

string infixToPostfix(string infix) {
  Stack s;
  string postfix;

  for (char c : infix) {
    if (isAlphanumeric(c)) { 
      postfix += c;
    } else if (c == '(') {
      s.push(c);
    } else if (c == ')') {
      while (s.top != -1 && s.top != '(') { 
        postfix += s.pop();
      }
      if (s.top == -1) return "Invalid Expression";
      s.pop(); 
    } else { 
      while (s.top != -1 && precedence(c) <= precedence(s.top)) {
        postfix += s.pop();
      }
      s.push(c);
    }
  }

  while (s.top != -1) { 
    postfix += s.pop();
  }

  return postfix;
}

int main() {
  string expression = "A+B*C";
  string i2p = infixToPostfix(expression);
  cout << "Infix: " << expression << endl;
  cout << "Postfix: " << i2p << endl;
  return 0;
}
