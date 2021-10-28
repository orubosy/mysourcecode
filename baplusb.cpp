// aplusb.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <array>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int cases = 3;
    int casecnt[cases];
    int casehits[cases];
    for (int i = 0; i < cases; i++)
    {
        casecnt[i] = 0;
        casehits[i] = 0;
    }
    int mycase;
    int noofdigits = 0;
    cin >> noofdigits;
    int digits[noofdigits];
    int firstpos = noofdigits - 1;
    for (int i = 0; i < noofdigits; i++)
    {
        digits[i] = 0;
        cin >> digits[i];
        //cout << digits[i] << " " << to_string(i);
    }

    sort((digits), digits + noofdigits);
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
            // Find out case #
            if (digits[j] < 0)
            { // Two negs
                mycase = 0;
                casecnt[mycase]++;
                for (int k = 0; k < i; k++)
                {
                    if (digits[k] == sum)
                    {
                        noofhits += 2;
                        casehits[mycase] += 2;
                        //cout << digits[i] << " + " << digits[j] << " = " << digits[k] << endl;
                    }
                }
            }

            else if (digits[i] >= 0)
            { // Two pos
                mycase = 1;
                casecnt[mycase]++;
                for (int k = j + 1; k < noofdigits; k++)
                {
                    if (digits[k] == sum)
                    {
                        noofhits += 2;
                        casehits[mycase] += 2;
                        //cout << digits[i] << " + " << digits[j] << " = " << digits[k] << endl;
                    }
                }
            }
            else
            { // One neg and one pos
                mycase = 2;
                casecnt[mycase]++;
                for (int k = i + 1; k < j; k++)
                {
                    if (digits[k] == sum)
                    {
                        noofhits += 2;
                        casehits[mycase] += 2;
                        //cout << digits[i] << " + " << digits[j] << " = " << digits[k] << endl;
                    }
                }
            }
        }
    }
    int cntcntl = 0;
    for (int i = 1; i <= cases; i++)
    {
        cout << "Case # " << i << "\t" << casecnt[i - 1] << "\tHits = " << casehits[i - 1] << endl;
        cntcntl += casecnt[i - 1];
    }
    cout << endl
         << "Total # of case counts = " << cntcntl << endl;
    //Printing result
    cout << endl
         << "Total # of hits = " << noofhits << endl;

    return 0;
}
