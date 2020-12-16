#include <iostream>
using namespace std;

int factorial(int n);
int factorialWithIteration(int num);

int main()
{
  int n = 0;
  cout << "----------Factorial Finder----------" << endl;
  cout << "Enter a positive integer: " << endl;
  cin >> n;
  cout << "Factorial of " << n << " is: " << factorial(n) << endl;

  return 0;
}

int factorial(int n)
{
  if (n > 1)
  {
    return n * factorial(n - 1);
  }
  return 1;
}

int factorialWithIteration(int num)
{
  int result = 1;

  for (int i = 2; i <= num; i++)
  {
    result *= i;
  }

  return result;
}