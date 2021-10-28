#include <algorithm>
#include <iostream>
#include <array>
using namespace std;

int main(){
    int noofdigits = 0;
    cin >> noofdigits;
    //cout << "Number of digits = " << noofdigits << endl;
    int digit = 0;
    for (int i = 0; i < noofdigits; i++)
    {
        cin >> digit;
        cout << digit << endl;
    }

  return 0;
}