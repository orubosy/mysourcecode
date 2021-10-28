// aplusb.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <array>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    bool do_printing = true;
    int noofdigits = 0;
    cin >> noofdigits;

    int digits[noofdigits];
    for (int i = 0; i < noofdigits; i++)
    {
        digits[i] = 0;
        cin >> digits[i];
        //cout << digits[i] << " " << to_string(i);
    }
    sort((digits), digits + noofdigits);
    //Finding the first positive number
    int firstpos = noofdigits - 1;
    for (int i = 0; i < noofdigits; i++)
    {
        if (digits[i] >= 0)
        {
            firstpos = i;
            break;
        }
    }

    // Starting the real evaluation
    int noofhits = 0;
    int sum = 0;

    for (int i = 0; i < noofdigits - 1; i++)
    {
        for (int j = i + 1; j < noofdigits; j++)
        {
            sum = digits[i] + digits[j];
            if (i < firstpos && j >= firstpos)
            {
                // One positive and one negative
                for (int k = i + 1; k < j; k++)
                {
                    if (digits[k] == sum)
                    {
                        noofhits += 2;
                        if (do_printing) cout << i << " " << j << " " << k << endl;
                    }
                }
            }
        }
    }


//Printing result
cout << noofhits << endl;

return 0;

}
