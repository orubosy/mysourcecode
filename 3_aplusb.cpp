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
    //cout << "Number of digits = " << noofdigits << endl;
    int digits[noofdigits];
    for (int i = 0; i < noofdigits; i++)
    {
        //digits[i] = 0;
        cin >> digits[i];
        //cout << digits[i] << " " << to_string(i);
    }

    sort((digits), digits + noofdigits);

    int maxsum = digits[noofdigits - 1];
    int minsum = digits[0];
    int sum = 0;

    // Starting the real evaluation
    int noofhits = 0;
    int totalranking = 0;
    for (int i = 0; i < noofdigits; i++)
    {
        for (int j = 0; j < noofdigits; j++)
        {
            sum = digits[i] + digits[j];
            if (sum < minsum || sum > maxsum || i==j) 
            {
                continue;
            }
            for (int k = 0; k < noofdigits; k++)
            {
                if (digits[k] == sum && k!=i && k!=j)
                {
                    noofhits++;
                    //cout << i << " " << j << " " << k << "\t" << digits[i] << " + " << digits[j] << " = " << digits[k] << endl;
                }
                else
                {
                    if (digits[k] > sum)
                    {
                        break;
                    }
                }
            }
        }
    }

    //Printing result
    //cout << endl << "Total # of hits = " << noofhits << endl;
    cout << noofhits << endl;

    return 0;
}
