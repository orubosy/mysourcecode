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
        digits[i] = 0;
        cin >> digits[i];
        //cout << digits[i] << " " << to_string(i);
    }
    sort((digits), digits + noofdigits);
    //Finding the first positive number
    int firstpos;
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

    for (int i = 0; i < noofdigits; i++)
    {
        for (int j = i + 1; j < noofdigits; j++)
        {
            if (i < firstpos && j < firstpos) // Two negative number
            {
                for (int k = 0; k < i; k++)
                {
                    if (digits[k] == digits[i] + digits[j])
                    {
                        noofhits += 2;
                        cout << i << " " << j << " " << k << "\t" << digits[i] << " + " << digits[j] << " = " << digits[k] << endl;
                    }
                }
            }
            else
            {
                if (i >= firstpos && j >= firstpos) // Two positive numbers
                {
                    for (int k = j; k < noofdigits; k++)
                    {
                        if (digits[k] == digits[i] + digits[j])
                        {

                            noofhits += 2;
                            cout << i << " " << j << " " << k << "\t" << digits[i] << " + " << digits[j] << " = " << digits[k] << endl;
                        }
                    }
                }
                else
                { // One positive and one negative
                    for (int k = i; k < j; k++)
                    {
                        if (digits[k] == digits[i] + digits[j])
                        {

                            noofhits += 2;
                            cout << i << " " << j << " " << k << "\t" << digits[i] << " + " << digits[j] << " = " << digits[k] << endl;
                        }
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
