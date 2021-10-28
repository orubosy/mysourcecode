#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
    int noofdigits = 0;
    cin >> noofdigits;

    int digits[noofdigits];
    for (int i = 0; i < noofdigits; i++)
    {
        digits[i] = 0;
        cin >> digits[i];
    }
    sort((digits), digits + noofdigits);
    for (int i = 0; i < noofdigits; i++)
    {
        cout << digits[i] << "\t" << to_string(i+1) << endl;
    }

    return 0;
}
