#include <iostream>
using namespace std;

int factorial(int num);
int nonRepeatingCombinations(int n, int r);

int main()
{
  int n = 1, r = 1;
  cout << "------------------------Combination Problem------------------------" << endl;
  cout << "Enter the number of items (n): ";
  cin >> n;
  cout << "Enter the number of selections (r): ";
  cin >> r;

  cout << "The number of non-repeating combinations is: " << nonRepeatingCombinations(n, r) << endl;

  return 0;
}

int factorial(int num)
{
  int result = 1;

  for (int i = 2; i <= num; i++)
  {
    result *= i;
  }

  return result;
}

int nonRepeatingCombinations(int n, int r)
{
  return (factorial(n) / (factorial(r) * factorial(n - r)));
}
