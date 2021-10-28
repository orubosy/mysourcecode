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
    bool do_printing = false;
    cin >> noofdigits;
    //cout << "Number of digits = " << noofdigits << endl;
    int digits[noofdigits];
    int noofeven = 0;
    int noofodd = 0;
    for (int i = 0; i < noofdigits; i++)
    {
        //digits[i] = 0;
        cin >> digits[i];
        //cout << digits[i] << " " << to_string(i);
        if (digits[i] % 2 == 0)
        {
            noofeven++;
        }
        else
        {
            noofodd++;
        }
    }

    sort((digits), digits + noofdigits);
    int sum = 0;

    int deven[noofeven];
    int dodd[noofodd];
    int evencnt = 0;
    int oddcnt = 0;

    for (int i = 0; i < noofdigits; i++)
    {
        if (digits[i] % 2 == 0)
        {
            deven[evencnt++] = digits[i];
        }
        else
        {
            dodd[oddcnt++] = digits[i];
        }
    }
    sort((deven), deven + noofeven);
    sort((dodd), dodd + noofodd);
    int maxsumeven = deven[noofeven - 1];
    int minsumeven = deven[0];
    int maxsumodd = dodd[noofodd - 1];
    int minsumodd = dodd[0];

    // Starting the real evaluation
    // Starting with two even numbers
    int noofhits = 0;

    for (int i = 0; i < noofeven; i++)
    {
        for (int j = 0; j < noofeven; j++)
        {
            sum = deven[i] + deven[j];
            if (sum < minsumeven || sum > maxsumeven)
            {
                continue;
            }
            for (int k = 0; k < noofeven; k++)
            {
                if (deven[k] == sum && k != i && k != j)
                {
                    noofhits++;
                    if(do_printing) 
                    cout << i << " " << j << " " << k << "\t" << deven[i] << " + " << deven[j] << " = " << deven[k] << endl;
                }
                else
                {
                    if (deven[k] > sum)
                    {
                        break;
                    }
                }
            }
        }
    }

    // Continue with two odd numbers
    for (int i = 0; i < noofodd; i++)
    {
        for (int j = 0; j < noofodd; j++)
        {
            sum = dodd[i] + dodd[j];
            if (sum < minsumeven || sum > maxsumeven)
            {
                continue;
            }
            for (int k = 0; k < noofodd; k++)
            {
                if (deven[k] == sum)
                {
                    noofhits++;
                    if(do_printing) 
                    cout << i << " " << j << " " << k << "\t" << dodd[i] << " + " << dodd[j] << " = " << deven[k] << endl;
                }
                else
                {
                    if (deven[k] > sum)
                    {
                        break;
                    }
                }
            }
        }
    }

    // Finally one odd and one even number
    for (int i = 0; i < noofeven; i++)
    {
        for (int j = 0; j < noofodd; j++)
        {
            sum = deven[i] + dodd[j];
            if (sum < minsumodd || sum > maxsumodd)
            {
                continue;
            }
            for (int k = 0; k < noofodd; k++)
            {
                if (dodd[k] == sum)
                {
                    noofhits++;
                    if(do_printing) 
                    cout << i << " " << j << " " << k << "\t" << deven[i] << " + " << dodd[j] << " = " << dodd[k] << endl;
                }
                else
                {
                    if (dodd[k] > sum)
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
