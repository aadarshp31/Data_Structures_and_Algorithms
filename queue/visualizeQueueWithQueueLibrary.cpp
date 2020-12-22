#include <iostream>
#include <queue>
using namespace std;

void printQueue(queue<int> q);

int main()
{
  queue<int> q;
  q.push(22);
  q.push(33);
  q.push(44);
  q.push(55);

  printQueue(q);
  cout << "The size of the queue is: " << q.size() << endl;

  q.pop();

  printQueue(q);
  cout << "The size of the queue is: " << q.size() << endl;

  q.push(11);

  printQueue(q);
  cout << "The size of the queue is: " << q.size() << endl;

  return 0;
}

void printQueue(queue<int> q)
{
  cout << "front <=\t";
  while (!q.empty())
  {
    cout << q.front() << "\t";
    q.pop();
  }
  cout << "<= back";
  cout << endl;
}