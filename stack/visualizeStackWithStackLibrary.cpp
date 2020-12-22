#include <iostream>
#include <stack>
using namespace std;

void printStack(stack<int> s);

int main()
{
  stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  printStack(s);
  cout << "The size of the stack is: " << s.size() << endl;

  s.pop();

  printStack(s);
  cout << "The size of the stack is: " << s.size() << endl;

  return 0;
}

void printStack(stack<int> s)
{
  while (!s.empty())
  {
    cout << s.top() << "\t";
    s.pop();
  }
  cout << endl;
}
