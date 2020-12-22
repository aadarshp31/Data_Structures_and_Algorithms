#include <iostream>
using namespace std;

class CircularQueue
{
public:
  int front, rear, size;
  int *arr;
  CircularQueue(int s)
  {
    front = rear = -1;
    size = s;
    arr = new int[size];
  }

  void enqueue(int data)
  {
    if (front == -1)
    {
      front = rear = 0;
      arr[rear] = data;
      return;
    }
    else if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
    {
      cout << "The Queue is already full!" << endl;
      return;
    }
    else if (rear == size - 1 && front != 0)
    {
      rear = 0;
      arr[rear] = data;
    }
    else
    {
      rear++;
      arr[rear] = data;
    }
  }

  int dequeue()
  {

    if (front == -1)
    {
      cout << "The Queue is empty!" << endl;
      return -1;
    }

    int data = arr[front];
    arr[front] = -1;

    if (front == rear)
    {
      front = rear = -1;
    }
    else if (front == size - 1)
    {
      front = 0;
    }
    else
    {
      front++;
    }
    return data;
  }
};

void printQueue(CircularQueue *cq)
{
  if (cq->front == -1)
  {
    cout << "Error while printing: This is an empty Queue!" << endl;
    return;
  }
  cout << "Front <=\t";

  if ((cq->front) < (cq->rear))
  {
    for (size_t i = (cq->front); i <= (cq->rear); i++)
    {
      cout << cq->arr[i] << "\t";
    }
  }
  else
  {
    for (size_t i = (cq->front); i < (cq->size); i++)
    {
      cout << cq->arr[i] << "\t";
    }
    for (size_t i = 0; i <= cq->rear; i++)
    {
      cout << cq->arr[i] << "\t";
    }
  }

  cout << "<= Rear" << endl;
  cout << "Front: " << cq->front << ", Rear: " << cq->rear << endl;
}

int testng()
{
  CircularQueue *cq = new CircularQueue(5);
  cq->enqueue(1);
  cq->enqueue(2);
  cq->enqueue(3);
  cq->enqueue(4);
  cq->enqueue(5);
  printQueue(cq);

  cq->dequeue();
  cq->dequeue();
  cq->enqueue(6);
  cq->enqueue(7);
  printQueue(cq);

  return 0;
}