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

    // Starting the real evaluation
    int noofhits = 0;
    /*
    for (int i = 0; i < noofdigits; i++)
    {
        for (int j = 0; j < noofdigits; j++)
        {
            //cout << sum << "\t";
            for (int k = min(i,j); k < noofdigits; k++)
            {
                if (digits[k] == digits[i] + digits[j])
                {
                    if (k != i && k != j && i != j)
                    {
                        noofhits++;
                        //cout << endl << "Hit # " << noofhits;
                        //cout << "\t" << "Indexis are " << i << " " << j << " " << k << endl;
                    }
                }
                else
                {
                    if (digits[k] > digits[i] + digits[j])
                    {
                        break;
                    }
                }
                
            }
        }
    }
    */
    //Printing result
    //cout << endl << "Total # of hits = " << noofhits << endl;
    cout << noofhits << endl;

    return 0;
}
