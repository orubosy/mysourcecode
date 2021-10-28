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

    int uniques[noofdigits];
    int ranks[noofdigits];
    int lastindex = 0;
    uniques[lastindex] = digits[0];
    ranks[lastindex] = 1;
    int integritycheck = 0;

    for (int i = 1; i < noofdigits; i++)
    {
        uniques[i] = 0;
        ranks[i] = 1;

        if (digits[i] == digits[i - 1])
        {
            ranks[lastindex]++;
            integritycheck++;
        }
        else
        {
            uniques[++lastindex] = digits[i];
        }
    }
/*
    for (int i = 0; i < lastindex + 1; i++)
    {
        cout << "Digit = " << uniques[i] << " with the rank of " << ranks[i] << endl;
    }
   
    cout << "Last index = " << lastindex << endl;
    int topscore = integritycheck + lastindex + 1;
    cout << "Integrity check  = " << topscore << endl;
*/ 
    // Starting the real evaluation
    int noofhits = 0;
    int totalranking = 0;
    for (int i = 0; i < lastindex + 1; i++)
    {
        for (int j = 0; j < lastindex + 1; j++)
        {
            //cout << sum << "\t";
            for (int k = 0; k < lastindex + 1; k++)
            {
                if (uniques[k] == uniques[i] + uniques[j])
                {
                    totalranking = ranks[i] * ranks[j] * ranks[k];
                    noofhits += totalranking;
                    //cout << endl << "Hit # " << noofhits;
                    //cout << i << " " << j << " " << k << endl;
                }
                else
                {
                    if (uniques[k] > uniques[i] + uniques[j] )
                    {
                        continue;
                    }
                }
            }
        }
    }
    //noofhits *= 2;
    // Handling of multiple digits
    for (int i = 0; i < lastindex + 1; i++)
    {
        if (ranks[i] > 1)
        {
            for (int k = i + 1; k < lastindex + 1; k++)
            {
                if (uniques[k] == uniques[i] * 2)
                {
                    totalranking = ranks[i] * ranks[k];
                    noofhits += totalranking;
                    //cout << endl << "Hit # " << noofhits;
                    //cout << "\t" << "Indexis are " << i << " " << j << " " << k << endl;
                }
                else
                {
                    if (uniques[k] > uniques[i] * 2)
                    {
                        continue;
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
