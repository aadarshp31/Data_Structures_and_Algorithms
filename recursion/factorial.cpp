#include <iostream>
using namespace std;

int factorial(int n);

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