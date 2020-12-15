#include <iostream>
using namespace std;

int fibonacciSeries(int num);
void printFibonacciSeries();

int fibonacciSum(int limit);
void printFibonacciSum();

int fibonacciElement(int position);
void printFibonacciElement();

int main()
{
  printFibonacciSeries();
  printFibonacciElement();
  printFibonacciSum();
  return 0;
}

int fibonacciSeries(int num)
{
  if (num == 0 || num == 1)
  {
    return num;
  }
  else
  {
    return (fibonacciSeries(num - 1) + fibonacciSeries(num - 2));
  }
}

void printFibonacciSeries()
{
  int limit = 0, i = 0;
  cout << "-------------------------------Fibonacci Series-------------------------------" << endl;
  cout << "Enter the number of the elements you want to get: ";
  cin >> limit;

  while (i < limit)
  {
    cout << fibonacciSeries(i) << " ";
    i++;
  }
  cout << "" << endl;
}

int fibonacciSum(int limit)
{
  int sum = 0, i = 0;
  while (i < limit)
  {
    sum += fibonacciSeries(i);
    i++;
  }
  return sum;
}

void printFibonacciSum()
{
  int limit = 0;
  cout << "-------------------------------Fibonacci Series-------------------------------" << endl;
  cout << "Enter the number of elements' sum you want: ";
  cin >> limit;
  cout << "The Sum of " << limit << " first elements is: " << fibonacciSum(limit) << endl;
}

int fibonacciElement(int position)
{
  return fibonacciSeries(position - 1);
}

void printFibonacciElement()
{
  int position = 0;
  cout << "-------------------------------Fibonacci Series-------------------------------" << endl;
  cout << "Enter the position of elements you want: ";
  cin >> position;
  cout << "The element at position " << position << " is: " << fibonacciElement(position) << endl;
}