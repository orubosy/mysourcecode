#include <iostream>
using namespace std;

int main()
{
    float sum = 0;

    for (int i = 1; i < 100000; i++)
    {
        float idx = i;
        sum = sum + 1 / idx;
        cout << i << "\t" << sum << "\n";
    }
}