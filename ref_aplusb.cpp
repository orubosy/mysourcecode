// aplusb.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <array>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int noofdigits = 0;
    cin >> noofdigits;
    int digits[noofdigits];
    for (int i = 0; i < noofdigits; i++)
    {
        //digits[i] = 0;
        cin >> digits[i];
    }
    int casecnt[3];
    for (int i = 0; i < 3; i++)
    {
        casecnt[i] = 0;
    }

    // Starting the real evaluation
    int noofhits = 0;
    int sum = 0;
    for (int i = 0; i < noofdigits; i++)
    {
        for (int j = 0; j < noofdigits; j++)
        {
            sum = digits[i] + digits[j];
            for (int k = 0; k < noofdigits; k++)
            {
                if (digits[k] == sum)
                {
                    if (k != i && k != j && i != j)
                    {
                        noofhits++;
                        if (digits[i] < 0 && digits[j] < 0)
                        {
                            casecnt[0]++;
                        }
                        else if (digits[i] >= 0 && digits[j] >= 0)
                        {
                            casecnt[1]++;
                        }
                        else
                        {
                            casecnt[2]++;
                        }
                    }
                }
            }
        }
    }

    //Printing result
    for (int i = 0; i < 3; i++)
    {
        cout << casecnt[i] << endl;
    }

    cout << endl
         << noofhits << endl;

    return 0;
}
