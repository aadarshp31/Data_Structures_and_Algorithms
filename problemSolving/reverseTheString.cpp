#include <iostream>
using namespace std;

int main()
{
  string input = "I am forward";
  string reversedInput;

  for (int i = input.size() - 1; i >= 0; i--)
  {
    reversedInput += input[i];
  }

  cout << reversedInput << endl;
  return 0;
}