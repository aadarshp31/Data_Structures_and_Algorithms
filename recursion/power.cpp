#include <iostream>
using namespace std;

int power(int base, int exp);

int main()
{
  cout << "Result: " << power(2, 4) << endl;
}

int power(int base, int exp)
{
  if (exp == 1)
  {
    return base;
  }
  else
  {
    return base * power(base, exp - 1);
  }
}