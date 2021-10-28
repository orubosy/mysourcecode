#include <algorithm>
#include <iostream>
#include <array>
using namespace std;

int main()
{
  int arr_size = 1000;
  int rand_max = 2 * arr_size;
  int v[arr_size];
  cout << arr_size << endl;
  /* initialize random seed: */
  srand(time(NULL));

  for (int i = 0; i < arr_size / 2; i++)
  {
    v[i] = -rand() % rand_max;
    cout << v[i] << " ";
  }

  for (int i = 0; i < arr_size / 2; i++)
  {
    v[i] = rand() % rand_max;
    cout << v[i] << " ";
  }

  cout << endl;
  return 0;
}