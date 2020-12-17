#include <iostream>
using namespace std;

void toh(int n, char from_rod, char to_rod, char aux_rod);

int main()
{
  int n = 3;
  toh(n, 'A', 'C', 'B');
  return 0;
}

void toh(int n, char from_rod, char to_rod, char aux_rod)
{
  if (n == 1)
  {
    cout << "Mov disk 1 from rod " << from_rod << " to rod " << to_rod << endl;
    return;
  }
  toh(n - 1, from_rod, aux_rod, to_rod);
  cout << "Mov disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
  toh(n - 1, aux_rod, to_rod, from_rod);
}